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

#ifndef PRESTATION_H
#define PRESTATION_H

#include <QString>

/**
 * @brief La classe Prestation représente les prestations proposées (locations
 * etc...) avec les tarifs pour les adultes les moins de 8 ans et moins de 12
 * ans
 */
class Prestation {
public:
  Prestation(unsigned int id, const QString &nom, const QString &type,
             const float tarifAdulte, const float tarifU12,
             const float tarifU8);

  unsigned int getId() const;
  QString getNom() const;
  QString getType() const;
  float getTarifAdulte() const;
  float getTarifU12() const;
  float getTarifU8() const;

private:
  unsigned int m_id;
  QString m_nom;
  QString m_type;
  float m_tarifAdulte;
  float m_tarifU12;
  float m_tarifU8;
};

#endif // PRESTATION_H
