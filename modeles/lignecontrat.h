#ifndef LIGNECONTRAT_H
#define LIGNECONTRAT_H

#include <QString>

#include "client.h"
#include "contrat.h"

class LigneContrat
{
public:
    LigneContrat(unsigned int id,
                 const Client &client,
                 const Contrat &contrat,
                 const QString &embarcation,
                 float prix);

    unsigned int getId() const;
    Client getClient() const;
    Contrat getContrat() const;
    QString getEmbarcation() const;
    float getPrix() const;

private:
    unsigned int m_id;
    Client m_client;
    Contrat m_contrat;
    QString m_embarcation;
    float m_prix;
};

#endif // LIGNECONTRAT_H
