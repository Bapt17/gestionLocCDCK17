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
 * GestionLocCDCK17.If not, see https://www.gnu.org/licenses/.
 */

#ifndef CLUB_H
#define CLUB_H

#include <QObject>
#include <QString>

/**
 * @brief La classe club contient les informations du club qui utilise le
 * logiciel. elle sert a afficher les informations du club sur le ticket de
 * caisse par exemple et son mail est aussi utilisé pour le fichier csv exporté
 * pour les cartes 1 jour
 */
class Club : public QObject {
  Q_OBJECT
  Q_PROPERTY(unsigned int id READ getId WRITE setId NOTIFY idChanged)
  Q_PROPERTY(QString nom READ getNom WRITE setNom NOTIFY nomChanged)
  Q_PROPERTY(QString email READ getEmail WRITE setEmail NOTIFY emailChanged)
  Q_PROPERTY(QString tel READ getTel WRITE setTel NOTIFY telChanged)
  Q_PROPERTY(
      QString adresse READ getAdresse WRITE setAdresse NOTIFY adresseChanged)
  Q_PROPERTY(QString codePostal READ getCodePostal WRITE setCodePostal NOTIFY
                 codePostalChanged)
  Q_PROPERTY(QString ville READ getVille WRITE setVille NOTIFY villeChanged)

public:
  explicit Club(QObject *parent = nullptr, unsigned int id = 0,
                const QString &nom = "", const QString &email = "",
                const QString &tel = "", const QString &adresse = "",
                const QString &codePostal = "", const QString &ville = "");

  unsigned int getId() const;
  void setId(unsigned int id);

  QString getNom() const;
  void setNom(const QString &nom);

  QString getEmail() const;
  void setEmail(const QString &email);

  QString getTel() const;
  void setTel(const QString &tel);

  QString getAdresse() const;
  void setAdresse(const QString &adresse);

  QString getCodePostal() const;
  void setCodePostal(const QString &codePostal);

  QString getVille() const;
  void setVille(const QString &ville);

signals:
  void idChanged();
  void nomChanged();
  void emailChanged();
  void telChanged();
  void adresseChanged();
  void codePostalChanged();
  void villeChanged();

private:
  unsigned int m_id;
  QString m_nom;
  QString m_email;
  QString m_tel;
  QString m_adresse;
  QString m_codePostal;
  QString m_ville;
};

#endif // CLUB_H
