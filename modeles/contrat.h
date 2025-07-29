#ifndef CONTRAT_H
#define CONTRAT_H

#include <QDateTime>
#include <QString>

#include "prestation.h"
/**
 * @brief La classe contrat fait le lien entre les lignes, le contrat et la prestation choisie
 */
class Contrat
{
public:
    Contrat(unsigned int id,
            const Prestation &prestation,
            const QDateTime &dateHeure,
            float remise,
            bool confirme);

    unsigned int getId() const;
    QDateTime getDateHeure() const;
    float getRemise() const;
    bool getConfirme() const;

private:
    unsigned int m_id;
    Prestation m_prestation;
    QDateTime m_dateHeure;
    float m_remise;  //pas utilisée pour le moment mais servira peut être par la suite
    bool m_confirme; //défini si le contrat est terminé et fini d'être remplie/payé
};

#endif // CONTRAT_H
