#include "contrat.h"

Contrat::Contrat(unsigned int id,
                 const Prestation &prestation,
                 const QDateTime &dateHeure,
                 float remise,
                 bool confirme)
    : m_id(id)
    , m_prestation(prestation)
    , m_dateHeure(dateHeure)
    , m_remise(remise)
    , m_confirme(confirme)
{}

unsigned int Contrat::getId() const
{
    return m_id;
}

QDateTime Contrat::getDateHeure() const
{
    return m_dateHeure;
}

float Contrat::getRemise() const
{
    return m_remise;
}

bool Contrat::getConfirme() const
{
    return m_confirme;
}
