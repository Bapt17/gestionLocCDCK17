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

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Gestion des Contrats")

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Button {
            text: "Ajouter un Contrat"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                console.log("Ajouter un Contrat clicked")
                // Navigation vers la page de création de contrat
            }
        }

        Text {
            text: "Contrats en attente"
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: listViewNonConfirmes
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: contratRepository.contratsNonConfirmes
            delegate: Rectangle {
                width: parent.width
                height: 50
                border.color: "lightgray"
                color: "white"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Contrat clicked:", modelData.id)
                        // Navigation vers la page de visualisation du contrat
                    }

                    Row {
                        spacing: 10
                        anchors.centerIn: parent

                        Text { text: "N°" + modelData.id; width: 50}
                        Text { text: modelData.prestation.nom; width: 150 }
                        Text { text: Qt.formatDateTime(modelData.dateHeure, "dd/MM/yyyy hh:mm"); width: 150 }
                        Text { text: modelData.nbLignes; width: 100 }

                        Button {
                            text: "Valider"
                            onClicked: {
                                //on passe l'état du contrat a validé
                                modelData.etat = 1
                                contratRepository.updateContrat(modelData)
                                console.log("valider cliqué")
                            }
                        }
                    }
                }
            }
        }

        Text {
            text: "Contrats validés"
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: listViewConfirmes
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: contratRepository.contratsConfirmes
            delegate: Rectangle {
                width: parent.width
                height: 50
                border.color: "lightgray"
                color: "lightblue"

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Contrat clicked:", modelData.id)
                        // Navigation vers la page de visualisation du contrat
                    }

                    Row {
                        spacing: 10
                        anchors.centerIn: parent

                        Text { text: "N°" + modelData.id; width: 50 }
                        Text { text: modelData.prestation.nom; width: 150 }
                        Text { text: Qt.formatDateTime(modelData.dateHeure, "dd/MM/yyyy hh:mm"); width: 150 }
                        Text { text: modelData.nbLignes; width: 100 }
                    }
                }
            }
        }
    }
}
