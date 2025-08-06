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

#include "prestationrepository.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

PrestationRepository::PrestationRepository(QObject *parent,
                                           DataBaseManager &dbManager)
    : QObject(parent), m_dbManager(dbManager) {}

bool PrestationRepository::addPrestation(const Prestation &prestation) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "INSERT INTO prestations (nom, tarifAdulte, tarifU12, tarifU8, type)"
      "VALUES (:nom, :tarifAdulte, :tarifU12, :tarifU8, :type)");
  query.bindValue(":nom", prestation.getNom());
  query.bindValue(":tarifAdulte", prestation.getTarifAdulte());
  query.bindValue(":tarifU12", prestation.getTarifU12());
  query.bindValue(":tarifU8", prestation.getTarifU8());
  query.bindValue(":type", prestation.getType());

  if (!query.exec()) {
    qDebug() << "erreur a l'ajout de la prestation: " << query.lastError();
    return false;
  }
  return true;
}

bool PrestationRepository::updatePrestation(const Prestation &prestation) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "UPDATE prestations set nom = :nom, tarifAdulte = :tarifAdulte, tarifU12 "
      "= :tarifU12, tarifU8 = :tarifU8, type = :type"
      "WHERE idPrestation = :id");
  query.bindValue(":nom", prestation.getNom());
  query.bindValue(":tarifAdulte", prestation.getTarifAdulte());
  query.bindValue(":tarifU12", prestation.getTarifU12());
  query.bindValue(":tarifU8", prestation.getTarifU8());
  query.bindValue(":type", prestation.getType());
  query.bindValue(":id", prestation.getId());

  if (!query.exec()) {
    qDebug() << "erreur a la mise a jour de la prestation: "
             << query.lastError();
    return false;
  }
  return true;
}

bool PrestationRepository::deletePrestation(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("DELETE FROM prestations WHERE idPrestation = :id");
  query.bindValue(":id", id);

  if (!query.exec()) {
    qDebug() << "erreur à la suppression de la prestation: "
             << query.lastError();
    return false;
  }
  return true;
}

QList<QObject *> PrestationRepository::getAllPrestations() {
  QList<QObject *> prestations;
  QSqlQuery query("SELECT * FROM Prestations", m_dbManager.getDatabase());

  // on cree des prestations et on les ajoute a la liste tant qu'il y en a de
  // récupérés
  while (query.next()) {
    QObject *prestation = new Prestation(
        nullptr, query.value("idPrestation").toUInt(),
        query.value("nom").toString(), query.value("type").toString(),
        query.value("tarifAdulte").toFloat(), query.value("tarifU12").toFloat(),
        query.value("tarifU8").toFloat());
    prestations.append(prestation);
  }
  // on restourne la liste
  return prestations;
}

QObject *PrestationRepository::getPrestationById(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("SELECT * FROM prestations WHERE idPrestation = :id");
  query.bindValue(":id", id);

  if (!query.exec() || !query.next()) {
    qDebug() << "Erreur lor de la recupération de la prestation par son ID:"
             << query.lastError();
    return nullptr; // TODO: gérer l'erreur autrement
  }
  QObject *prestation = new Prestation(
      nullptr, query.value("idPrestation").toUInt(),
      query.value("nom").toString(), query.value("type").toString(),
      query.value("tarifAdulte").toFloat(), query.value("tarifU12").toFloat(),
      query.value("tarifU8").toFloat());
  return prestation;
}
