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
                        "type TEXT NOT NULL")) {
        qDebug() << "Erreur: impossible de créer la table prestations";
      }

      // table contrats:
      if (!requete.exec(
              "CREATE TABLE contrats ("
              "idContrat INTEGER PRIMARY KEY,"
              "FOREIGN KEY(idPrestation) REFERENCES prestations(idPrestation) "
              "NOT NULL,"
              "dateHeure TEXT NOT NULL,"
              "remise NUMERIC NOT NULL DEFAULT 0,"
              "etat INTEGER NOT NULL DEFAULT 0" // etat est a 0 pour brouillon,
                                                // 1 pour confirme et
                                                // -1 pour supprimé
              )) {
        qDebug() << "Erreur: impossible de créer la table contrats";
      }

      // table lignesContrat:
      if (!requete.exec(
              "CREATE TABLE lignesContrat ("
              "idLigne INTEGER PRIMARY KEY AUTOINCREMENT,"
              "FOREIGN KEY(idContrat) REFERENCES contrats(idContrat) NOT NULL,"
              "FOREIGN KEY(idClient) REFERENCES clients(idClients) NOT NULL,"
              "embarcation TEXT NOT NULL,"
              "prix NUMERIC NOT NULL")) {
        qDebug() << "Erreur: impossible de créer la table lignesContrat";
      }

    } else {
      // Si la base existe on l'ouvre
      if (!m_database.open()) {
        qDebug() << "Erreur: impossible d'ouvrir la base de données existante.";
        return false;
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
