#include "chargeurD.h"
#include <iostream>

using namespace std ;

 chargeurD::chargeurD() : chargeur()  {

 }


chargeurD::chargeurD(chargeur c , float prix) : chargeur(c) , prix(prix)
{
    
}


ostream & operator << (ostream &out, const chargeurD&  c)  {
    
    if ( &out == &cout ) {
        out << "\nId : " << c.id << endl ;
        out << "Puissance : " << c.puissance << endl ;
        out << "Debit : " << c.debit << endl;
        out << "Prix : "  << c.prix ;
        
    }
    else {
        out << c.id << " " << c.puissance << " " << c.debit << " " << c.prix ;
    }

    return out;
}

istream& operator>>(istream& in, chargeurD& c) {
    if ( &in == &cin ) {
        cout << "\nId : " ;
        in >> c.id  ;
        cout << "Puissance : " ;
        in >> c.puissance  ;
        cout << "Debit : " ;
        in >> c.debit ;
        cout << "Prix : "  ;
        in >> c.prix ;
        
    }
    else {
        in >> c.id >> c.puissance >> c.debit >> c.prix  ;
    }

    return in;    
}



chargeurD::~chargeurD() {
    
}