#include  "factureA.h"
#include "client.h"
#include <iostream>

using namespace std ;

factureA::factureA () {

}

factureA::factureA (int num , Date d , bool im  , client* cl, int q,
    chargeurD* ch ) : factureC(num, d, im , cl), quantite(q) , ch(ch)
{
    
    montant = calculPrix() ;
}

float factureA::calculPrix() {

    return quantite * ch->getPrix() ; 

}

void factureA::appliquerRemise() {
    if (montant > 2000) montant = montant - 0.1 * montant ;
}

void factureA::afficherFacture() {
        cout << "\nNumero : " << numFacture << endl ;
        cout <<  date  ;
        cout << "Montant : " << montant << endl;
        cout << "Quantite : "  << quantite << endl ;
        cout << "Impaye : " << impaye << endl ;
        cout << "Client id : " << cl->getId() << endl ;
}

ostream & operator << (ostream &out, const factureA& f ) {
    if ( &out == &cout ) {
        out << "\nNumero : " << f.numFacture << endl ;
        out <<  f.date  ;
        out << "Montant : " << f.montant << endl;
        out << "Quantite : "  << f.quantite << endl ;
        out << "Impaye : " << f.impaye ;
    }
    else {
        out << f.numFacture << " " << f.date << " " << f.montant << " " << f.quantite << " " 
        << f.impaye << " " << (f.cl)->getId() << " " << f.ch->getID() ;
    }

    return out;
}


istream& operator>>(istream& in, factureA& f)  {


    in >> f.numFacture >> f.date >> f.montant >> f.quantite >> f.impaye ;
    // read client and chargeur id from outside and assign ;

    return in;    
}

factureA::~factureA() {
    
}