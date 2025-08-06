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

// TODO: ATTENTION LE GETCONFIRME EST UN BOOL ALORS QUE L4ON PEUT AVOIR 1 0 ou
// -1 pour confirme en attente ou supprimé

#ifndef CONTRAT_H
#define CONTRAT_H

#include "lignecontrat.h"
#include "prestation.h"
#include <QDateTime>
#include <QList>
#include <QObject>
/**
 * @brief La classe contrat fait le lien entre les lignes, le contrat et la
 * prestation choisie
 */
class Contrat : public QObject {
  // propriétés accessibles dans le qml
  Q_OBJECT
  Q_PROPERTY(unsigned int id READ getId CONSTANT)
  Q_PROPERTY(Prestation *prestation READ getPrestation CONSTANT)
  Q_PROPERTY(QDateTime dateHeure READ getDateHeure CONSTANT)
  Q_PROPERTY(float remise READ getRemise WRITE setRemise NOTIFY remiseChanged)
  Q_PROPERTY(int etat READ getEtat WRITE setEtat NOTIFY etatChanged)
  Q_PROPERTY(QList<QObject *> lignes READ getLignes WRITE setLignes NOTIFY
                 lignesChanged)

public:
  Contrat(QObject *parent = nullptr, unsigned int id = 0,
          Prestation *prestation = nullptr,
          const QDateTime &dateHeure = QDateTime(), float remise = 0,
          int etat = 0, QList<QObject *> lignes = QList<QObject *>());

  unsigned int getId() const;

  Prestation *getPrestation() const;

  QDateTime getDateHeure() const;

  float getRemise() const;
  void setRemise(float remise);

  int getEtat() const;
  void setEtat(int etat);

  QList<QObject *> getLignes() const;
  void setLignes(const QList<QObject *> &lignes);

signals:
  void remiseChanged();
  void etatChanged();
  void lignesChanged();

private:
  unsigned int m_id;
  Prestation *m_prestation;
  QDateTime m_dateHeure;
  float m_remise;
  int m_etat;
  QList<QObject *> m_lignes;
};

#endif // CONTRAT_H
