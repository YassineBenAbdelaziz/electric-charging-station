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

    
    int getNum() { return numFacture ;}
    float getMontant() {return montant ;}
    client* getClient() { return cl ;}

    void setClient(client* cl) { this->cl = cl ;}

    bool est_impaye() {return impaye ;}
    void payer() {impaye = false ;}
    

    virtual void afficherFacture() ;
    virtual void appliquerRemise() ;
    virtual float calculPrix()=0 ;



};




