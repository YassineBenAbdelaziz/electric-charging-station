#pragma once
#include <string>
#include "date.h"
#include <map>
using namespace std;

class client;

class factureC
{
protected:
    int numFacture;
    Date date;
    bool impaye;
    float montant;
    client *cl;
    map<string, float> taxes;

public:
    factureC();
    factureC(const factureC &f);
    factureC(int num, Date d, bool im, client *cl);
    virtual ~factureC();

    int getNum() { return numFacture; }
    float getMontant() { return montant; }
    client *getClient() { return cl; }

    void setClient(client *cl) { this->cl = cl; }
    void ajouterTax(string str, float f);
    bool est_impaye() { return impaye; }
    void payer() { impaye = false; }

    factureC &operator=(const factureC &f);

    virtual void afficherFacture();
    virtual void appliquerRemise();
    virtual float calculPrix() = 0;
};
