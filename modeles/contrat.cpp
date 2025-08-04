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

Contrat::Contrat(unsigned int id, const Prestation &prestation,
                 const QDateTime &dateHeure, float remise, bool confirme,
                 QList<LigneContrat> &lignes)
    : m_id(id), m_prestation(prestation), m_dateHeure(dateHeure),
      m_remise(remise), m_confirme(confirme), m_lignes(lignes) {}

unsigned int Contrat::getId() const { return m_id; }

Prestation Contrat::getPrestation() const { return m_prestation; }

QDateTime Contrat::getDateHeure() const { return m_dateHeure; }

float Contrat::getRemise() const { return m_remise; }

bool Contrat::getConfirme() const { return m_confirme; }

QList<LigneContrat> Contrat::getLignes() const { return m_lignes; }
