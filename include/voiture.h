#pragma once
#include <string>


using namespace std ;

class client ;

class voiture
{
private:
    string immat ;
    string modele ;
    string marque ;
    float pourcentageBat ;
    int capaciteBat ;
    int dureeVie ; 
    client* cl ;
public:
    voiture() ;
    voiture(string imat , string mod , string marque , float p , int c , int d , client* cl) ;
    ~voiture() ;

    void saisir();
    string getImmat() { return immat ;}
    void setClient(client* cl) ;
    client* getClient() {return cl ;}
    void updateBatterie(float kw) ;

    friend ostream & operator << (ostream &out, const voiture& v ) ;
    friend istream& operator>>(istream& in, voiture& v) ;
};

#include "client.h"