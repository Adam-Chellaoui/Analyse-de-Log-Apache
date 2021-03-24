/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 15/01/2021
    copyright            : (C) 2021 par BENZEKRI Rim & CHELLAOUI Adam
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Noeud.h"

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------- Constructeur - destructeur
Graphe::Graphe()
{
    #ifdef MAP
    	cout << "Appel au constructeur de <Graphe>" << endl;
	#endif
    nombreNoeuds = 0;
} //----- Fin du constructeur de Graphe

Graphe::~Graphe()
{
	#ifdef MAP
    	cout << "Appel au destructeur de <Graphe>" << endl;
	#endif
} //----- Fin du destructeur de Graphe

//----------------------------------------------------- Méthodes publiques
const map < string, Noeud > & Graphe::getTableauLiens() 
{
	return tableauLiens;
} //----- Fin de getTableauLiens

bool Graphe::ajouterLien(string nomNoeud1, string nomNoeud2, bool condition)
{

	if(tableauLiens.count(nomNoeud2)!= 0)
	{
		tableauLiens[nomNoeud2].ajouterLien(nomNoeud1,condition);
	}
	else
	{
		Noeud nouveauNoeud = Noeud(nomNoeud2);
		nouveauNoeud.ajouterLien(nomNoeud1,condition);
		tableauLiens.emplace(nomNoeud2,nouveauNoeud);
		nombreNoeuds++;
	}
	
	if(tableauLiens.count(nomNoeud1) == 0)
	{
		tableauLiens.emplace(nomNoeud1, Noeud(nomNoeud1));
		nombreNoeuds++;
	}
	return true;
} //----- Fin de ajouterLiens

const vector < Noeud > Graphe::getPlusConnectes(int n) const
{
	unsigned int nbRetour = 0;
	if(n < 0 || (unsigned int)n > nombreNoeuds)
	{
		nbRetour = nombreNoeuds;
	}
	else
	{
		nbRetour = (unsigned int) n;
	}
	
	vector < Noeud > tousDocs = vector < Noeud > (nombreNoeuds);
	unsigned int i = 0;
	for (map < string , Noeud > ::const_iterator it = tableauLiens.begin(); it != tableauLiens.end() ; ++ it )
	{
		tousDocs[i] = it->second;
		i++;
	}
	vector < Noeud > selection = vector < Noeud> (nbRetour);
	partial_sort_copy(tousDocs.begin(), tousDocs.end(), selection.begin() , selection.end(), // utilisation d'une fonction lambda
		[](const Noeud & docA, const Noeud & docB)
		{
			return (docA > docB);
		});
	return selection;
} //----- Fin de 