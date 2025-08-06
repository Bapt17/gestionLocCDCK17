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

#include "lignecontrat.h"

LigneContrat::LigneContrat(QObject *parent, unsigned int id, Client *client,
                           unsigned int idContrat, const QString &embarcation,
                           float prix)
    : QObject(parent), m_id(id), m_client(client), m_idContrat(idContrat),
      m_embarcation(embarcation), m_prix(prix) {}

unsigned int LigneContrat::getId() const { return m_id; }

Client *LigneContrat::getClient() const { return m_client; }

unsigned int LigneContrat::getIdContrat() const { return m_idContrat; }

QString LigneContrat::getEmbarcation() const { return m_embarcation; }

float LigneContrat::getPrix() const { return m_prix; }
