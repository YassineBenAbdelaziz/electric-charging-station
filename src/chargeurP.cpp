#include "chargeurP.h"
#include <iostream>

using namespace std;

chargeurP::chargeurP() : chargeurL() {
    
}



chargeurP::chargeurP(chargeurL c , float tax) : chargeurL(c) , Tax(tax)
{
    
}




ostream & operator << (ostream &out, const chargeurP&  c) {
    if ( &out == &cout ) {
        out << "\nId : " << c.id << endl ;
        out << "Puissance : " << c.puissance << endl ;
        out << "Debit : " << c.debit << endl;
        out << "Prix : "  << c.prixKW << endl ;
        out << "Status : " << c.status << endl ;
        out << "Tax : " << c.Tax ;
    }
    else {
        out << c.id << " "<< c.puissance << " "<< c.debit << " "<< c.prixKW << " "<< c.status 
        << " "<< c.Tax ;
    }

    return out;
}


istream& operator>>(istream& in, chargeurP& c)  {
    if ( &in == &cin ) {
        cout << "\nId : "  ;
        in >> c.id  ;
        cout << "Puissance : "  ;
        in >> c.puissance  ;
        cout << "Debit : "  ;
        in >> c.debit ;
        cout << "Prix : "   ;
        in >> c.prixKW  ;
        cout << "Status : "  ;
        in >> c.status  ;
        cout << "Tax : "  ;
        in >> c.Tax ;
    }
    else {
        in >> c.id >> c.puissance >> c.debit >> c.prixKW >> c.status >> c.Tax  ;
    }

    return in;    
}



chargeurP::~chargeurP() {
    
}