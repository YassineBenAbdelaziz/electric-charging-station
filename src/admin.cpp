#include "station.h"
#include <iostream>


using namespace std ;



admin::admin() {

}

admin::admin(int id , string nom , string prenom) : id(id) , nom(nom) , prenom(prenom)
{

}


void admin::ajouterSession(station* st) 
{
    session* ses  = new  session();
    cin >> *ses ;
    int n ;
    cout << "Enter id chargeur : " ;
    cin >> n ;
   ses->setPort( st->findPortByNum(n));
    st->ajouter(ses) ;
}



void admin::deleteSession(station* st) 
{
    int n ;
    cout << "\nEnter Id : " ;
    cin >> n ;
    st->deleteSession(n) ;


}


void admin::ajouterChargeurD(station* st) {

    chargeurD * d  = new  chargeurD();
    cin >> *d ;
    st->ajouter(d) ;
}


void admin::deleteChargeurD(station* st) {

    int n ;
    cout << "\nEnter Id : " ;
    cin >> n ;
    st->deleteChargeurD(n) ;


}


void admin::ajouterChargeurL(station* st) {

    chargeurL * l  = new  chargeurL();
    cin >> *l ;
    st->ajouter(l) ;
}


void admin::deleteChargeurL(station* st) {

    int n ;
    cout << "\nEnter Id : " ;
    cin >> n ;
    st->deleteChargeurL(n) ;


}


ostream & operator << (ostream &out, const admin& a )  {

    if ( &out == &cout ) {
        out << "\nId : " << a.id << endl ;
        out << "Nom : " << a.nom << endl ;
        out << "Prenom : " << a.prenom << endl ;
        
    }
    else {
        out << a.id << " " << a.nom << " "  << a.prenom  ;
    }

    return out;

}


istream& operator>>(istream& in, admin& a) 
{
    if ( &in == &cin ) {
        cout << "\nId : " ;
        in >> a.id ;
        cout << "Nom : " ;
        in >> a.nom ;
        cout << "Prenom : "  ; 
        in >> a.prenom ;
        
    }
    else {
        in >> a.id >> a.nom >> a.prenom ;
    }

    return in;
}







admin::~admin() {

}