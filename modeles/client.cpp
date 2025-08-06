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

#include "client.h"

Client::Client(QObject *parent, unsigned int id, const QString &nom,
               const QString &prenom, const QDate &dateNaissance,
               const QString &genre, const QString &codePostal)
    : QObject(parent), m_id(id), m_nom(nom), m_prenom(prenom),
      m_dateNaissance(dateNaissance), m_genre(genre), m_codePostal(codePostal) {
}

unsigned int Client::getId() const { return m_id; }

QString Client::getNom() const { return m_nom; }

QString Client::getPrenom() const { return m_prenom; }

QDate Client::getDateNaissance() const { return m_dateNaissance; }

QString Client::getGenre() const { return m_genre; }

QString Client::getCodePostal() const { return m_codePostal; }
