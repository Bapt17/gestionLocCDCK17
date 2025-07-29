#include "prestation.h"

Prestation::Prestation(unsigned int id,
                       const QString &nom,
                       const QString &type,
                       float tarifAdulte,
                       float tarifU12,
                       float tarifU8)
    : m_id(id)
    , m_nom(nom)
    , m_type(type)
    , m_tarifAdulte(tarifAdulte)
    , m_tarifU12(tarifU12)
    , m_tarifU8(tarifU8)
{}

unsigned int Prestation::getId() const
{
    return m_id;
}

QString Prestation::getNom() const
{
    return m_nom;
}

QString Prestation::getType() const
{
    return m_type;
}

float Prestation::getTarifAdulte() const
{
    return m_tarifAdulte;
}

float Prestation::getTarifU12() const
{
    return m_tarifU12;
}

float Prestation::getTarifU8() const
{
    return m_tarifU8;
}
