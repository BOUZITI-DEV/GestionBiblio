//bouziti jaouad 3IIRG5
#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
#include<fstream>
using namespace std;

class livre
{
    private:
        int id;
        string nom_livre;
        string nom_auteur;
        string nom_edition;
        string genre;
        float prix;
    public:
        livre *suivant;
        livre *precedent;
        livre();
        livre(int a, string b, string c, string d, string e, float f);

        void setId(int);
        void setNom_livre(string);
        void setNom_auteur(string);
        void setNom_edition(string);
        void setGenre(string);
        void setPrix(float);
        
        int getId();
        string getNom_livre();
        string getNom_auteur();
        string getNom_edition();
        string getGenre();
        float getPrix();

        void operator=(livre);
        void afficher();
};
int menu();
void retour();
livre ajouter_info(int);
livre ajouter_info(livre *);
int nb_element(livre *);
livre* retourner_element(livre *, int);
void ajouter_element(livre *);
void afficher_liste(livre *);
bool rechercher_element(livre *, int, int);
void modifier_element(livre *, int);
void supprimer_element(livre *, int);
void enter(livre *);
void quitter(livre *);

void main()
{
    int rep,confirmer;
    livre *tete = new livre;
    int id_temp;
    
    if(tete == NULL)
    {
        cout << "erreur de memoire!";
        exit(0);
    }
    enter(tete);
    while(1)
    {
        cout << "Realise par BOUZITI Jaouad 3IIRG5." << endl << endl;
        confirmer=menu();
        switch(confirmer)
        {
            case 0:
            {
                afficher_liste(tete);
                retour();
                break;
            }
            case 1:
            {
                cout << "Veuillez saisir l'ID du livre que vous rechercher. ID: ";
                cin >> id_temp;
                if(!rechercher_element(tete,id_temp,1))
                    cout << endl << "Le livre que vous rechercher n'existe pas dans la bilbliotheque." << endl;
                retour();
                break;
            }
            case 2:
            {   
                ajouter_element(tete);
                retour();
                break;
            }
            case 3:
            {   
                cout << "Veuillez saisir l'ID du livre que vous voulez modifier. ID: ";
                cin >> id_temp;
                modifier_element(tete, id_temp);
                retour();
                break;
            }
            case 4:
            {
                cout << "Veuillez saisir l'ID du livre que vous voulez supprimer. ID: ";
                cin >> id_temp;
                supprimer_element(tete, id_temp);
                retour();
                break;
            }
            case 5:
            {
                quitter(tete);
            }
        }
    }
}
livre::livre()
{
    suivant = NULL;
}
livre::livre(int a, string b, string c, string d, string e, float f)
{
    id = a;
    nom_livre = b;
    nom_auteur = c;
    nom_edition = d;
    genre = e;
    prix = f;
    suivant = NULL;
}
void livre::setId(int x)                {    id = x;                }
void livre::setNom_livre(string x)      {    nom_livre = x;         }
void livre::setNom_auteur(string x)     {    nom_auteur = x;        }
void livre::setNom_edition(string x)    {    nom_edition = x;       }
void livre::setGenre(string x)          {    genre = x;             }
void livre::setPrix(float x)            {    prix = x;              }
int livre::getId()                      {    return id;             }
string livre::getNom_livre()            {    return nom_livre;      }
string livre::getNom_auteur()           {    return nom_auteur;     }
string livre::getNom_edition()          {    return nom_edition;    }
string livre::getGenre()                {    return genre;          }
float livre::getPrix()                  {    return prix;           }
void livre::afficher()
{
    cout << "ID               : " << id << endl;
    cout << "Nom du livre     : " << nom_livre << endl;
    cout << "Nom de l'auteur  : " << nom_auteur << endl;
    cout << "Nom de l'edition : " << nom_edition << endl;
    cout << "Genre            : " << genre << endl;
    cout << "Prix             : " << prix << endl << endl;
}
void livre::operator=(livre temp)
{
    id = temp.id;
    nom_livre = temp.nom_livre;
    nom_auteur = temp.nom_auteur;
    nom_edition = temp.nom_edition;
    genre = temp.genre;
    prix = temp.prix;
}
int menu()
{
    int rep;

    cout << "Entrer le numero de la commande que vous voulez executez:\n";
    cout << "[0] afficher tous les livres." << endl;
    cout << "[1] rechercher un livre." << endl;
    cout << "[2] ajouter un livre." << endl;
    cout << "[3] modifier les informations d'un livre." << endl;
    cout << "[4] supprimer un livre." << endl;
    cout << "[5] quitter l'application." << endl;
    cout << "commande numero: ";
    do{
        cin >> rep;
        if(rep<0 || rep>5)
        {
            cout << "valeur invalide!" << endl;
            cout << "commande numero: ";
        }
    }while(rep<0 || rep>5);
    system("CLS");
    return rep;
}
livre ajouter_info(int flag = 1)
{
    int id;
    string nom_livre;
    string nom_auteur;
    string nom_edition;
    string genre;
    float prix;
    livre l;

    cout << "veuillez saisir les infromations." << endl;
    if(flag)
    {
        cout << "ID               : ";
        cin >> id;
        l.setId(id);
    }
    cout << "Nom du livre     : ";
    cin >> nom_livre;
    l.setNom_livre(nom_livre);
    cout << "Nom de l'auteur  : ";
    cin >> nom_auteur;
    l.setNom_auteur(nom_auteur);
    cout << "Nom de l'edition : ";
    cin >> nom_edition;
    l.setNom_edition(nom_edition);
    cout << "Genre            : ";
    cin >> genre;
    l.setGenre(genre);
    do{
        cout << "Prix             : ";
        cin >> prix;
        if(prix < 0)
            cout << "Prix invalide!" << endl;
    }while(prix < 0); 
    
    l.setPrix(prix);

    return l;
}
livre ajouter_info(livre *tete)
{
    int id,i = 0;
    string nom_livre;
    string nom_auteur;
    string nom_edition;
    string genre;
    float prix;
    livre l,*temp;

    cout << "veuillez saisir les infromations." << endl;
    
    do{
        cout << "ID               : ";
        cin >> id;
        temp = tete->suivant;
        while(temp != NULL)
        {
            if(id == temp->getId())
            {
                cout << endl << "L'id que vous venez de saisir est deja utilise" << endl;
                i = 1;
                break;
            }
            temp = temp->suivant;
            i = 0;
        }
    }while(i);
    l.setId(id);
    cout << "Nom du livre     : ";
    cin >> nom_livre;
    l.setNom_livre(nom_livre);
    cout << "Nom de l'auteur  : ";
    cin >> nom_auteur;
    l.setNom_auteur(nom_auteur);
    cout << "Nom de l'edition : ";
    cin >> nom_edition;
    l.setNom_edition(nom_edition);
    cout << "Genre            : ";
    cin >> genre;
    l.setGenre(genre); 
    do{
        cout << "Prix             : ";
        cin >> prix;
        if(prix < 0)
            cout << "Prix invalide!" << endl;
    }while(prix < 0); 
    l.setPrix(prix);

    return l;
}
int nb_element(livre *tete)
{
    int i=0;

    tete = tete->suivant;
    while(tete != NULL)
    {
        i++;
        tete = tete->suivant;
    }
    return i;
}
livre* retourner_element(livre *tete, int id_temp)
{
    tete = tete->suivant;
    while(tete != NULL)
    {
        if(tete->getId() == id_temp)
            break;
        tete = tete->suivant;
    }
    return tete;
}
void ajouter_element(livre *tete)
{   
    livre *l = new livre;
    livre *temp;

    if(l == NULL)
    {
        cout << "erreur de memoire!";
        exit(0);
    }
    *l = ajouter_info(tete);
    if(tete->suivant == NULL)
    {
        tete->suivant = l;
    }
    else
    {
        while(tete != NULL)
        {
            temp = tete;
            tete = tete->suivant;
        }
        temp->suivant = l;
    }
    cout << endl << "Votre livre vient d'etre ajouer correctement." << endl;
}
void afficher_liste(livre *tete)
{
    int i = 1;

    if(nb_element(tete) == 0)
        cout << "La bibliotheque est vide" << endl;
    else
    {
        tete = tete->suivant;
        while(tete != NULL)
        {
            cout << "les informations du livre " << i++ << " sont:" << endl;
            tete->afficher();
            tete = tete->suivant;
        }
    }
}
bool rechercher_element(livre *tete, int id_temp ,int flag=0)
{
    int rep;

    tete = tete->suivant;
    while(tete != NULL)
    {
        if(tete->getId() == id_temp)
        {
            if(flag)
            {
                cout << endl << "Le livre que vous rechercher existe dans la bilbliotheque." << endl << endl;
                cout << "Voulez-vous afficher ses informations? Tapez 1 si oui: ";
                cin >> rep;
                if(rep == 1)
                {
                    cout << endl;
                    tete->afficher();
                }
            }
            return true;            
        }
        tete = tete->suivant; 
    }
    return false;
}
void modifier_element(livre *tete, int id_temp)
{
    livre temp;

    if(rechercher_element(tete, id_temp))
    {
        tete = tete->suivant;
        while(tete != NULL)
        {
            if(tete->getId() == id_temp)
            {
                temp = ajouter_info(0);
                tete->setNom_livre(temp.getNom_auteur());
                tete->setNom_auteur(temp.getNom_auteur());
                tete->setNom_edition(temp.getNom_edition());
                tete->setGenre(temp.getGenre());
                tete->setPrix(temp.getPrix());
                cout << endl << "Votre livre vient d'etre modifier correctement." << endl;
                break;
            }
            tete = tete->suivant;
        }
    }
    else
        cout << endl << "Le livre que vous rechercher n'existe pas dans la bilbliotheque." << endl;
}
void supprimer_element(livre *tete, int id_temp)
{
    livre *temp;

    if(rechercher_element(tete, id_temp))
    {
        temp = retourner_element(tete, id_temp);
        if(nb_element(tete) == 1)
        {
            tete->suivant = NULL;
            delete temp;
        }
        else
        {
            while(tete != NULL)
            { 
                if(tete->suivant->getId() == temp->getId())
                {
                    tete->suivant = tete->suivant->suivant;
                    delete temp;
                    break;
                }
                tete = tete->suivant;
            }
        }
        cout << endl << "Le livre vient d'etre supprimer." << endl; 
    }
    else
        cout << endl << "Le livre que vous rechercher n'existe pas dans la bilbliotheque." << endl;
}
void retour()
{
    cout << endl << endl << "Appuyer sur une touche pour revenir au menu pricipal.";
    getch();
    system("CLS");
}
void enter(livre *tete)
{
    fstream file;
    livre *temp;
    int id,nb;
    string nom_livre;
    string nom_auteur;
    string nom_edition;
    string genre;
    float prix;
    
    file.open("biblio.txt", ios::in);
    if(file)
    {
        file >> nb; 
        for(int i=0; i<nb; i++)
        {
            temp = new livre;
            file >> id;
            temp->setId(id);
            file >> nom_livre;
            temp->setNom_livre(nom_livre);
            file >> nom_auteur;
            temp->setNom_auteur(nom_auteur);
            file >> nom_edition;
            temp->setNom_edition(nom_edition);
            file >> genre;
            temp->setGenre(genre);
            file >> prix;
            temp->setPrix(prix);
            tete->suivant = temp;
            tete = tete->suivant; 
        }
        file.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier";
        exit(0);
    }    
}
void quitter(livre *tete)
{
    int rep;
    fstream file;
    livre *temp;

    file.open("biblio.txt", ios::out);
    cout << "Voulez-vous vraimment quitter l'application? Tapez 1 si oui." << endl;
    cin >> rep;
    if(file)
    {
        file << nb_element(tete) << endl;
        tete = tete->suivant;
        while(tete != NULL)
        {
            file << tete->getId() << "\t";
            file << tete->getNom_livre() << "\t";
            file << tete->getNom_auteur() << "\t";
            file << tete->getNom_edition() << "\t";
            file << tete->getGenre() << "\t";
            file << tete->getPrix() << endl;
            tete = tete->suivant;
        }
        file.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier";
        exit(0);
    }
    if(rep == 1)
    {
        while(tete != NULL)
        {
            temp = tete;
            tete = tete->suivant;
            delete temp;
        }
        exit(0);
    }    
    else
        system("CLS");
}
