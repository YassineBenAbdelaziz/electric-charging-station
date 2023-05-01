#pragma once
#include <iostream>

using namespace std;

class temps
{
private:
    int heures;
    int minutes;

public:
    temps();
    temps(int h, int m);
    ~temps();

    bool operator==(const temps &t);
    friend ostream &operator<<(ostream &out, const temps &t);
    friend istream &operator>>(istream &in, temps &t);
};