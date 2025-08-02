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

#ifndef CONTRAT_H
#define CONTRAT_H

#include "prestation.h"
#include <QDateTime>
#include <QString>
/**
 * @brief La classe contrat fait le lien entre les lignes, le contrat et la
 * prestation choisie
 */
class Contrat {
public:
  Contrat(unsigned int id, const Prestation &prestation,
          const QDateTime &dateHeure, float remise, bool confirme);

  unsigned int getId() const;
  Prestation getPrestation() const;
  QDateTime getDateHeure() const;
  float getRemise() const;
  bool getConfirme() const;

private:
  unsigned int m_id;
  Prestation m_prestation;
  QDateTime m_dateHeure;
  float m_remise;  // pas utilisée pour le moment mais servira peut être par la
                   // suite
  bool m_confirme; // défini si le contrat est terminé et fini d'être
                   // remplie/payé
};

#endif // CONTRAT_H
