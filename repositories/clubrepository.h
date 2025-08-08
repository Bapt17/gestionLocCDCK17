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

#ifndef CLUBREPOSITORY_H
#define CLUBREPOSITORY_H

#include "modeles/club.h"
#include "utils/databasemanager.h"
#include <QObject>

class ClubRepository : public QObject {
  Q_OBJECT

public:
  explicit ClubRepository(
      QObject *parent = nullptr,
      DataBaseManager &dbManager = DataBaseManager::getInstance());

  Q_INVOKABLE bool addClub(const Club &club);
  Q_INVOKABLE bool updateClub(const Club &club);
  Q_INVOKABLE Club *getClub();

private:
  DataBaseManager &m_dbManager;
};

#endif // CLUBREPOSITORY_H
