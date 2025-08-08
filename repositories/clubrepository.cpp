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

#include "clubrepository.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

ClubRepository::ClubRepository(QObject *parent, DataBaseManager &dbManager)
    : QObject(parent), m_dbManager(dbManager) {}

bool ClubRepository::addClub(const Club &club) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "INSERT INTO club (nom, email, tel, adresse, codePostal, ville) "
      "VALUES (:nom, :email, :tel, :adresse, :codePostal, :ville)");
  query.bindValue(":nom", club.getNom());
  query.bindValue(":email", club.getEmail());
  query.bindValue(":tel", club.getTel());
  query.bindValue(":adresse", club.getAdresse());
  query.bindValue(":codePostal", club.getCodePostal());
  query.bindValue(":ville", club.getVille());

  if (!query.exec()) {
    qDebug() << "Erreur à l'ajout du club:" << query.lastError();
    return false;
  }
  return true;
}

bool ClubRepository::updateClub(const Club &club) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("UPDATE club SET nom = :nom, email = :email, tel = :tel, "
                "adresse = :adresse, "
                "codePostal = :codePostal, ville = :ville WHERE id = :id");
  query.bindValue(":nom", club.getNom());
  query.bindValue(":email", club.getEmail());
  query.bindValue(":tel", club.getTel());
  query.bindValue(":adresse", club.getAdresse());
  query.bindValue(":codePostal", club.getCodePostal());
  query.bindValue(":ville", club.getVille());
  query.bindValue(":id", club.getId());

  if (!query.exec()) {
    qDebug() << "Erreur à la mise à jour du club:" << query.lastError();
    return false;
  }
  return true;
}

Club *ClubRepository::getClub() {
  QSqlQuery query("SELECT * FROM club LIMIT 1", m_dbManager.getDatabase());

  if (!query.next()) {
    qDebug() << "Erreur lors de la récupération du club:" << query.lastError();
    return nullptr;
  }

  return new Club(
      nullptr, query.value("id").toUInt(), query.value("nom").toString(),
      query.value("email").toString(), query.value("tel").toString(),
      query.value("adresse").toString(), query.value("codePostal").toString(),
      query.value("ville").toString());
}
