#pragma once
#include <string>
#include "temps.h"
#include "chargeurL.h"
#include "date.h"


using namespace std ;


class station ;

class session
{
protected:
    int id ;
    Date date ;
    temps debut ;
    temps fin ;
    string etat ; 
    chargeurL* port ;

public:
    session();
    session(int id  , Date d , temps deb , temps fin , string etat,chargeurL* p);
    virtual ~session() ;

    chargeurL* getPort() { return port ; }
    Date getDate() {return date ;}
    temps getTemps() { return debut ;}
    int getID() { return id ;}
    void setEtat(string s) {etat = s ;}
    void setPort(chargeurL* p) { port = p ;}

    friend ostream & operator << (ostream &out, const session& s ) ;
    friend istream& operator>>(istream& in, session& s) ;
};



