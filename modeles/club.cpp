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

#include "club.h"

Club::Club(QObject *parent, unsigned int id, const QString &nom,
           const QString &email, const QString &tel, const QString &adresse,
           const QString &codePostal, const QString &ville)
    : QObject(parent), m_id(id), m_nom(nom), m_email(email), m_tel(tel),
      m_adresse(adresse), m_codePostal(codePostal), m_ville(ville) {}

unsigned int Club::getId() const { return m_id; }

void Club::setId(unsigned int id) {
  if (m_id != id) {
    m_id = id;
    emit idChanged();
  }
}

QString Club::getNom() const { return m_nom; }

void Club::setNom(const QString &nom) {
  if (m_nom != nom) {
    m_nom = nom;
    emit nomChanged();
  }
}

QString Club::getEmail() const { return m_email; }

void Club::setEmail(const QString &email) {
  if (m_email != email) {
    m_email = email;
    emit emailChanged();
  }
}

QString Club::getTel() const { return m_tel; }

void Club::setTel(const QString &tel) {
  if (m_tel != tel) {
    m_tel = tel;
    emit telChanged();
  }
}

QString Club::getAdresse() const { return m_adresse; }

void Club::setAdresse(const QString &adresse) {
  if (m_adresse != adresse) {
    m_adresse = adresse;
    emit adresseChanged();
  }
}

QString Club::getCodePostal() const { return m_codePostal; }

void Club::setCodePostal(const QString &codePostal) {
  if (m_codePostal != codePostal) {
    m_codePostal = codePostal;
    emit codePostalChanged();
  }
}

QString Club::getVille() const { return m_ville; }

void Club::setVille(const QString &ville) {
  if (m_ville != ville) {
    m_ville = ville;
    emit villeChanged();
  }
}
