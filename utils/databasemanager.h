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
