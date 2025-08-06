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
#include <QObject>

/**
 * @brief La classe ContratRepository a pour but de faire le lien avec la base
 * de donnée pour y enregistrer, récupérer ou mettre à jour les contrats dans la
 * bdd.
 */
class ContratRepository : public QObject {
  Q_OBJECT
  Q_PROPERTY(QList<QObject *> contratsNonConfirmes READ getContratsNonConfirmes
                 NOTIFY contratsNonConfirmesChanged)
  Q_PROPERTY(QList<QObject *> contratsConfirmes READ getContratsConfirmes NOTIFY
                 contratsConfirmesChanged)

public:
  explicit ContratRepository(
      QObject *parent = nullptr,
      DataBaseManager &dbManager = DataBaseManager::getInstance());

  Q_INVOKABLE bool addContrat(const Contrat &contrat);
  Q_INVOKABLE bool updateContrat(const Contrat &contrat);
  Q_INVOKABLE bool deleteContrat(unsigned int id);
  Q_INVOKABLE QList<QObject *> getAllContrats();
  Q_INVOKABLE QObject *getContratById(unsigned int id);

  QList<QObject *> getContratsNonConfirmes();
  QList<QObject *> getContratsConfirmes();

signals:
  void contratsNonConfirmesChanged();
  void contratsConfirmesChanged();

private:
  DataBaseManager &m_dbManager;
};

#endif // CONTRATREPOSITORY_H
