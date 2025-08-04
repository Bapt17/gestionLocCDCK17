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

#ifndef LIGNECONTRATREPOSITORY_H
#define LIGNECONTRATREPOSITORY_H

#include "modeles/lignecontrat.h"
#include "utils/databasemanager.h"
#include <QList>

/**
 * @brief La classe LigneContratRepository a pour but de faire le lien avec la
 * base de donnée pour y enregistrer, récupérer ou mettre à jour les lignes de
 * contrat dans la bdd.
 */
class LigneContratRepository {
public:
  LigneContratRepository(DataBaseManager &dbManager);

  bool addLigneContrat(const LigneContrat &ligneContrat);
  bool updateLigneContrat(const LigneContrat &ligneContrat);
  bool deleteLigneContrat(unsigned int id);
  QList<LigneContrat> getAllLignesContrat();
  LigneContrat getLigneContratById(unsigned int id);
  /**
   * @brief getAllLignesByIdContrat récupère les lignes liés a un contrat
   * @param id identifiant du contrat pour lequel on veut les lignes
   * @return la liste des ligneContrat associées.
   */
  QList<LigneContrat> getAllLignesByIdContrat(unsigned int id);

private:
  DataBaseManager &m_dbManager;
};

#endif // LIGNECONTRATREPOSITORY_H
