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

#include "client.h"
#include <QObject>
#include <QString>

class LigneContrat : public QObject {
  // utilisation de la macro qobject pour spécifier les éléments accessibles
  // dans le qml
  Q_OBJECT
  Q_PROPERTY(unsigned int id READ getId CONSTANT)
  Q_PROPERTY(Client *client READ getClient CONSTANT)
  Q_PROPERTY(unsigned int idContrat READ getIdContrat CONSTANT)
  Q_PROPERTY(QString embarcation READ getEmbarcation CONSTANT)
  Q_PROPERTY(float prix READ getPrix CONSTANT)

public:
  explicit LigneContrat(QObject *parent = nullptr, unsigned int id = 0,
                        Client *client = nullptr, unsigned int idContrat = 0,
                        const QString &embarcation = "", float prix = 0.0f);

  unsigned int getId() const;
  Client *getClient() const;
  unsigned int getIdContrat() const;
  QString getEmbarcation() const;
  float getPrix() const;

private:
  unsigned int m_id;
  Client *m_client;
  unsigned int m_idContrat;
  QString m_embarcation;
  float m_prix;
};

#endif // LIGNECONTRAT_H
