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

#include "contratrepository.h"
#include "lignecontratrepository.h"
#include "prestationrepository.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

ContratRepository::ContratRepository(QObject *parent,
                                     DataBaseManager &dbManager)
    : QObject(parent), m_dbManager(dbManager) {}

bool ContratRepository::addContrat(const Contrat &contrat) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "INSERT INTO contrats (idContrat, idPrestation, dateHeure, remise, etat) "
      "VALUES (:id, :idPrestation, :dateHeure, :remise, :etat)");
  query.bindValue(":id", contrat.getId());
  query.bindValue(":idPrestation", contrat.getPrestation()->getId());
  query.bindValue(":dateHeure",
                  contrat.getDateHeure().toString("yyyy-MM-dd hh:mm:ss"));
  query.bindValue(":remise", contrat.getRemise());
  query.bindValue(":etat", contrat.getEtat());

  if (!query.exec()) {
    qDebug() << "Erreur à l'ajout du contrat:" << query.lastError();
    return false;
  }
  return true;
}

bool ContratRepository::updateContrat(const Contrat &contrat) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("UPDATE contrats SET idPrestation = :idPrestation, dateHeure = "
                ":dateHeure, "
                "remise = :remise, etat = :etat WHERE idContrat = :id");
  query.bindValue(":idPrestation", contrat.getPrestation()->getId());
  query.bindValue(":dateHeure",
                  contrat.getDateHeure().toString("yyyy-MM-dd hh:mm:ss"));
  query.bindValue(":remise", contrat.getRemise());
  query.bindValue(":etat", contrat.getEtat());
  query.bindValue(":id", contrat.getId());

  if (!query.exec()) {
    qDebug() << "Erreur à la mise à jour du contrat:" << query.lastError();
    return false;
  }
  return true;
}

bool ContratRepository::deleteContrat(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("DELETE FROM contrats WHERE idContrat = :id");
  query.bindValue(":id", id);

  if (!query.exec()) {
    qDebug() << "Erreur à la suppression du contrat:" << query.lastError();
    return false;
  }
  return true;
}

QList<QObject *> ContratRepository::getAllContrats() {
  QList<QObject *> contrats;
  QSqlQuery query("SELECT * FROM contrats", m_dbManager.getDatabase());
  PrestationRepository prestaRepo(nullptr, m_dbManager);
  LigneContratRepository lignesRepo(nullptr, m_dbManager);

  while (query.next()) {
    unsigned int id = query.value("idContrat").toUInt();
    // on récupère la liste des lignes liées au contrat:
    QList<QObject *> lignes = lignesRepo.getAllLignesByIdContrat(id);

    // on crée le contrat a retourner
    QObject *contrat = new Contrat(
        nullptr, id,
        // on récupère la prestation associée grace à son id
        qobject_cast<Prestation *>(
            prestaRepo.getPrestationById(query.value("idPrestation").toUInt())),
        QDateTime::fromString(query.value("dateHeure").toString(),
                              "yyyy-MM-dd hh:mm:ss"),
        query.value("remise").toFloat(), query.value("etat").toInt(), lignes);
    contrats.append(contrat);
  }

  return contrats;
}

QObject *ContratRepository::getContratById(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("SELECT * FROM contrats WHERE idContrat = :id");
  query.bindValue(":id", id);

  if (!query.exec() || !query.next()) {
    qDebug() << "Erreur lors de la récupération du contrat par son ID:"
             << query.lastError();
    return nullptr;
  }

  PrestationRepository prestaRepo(nullptr, m_dbManager);
  LigneContratRepository lignesRepo(nullptr, m_dbManager);

  // on récupère la liste des lignes liées au contrat:
  QList<QObject *> lignes = lignesRepo.getAllLignesByIdContrat(id);

  return new Contrat(nullptr, id,
                     // on récupère la prestation associée grace à son id
                     qobject_cast<Prestation *>(prestaRepo.getPrestationById(
                         query.value("idPrestation").toUInt())),
                     QDateTime::fromString(query.value("dateHeure").toString(),
                                           "yyyy-MM-dd hh:mm:ss"),
                     query.value("remise").toFloat(),
                     query.value("etat").toInt(), lignes);
}

/**
 * @brief ContratRepository::getContratsConfirmes retourne les contrats validés
 * (etat a 1)
 * @return les contrats qui ont étés validés
 */
QList<QObject *> ContratRepository::getContratsConfirmes() {
  QList<QObject *> contrats;
  // selection des contrats validés uniquement
  QSqlQuery query("SELECT * FROM contrats WHERE etat = 1",
                  m_dbManager.getDatabase());

  PrestationRepository prestaRepo(nullptr, m_dbManager);
  LigneContratRepository lignesRepo(nullptr, m_dbManager);

  while (query.next()) {
    unsigned int id = query.value("idContrat").toUInt();
    // on récupère la liste des lignes liées au contrat:
    QList<QObject *> lignes = lignesRepo.getAllLignesByIdContrat(id);

    // on crée le contrat a retourner
    QObject *contrat = new Contrat(
        nullptr, id,
        // on récupère la prestation associée grace à son id
        qobject_cast<Prestation *>(
            prestaRepo.getPrestationById(query.value("idPrestation").toUInt())),
        QDateTime::fromString(query.value("dateHeure").toString(),
                              "yyyy-MM-dd hh:mm:ss"),
        query.value("remise").toFloat(), query.value("etat").toInt(), lignes);
    contrats.append(contrat);
  }

  return contrats;
}

/**
 * @brief ContratRepository::getContratsConfirmes retourne les contrats en
 * attente (etat a 0)
 * @return les contrats qui ont étés validés
 */
QList<QObject *> ContratRepository::getContratsNonConfirmes() {
  QList<QObject *> contrats;
  // selection des contrats en attente uniquement
  QSqlQuery query("SELECT * FROM contrats WHERE etat = 0",
                  m_dbManager.getDatabase());

  PrestationRepository prestaRepo(nullptr, m_dbManager);
  LigneContratRepository lignesRepo(nullptr, m_dbManager);

  while (query.next()) {
    unsigned int id = query.value("idContrat").toUInt();
    // on récupère la liste des lignes liées au contrat:
    QList<QObject *> lignes = lignesRepo.getAllLignesByIdContrat(id);

    // on crée le contrat a retourner
    QObject *contrat = new Contrat(
        nullptr, id,
        // on récupère la prestation associée grace à son id
        qobject_cast<Prestation *>(
            prestaRepo.getPrestationById(query.value("idPrestation").toUInt())),
        QDateTime::fromString(query.value("dateHeure").toString(),
                              "yyyy-MM-dd hh:mm:ss"),
        query.value("remise").toFloat(), query.value("etat").toInt(), lignes);
    contrats.append(contrat);
  }

  return contrats;
}
