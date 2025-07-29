#ifndef CLIENT_H
#define CLIENT_H

#include <QDate>
#include <QString>

class Client
{
public:
    Client(unsigned int id,
           const QString &nom,
           const QString &prenom,
           const QDate &dateNaissance,
           const QString &genre,
           const QString &codePostal);

    unsigned int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QDate getDateNaissance() const;
    QString getGenre() const;
    QString getCodePostal() const;

private:
    unsigned int m_id;
    QString m_nom;
    QString m_prenom;
    QDate m_dateNaissance;
    QString m_genre;
    QString m_codePostal;
};

#endif // CLIENT_H
