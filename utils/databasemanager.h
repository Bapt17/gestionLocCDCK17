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

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DataBaseManager {
public:
  /**
   * @brief initialiser methode pour initialiser la base de données, si la base
   * existe on l'ouvre sinon on la cree
   * @param chemin chemin du fichier.db contenant la base de données
   * @return false en cas d'echec, true sinon
   */
  static bool initialiser(const QString &chemin = "licationCK.db");
  static QSqlDatabase &getDatabase();
  static void close();

private:
  static QSqlDatabase m_database;
  /**
   * @brief mettreAJourBDD verifie la version actuelle de la bdd et fait les
   * changements nécéssaires si le schéma n'est pas a la version la plus récente
   * (pour le moment cette fonction ne fait rien car c'est la première version)
   * @return false en cas de problemes
   */
  static bool mettreAJourBDD();
};

#endif // DATABASEMANAGER_H
