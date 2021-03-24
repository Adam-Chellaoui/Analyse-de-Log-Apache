/*************************************************************************
                           Affichage  -  Manipule les sorties du programme
                             -------------------
    début                : 15/01/21
    copyright            : (C) 2021 par Chellaoui A, Benzekri R
*************************************************************************/

//---------- Interface de la classe <Affichage> (fichier Affichage.h) ----------------
#if ! defined ( AFFICHAGE_H )
#define AFFICHAGE_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <string>
#include <fstream>
#include <vector>

//---------------------------------------------------Includes personnels
#include "Noeud.h"

using namespace std;


//------------------------------------------------------------------ Types
enum fluxEtat { VALIDE , ERR_open , ERR_wr };
enum Modes { ABORT , FORCE };
//------------------------------------------------------------------------
// Rôle de la classe <Affichage>
//
//
//------------------------------------------------------------------------

class Affichage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    fluxEtat Open( string nom, Modes mode = ABORT );
    // Mode d'emploi : 
    // Ouvre le flux d'ecriture vers le chemin spécifié
    // Si un fichier existe deja et que Modes est placé sur ABORT la methode renvoie ERR_wr
    // Si le fichier ne peut pas être ouvert elle renvoie Err_open
    // Si un fichier ne peut pas être ouvert en écriture la méthode renvoie ERR_wr
    // Sinon renvoie VALIDE

    void Close();
    // Mode d'emploi : 
    // Ferme le flux ouvert
    // Contrat : 
    // Le flux est bien ouvert

    bool AfficherGraphe( const map < string , Noeud > & liens);
    // Mode d'emploi :
    // Prend en paramètre la map contenant tous les liens entre Noeuds, et la retranscrit au format GrapheViz


    bool AfficherLiensGraphe( const vector < Noeud > & graphe);
    // Mode d'emploi : 
    // Dessine uniquement les liens entre les noeuds contenues dans le sous graphe dans le fichier .dot spécifié à l'ouverture


    void AfficherNoeuds (const vector < Noeud > & liste);
    // Mode d'emploi : 
    // Affiche le nom et le nombre de liens des Noeuds dans le conteneur, dans l'ordre


//-------------------------------------------- Constructeurs - destructeur

    Affichage ( );
    // Mode d'emploi : constructeur par défaut de Affichage
    //
    // Contrat :

    virtual ~Affichage ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string nomFichier;
    ofstream fluxSortant;
};

#endif // Affichage_H
