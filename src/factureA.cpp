#include "factureA.h"
#include "client.h"
#include <iostream>

using namespace std;

int factureA::id = 600;

factureA::factureA()
{
    id++;
}

factureA::factureA(int num, Date d, bool im, client *cl, int q,
                   chargeurD *ch) : factureC(num, d, im, cl), quantite(q), ch(ch)
{
    id++;
    montant = 0;
}

factureA::factureA(const factureA &f) : factureC(f)
{
    id++;
    quantite = f.quantite;
    montant = f.montant;
    ch = new chargeurD(*f.ch);
}

factureA &factureA::operator=(const factureA &f)
{
    if (this != &f)
    {
        numFacture = f.numFacture;
        date = f.date;
        impaye = f.impaye;
        montant = f.montant;
        cl = new client(*f.cl);
        taxes = f.taxes;
        quantite = f.quantite;
        montant = f.montant;
        ch = new chargeurD(*f.ch);
    }
    return *this;
}

float factureA::calculPrix()
{

    return quantite * ch->getPrix();
}

void factureA::calculMontant()
{
    float prix = calculPrix();
    montant = prix;
    for (auto it : taxes)
    {
        montant = montant + prix * it.second;
    }
}

void factureA::appliquerRemise()
{
    if (montant > 2000)
        montant = montant - 0.1 * montant;
}

void factureA::afficherFacture()
{
    cout << "\nNumero : " << numFacture << endl;
    cout << date;
    cout << "Montant : " << montant << endl;
    cout << "Quantite : " << quantite << endl;
    cout << "Impaye : " << impaye << endl;
    cout << "Client id : " << cl->getId() << endl;
    if (taxes.size() > 0)
    {
        for (auto it : taxes)
        {
            cout << endl
                 << it.first << " : " << it.second;
        }
    }
    else
        cout << endl
             << "Aucun Taxe";
}

ostream &operator<<(ostream &out, const factureA &f)
{
    if (&out == &cout)
    {
        out << "\nNumero : " << f.numFacture << endl;
        out << f.date;
        out << "Montant : " << f.montant << endl;
        out << "Quantite : " << f.quantite << endl;
        out << "Impaye : " << f.impaye;
        if (f.taxes.size() > 0)
        {
            out << "\nTaxes : \n";
            for (auto it : f.taxes)
            {
                out << it.first << " : " << it.second << endl;
            }
        }
        else
            out << endl
                << "Aucun Taxe";
    }
    else
    {
        out << f.numFacture << " " << f.date << " " << f.montant << " " << f.quantite << " "
            << f.impaye << " " << f.taxes.size() << " ";
        for (auto it : f.taxes)
            out << it.first << " " << it.second << " ";
        out << (f.cl)->getId() << " " << f.ch->getID();
    }

    return out;
}

istream &operator>>(istream &in, factureA &f)
{
    int n;
    string str;
    float prix;
    in >> f.numFacture >> f.date >> f.montant >> f.quantite >> f.impaye >> n;
    for (int i = 0; i < n; i++)
    {
        in >> str >> prix;
        f.taxes.insert({str, prix});
    }
    // read client and chargeur id from outside and assign ;

    return in;
}

factureA::~factureA()
{
    id--;
}