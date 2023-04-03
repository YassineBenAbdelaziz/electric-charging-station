#pragma once
#include <string>



using namespace std ;



class chargeur
{
protected:
    int id ;
    int puissance ;
    float debit ;
public:
    chargeur()  ;
    chargeur(int id , int puissance , float debit) ;
    ~chargeur()  ;


    float getDebit() {return debit ; }
    int getID() {return id ;}
    
    friend ostream & operator << (ostream &out, const chargeur& c ) ;
    friend istream& operator>>(istream& in, chargeur& c) ;

};