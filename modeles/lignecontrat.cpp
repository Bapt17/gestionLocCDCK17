#include "lignecontrat.h"

LigneContrat::LigneContrat(unsigned int id,
                           const Client &client,
                           const Contrat &contrat,
                           const QString &embarcation,
                           float prix)
    : m_id(id)
    , m_client(client)
    , m_contrat(contrat)
    , m_embarcation(embarcation)
    , m_prix(prix)
{}

unsigned int LigneContrat::getId() const
{
    return m_id;
}

Client LigneContrat::getClient() const
{
    return m_client;
}

Contrat LigneContrat::getContrat() const
{
    return m_contrat;
}

QString LigneContrat::getEmbarcation() const
{
    return m_embarcation;
}

float LigneContrat::getPrix() const
{
    return m_prix;
}
