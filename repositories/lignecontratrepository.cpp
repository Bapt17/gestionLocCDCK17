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

#include "lignecontratrepository.h"
#include "clientrepository.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

LigneContratRepository::LigneContratRepository(QObject *parent,
                                               DataBaseManager &dbManager)
    : QObject(parent), m_dbManager(dbManager) {}

bool LigneContratRepository::addLigneContrat(const LigneContrat &ligneContrat) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "INSERT INTO lignesContrat (idContrat, idClient, embarcation, prix) "
      "VALUES (:idContrat, :idClient, :embarcation, :prix)");
  query.bindValue(":idContrat", ligneContrat.getIdContrat());
  query.bindValue(":idClient", ligneContrat.getClient()->getId());
  query.bindValue(":embarcation", ligneContrat.getEmbarcation());
  query.bindValue(":prix", ligneContrat.getPrix());

  if (!query.exec()) {
    qDebug() << "Erreur à l'ajout de la ligne de contrat:" << query.lastError();
    return false;
  }
  return true;
}

bool LigneContratRepository::updateLigneContrat(
    const LigneContrat &ligneContrat) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "UPDATE lignesContrat SET idContrat = :idContrat, idClient = :idClient, "
      "embarcation = :embarcation, prix = :prix WHERE idLigne = :id");
  query.bindValue(":idContrat", ligneContrat.getIdContrat());
  query.bindValue(":idClient", ligneContrat.getClient()->getId());
  query.bindValue(":embarcation", ligneContrat.getEmbarcation());
  query.bindValue(":prix", ligneContrat.getPrix());
  query.bindValue(":id", ligneContrat.getId());

  if (!query.exec()) {
    qDebug() << "Erreur à la mise à jour de la ligne de contrat:"
             << query.lastError();
    return false;
  }
  return true;
}

bool LigneContratRepository::deleteLigneContrat(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("DELETE FROM lignesContrat WHERE idLigne = :id");
  query.bindValue(":id", id);

  if (!query.exec()) {
    qDebug() << "Erreur à la suppression de la ligne de contrat:"
             << query.lastError();
    return false;
  }
  return true;
}

QList<QObject *> LigneContratRepository::getAllLignesContrat() {
  QList<QObject *> lignesContrat;
  QSqlQuery query("SELECT * FROM lignesContrat", m_dbManager.getDatabase());
  ClientRepository clientRepo(nullptr, m_dbManager);

  while (query.next()) {
    // on récupère le client relié grace a son id
    QObject *client =
        clientRepo.getClientById(query.value("idClient").toUInt());
    QObject *ligneContrat = new LigneContrat(
        nullptr, query.value("idLigne").toUInt(),
        qobject_cast<Client *>(client), query.value("idContrat").toUInt(),
        query.value("embarcation").toString(), query.value("prix").toFloat());
    lignesContrat.append(ligneContrat);
  }

  return lignesContrat;
}

QObject *LigneContratRepository::getLigneContratById(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("SELECT * FROM lignesContrat WHERE idLigne = :id");
  query.bindValue(":id", id);

  if (!query.exec() || !query.next()) {
    qDebug()
        << "Erreur lors de la récupération de la ligne de contrat par son ID:"
        << query.lastError();
    return nullptr;
  }
  // on récupère le client relié grace a son id
  ClientRepository clientRepo(nullptr, m_dbManager);
  QObject *client =
      (Client *)clientRepo.getClientById(query.value("idClient").toUInt());

  return new LigneContrat(
      nullptr, query.value("idLigne").toUInt(), qobject_cast<Client *>(client),
      query.value("idContrat").toUInt(), query.value("embarcation").toString(),
      query.value("prix").toFloat());
}

QList<QObject *>
LigneContratRepository::getAllLignesByIdContrat(unsigned int id) {
  QList<QObject *> lignesContrat;
  QSqlQuery query("SELECT idLigne, idClient, embarcation, prix"
                  "FROM lignesContrat"
                  "WHERE idContrat = :id",
                  m_dbManager.getDatabase());
  ClientRepository clientRepo(nullptr, m_dbManager);

  while (query.next()) {
    Client *client =
        (Client *)clientRepo.getClientById(query.value("idClient").toUInt());
    QObject *ligneContrat = new LigneContrat(
        nullptr, query.value("idLigne").toUInt(), client, id,
        query.value("embarcation").toString(), query.value("prix").toFloat());
    lignesContrat.append(ligneContrat);
  }

  return lignesContrat;
}
