#pragma once
#include <string>
#include "admin.h"
#include "date.h"
#include "temps.h"
#include "session.h"
#include "client.h"
#include "factureC.h"
#include "voiture.h"
#include "chargeurD.h"
#include "chargeurL.h"
#include <vector>

using namespace std;

class station
{
private:
    int id;
    string designation;
    string adresse;
    vector<session *> sessions;
    vector<client *> clients;
    vector<factureC *> factures;
    vector<voiture *> voitures;
    vector<chargeurD *> chargeursD;
    vector<chargeurL *> chargeursL;
    vector<admin *> admins;

public:
    station();
    station(int id, string des, string adr);
    ~station();

    void saisir();
    void afficherSessionDispo(); // print sessions dispo
    bool sessionDispo(Date d, temps t);
    bool sessionDispo(int n); // check session dispo at a certain date and time
    void reserverSession(client *cl);
    void annulerReservation(client *cl);

    client *findClientById(int n);
    admin *findAdminById(int n);
    chargeurL *findPortByNum(int n);
    chargeurD *findChargeurById(int n);
    factureR *findFactureByNum(int n);
    voiture *findVoitureByImat(string str);
    sessionReserve *findSessionReserveById(int n);
    session *findSessionById(int n);

    void ajouter(admin *a);
    void ajouter(session *s);
    void ajouter(voiture *v);
    void ajouter(client *c);
    void ajouter(factureC *f);
    void ajouter(chargeurD *d);
    void ajouter(chargeurL *l);

    void deleteSession(int id);
    void deleteVoiture(voiture *v);
    void deleteClient(client *c);
    void deleteFacture(factureC *f);
    void deleteChargeurD(int n);
    void deleteChargeurL(int n);

    void LoadAdmins();
    void StoreAdmins();
    void printAdmins();

    void LoadClients();
    void StoreClients();
    void printClients();

    void LoadVoitures();
    void StoreVoitures();
    void printVoitures();

    void LoadChargeursD();
    void StoreChargeursD();
    void printChargeursD();

    void LoadChargeursL();
    void StoreChargeursL();
    void printChargeursL();

    void LoadSessions();
    void StoreSessions();
    void printSessions();

    void LoadFactures();
    void StoreFactures();
    void printFactures();

    void Load();
    void Store();

    friend ostream &operator<<(ostream &out, const station &st);
    friend istream &operator>>(istream &in, station &st);
};