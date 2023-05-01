#pragma once
#include "chargeurL.h"

using namespace std;

class chargeurP : public chargeurL
{
private:
    float Tax;

public:
    chargeurP();
    chargeurP(chargeurL c, float tax);
    ~chargeurP();

    float getTax() { return Tax; }

    friend ostream &operator<<(ostream &out, const chargeurP &c);
    friend istream &operator>>(istream &in, chargeurP &c);
};