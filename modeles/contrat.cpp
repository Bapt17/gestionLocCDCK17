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

#include "contrat.h"

Contrat::Contrat(QObject *parent, unsigned int id, Prestation *prestation,
                 const QDateTime &dateHeure, float remise, int etat,
                 QList<QObject *> lignes)
    : m_id(id), m_prestation(prestation), m_dateHeure(dateHeure),
      m_remise(remise), m_etat(etat), m_lignes(lignes) {}

unsigned int Contrat::getId() const { return m_id; }

Prestation *Contrat::getPrestation() const { return m_prestation; }

QDateTime Contrat::getDateHeure() const { return m_dateHeure; }

float Contrat::getRemise() const { return m_remise; }

void Contrat::setRemise(float remise) { m_remise = remise; }

int Contrat::getEtat() const { return m_etat; }
void Contrat::setEtat(int etat) { m_etat = etat; }

QList<QObject *> Contrat::getLignes() const { return m_lignes; }
void Contrat::setLignes(const QList<QObject *> &lignes) { m_lignes = lignes; }
