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

#ifndef LIGNECONTRAT_H
#define LIGNECONTRAT_H

#include <QString>

#include "client.h"

class LigneContrat {
public:
  LigneContrat(unsigned int id, const Client &client, unsigned int idContrat,
               const QString &embarcation, float prix);

  unsigned int getId() const;
  Client getClient() const;
  unsigned int getIdContrat() const;
  QString getEmbarcation() const;
  float getPrix() const;

private:
  unsigned int m_id;
  Client m_client;
  unsigned int m_idContrat;
  QString m_embarcation;
  float m_prix;
};

#endif // LIGNECONTRAT_H
