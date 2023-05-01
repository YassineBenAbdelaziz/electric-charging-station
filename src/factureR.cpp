#include "factureR.h"
#include "sessionReserve.h"
#include <typeinfo>
#include "chargeurP.h"
#include <iostream>

using namespace std;

factureR::factureR()
{
}

factureR::factureR(int num, Date d, bool im, client *cl,
                   sessionReserve *s) : factureC(num, d, im, cl),
                                        sess(s)
{
    quantite = 0;
    montant = 0;
}

factureR::factureR(const factureR &f) : factureC(f)
{
    quantite = f.quantite;
    montant = f.montant;
    sess = new sessionReserve(*f.sess);
}

factureR &factureR::operator=(const factureR &f)
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
        sess = new sessionReserve(*f.sess);
    }
    return *this;
}

void factureR::appliquerRemise()
{
    if (quantite > 2000)
        montant = montant - 0.1 * montant;
}

void factureR::calculQuantite(int duree)
{
    quantite = duree * sess->getPort()->getDebit();
}

float factureR::calculPrix()
{

    if (typeid(*(sess->getPort())) == typeid(chargeurP))
    {
        chargeurP *p = static_cast<chargeurP *>(sess->getPort());
        return sess->getPort()->getPrixKW() * quantite + p->getTax();
    }
    else
        return sess->getPort()->getPrixKW() * quantite;
}

void factureR::calculMontant()
{
    float prix = calculPrix();
    montant = prix;
    for (auto it : taxes)
    {
        montant = montant + prix * it.second;
    }
}

void factureR::afficherFacture()
{
    cout << "\nNumero : " << numFacture << endl;
    cout << date;
    cout << "Montant : " << montant << endl;
    cout << "Quantite : " << quantite << endl;
    cout << "Impaye : " << impaye << endl;
    cout << "Client id : " << cl->getId();
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
    cout << "Voiture  : " << sess->getVoiture()->getImmat();
}

ostream &operator<<(ostream &out, const factureR &f)
{
    if (&out == &cout)
    {
        out << "\nNumero : " << f.numFacture << endl;
        out << f.date;
        out << "Montant : " << f.montant << endl;
        out << "Quantite : " << f.quantite << endl;
        out << "Impaye : " << f.impaye << endl;
        out << "Client id : " << f.cl->getId() << endl;
        out << "Voiture  : " << f.sess->getVoiture()->getImmat() << endl;
        if (f.taxes.size() > 0)
        {
            for (auto it : f.taxes)
            {
                out << endl
                    << it.first << " : " << it.second << endl;
            }
        }
        else
            out << endl
                << "Aucun Taxe\n";
    }
    else
    {
        out << f.numFacture << " " << f.date << " " << f.montant << " " << f.quantite << " "
            << f.impaye << " " << f.taxes.size() << " ";
        for (auto it : f.taxes)
            out << it.first << " " << it.second << " ";
        out << (f.cl)->getId() << " " << f.sess->getID();
    }

    return out;
}

istream &operator>>(istream &in, factureR &f)
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

    // read client and session id from outside and assign ;

    return in;
}

factureR::~factureR()
{
}