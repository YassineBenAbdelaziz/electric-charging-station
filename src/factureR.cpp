#include "factureR.h"
#include "sessionReserve.h"
#include <typeinfo>
#include "chargeurP.h"
#include <iostream>

using namespace std ;

factureR::factureR() {

}

factureR::factureR(int num , Date d , bool im , client* cl,
    sessionReserve* s) : factureC(num, d, im  , cl), 
     sess(s)
{
    // assign the quantity of all factures
    montant = calculPrix() ;
}


void factureR::appliquerRemise() {
    if (quantite > 2000) montant = montant - 0.1 * montant ;
}




float factureR::calculPrix() {
    
    if ( typeid( *(sess->getPort()) ) == typeid(chargeurP) )
    {
        chargeurP* p = static_cast<chargeurP*> (sess->getPort()) ;
        return sess->getPort()->getPrixKW() * quantite  + p->getTax() ;
    }
    else return sess->getPort()->getPrixKW() * quantite  ;
    

}


void factureR::afficherFacture() {
        cout << "\nNumero : " << numFacture << endl ;
        cout <<  date  ;
        cout << "Montant : " << montant << endl;
        cout << "Quantite : "  << quantite << endl ;
        cout << "Impaye : " << impaye << endl ;
        cout << "Client id : " << cl->getId() << endl ;
        cout << "Voiture  : " << sess->getVoiture()->getImmat()  ;
}

ostream & operator << (ostream &out, const factureR& f ) {
    if ( &out == &cout ) {
        out << "\nNumero : " << f.numFacture << endl ;
        out <<  f.date  ;
        out << "Montant : " << f.montant << endl;
        out << "Quantite : "  << f.quantite << endl ;
        out << "Impaye : " << f.impaye ;
        
    }
    else {
        out << f.numFacture << " " << f.date << " " << f.montant << " " << f.quantite << " " 
        << f.impaye << " " << (f.cl)->getId() << " " << f.sess->getID()  ;
    }

    return out;
}



istream& operator>>(istream& in, factureR& f) {
    
    in >> f.numFacture >> f.date >> f.montant >> f.quantite >> f.impaye ;
    // read client and session id from outside and assign ;

    return in;  
}

factureR::~factureR() {
    
}