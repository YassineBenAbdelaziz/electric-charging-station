#include "station.h"
#include <typeinfo>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "chargeurP.h"
#include "factureA.h"

using namespace std;

station::station()
{
}

station::station(int id, string des, string adr) : id(id), designation(des), adresse(adr)
{
}

void station::afficherSessionDispo()
{
    cout << "Sessions Disponibles : \n";
    if (sessions.size() > 0)
    {
        for (int i = 0; i < sessions.size(); i++)
        {
            if (typeid(*sessions[i]) == typeid(session))
            {

                cout << *(sessions[i]);
                cout << "\n*******************";
            }
        }
        cout << endl;
    }
    else
        cout << "Aucune session est disponible. \n";
}

bool station::sessionDispo(Date d, temps t)
{

    for (int i = 0; i < sessions.size(); i++)
    {
        if (typeid(*sessions[i]) == typeid(session))
        {
            if (sessions[i]->getDate() == d)
            {
                if (sessions[i]->getTemps() == t)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool station::sessionDispo(int n)
{

    for (int i = 0; i < sessions.size(); i++)
    {
        if (typeid(*sessions[i]) == typeid(session))
        {
            if (sessions[i]->getID() == n)
            {
                return true;
            }
        }
    }

    return false;
}

void station::acheterChargeur(client *cl)
{

    factureA *f = nullptr;
    int n, q;
    Date d;

    cout << "\nEnter id chargeur : ";
    cin >> n;

    chargeurD *c = findChargeurById(n);

    if (findChargeurById(n) == nullptr)
    {
        cout << "Chargeur non trouvé !";
    }
    else
    {
        cin >> d;
        cout << "Entrer quantité : ";
        cin >> q;
        f = new factureA(factureA::id + 1, d, true, cl, q, c);
        f->ajouterTax("Vente", 0.05);
        f->ajouterTax("TVA", 0.12);
        if (c->getPrix() > 4000)
        {
            f->ajouterTax("Luxe", 0.10);
        }
        f->calculMontant();

        cl->ajouterFacture(f);
        ajouter(f);
    }
}

void station::saisir()
{

    cout << "\nEnter l'identifiant : " << endl;
    cin >> id;
    cout << "\nEnter designation : " << endl;
    cin >> designation;
    cout << "\nEnter l'adresse : " << endl;
    cin >> adresse;
}

void station::ajouter(session *s)
{

    sessions.push_back(s);
}

void station::deleteSession(int id)
{

    session *s;
    bool exist = false;
    for (int i = 0; i < sessions.size(); i++)
    {
        if (sessions[i]->getID() == id)
        {
            s = sessions[i];
            exist = true;
            break;
        }
    }
    if (exist)
    {
        sessions.erase(remove(sessions.begin(), sessions.end(), s), sessions.end());
        // maybe remove from file
        delete s;
    }
    else
        cout << "Id introuvable";
}

void station::ajouter(voiture *v)
{

    voitures.push_back(v);
}

void station::deleteVoiture(voiture *v)
{

    voitures.erase(remove(voitures.begin(), voitures.end(), v), voitures.end());
    // maybe remove from file
    delete v;
}

client *station::findClientById(int n)
{
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i]->getId() == n)
            return clients[i];
    }
    return (client *)nullptr;
}

admin *station::findAdminById(int n)
{
    for (int i = 0; i < admins.size(); i++)
    {
        if (admins[i]->getId() == n)
            return admins[i];
    }
    return (admin *)nullptr;
}

void station::ajouter(client *c)
{
    clients.push_back(c);
}

void station::deleteClient(client *c)
{

    clients.erase(remove(clients.begin(), clients.end(), c), clients.end());
    // maybe remove from file
    delete c;
}

void station::ajouter(factureC *f)
{
    factures.push_back(f);
}

void station::deleteFacture(factureC *f)
{

    factures.erase(remove(factures.begin(), factures.end(), f), factures.end());
    // maybe remove from file
    delete f;
}

void station::ajouter(chargeurD *d)
{
    chargeursD.push_back(d);
}

void station::deleteChargeurD(int n)
{

    chargeurD *d;
    bool exist = false;
    for (int i = 0; i < chargeursD.size(); i++)
    {
        if (chargeursD[i]->getID() == n)
        {
            d = chargeursD[i];
            exist = true;
            break;
        }
    }
    if (exist)
    {
        chargeursD.erase(remove(chargeursD.begin(), chargeursD.end(), d), chargeursD.end());
        // maybe remove from file
        delete d;
        cout << "Chargeur Supprime \n";
    }
    else
        cout << "Id introuvable";
}

void station::ajouter(admin *a)
{
    admins.push_back(a);
}

void station::ajouter(chargeurL *l)
{
    chargeursL.push_back(l);
}

void station::deleteChargeurL(int n)
{

    chargeurL *l;
    bool exist = false;
    for (int i = 0; i < chargeursL.size(); i++)
    {
        if (chargeursL[i]->getID() == n)
        {
            l = chargeursL[i];
            exist = true;
            break;
        }
    }
    if (exist)
    {
        chargeursL.erase(remove(chargeursL.begin(), chargeursL.end(), l), chargeursL.end());
        // maybe remove from file
        delete l;
        cout << "Chargeur Supprime \n ";
    }
    else
        cout << "Id introuvable";
}

session *station::findSessionById(int n)
{
    for (int i = 0; i < sessions.size(); i++)
    {
        if (sessions[i]->getID() == n && typeid(*sessions[i]) == typeid(session))
            return sessions[i];
    }
    return (session *)nullptr;
}

void station::reserverSession(client *cl)
{

    int n;
    cout << "Enter id session a reserver : ";
    cin >> n;

    if (sessionDispo(n))
    {
        string str;
        cout << "Enter Immat voiture : ";
        cin >> str;
        if (cl->avoirVoiture(str))
        {
            sessionReserve *r = new sessionReserve(*findSessionById(n));
            r->setVoiture(findVoitureByImat(str));
            cl->reserverSession(r);
            sessions.push_back(r);
            deleteSession(n);
            cout << "Session Reserve \n";
        }
        else
            cout << "Voiture introuvable \n";
    }
    else
        cout << "Id introuvable ou session est reserve \n";
}

ostream &operator<<(ostream &out, const station &st)
{
    if (&out == &cout)
    {
        out << "\nId : " << st.id << endl;
        out << "Designation: " << st.designation << endl;
        out << "Adresse : " << st.adresse;
    }
    else
    {
        out << st.id << st.designation << st.adresse << endl;
    }

    return out;
}

void station::annulerReservation(client *cl)
{
    int n;
    cout << "Annuler Reservation \n";
    cout << "Enter id session : ";
    cin >> n;
    sessionReserve *r = cl->findSession(n);

    if (r)
    {
        session *s = new session();
        *s = *r;
        cl->annulerReservation(r);
        deleteSession(n);
        ajouter(s);
        cout << "Annulation Terminé\n";
    }
    else
        cout << "Reservation introuvable\n";
}

istream &operator>>(istream &in, station &st)
{
    if (&in == &cin)
    {
        cout << "\nId : ";
        in >> st.id;
        cout << "Designation: ";
        in >> st.designation;
        cout << "Adresse : ";
        in >> st.adresse;
    }
    else
    {
        in >> st.id >> st.designation >> st.adresse;
    }

    return in;
}

void station::LoadAdmins()
{
    fstream f;
    f.open("../database/admin.txt", ios::in);

    while (f.good() && (f.peek() != EOF))
    {
        admin *c = new admin();
        f >> *c;
        admins.push_back(c);
    }

    f.close();
}

void station::StoreAdmins()
{
    fstream f;
    f.open("../database/admin.txt", ios::out | ios::trunc);
    if (admins.size() > 0)
    {
        for (int i = 0; i < admins.size() - 1; i++)
        {
            f << *(admins[i]);
            f << endl;
        }
        f << *(admins[admins.size() - 1]);
    }

    f.close();
}

void station::printAdmins()
{
    for (int i = 0; i < admins.size(); i++)
    {
        cout << *(admins[i]);
    }
}

void station::LoadClients()
{
    fstream f;
    f.open("../database/clients.txt", ios::in);

    while (f.good() && (f.peek() != EOF))
    {
        client *c = new client();
        f >> *c;
        clients.push_back(c);
    }

    f.close();
}

void station::StoreClients()
{
    fstream f;
    f.open("../database/clients.txt", ios::out | ios::trunc);
    if (clients.size() > 0)
    {
        for (int i = 0; i < clients.size() - 1; i++)
        {
            f << *(clients[i]);
            f << endl;
        }
        f << *(clients[clients.size() - 1]);
    }

    f.close();
}

void station::printClients()
{
    for (int i = 0; i < clients.size(); i++)
    {
        cout << *(clients[i]);
    }
}

void station::LoadVoitures()
{
    fstream f;
    f.open("../database/voitures.txt", ios::in);

    while (f.good() && (f.peek() != EOF))
    {
        int id;
        voiture *v = new voiture();
        f >> *v;

        f >> id;
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i]->getId() == id)
            {
                v->setClient(clients[i]);
                clients[i]->ajouterVoiture(v);
                break;
            }
        }
        voitures.push_back(v);
    }

    f.close();
}

void station::StoreVoitures()
{
    fstream f;
    f.open("../database/voitures.txt", ios::out | ios::trunc);
    if (voitures.size() > 0)
    {
        for (int i = 0; i < voitures.size() - 1; i++)
        {
            f << *(voitures[i]);
            f << endl;
        }
        f << *(voitures[voitures.size() - 1]);
    }

    f.close();
}

void station::printVoitures()
{
    for (int i = 0; i < voitures.size(); i++)
    {
        cout << *(voitures[i]);
    }
}

void station::LoadChargeursD()
{
    fstream f;
    f.open("../database/chargeurD.txt", ios::in);

    while (f.good() && (f.peek() != EOF))
    {
        chargeurD *d = new chargeurD();
        f >> *d;
        chargeursD.push_back(d);
    }

    f.close();
}

void station::StoreChargeursD()
{
    fstream f;
    f.open("../database/chargeurD.txt", ios::out | ios::trunc);
    if (chargeursD.size() > 0)
    {
        for (int i = 0; i < chargeursD.size() - 1; i++)
        {
            f << *(chargeursD[i]);
            f << endl;
        }
        f << *(chargeursD[chargeursD.size() - 1]);
    }

    f.close();
}

void station::printChargeursD()
{
    cout << "Chargeurs en vente : \n";
    if (chargeursD.size() > 0)
    {
        for (int i = 0; i < chargeursD.size(); i++)
        {

            cout << *(chargeursD[i]);
            cout << "\n*******************";
        }
        cout << endl;
    }
    else
        cout << "Aucune chargeur est disponible. \n";
}

void station::LoadChargeursL()
{
    fstream f, g;
    f.open("../database/chargeurL.txt", ios::in);
    g.open("../database/chargeurP.txt", ios::in);
    while (f.good() && (f.peek() != EOF))
    {
        chargeurL *d = new chargeurL();
        f >> *d;
        chargeursL.push_back(d);
    }

    f.close();

    while (g.good() && (g.peek() != EOF))
    {
        chargeurP *d = new chargeurP();
        g >> *d;
        chargeursL.push_back(d);
    }
    g.close();
}

void station::StoreChargeursL()
{
    fstream f, g;
    f.open("../database/chargeurL.txt", ios::out | ios::trunc);
    g.open("../database/chargeurP.txt", ios::out | ios::trunc);
    if (chargeursL.size() > 0)
    {
        for (int i = 0; i < chargeursL.size() - 1; i++)
        {
            if (typeid(*chargeursL[i]) == typeid(chargeurL))
            {
                f << *(chargeursL[i]);
                if (typeid(*chargeursL[i + 1]) == typeid(chargeurL))
                    f << endl;
            }
            else
            {
                chargeurP *p = static_cast<chargeurP *>(chargeursL[i]);
                g << *p;
                if (typeid(*chargeursL[i + 1]) == typeid(chargeurP))
                    g << endl;
            }
        }

        if (typeid(*chargeursL[chargeursL.size() - 1]) == typeid(chargeurL))
        {
            f << *(chargeursL[chargeursL.size() - 1]);
        }
        else
        {
            chargeurP *p = static_cast<chargeurP *>(chargeursL[chargeursL.size() - 1]);
            g << *p;
        }
    }

    f.close();
    g.close();
}

void station::printChargeursL()
{
    cout << "Chargeurs Locales : \n";
    if (chargeursL.size() > 0)
    {
        for (int i = 0; i < chargeursL.size(); i++)
        {
            if (typeid(*chargeursL[i]) == typeid(chargeurL))
            {
                cout << *(chargeursL[i]);
                cout << "\n****************\n";
            }
            else
            {
                chargeurP *p = static_cast<chargeurP *>(chargeursL[i]);
                cout << *p;
                cout << "\n****************\n";
            }
        }
    }
    else
        cout << "Aucune chargeur est disponible. \n";
}

chargeurL *station::findPortByNum(int n)
{
    for (int i = 0; i < chargeursL.size(); i++)
    {
        if (chargeursL[i]->getID() == n)
            return chargeursL[i];
    }
    return (chargeurL *)nullptr;
}

chargeurD *station::findChargeurById(int n)
{
    for (int i = 0; i < chargeursD.size(); i++)
    {
        if (chargeursD[i]->getID() == n)
            return chargeursD[i];
    }
    return (chargeurD *)nullptr;
}

factureR *station::findFactureByNum(int n)
{
    for (int i = 0; i < factures.size(); i++)
    {
        if (factures[i]->getNum() == n)
            return static_cast<factureR *>(factures[i]);
    }
    return (factureR *)nullptr;
}

voiture *station::findVoitureByImat(string str)
{
    for (int i = 0; i < voitures.size(); i++)
    {
        if (voitures[i]->getImmat() == str)
            return static_cast<voiture *>(voitures[i]);
    }
    return (voiture *)nullptr;
}

sessionReserve *station::findSessionReserveById(int n)
{

    for (int i = 0; i < sessions.size(); i++)
    {
        if (sessions[i]->getID() == n)
            return static_cast<sessionReserve *>(sessions[i]);
    }
    return (sessionReserve *)nullptr;
}

void station::LoadSessions()
{
    fstream f, g;
    int n;
    string str;
    f.open("../database/session.txt", ios::in);
    g.open("../database/sessionReserve.txt", ios::in);
    while (f.good() && (f.peek() != EOF))
    {
        session *d = new session();
        f >> *d;
        f >> n;
        d->setPort(findPortByNum(n));
        sessions.push_back(d);
    }

    f.close();

    while (g.good() && (g.peek() != EOF))
    {
        sessionReserve *d = new sessionReserve();
        g >> *d;
        g >> n;
        d->setPort(findPortByNum(n));
        g >> str;
        d->setVoiture(findVoitureByImat(str));

        d->getVoiture()->getClient()->ajouterSession(d);
        sessions.push_back(d);
    }
    g.close();
}

void station::StoreSessions()
{
    fstream f, g;
    f.open("../database/session.txt", ios::out | ios::trunc);
    g.open("../database/sessionReserve.txt", ios::out | ios::trunc);
    if (sessions.size() > 0)
    {
        for (int i = 0; i < sessions.size() - 1; i++)
        {
            if (typeid(*sessions[i]) == typeid(session))
            {
                f << *(sessions[i]);
                if (typeid(*sessions[i + 1]) == typeid(session))
                    f << endl;
            }
            else
            {
                sessionReserve *p = static_cast<sessionReserve *>(sessions[i]);
                g << *p;
                if (typeid(*sessions[i + 1]) == typeid(sessionReserve))
                    g << endl;
            }
        }

        if (typeid(*sessions[sessions.size() - 1]) == typeid(session))
        {
            f << *(sessions[sessions.size() - 1]);
        }
        else
        {
            sessionReserve *p = static_cast<sessionReserve *>(sessions[sessions.size() - 1]);
            g << *p;
        }
    }

    f.close();
    g.close();
}

void station::printSessions()
{
    for (int i = 0; i < sessions.size(); i++)
    {
        if (typeid(*sessions[i]) == typeid(session))
        {
            cout << *(sessions[i]);
            cout << "\n****************";
        }
        else
        {
            sessionReserve *p = static_cast<sessionReserve *>(sessions[i]);
            cout << *p;
            cout << "\n****************";
        }
    }
}

void station::LoadFactures()
{
    fstream f, g;
    int n;
    float val;
    string str, key;

    f.exceptions(ifstream::failbit | ifstream::badbit);
    g.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        f.open("../database/factureR.txt", ios::in);
        g.open("../database/factureA.txt", ios::in);

        while (f.good() && (f.peek() != EOF))
        {

            try
            {
                factureR *d = new factureR();
                f >> *d;
                f >> n;
                d->setClient(findClientById(n));
                if (d->getClient() == nullptr)
                    throw 1;
                f >> n;
                d->setSession(findSessionReserveById(n));
                if (d->getSession() == nullptr)
                    throw 2;

                d->getSession()->setFacture(d);
                d->getClient()->ajouterFacture(d);
                factures.push_back(d);
            }
            catch (int i)
            {
                if (i == 1)
                    cout << "exception : client introuvable\n";
                else
                    cout << "exception : session introuvable \n";
                f.getline(nullptr, 100);
            }
        }

        f.close();

        while (g.good() && (g.peek() != EOF))
        {
            try
            {
                factureA *d = new factureA();
                g >> *d;
                g >> n;
                d->setClient(findClientById(n));
                if (d->getClient() == nullptr)
                    throw 1;
                g >> n;
                d->setChargeur(findChargeurById(n));
                if (findChargeurById(n) == nullptr)
                    throw 2;

                d->getClient()->ajouterFacture(d);
                factures.push_back(d);
            }
            catch (int i)
            {
                if (i == 1)
                    cout << "exception : client introuvable\n";
                else
                    cout << "exception : Chargeur introuvable \n";
                f.getline(nullptr, 100);
            }
        }
        g.close();
    }
    catch (ifstream::failure e)
    {
        cout << e.what();
        cout << "Exception opening/reading/closing file\n";
    }
}

bool compare(const factureC *p, const factureC *q)
{

    if (typeid(*p) == typeid(*q))
    {
        return true;
    }
    else if (typeid(*p) == typeid(factureR))
    {
        return true;
    }
    return false;
}

void station::StoreFactures()
{
    fstream f, g;

    f.exceptions(ifstream::failbit | ifstream::badbit);
    g.exceptions(ifstream::failbit | ifstream::badbit);

    sort(factures.begin(), factures.end(), compare);

    try
    {
        f.open("../database/factureR.txt", ios::out | ios::trunc);
        g.open("../database/factureA.txt", ios::out | ios::trunc);
        if (factures.size() > 0)
        {
            for (int i = 0; i < factures.size() - 1; i++)
            {
                if (typeid(*factures[i]) == typeid(factureR))
                {
                    factureR *p = static_cast<factureR *>(factures[i]);
                    f << *(p);
                    if (typeid(*factures[i + 1]) == typeid(factureR))
                        f << endl;
                }
                else
                {
                    factureA *p = static_cast<factureA *>(factures[i]);
                    g << *p;
                    if (typeid(*factures[i + 1]) == typeid(factureA))
                        g << endl;
                }
            }

            if (typeid(*factures[factures.size() - 1]) == typeid(factureR))
            {
                factureR *p = static_cast<factureR *>(factures[factures.size() - 1]);
                f << *(p);
            }
            else
            {
                factureA *p = static_cast<factureA *>(factures[factures.size() - 1]);
                g << *(p);
            }
        }

        f.close();
        g.close();
    }
    catch (ifstream::failure e)
    {
        cout << "Exception opening/reading/closing file\n";
    }
}

void station::printFactures()
{
    for (int i = 0; i < factures.size(); i++)
    {
        if (typeid(*factures[i]) == typeid(factureR))
        {
            factureR *p = static_cast<factureR *>(factures[i]);
            cout << *p;
        }
        else
        {
            factureA *p = static_cast<factureA *>(factures[i]);
            cout << *p;
        }
    }
}

void station::Load()
{
    LoadAdmins();
    LoadClients();
    LoadVoitures();
    LoadChargeursD();
    LoadChargeursL();
    LoadSessions();
    LoadFactures();
}

void station::Store()
{
    StoreChargeursD();
    StoreChargeursL();
    StoreClients();
    StoreAdmins();
    StoreFactures();
    StoreSessions();
    StoreVoitures();
}

station::~station()
{
    for (int i = 0; i < clients.size(); i++)
    {
        delete clients[i];
    }
    clients.clear();

    for (int i = 0; i < admins.size(); i++)
    {
        delete admins[i];
    }
    admins.clear();

    for (int i = 0; i < voitures.size(); i++)
    {
        delete voitures[i];
    }
    voitures.clear();

    for (int i = 0; i < chargeursD.size(); i++)
    {
        delete chargeursD[i];
    }
    chargeursD.clear();

    for (int i = 0; i < chargeursL.size(); i++)
    {
        delete chargeursL[i];
    }
    chargeursL.clear();

    for (int i = 0; i < sessions.size(); i++)
    {
        delete sessions[i];
    }
    sessions.clear();

    for (int i = 0; i < factures.size(); i++)
    {
        delete factures[i];
    }
    factures.clear();
}