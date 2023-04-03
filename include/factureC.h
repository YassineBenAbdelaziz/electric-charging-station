#pragma once
#include <string>
#include "date.h"
using namespace std ;


class client ;

class factureC
{
protected:
    int numFacture ;
    Date date ;
    bool impaye ;
    float montant ;
    client* cl ;

public:
    factureC() ;
    factureC(int num , Date d , bool im  , client* cl) ;
    ~factureC() ;

    bool est_impaye() {return impaye ;}
    int getNum() { return numFacture ;}
    void payer() {impaye = false ;}
    float getMontant() {return montant ;}
    void setClient(client* cl) { this->cl = cl ;}
    client* getClient() { return cl ;}
    virtual float calculPrix()=0 ;



};




