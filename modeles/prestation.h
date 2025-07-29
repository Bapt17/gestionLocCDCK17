#ifndef PRESTATION_H
#define PRESTATION_H

#include <QString>

/**
 * @brief La classe Prestation représente les prestations
 * proposés (locations etc...) avec les tarifs pour les adultes 
 * les moins de 8 ans et moins de 12 ans
 */
class Prestation
{
public:
    Prestation(unsigned int id,
               const QString &nom,
               const QString &type,
               const float tarifAdulte,
               const float tarifU12,
               const float tarifU8);

    unsigned int getId() const;
    QString getNom() const;
    QString getType() const;
    float getTarifAdulte() const;
    float getTarifU12() const;
    float getTarifU8() const;

private:
    unsigned int m_id;
    QString m_nom;
    QString m_type;
    float m_tarifAdulte;
    float m_tarifU12;
    float m_tarifU8;
};

#endif // PRESTATION_H
