#pragma once
#include "factureC.h"


using namespace std ;

class sessionReserve ;

class factureR : public factureC
{
private:
    float quantite ;
    sessionReserve* sess;
public:
    factureR();
    factureR (int num , Date d , bool im , client* cl, sessionReserve* s) ;
    ~factureR () ;


    float calculPrix() ;
    void setSession(sessionReserve* s) {sess = s ;}
    sessionReserve* getSession() {return sess ;} 

    void afficherFacture() ;
    void appliquerRemise() ;
    
    friend ostream & operator << (ostream &out, const factureR& f ) ;
    friend istream& operator>>(istream& in, factureR& f) ;
};