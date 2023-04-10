#include "client.h"
#include <iostream>
#include <algorithm>


using namespace std ;

int client::nb_clients = 0 ;

client::client() {
    solde = 0 ;
    nb_clients++;
}


client::client(int id , string nom , string prenom , string adresse , int tel,
    float sold):  id(id) , nom(nom) , prenom(prenom) , adresse(adresse) , telephone(tel),
    solde(sold)
{
    nb_clients++;
}

client::~client() {
    facturesR.clear();
    facturesA.clear();
    voitures.clear();
    sessions.clear();
    nb_clients--;
}



client::client(const client& c) {
    id = c.id ;
    nom = c.nom ;
    prenom = c.prenom ;
    adresse = c.adresse ;
    telephone = c.telephone ;
    solde = c.solde ;
    for (int i = 0; i < c.facturesA.size() ; i++)
    {
        factureA* a = new factureA(*c.facturesA[i]);
        facturesA.push_back(a);
    }
        for (int i = 0; i < c.facturesR.size() ; i++)
    {
        factureR* a = new factureR(*c.facturesR[i]);
        facturesR.push_back(a);
    }
        for (int i = 0; i < c.voitures.size() ; i++)
    {
        voiture* a = new voiture(*c.voitures[i]);
        voitures.push_back(a);
    }
        for (int i = 0; i < c.sessions.size() ; i++)
    {
        sessionReserve* a = new sessionReserve(*c.sessions[i]);
        sessions.push_back(a);
    }
    
}











void client::saisir() {

    cout << "\nEnter id : " ;
    cin >> id ;
    cout << "Enter nom : " ;
    cin >> nom ;
    cout << "Enter prenom : " ;
    cin >> prenom;
    cout << "Enter adresse : " ;
    cin >> adresse ;
    cout << "Enter telephone : " ;
    cin >> telephone ;
    
}

void client::chargerSolde(float m) {
    solde += m ;
}




void client::afficherSessionDispo() {

}



void client::afficherVoitures() {
    if (voitures.size() > 0) {
    for (int i = 0; i < voitures.size(); i++)
    {
        
        cout << *(voitures[i]) ;
        cout << "\n******************" ;
    }
    }
    else cout << "Aucun voiture \n" ;
}

void client::afficherSessionReserve() {
    cout << "Sessions Reservés : \n" ;
    if (sessions.size() > 0) {
        for (int i = 0; i < sessions.size(); i++)
        {
            
            cout << *(sessions[i]) ;
            cout << "\n******************" ;
        }
        cout << endl ;
    }
    else cout << "Aucune session reserve \n" ;
}



void client::reserverSession(sessionReserve* s) {

        // send pointer from station .reserver() as argument
        // add pointer to vector
        sessions.push_back(s) ;

 
}

bool client::avoirVoiture(string str) {
    for (int i = 0; i < voitures.size(); i++)
    {
        if (voitures[i]->getImmat() == str) return true ;
    }
    return false ;
}


sessionReserve* client::findSession(int n) {
    for (int i = 0; i < sessions.size(); i++)
    {
        if( sessions[i]->getID() == n ) return sessions[i] ;
    }
    return (sessionReserve*) nullptr ;
}





void client::annulerReservation(sessionReserve* s) {
    // delete and create new object done from station api
    sessions.erase( remove( sessions.begin(), sessions.end(),s ), sessions.end() );
}

void client::startCharging() {
    
    int temp ;
    bool exist = false ;
    cout << "\nEntrer id de la session : " ;
    cin >> temp ;

    for(int i = 0 ; i < sessions.size()  ; i++ )  {
        if (sessions[i]->getID() == temp ) {
            sessions[i]->setEtat("Active");
            sessions[i]->getPort()->activerChargeur() ;
            exist = true ;
            cout << "Recharge en cours..."  ;
            break ;
        }
    }
    if(!exist) cout << "Session non trouvé !" ;
}


factureR* client::stopCharging() {

    int temp ,i=0;
    factureR* f = nullptr ;
    bool exist = false ;
    cout << "\nEntrer id de la session : " ;
    cin >> temp ;

    for( i = 0 ; i < sessions.size()  ; i++ )  {
        if (sessions[i]->getID() == temp ) {
            sessions[i]->setEtat("Terminé");
            sessions[i]->getPort()->desactiverChargeur() ;
            exist = true ;
            f = new factureR(sessions[i]->getID(), sessions[i]->getDate(), true,this,sessions[i]);
            facturesR.push_back(f) ;
            cout << "Recharge Terminé..."  ;
            break ;
        }
    }
    if(!exist) cout << "Session non trouvé !" ;
    else sessions.erase(sessions.begin() + i);

    return f ;

}



void client::afficherFactureImpaye() {

    if ( facturesR.size() > 0) {
        cout << "\nFacture de recharge impayés : "  ;
        for (int i = 0 ; i < facturesR.size() ; i++ ) {
            if ( facturesR[i]->est_impaye()) {
                
                cout << *(facturesR[i]) ;
                cout << "\n***********************" ;
            }
        }
        cout << endl ;
    }
    else cout << "\n0 Factures de recharge reste impaye \n" ;
    cout << "_____________________________\n" ;
    if ( facturesA.size() > 0) {
        cout << "\nFacture d'achat impayés : "  ;
        for (int i = 0 ; i < facturesA.size() ; i++ ) {
            if ( facturesA[i]->est_impaye()) {
                cout << "***********************\n" ;
                cout << *(facturesA[i] );
            }
        }
        cout << endl ;
    }
    else cout << "\n0 Factures d'achat reste impaye \n" ;
}

void client::payerFacture() {

    int n,f ;
    cout << "\nEntrer 1 pour facture de recharge ou 2 pour facture achat : " ;
    cin >> n ;
    cout << "Entrer numero Facture a payer : " ;
    cin >> f;
    

    if(n == 1) {
    for(int i = 0 ; i < facturesR.size() ; i++ ) {
        if ( facturesR[i]->getNum() == f && facturesR[i]->est_impaye()) {
                
                if (solde - facturesR[i]->getMontant() >=0 ) {
                    solde = solde - facturesR[i]->getMontant() ;
                    facturesR[i]->payer() ;
                    cout << "Facture payé avec succes.\n" ;
                    
                }
                else cout << "Solde insuffisant" ;
                return ;
        }
        else if (facturesR[i]->getNum() == f && !facturesR[i]->est_impaye()) {
            
            cout << "Facture deja payé" ;
            return ;
        }
    }
    }
    else if ( n == 2 ) {
        for(int i = 0 ; i < facturesA.size() ; i++ ) {
            if ( facturesA[i]->getNum() == f && facturesA[i]->est_impaye()) {
                    
                    if (solde - facturesA[i]->getMontant() >=0 ) {
                        solde = solde - facturesA[i]->getMontant() ;
                        facturesA[i]->payer() ;
                        cout << "Facture payé avec succes." ;
                        
                    }
                else cout << "Solde insuffisant" ;
                return ;
            }
            else if (facturesA[i]->getNum() == f && !facturesA[i]->est_impaye()) {
                
                cout << "Facture deja payé" ;
                return ;
            }
    }
    }

    cout << "Facture introuvable." ;
    return ;

}

ostream & operator << (ostream &out, const client& c ) {
    if ( &out == &cout ) {
        out << "\nId : " << c.id << endl ;
        out << "Nom: " << c.nom << endl ;
        out << "Prenom : " << c.prenom << endl;
        out << "Adresse : "  << c.adresse << endl ;
        out << "Telephone : " << c.telephone << endl ;
        out << "Solde : " << c.solde ;
    }
    else {
        out << c.id << " " << c.nom << " " << c.prenom << " " << c.adresse 
        << " " << c.telephone << " " << c.solde  ;
    }

    return out;
}


istream& operator>>(istream& in, client& c)  {
    if ( &in == &cin ) {
        cout << "\nId : " ; in >> c.id  ;
        cout << "Nom: " ; in >> c.nom  ;
        cout << "Prenom : " ; in >> c.prenom ;
        cout << "Adresse : "  ; in >> c.adresse  ;
        cout << "Telephone : " ; in >> c.telephone  ;
        cout << "Solde : " ; in >> c.solde ;
    }
    else {
        in >> c.id >> c.nom >> c.prenom >> c.adresse >> c.telephone >> c.solde  ;
    }

    return in;   
}





void client::ajouterVoiture(voiture*  v) {
    voitures.push_back(v);
    

}


void client::ajouterSession(sessionReserve*  s) {
    sessions.push_back(s) ;
}




void client::ajouterFacture(factureC*  f) {
    if ( typeid(*f) == typeid(factureR) ) {
        facturesR.push_back(static_cast<factureR*>(f)) ;
    }
    else {
        facturesA.push_back(static_cast<factureA*>(f)) ;
    }

}



voiture* client::ajouterVoiture() {
    voiture* v = new voiture();
    v->saisir() ;
    v->setClient(this) ;
    voitures.push_back(v);
    return v ;

}