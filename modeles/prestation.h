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

#include <QObject>
#include <QString>

/**
 * @brief La classe Prestation représente les prestations proposées (locations
 * etc...) avec les tarifs pour les adultes les moins de 8 ans et moins de 12
 * ans
 */
class Prestation : public QObject {
  // utilisation de la macro qobject pour spécifier les éléments accessibles
  // dans le qml
  Q_OBJECT
  Q_PROPERTY(unsigned int id READ getId CONSTANT)
  Q_PROPERTY(QString nom READ getNom CONSTANT)
  Q_PROPERTY(QString type READ getType CONSTANT)
  Q_PROPERTY(float tarifAdulte READ getTarifAdulte WRITE setTarifAdulte NOTIFY
                 tarifAdultChanged)
  Q_PROPERTY(
      float tarifU12 READ getTarifU12 WRITE setTarifU12 NOTIFY tarifU12Changed)
  Q_PROPERTY(
      float tarifU8 READ getTarifU8 WRITE setTarifU8 NOTIFY tarifU8Changed)

public:
  explicit Prestation(QObject *parent = nullptr, unsigned int id = 0,
                      const QString &nom = "", const QString &type = "",
                      float tarifAdulte = 0.0f, float tarifU12 = 0.0f,
                      float tarifU8 = 0.0f);

  unsigned int getId() const;
  QString getNom() const;
  QString getType() const;
  float getTarifAdulte() const;
  void setTarifAdulte(float tarif);
  float getTarifU12() const;
  void setTarifU12(float tarif);
  float getTarifU8() const;
  void setTarifU8(float tarif);

signals:
  void tarifAdultChanged();
  void tarifU12Changed();
  void tarifU8Changed();

private:
  unsigned int m_id;
  QString m_nom;
  QString m_type;
  float m_tarifAdulte;
  float m_tarifU12;
  float m_tarifU8;
};

#endif // PRESTATION_H
