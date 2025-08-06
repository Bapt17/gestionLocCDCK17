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

#ifndef CLIENT_H
#define CLIENT_H

#include <QDate>
#include <QObject>
#include <QString>

class Client : public QObject {
  // utilisation de la macro qobject pour spécifier les éléments accessibles
  // dans le qml
  Q_OBJECT
  Q_PROPERTY(unsigned int id READ getId CONSTANT)
  Q_PROPERTY(QString nom READ getNom CONSTANT)
  Q_PROPERTY(QString prenom READ getPrenom CONSTANT)
  Q_PROPERTY(QDate dateNaissance READ getDateNaissance CONSTANT)
  Q_PROPERTY(QString genre READ getGenre CONSTANT)
  Q_PROPERTY(QString codePostal READ getCodePostal CONSTANT)

public:
  explicit Client(QObject *parent = nullptr, unsigned int id = 0,
                  const QString &nom = "", const QString &prenom = "",
                  const QDate &dateNaissance = QDate(),
                  const QString &genre = "", const QString &codePostal = "");

  unsigned int getId() const;
  QString getNom() const;
  QString getPrenom() const;
  QDate getDateNaissance() const;
  QString getGenre() const;
  QString getCodePostal() const;

private:
  unsigned int m_id;
  QString m_nom;
  QString m_prenom;
  QDate m_dateNaissance;
  QString m_genre;
  QString m_codePostal;
};

#endif // CLIENT_H
