#pragma once
#include "factureC.h"
#include "chargeurD.h"


using namespace std ;

class factureA : public factureC
{
private:
    int quantite ;
    chargeurD* ch ;
public:
    factureA () ;
    factureA (int num , Date d , bool im  , client* cl,int quantite, chargeurD* ch)  ;
    ~factureA () ;


    float calculPrix() ;
    void setChargeur(chargeurD* c) { ch = c ;}

    void appliquerRemise();

    friend ostream & operator << (ostream &out, const factureA& f ) ;
    friend istream& operator>>(istream& in, factureA& f) ;
};