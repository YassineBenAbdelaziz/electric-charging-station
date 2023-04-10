#include "factureC.h"
#include "client.h"
#include <iostream>

using namespace std ;


factureC::factureC() {

}
factureC::factureC(const factureC& f){
    numFacture = f.numFacture ;
    date = f.date ;
    impaye = f.impaye ;
    montant = f.montant ;
    cl = new client(*f.cl) ; 

}
factureC::factureC(int num , Date d , bool im  , client* cl)  : numFacture(num),
    date(d), impaye(im), cl(cl) 

{
    montant = 0 ;
}

void factureC::afficherFacture() {
        cout << "\nNumero : " << numFacture << endl ;
        cout <<  date  ;
        cout << "Montant : " << montant << endl;
        cout << "Impaye : " << impaye << endl ;
        cout << "Client id : " << cl->getId() ;
}

void factureC::appliquerRemise() {
    montant = montant - 0.1 * montant ;
}

void factureC::operator=(const factureC& f) {
    numFacture = f.numFacture ;
    date = f.date ;
    impaye = f.impaye ;
    montant = f.montant ;
    cl = new client(*f.cl) ; 
}


factureC::~factureC(){
    
}