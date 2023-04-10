#include "chargeurL.h"
#include <iostream>

using namespace std ;

chargeurL::chargeurL() : chargeur() {
    
}


chargeurL::chargeurL(chargeur c , int num , bool stat, float prix) : chargeur(c) ,
    numero_port(num), status(stat) , prixKW(prix)
{
    
}




ostream & operator << (ostream &out, const chargeurL&  c)
{
    if ( &out == &cout ) {
        out << "\nId : " << c.id << endl ; 
        out << "Numero : " << c.numero_port << endl ;
        out << "Puissance : " << c.puissance << endl ;
        out << "Debit : " << c.debit << endl;
        out << "Prix : "  << c.prixKW << endl ;
        out << "Status : " << c.status ;
        
    }
    else {
        out << c.id << " " << c.numero_port << " " << c.puissance << " " << c.debit 
        << " " << c.prixKW << " " << c.status  ;
    }

    return out;
}


istream& operator>>(istream& in, chargeurL& c) {
    if ( &in == &cin ) {
        cout << "\nId : " ;
        in >> c.id  ;
        cout << "Puissance : " ;
        in >> c.puissance  ;
        cout << "Debit : " ;
        in >> c.debit ;
        cout << "Prix : "  ;
        in >> c.prixKW  ;
        cout << "Status : " ;
        in >> c.status ;
        
    }
    else {
        in >>c.id >> c.numero_port >> c.puissance >>c.debit >>c.prixKW >>c.status  ;
    }

    return in;    
}






chargeurL::~chargeurL() {
    
}