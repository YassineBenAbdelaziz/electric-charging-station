#pragma once
#include "session.h"
#include "factureR.h"
#include "voiture.h"

using namespace std;

class sessionReserve : public session
{
private:
    factureR *facture;
    voiture *vehicule;

public:
    sessionReserve();
    sessionReserve(session s, factureR *fac, voiture *v);
    sessionReserve(const session &s);
    ~sessionReserve();

    void setFacture(factureR *r) { facture = r; }
    void setVoiture(voiture *v) { vehicule = v; }
    voiture *getVoiture() { return vehicule; }

    friend ostream &operator<<(ostream &out, const sessionReserve &s);
    friend istream &operator>>(istream &in, sessionReserve &s);
    sessionReserve operator=(const session &b);
};
