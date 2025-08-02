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

#ifndef PRESTATIONREPOSITORY_H
#define PRESTATIONREPOSITORY_H

#include "modeles/prestation.h"
#include "utils/databasemanager.h"
#include <QList>

/**
 * @brief La classe PrestationRepository a pour but de faire le lien avec la
 * base de donnée pour y enregistrer, récupérer ou mettre a jour les Prestations
 * dans la bdd
 */
class PrestationRepository {
public:
  PrestationRepository(DataBaseManager &dbManager);

  bool addPrestation(const Prestation &prestation);
  bool updatePrestation(const Prestation &prestation);
  bool deletePrestation(unsigned int id);
  QList<Prestation> getAllPrestations();
  Prestation getPrestationById(unsigned int id);

private:
  DataBaseManager &m_dbManager;
};

#endif // PRESTATIONREPOSITORY_H
