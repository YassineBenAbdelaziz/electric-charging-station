#include "temps.h"
using namespace std;

temps::temps()
{
}

temps ::temps(int h, int m) : heures(h), minutes(m)
{
}

bool temps::operator==(const temps &t)
{
    if (heures != t.heures)
        return false;
    else
    {
        if (minutes != t.minutes)
            return false;
        else
            return true;
    }
}

ostream &operator<<(ostream &out, const temps &t)
{
    if (&out == &cout)
    {
        out << t.heures << ":" << t.minutes;
    }
    else
    {
        out << t.heures << " " << t.minutes;
    }

    return out;
}

istream &operator>>(istream &in, temps &t)
{
    if (&in == &cin)
    {
        in >> t.heures >> t.minutes;
    }
    else
    {
        in >> t.heures >> t.minutes;
    }

    return in;
}

temps::~temps()
{
}