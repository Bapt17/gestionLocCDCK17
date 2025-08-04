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

ContratRepository::ContratRepository(DataBaseManager &dbManager)
    : m_dbManager(dbManager) {}

bool ContratRepository::addContrat(const Contrat &contrat) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "INSERT INTO contrats (idContrat, idPrestation, dateHeure, remise, etat) "
      "VALUES (:id, :idPrestation, :dateHeure, :remise, :etat)");
  query.bindValue(":id", contrat.getId());
  query.bindValue(":idPrestation", contrat.getPrestation().getId());
  query.bindValue(":dateHeure",
                  contrat.getDateHeure().toString("yyyy-MM-dd hh:mm:ss"));
  query.bindValue(":remise", contrat.getRemise());
  query.bindValue(":etat", contrat.getConfirme());

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
  query.bindValue(":idPrestation", contrat.getPrestation().getId());
  query.bindValue(":dateHeure",
                  contrat.getDateHeure().toString("yyyy-MM-dd hh:mm:ss"));
  query.bindValue(":remise", contrat.getRemise());
  query.bindValue(":etat", contrat.getConfirme());
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

QList<Contrat> ContratRepository::getAllContrats() {
  QList<Contrat> contrats;
  QSqlQuery query("SELECT * FROM contrats", m_dbManager.getDatabase());
  PrestationRepository prestaRepo(m_dbManager);
  LigneContratRepository lignesRepo(m_dbManager);

  while (query.next()) {
    unsigned int id = query.value("idContrat").toUInt();
    // on récupère la liste des lignes liées au contrat:
    QList<LigneContrat> lignes = lignesRepo.getAllLignesByIdContrat(id);

    // on récupère la prestation associée
    Contrat contrat(
        id,
        // on récupère la prestation associée grace à son id
        prestaRepo.getPrestationById(query.value("idPrestation").toUInt()),
        QDateTime::fromString(query.value("dateHeure").toString(),
                              "yyyy-MM-dd hh:mm:ss"),
        query.value("remise").toFloat(), query.value("etat").toBool(), lignes);
    contrats.append(contrat);
  }

  return contrats;
}

Contrat ContratRepository::getContratById(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("SELECT * FROM contrats WHERE idContrat = :id");
  query.bindValue(":id", id);

  if (!query.exec() || !query.next()) {
    QList listeVide = QList<LigneContrat>{};
    qDebug() << "Erreur lors de la récupération du contrat par son ID:"
             << query.lastError();
    return Contrat(0, Prestation(id, "", "", 0, 0, 0), QDateTime(), 0.0f, false,
                   listeVide); // TODO: gérer l'erreur autrement
  }

  PrestationRepository prestaRepo(m_dbManager);
  LigneContratRepository lignesRepo(m_dbManager);

  // on récupère la liste des lignes liées au contrat:
  QList<LigneContrat> lignes = lignesRepo.getAllLignesByIdContrat(id);

  return Contrat(
      id,
      // on récupère la prestation associée grace à son id
      prestaRepo.getPrestationById(query.value("idPrestation").toUInt()),
      QDateTime::fromString(query.value("dateHeure").toString(),
                            "yyyy-MM-dd hh:mm:ss"),
      query.value("remise").toFloat(), query.value("etat").toBool(), lignes);
}
