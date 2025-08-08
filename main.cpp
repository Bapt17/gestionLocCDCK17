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

#include "modeles/contrat.h"
#include "repositories/contratrepository.h"
#include "utils/databasemanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  // on initialise la base de données pour soit la créer a la première
  // utilisation soit l'ouvrir les autre fois
  // TODO: il pourait être utile de laisser la possibilité à l'utilisateur de
  // choisir le fichier a ouvrir si aucun n'est encore créé
  DataBaseManager::initialiser();

  qmlRegisterType<Contrat>("GestionLocCDCK17", 1, 0, "Contrat");

  ContratRepository contratRepository;

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("contratRepository",
                                           &contratRepository);

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

  engine.loadFromModule("GestionLocCDCK17", "Main");

  return app.exec();
}
