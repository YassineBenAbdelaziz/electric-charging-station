#include "voiture.h"
#include <iostream>

using namespace std;

voiture::voiture()
{
}

voiture::voiture(string imat, string mod, string marque, float p, int c, int d,
                 client *cl) : immat(imat), modele(mod), marque(marque), pourcentageBat(p), capaciteBat(c),
                               dureeVie(d), cl(cl)

{
}

void voiture::updateBatterie(float kw)
{
    if (capaciteBat * pourcentageBat + kw >= capaciteBat)
        pourcentageBat = 1;
    else
        pourcentageBat = (capaciteBat * pourcentageBat + kw) / capaciteBat;
}

voiture::~voiture()
{
}

void voiture::saisir()
{

    cout << "\nEnter immatricule : ";
    cin >> immat;
    cout << "Enter marque : ";
    cin >> marque;
    cout << "Enter modele : ";
    cin >> modele;
    cout << "Enter pourcentage batterie : ";
    cin >> pourcentageBat;
    cout << "Enter capacite batterie : ";
    cin >> capaciteBat;
    cout << "Enter duree de vie: ";
    cin >> dureeVie;
}

ostream &operator<<(ostream &out, const voiture &v)
{
    if (&out == &cout)
    {
        out << "\nImmat : " << v.immat << endl;
        out << "Marque : " << v.marque << endl;
        out << "Modele " << v.modele << endl;
        out << "Capacite Batterie : " << v.capaciteBat << endl;
        out << "Pourcentage Batterie : " << v.pourcentageBat << endl;
        out << "Duree de vie : " << v.dureeVie << endl;
        out << "Client : " << v.cl->getId();
    }
    else
    {
        out << v.immat << " " << v.marque << " " << v.modele << " " << v.capaciteBat << " " << v.pourcentageBat << " " << v.dureeVie << " " << v.cl->getId();
    }

    return out;
}

istream &operator>>(istream &in, voiture &v)
{
    if (&in == &cin)
    {
        cout << "\nImmat : ";
        in >> v.immat;
        cout << "Marque : ";
        in >> v.marque;
        cout << "Modele ";
        in >> v.modele;
        cout << "Capacite Batterie : ";
        in >> v.capaciteBat;
        cout << "Pourcentage Batterie : ";
        in >> v.pourcentageBat;
        cout << "Duree de vie : ";
        in >> v.dureeVie;
    }
    else
    {
        in >> v.immat >> v.marque >> v.modele >> v.capaciteBat >> v.pourcentageBat >> v.dureeVie;
        // read client from outside and assign
    }

    return in;
}

void voiture::setClient(client *cl)
{
    this->cl = cl;
}