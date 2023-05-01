#include "date.h"
#include <iostream>
using namespace std;

Date::Date()
{
}

Date::Date(int j, int m, int a) : jour(j), mois(m), annee(a)
{
}

bool Date::operator==(const Date &d)
{

    if (annee != d.annee)
    {
        return false;
    }
    else
    {
        if (mois != d.mois)
            return false;
        else
        {
            if (jour != d.jour)
                return false;
            else
                return true;
        }
    }
}

ostream &operator<<(ostream &out, const Date &d)
{
    if (&out == &cout)
    {
        out << "Date : " << d.jour << "/" << d.mois << "/" << d.annee << endl;
    }
    else
    {
        out << d.jour << " " << d.mois << " " << d.annee;
    }

    return out;
}

istream &operator>>(istream &in, Date &d)
{
    if (&in == &cin)
    {
        cout << "Date : ";
        in >> d.jour >> d.mois >> d.annee;
    }
    else
    {
        in >> d.jour >> d.mois >> d.annee;
    }

    return in;
}

Date::~Date()
{
}