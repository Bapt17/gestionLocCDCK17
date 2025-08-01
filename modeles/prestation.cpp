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

#include "prestation.h"

Prestation::Prestation(unsigned int id, const QString &nom, const QString &type,
                       float tarifAdulte, float tarifU12, float tarifU8)
    : m_id(id), m_nom(nom), m_type(type), m_tarifAdulte(tarifAdulte),
      m_tarifU12(tarifU12), m_tarifU8(tarifU8) {}

unsigned int Prestation::getId() const { return m_id; }

QString Prestation::getNom() const { return m_nom; }

QString Prestation::getType() const { return m_type; }

float Prestation::getTarifAdulte() const { return m_tarifAdulte; }

float Prestation::getTarifU12() const { return m_tarifU12; }

float Prestation::getTarifU8() const { return m_tarifU8; }
