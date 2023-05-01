#pragma once
#include "chargeur.h"

using namespace std;

class chargeurD : public chargeur
{
private:
    float prix;

public:
    chargeurD();
    chargeurD(chargeur c, float prix);
    ~chargeurD();

    float getPrix() { return prix; }

    friend ostream &operator<<(ostream &out, const chargeurD &c);
    friend istream &operator>>(istream &in, chargeurD &c);
};