#pragma once
#include "factureC.h"

using namespace std;

class sessionReserve;

class factureR : public factureC
{
private:
    float quantite;
    sessionReserve *sess;

public:
    factureR();
    factureR(int num, Date d, bool im, client *cl, sessionReserve *s);
    factureR(const factureR &f);
    ~factureR();

    float calculPrix();
    void calculQuantite(int duree);
    void calculMontant();
    void setSession(sessionReserve *s) { sess = s; }
    sessionReserve *getSession() { return sess; }
    float getQuantite() { return quantite; }

    void afficherFacture();
    void appliquerRemise();

    factureR &operator=(const factureR &f);

    friend ostream &operator<<(ostream &out, const factureR &f);
    friend istream &operator>>(istream &in, factureR &f);
};