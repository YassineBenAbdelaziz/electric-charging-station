#include <iostream>
#include <fstream>
#include "station.h"

using namespace std;

int main(int, char **)
{

    station st;
    int n, id, m, choix;
    client *c;
    admin *a;
    bool quit = false;
    float montant;

    st.Load();

    while (!quit)
    {
        cout << "----------------------------------------\n";
        cout << "Station de recharge electrique \n";
        cout << "Entrer commande \n";
        cout << "1) Create Client" << endl;
        cout << "2) Login Client" << endl;
        cout << "3) Create Admin" << endl;
        cout << "4) Login Admin" << endl;
        cout << "5) Quitter" << endl;
        cout << ">>> ";

        cin >> n;

        switch (n)
        {
        case 1:
            c = new client();
            c->saisir();
            st.ajouter(c);
            cout << "Client Ajouté\n";
            break;
        case 2:
            cout << "Enter id client ";
            cin >> id;
            c = st.findClientById(id);
            if (c)
            {
                cout << "OK\n";
                bool login = true;
                while (login)
                {
                    cout << "----------------------------------------\n";
                    cout << "Options Client \n";
                    cout << "Entrer commande \n";
                    cout << "1) Ajouter Voiture" << endl;
                    cout << "2) Afficher Voitures" << endl;
                    cout << "3) Consulter Solde" << endl;
                    cout << "4) Charger Solde" << endl;
                    cout << "5) Afficher Sessions Disponibles" << endl;
                    cout << "6) Afficher Sessions Reservés" << endl;
                    cout << "7) Reserver Session" << endl;
                    cout << "8) Annuler Reservation" << endl;
                    cout << "9) Afficher Facture Impayés" << endl;
                    cout << "10) Payer Facture" << endl;
                    cout << "11) Charger Voiture" << endl;
                    cout << "12) Quitter" << endl;
                    cout << ">>> ";

                    cin >> m;
                    switch (m)
                    {
                    case 1:
                        st.ajouter(c->ajouterVoiture());
                        cout << "Voiture ajoutée\n";
                        break;
                    case 2:
                        c->afficherVoitures();
                        cout << endl;
                        break;
                    case 3:
                        cout << "Solde : " << c->getSolde() << endl;
                        break;
                    case 4:
                        cout << "Entrer Montant\n";
                        cin >> montant;
                        c->chargerSolde(montant);
                        cout << "OK\n";
                        break;
                    case 5:
                        st.afficherSessionDispo();
                        break;
                    case 6:
                        c->afficherSessionReserve();
                        break;
                    case 7:
                        st.reserverSession(c);
                        break;
                    case 8:
                        st.annulerReservation(c);
                        break;
                    case 9:
                        c->afficherFactureImpaye();
                        break;
                    case 10:
                        c->payerFacture();
                        cout << endl ;
                        break;
                    case 11:
                        // start charging
                        break;
                    case 12:
                        login = false;
                        break;
                    default:
                        cout << "Commande erroné\n";
                        break;
                    }
                }
            }
            else
            {
                cout << "Id introuvable ;\n";
            }
            break;
        case 3:
            a = new admin();
            cin >> *a;
            st.ajouter(a);
            cout << "Admin Ajouté\n";
            break;
        case 4:
            cout << "Enter id admin ";
            cin >> id;
            a = st.findAdminById(id);
            if (a)
            {
                cout << "OK\n";
                bool login = true;
                while (login)
                {
                    cout << "----------------------------------------\n";
                    cout << "Options Admin \n";
                    cout << "1) Ajouter Session" << endl;
                    cout << "2) Afficher Session" << endl;
                    cout << "3) Delete Session" << endl;
                    cout << "4) Ajouter Chargeur" << endl;
                    cout << "5) Afficher Chargeur" << endl;
                    cout << "6) Delete Chargeur" << endl;
                    cout << "7) Quitter" << endl;
                    cout << ">>> ";
                    cin >> m;
                    switch (m)
                    {
                    case 1:
                        a->ajouterSession(&st);
                        cout << "Session Ajoutee " << endl;
                        break;
                    case 2:
                        st.printSessions();
                        cout << endl;
                        break;
                    case 3:
                        a->deleteSession(&st);
                        cout << endl;
                        break;
                    case 4:
                        cout << "Entrer 1 pour chargeur Locale, 2 chargeur Domicile : ";
                        cin >> choix;
                        if (choix == 1)
                            a->ajouterChargeurL(&st);
                        else if (choix == 2)
                            a->ajouterChargeurD(&st);
                        else
                            cout << "Choix erroné" << endl;
                        break;
                    case 5:
                        cout << "Entrer 1 pour chargeur Locale, 2 chargeur Domicile : ";
                        cin >> choix;
                        if (choix == 1)
                            st.printChargeursL();
                        else if (choix == 2)
                            st.printChargeursD();
                        else
                            cout << "Choix erroné" ;
                        cout << endl;
                        break;
                    case 6:
                        cout << "Entrer 1 pour chargeur Locale, 2 chargeur Domicile : ";
                        cin >> choix;
                        if (choix == 1)
                            a->deleteChargeurL(&st);
                        else if (choix == 2)
                            a->deleteChargeurD(&st);
                        else
                            cout << "Choix erroné" << endl;
                        cout << endl;
                        break;
                    case 7:
                        login = false;
                        break;
                    default:
                        cout << "Commande erroné\n";
                        break;
                    }
                }
            }
            break;
        case 5:
            quit = true;
            break;
        default:
            cout << "Commande erroné\n";
            break;
        }
    }

    st.Store();
}
