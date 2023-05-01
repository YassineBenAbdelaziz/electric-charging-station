#include "factureC.h"
#include "client.h"
#include <iostream>
#include <iterator>

using namespace std;

factureC::factureC()
{
}
factureC::factureC(const factureC &f)
{
    numFacture = f.numFacture;
    date = f.date;
    impaye = f.impaye;
    montant = f.montant;
    cl = new client(*f.cl);
    taxes = f.taxes;
}
factureC::factureC(int num, Date d, bool im, client *cl) : numFacture(num),
                                                           date(d), impaye(im), cl(cl)

{
    montant = 0;
}

void factureC::afficherFacture()
{
    cout << "\nNumero : " << numFacture << endl;
    cout << date;
    cout << "Montant : " << montant << endl;
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
}

void factureC::ajouterTax(string str, float f)
{
    taxes[str] = f;
}

void factureC::appliquerRemise()
{
    montant = montant - 0.1 * montant;
}

factureC &factureC::operator=(const factureC &f)
{
    if (this != &f)
    {
        numFacture = f.numFacture;
        date = f.date;
        impaye = f.impaye;
        montant = f.montant;
        cl = new client(*f.cl);
        taxes = f.taxes;
    }
    return *this;
}

factureC::~factureC()
{
}