#pragma once
#include <string>
#include "voiture.h"
#include "factureR.h"
#include "factureA.h"
#include "sessionReserve.h"
#include "date.h"
#include "temps.h"
#include <vector>
#include <list>

using namespace std ;



class client
{
private:
    static int nb_clients ;
    int id ;
    string nom ;
    string prenom ;
    string adresse ;
    int telephone ;
    float solde ;
    list <voiture*> voitures ;
    vector <factureR*> facturesR ;
    vector <factureA*> facturesA ;
    vector <sessionReserve*> sessions ;
    
public:
    
    client()  ;
    client(const client& c)  ;
    client(int id , string nom , string prenom , string adresse , int tel, float sold)  ;
    ~client()  ;

    void saisir() ;
    int getId() { return id ;}
    float getSolde() { return solde ;}
    void chargerSolde(float m) ;
    void afficherSessionDispo() ;
    void afficherSessionReserve() ;
    void afficherVoitures() ;
    bool avoirVoiture(string str) ;
    sessionReserve* findSession(int n) ;
    void reserverSession(sessionReserve* s);
    void annulerReservation(sessionReserve* s);
    void startCharging() ;
    factureR* stopCharging() ;
    void afficherFactureImpaye();
    void payerFacture() ;
    voiture* ajouterVoiture() ;
    void ajouterVoiture(voiture*  v) ;
    void ajouterFacture(factureC*  f) ;
    void ajouterSession(sessionReserve*  s) ;
    
    
    static int nombreClient() {return nb_clients;}

    client& operator=(const client &c) ;
    friend ostream & operator << (ostream &out, const client& c ) ;
    friend istream& operator>>(istream& in, client& c) ;
};