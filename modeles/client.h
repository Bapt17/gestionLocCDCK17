#ifndef CLIENT_H
#define CLIENT_H

#include <QDate>
#include <QString>

class Client
{
private:
    int m_id;
    QString m_nom;
    QString m_prenom;
    QDate m_dateNaissance;
    QString m_genre;
    QString m_codePostal;

public:
    Client(int id,
           const QString &nom,
           const Qstring &prenom,
           const QDate &dateNaissance,
           const Qstring &genre,
           const QString &codePostal);

    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QDate getDateNaissance() const;
    QString getGenre() const;
    QString getCodePostal() const;
};

#endif // CLIENT_H
