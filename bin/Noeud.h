/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 15/01/2021
    copyright            : (C) 2021 par BENZEKRI Rim & CHELLAOUI Adam
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.h) --
#if ! defined (NOEUD_H)
#define NOEUD_H

#include <string>
#include <map>
using namespace std;

class Noeud
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeurs - destructeur
    Noeud();
    
    Noeud(string NomNoeud);

    virtual ~Noeud();
    unsigned int getNombreLiens() const;

    unsigned int getNumNoeud() const;

    const map < string, int > & getLiens() const;

    const string getNomNoeud() const;

    void ajouterLien(string referer, bool condition);
    
    int valeurArc(string doc) const;
//------------------------------------------------- Surcharge d'opérateur
    bool operator > (const Noeud & nouveauNoeud) const;
    
//------------------------------------------------------------------ PRIVE 
//----------------------------------------------------- Attributs protégés
protected:
    string nomNoeud;
    unsigned int numNoeud;
    unsigned int nombreLiens;
    map < string, int> liens;
    static unsigned int nombreNoeuds;

};

#endif // NOEUD_H