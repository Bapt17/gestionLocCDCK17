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

#include "clientrepository.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

ClientRepository::ClientRepository(DataBaseManager &dbManager)
    : m_dbManager(dbManager) {}

bool ClientRepository::addClient(const Client &client) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "INSERT INTO clients (nom, prenom, dateNaissance, genre, codePostal) "
      "VALUES (:nom, :prenom, :dateNaissance, :genre, :codePostal)");
  query.bindValue(":nom", client.getNom());
  query.bindValue(":prenom", client.getPrenom());
  query.bindValue(":dateNaissance",
                  client.getDateNaissance().toString("yyyy-MM-dd"));
  query.bindValue(":genre", client.getGenre());
  query.bindValue(":codePostal", client.getCodePostal());

  if (!query.exec()) {
    qDebug() << "Erreur a l'ajout du client:" << query.lastError();
    return false;
  }
  return true;
}

bool ClientRepository::updateClient(const Client &client) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare(
      "UPDATE clients SET nom = :nom, prenom = :prenom, dateNaissance = "
      ":dateNaissance, "
      "genre = :genre, codePostal = :codePostal WHERE idClient = :id");
  query.bindValue(":nom", client.getNom());
  query.bindValue(":prenom", client.getPrenom());
  query.bindValue(":dateNaissance",
                  client.getDateNaissance().toString("yyyy-MM-dd"));
  query.bindValue(":genre", client.getGenre());
  query.bindValue(":codePostal", client.getCodePostal());
  query.bindValue(":id", client.getId());

  if (!query.exec()) {
    qDebug() << "Erreur à la mise a jour du client:" << query.lastError();
    return false;
  }
  return true;
}

bool ClientRepository::deleteClient(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("DELETE FROM clients WHERE idClient = :id");
  query.bindValue(":id", id);

  if (!query.exec()) {
    qDebug() << "Erreur à la suppression du client:" << query.lastError();
    return false;
  }
  return true;
}

QList<Client> ClientRepository::getAllClients() {
  QList<Client> clients;
  QSqlQuery query("SELECT * FROM clients", m_dbManager.getDatabase());

  while (query.next()) {
    Client client(
        query.value("idClient").toUInt(), query.value("nom").toString(),
        query.value("prenom").toString(),
        QDate::fromString(query.value("dateNaissance").toString(),
                          "yyyy-MM-dd"),
        query.value("genre").toString(), query.value("codePostal").toString());
    clients.append(client);
  }

  return clients;
}

Client ClientRepository::getClientById(unsigned int id) {
  QSqlQuery query(m_dbManager.getDatabase());
  query.prepare("SELECT * FROM clients WHERE idClient = :id");
  query.bindValue(":id", id);

  if (!query.exec() || !query.next()) {
    qDebug() << "Erreur lor de la recupération du client par son ID:"
             << query.lastError();
    return Client(0, "", "", QDate(), "", ""); // TODO: gérer l'erreur autrement
  }

  return Client(
      query.value("idClient").toUInt(), query.value("nom").toString(),
      query.value("prenom").toString(),
      QDate::fromString(query.value("dateNaissance").toString(), "yyyy-MM-dd"),
      query.value("genre").toString(), query.value("codePostal").toString());
}
