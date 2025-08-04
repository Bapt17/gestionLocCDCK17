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

#ifndef CONTRATREPOSITORY_H
#define CONTRATREPOSITORY_H

#include "modeles/contrat.h"
#include "utils/databasemanager.h"
#include <QList>

/**
 * @brief La classe ContratRepository a pour but de faire le lien avec la base
 * de donnée pour y enregistrer, récupérer ou mettre à jour les contrats dans la
 * bdd.
 */
class ContratRepository {
public:
  ContratRepository(DataBaseManager &dbManager);

  bool addContrat(const Contrat &contrat);
  bool updateContrat(const Contrat &contrat);
  bool deleteContrat(unsigned int id);
  QList<Contrat> getAllContrats();
  Contrat getContratById(unsigned int id);

private:
  DataBaseManager &m_dbManager;
};

#endif // CONTRATREPOSITORY_H
