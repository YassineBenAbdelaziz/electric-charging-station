#pragma once
#include <string>
#include "session.h"

using namespace std;

class station;

class admin
{
private:
    int id;
    string nom;
    string prenom;

public:
    admin();
    admin(int id, string nom, string prenom);
    ~admin();

    void ajouterSession(station *st);
    void deleteSession(station *st);

    void ajouterChargeurD(station *st);
    void deleteChargeurD(station *st);

    void ajouterChargeurL(station *st);
    void deleteChargeurL(station *st);

    int getId() { return id; }

    friend ostream &operator<<(ostream &out, const admin &a);
    friend istream &operator>>(istream &cin, admin &a);
};