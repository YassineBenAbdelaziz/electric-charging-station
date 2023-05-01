#include "session.h"

session::session()
{
}

session::session(int id, Date d, temps deb, temps fin, string etat,
                 chargeurL *p) : id(id), date(d), debut(deb), fin(fin), etat(etat),
                                 port(p)
{
}

ostream &operator<<(ostream &out, const session &s)
{

    if (&out == &cout)
    {
        out << "\nId : " << s.id << endl;
        out << s.date;
        out << "Temps debut: " << s.debut << endl;
        out << "Temps fin : " << s.fin << endl;
        out << "Etat : " << s.etat << endl;
        out << "Port : " << s.port->getNum();
    }
    else
    {
        out << s.id << " " << s.date << " " << s.debut << " " << s.fin << " " << s.etat << " " << s.port->getID();
    }

    return out;
}

istream &operator>>(istream &in, session &s)
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
        // read port number and assign chargeur from outside
    }

    return in;
}

session::~session()
{
}
