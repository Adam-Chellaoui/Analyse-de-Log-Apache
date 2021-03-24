/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 15/01/2021
    copyright            : (C) 2021 par BENZEKRI Rim & CHELLAOUI Adam
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.h) --
#if ! defined (GRAPHE_H)
#define GRAPHE_H

#include <map>
using namespace std;
#include "Noeud.h"

class Graphe
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeur - destructeur
    Graphe();

    virtual ~Graphe();
    const map < string , Noeud > & getTableauLiens();

    bool ajouterLien(string nomNoeud1,string nomNoeud2,bool condition = true);

    const vector < Noeud > getPlusConnectes(int n) const;

//------------------------------------------------------------------ PRIVE 
//----------------------------------------------------- Attributs protégés
protected:

    map < string, Noeud > tableauLiens;
    unsigned int nombreNoeuds;
};

#endif // GRAPHE_H