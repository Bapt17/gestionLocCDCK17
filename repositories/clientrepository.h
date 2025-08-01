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

#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include "modeles/client.h"
#include "utils/databasemanager.h"
#include <QList>

/**
 * @brief La classe ClientRepository a pour but de faire le lien avec la base de
 * donnée pour y enregistrer, récupérer ou mettre a jour les clients dans la bdd
 */
class ClientRepository {
public:
  ClientRepository(DataBaseManager &dbManager);

  bool addClient(const Client &client);
  bool updateClient(const Client &client);
  bool deleteClient(unsigned int id);
  QList<Client> getAllClients();
  Client getClientById(unsigned int id);

private:
  DataBaseManager &m_dbManager;
};

#endif // CLIENTREPOSITORY_H
