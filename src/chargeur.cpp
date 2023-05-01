#include "chargeur.h"
#include <iostream>

using namespace std;
chargeur::chargeur()
{
}

chargeur::chargeur(int id, int puissance, float debit) : id(id), puissance(puissance),
                                                         debit(debit)
{
}

ostream &operator<<(ostream &out, const chargeur &c)
{
    if (&out == &cout)
    {
        out << "\nId : " << c.id << endl;
        out << "Puissance : " << c.puissance << endl;
        out << "Debit : " << c.debit;
    }
    else
    {
        out << c.id << c.puissance << c.debit << endl;
    }

    return out;
}

istream &operator>>(istream &in, chargeur &c)
{
    if (&in == &cin)
    {
        cout << "\nId : ";
        in >> c.id;
        cout << "Puissance : ";
        in >> c.puissance;
        cout << "Debit : ";
        in >> c.debit;
    }
    else
    {
        in >> c.id >> c.puissance >> c.debit;
    }

    return in;
}

chargeur::~chargeur()
{
}