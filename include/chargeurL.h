#pragma once
#include "chargeur.h"

using namespace std;

class chargeurL : public chargeur
{
protected:
    int numero_port;
    bool status;
    float prixKW;

public:
    chargeurL();
    chargeurL(chargeur c, int num, bool stat, float prix);
    ~chargeurL();

    float getPrixKW() { return prixKW; }
    void activerChargeur() { status = true; }
    void desactiverChargeur() { status = false; }
    int getNum() { return numero_port; }
    friend ostream &operator<<(ostream &out, const chargeurL &c);
    friend istream &operator>>(istream &in, chargeurL &c);
};