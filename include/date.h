#pragma once
#include <iostream>

using namespace std ;


class Date
{
private:
    int jour ;
    int mois ;
    int annee ;
public:
    Date() ;
    Date(int j , int m , int a ) ;
    ~Date() ;


    bool operator==(const Date& d) ;
    friend ostream & operator << (ostream &out, const Date& d) ;
    friend istream& operator>>(istream& in, Date& d) ;
};