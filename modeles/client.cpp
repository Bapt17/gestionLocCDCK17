#include "client.h"

Client::Client(unsigned int id,
               const QString &nom,
               const QString &prenom,
               const QDate &dateNaissance,
               const QString &genre,
               const QString &codePostal)
    : m_id(id)
    , m_nom(nom)
    , m_prenom(prenom)
    , m_dateNaissance(dateNaissance)
    , m_genre(genre)
    , m_codePostal(codePostal)
{}

unsigned int Client::getId() const
{
    return m_id;
}

QString Client::getNom() const
{
    return m_nom;
}

QString Client::getPrenom() const
{
    return m_prenom;
}

QDate Client::getDateNaissance() const
{
    return m_dateNaissance;
}

QString Client::getGenre() const
{
    return m_genre;
}

QString Client::getCodePostal() const
{
    return m_codePostal;
}
