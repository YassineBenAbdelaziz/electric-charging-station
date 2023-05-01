#pragma once
#include "factureC.h"
#include "chargeurD.h"

using namespace std;

class factureA : public factureC
{
private:
    int quantite;
    chargeurD *ch;

public:
    static int id;
    factureA();
    factureA(int num, Date d, bool im, client *cl, int quantite, chargeurD *ch);
    factureA(const factureA &f);
    ~factureA();

    float calculPrix();
    void setChargeur(chargeurD *c) { ch = c; }

    void afficherFacture();
    void appliquerRemise();
    void calculMontant();

    factureA &operator=(const factureA &f);
    friend ostream &operator<<(ostream &out, const factureA &f);
    friend istream &operator>>(istream &in, factureA &f);
};