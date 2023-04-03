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



using namespace std ;

class station
{
private:
    int id ;
    string designation ;
    string adresse ;
    vector<session*> sessions ;
    vector<client*> clients ;
    vector<factureC*> factures ;
    vector<voiture*> voitures ;
    vector<chargeurD*> chargeursD ;
    vector<chargeurL*> chargeursL ;

public:
    station() ;
    station(int id , string des , string adr  ) ;
    ~station() ;

    void saisir() ;
    void afficherSessionDispo() ; // print sessions dispo
    bool sessionDispo(Date d , temps t) ;
    bool sessionDispo(int n) ; // check session dispo at a certain date and time
    void reserverSession(client* cl) ;
    void annulerReservation(client* cl) ;
    client* findClientById(int n) ;
    chargeurL* findPortByNum(int n);
    chargeurD* findChargeurById(int n);
    factureR* findFactureByNum(int n);
    voiture* findVoitureByImat(string str) ;
    sessionReserve* findSessionReserveById(int n) ;
    session* findSessionById(int n);

    void ajouterSession(session* s) ;
    void deleteSession(int id) ;

    void ajouterVoiture(voiture* v) ;
    void deleteVoiture(voiture* v) ;

    void ajouterClient(client* c) ;
    void deleteClient(client* c) ;

    void ajouterFacture(factureC* f) ;
    void deleteFacture(factureC* f )  ;

    void ajouterChargeurD(chargeurD* d)  ;
    void deleteChargeurD(int n) ;

    void ajouterChargeurL(chargeurL* l)  ;
    void deleteChargeurL(int n );

    void LoadClients() ;
    void StoreClients() ;
    void printClients() ;

    void LoadVoitures() ;
    void StoreVoitures() ;
    void printVoitures() ;

    void LoadChargeursD() ;
    void StoreChargeursD() ;
    void printChargeursD() ;

    void LoadChargeursL() ;
    void StoreChargeursL() ;
    void printChargeursL() ;

    void LoadSessions() ;
    void StoreSessions() ;
    void printSessions() ;

    void LoadFactures() ; 
    void StoreFactures()  ;
    void printFactures() ;

    void Load() ;
    void Store() ;

    friend ostream & operator << (ostream &out, const station& st ) ;
    friend istream& operator>>(istream& in, station& st) ;
};