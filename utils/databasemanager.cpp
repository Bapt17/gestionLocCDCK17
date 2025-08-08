/**Copyright 2025 Baptiste HUCHON
 *
 * This file is part of GestionLocCDCK17.
 *
 * GestionLocCDCK17 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * GestionLocCDCK17 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * GestionLocCDCK17.If not, see https://www.gnu.org/licenses/.*/

#include "databasemanager.h"

#include <QDebug>
#include <QFile>
#include <QSqlQuery>

QSqlDatabase DataBaseManager::m_database;

bool DataBaseManager::initialiser(const QString &chemin) {
  if (QSqlDatabase::isDriverAvailable("QSQLITE")) {
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(chemin);

    if (!QFile::exists(chemin)) {
      // si le fichier n'existe pas on le cree et on cree les tables
      if (!m_database.open()) {
        qDebug() << "Erreur: impossible d'ouvrir la base de données.";
        return false;
      }

      // création des tables:
      QSqlQuery requete;

      // table clients:
      if (!requete.exec("CREATE TABLE clients ("
                        "idClient INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "nom TEXT NOT NULL,"
                        "prenom TEXT NOT NULL,"
                        "dateNaissance TEXT NOT NULL,"
                        "genre TEXT NOT NULL,"
                        "codePostal TEXT NOT NULL default 'inconnu')")) {
        qDebug() << "Erreur: impossible de créer la table clients";
      }

      // table prestations:
      if (!requete.exec("CREATE TABLE prestations ("
                        "idPrestation INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "nom TEXT NOT NULL,"
                        "tarifAdulte NUMERIC NOT NULL,"
                        "tarifU12 NUMERIC NOT NULL,"
                        "tarifU8 NUMERIC NOT NULL,"
                        "type TEXT NOT NULL)")) {
        qDebug() << "Erreur: impossible de créer la table prestations";
      }

      // table contrats:
      if (!requete.exec(
              "CREATE TABLE contrats ("
              "idContrat INTEGER PRIMARY KEY,"
              "idPrestation INTEGER NOT NULL,"
              "dateHeure TEXT NOT NULL,"
              "remise NUMERIC NOT NULL DEFAULT 0,"
              "etat INTEGER NOT NULL DEFAULT 0," // etat est a 0 pour brouillon,
                                                 // 1 pour confirme et
                                                 // -1 pour supprimé
              "FOREIGN KEY(idPrestation) REFERENCES "
              "prestations(idPrestation))")) {
        qDebug() << "Erreur: impossible de créer la table contrats";
      }

      // table lignesContrat:
      if (!requete.exec(
              "CREATE TABLE lignesContrat ("
              "idLigne INTEGER PRIMARY KEY AUTOINCREMENT,"
              "idContrat INTEGER NOT NULL,"
              "idClient INTEGER NOT NULL,"
              "embarcation TEXT NOT NULL,"
              "prix NUMERIC NOT NULL,"
              "FOREIGN KEY(idContrat) REFERENCES contrats(idContrat),"
              "FOREIGN KEY(idClient) REFERENCES clients(idClient))")) {
        qDebug() << "Erreur: impossible de créer la table lignesContrat";
      }

      // table pour contenir les informations du club utilisant le logiciel
      // (surtout utilisé pour afficher sur le ticket de caisse et pour mettre
      // le mail dans les assurances fédérales
      if (!requete.exec("CREATE TABLE club ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "nom TEXT NOT NULL,"
                        "email TEXT NOT NULL,"
                        "tel TEXT NOT NULL,"
                        "adresse TEXT NOT NULL,"
                        "codePostal TEXT NOT NULL,"
                        "ville TEXT NOT NULL")) {
        qDebug() << "Erreur: impossible de créer la table club";
      }

      // table pour gérer et garder en mémoire la version
      if (!requete.exec(
              "CREATE TABLE schema_versions ("
              "version INTEGER PRIMARY KEY,"
              "description TEXT,"
              "dateInstallation TIMESTAMP DEFAULT CURRENT_TIMESTAMP)")) {
        qDebug() << "Erreur: impossible de créer la table schemas_versions";
      }

      // insertion de la version actuelle de la bdd dans le schemas
      if (!requete.exec("INSERT INTO schema_versions(version, description) "
                        "VALUES (0,'Version initiale avec clients, "
                        "prestations, contrats et lignesContrat')")) {
        qDebug() << "Erreur: impossible d'e créer la table "
                    "lignesContrat'insérer la version";
      }

    } else {
      // Si la base existe on l'ouvre
      if (!m_database.open()) {
        qDebug() << "Erreur: impossible d'ouvrir la base de données existante.";
        return false;
      }
      // on met a jour la base de donnée si besoin
      if (!mettreAJourBDD()) {
        qDebug() << "Erreur: un fichier de base de donnée existe mais il ne "
                    "contient pas de version.";
      }
    }
  } else {
    qDebug() << "Erreur: le Driver QSQlite n'est pas disponnible.";
    return false;
  }
  return true;
}

QSqlDatabase &DataBaseManager::getDatabase() { return m_database; }

void DataBaseManager::close() { m_database.close(); }

// TODO: cette fonction pourrait potentiellement être mise ailleurs pour
// l'executer dans un script seulement à la mise a jour
bool DataBaseManager::mettreAJourBDD() {
  QSqlQuery query(m_database);

  // on récupère la verion de la base de données actuelle
  query.exec(
      "SELECT version FROM schema_versions ORDER BY version DESC LIMIT 1");
  int versionActuelle = 0;
  // si il y a bien une version d'enregistrée on la récupère, sinon la base de
  // donnée actuelle n'est pas correcte
  if (query.next()) {
    versionActuelle = query.value(0).toInt();
  } else {
    return false;
  }

  // on appliquera ici pour chaque version dans l'ordre les changements a
  // effectuer pour permettre la migration vers la derniere version sans pertes.
  // il faudra penser a insérer dans la base de donnée la derniere version vers
  // laquelle on a migré pour éviter de répéter l'opération
  return true;
}

DataBaseManager &DataBaseManager::getInstance() {
  static DataBaseManager instance;
  return instance;
}
