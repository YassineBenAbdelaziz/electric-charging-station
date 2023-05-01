#include "sessionReserve.h"

sessionReserve::sessionReserve() : session()
{
}

sessionReserve::sessionReserve(const session &s) : session(s)
{
    facture = nullptr;
    vehicule = nullptr;
}

sessionReserve::sessionReserve(session s, factureR *fac, voiture *v) : session(s), facture(fac), vehicule(v)
{
}

ostream &operator<<(ostream &out, const sessionReserve &s)
{
    if (&out == &cout)
    {
        out << "\nId : " << s.id << endl;
        out << s.date;
        out << "Temps debut: " << s.debut << endl;
        out << "Temps fin : " << s.fin << endl;
        out << "Etat : " << s.etat << endl;
        out << "Port : " << s.port->getNum() << endl;
        out << "Voiture : " << s.vehicule->getImmat();
    }
    else
    {
        out << s.id << " " << s.date << " " << s.debut << " " << s.fin << " " << s.etat << " " << s.port->getID() << " " << s.vehicule->getImmat();
    }
    return out;
}

istream &operator>>(istream &in, sessionReserve &s)
{
    if (&in == &cin)
    {
        cout << "\nId : ";
        in >> s.id;
        in >> s.date;
        cout << "Temps debut: ";
        in >> s.debut;
        cout << "Temps fin : ";
        in >> s.fin;
        cout << "Etat : ";
        in >> s.etat;
    }
    else
    {
        in >> s.id >> s.date >> s.debut >> s.fin >> s.etat;
        // read from outside port and voiture ids  and assign
    }
    return in;
}

sessionReserve::~sessionReserve()
{
}
