/*************************************************************************
                           Affichage  -  Manipule les sorties du programme
                             -------------------
    début                : 15/01/21
    copyright            : (C) 2021 par Chellaoui A, Benzekri R
*************************************************************************/

//---------- Réalisation de la classe <Affichage> (fichier Affichage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <map>

//------------------------------------------------------ Include personnel
#include "Affichage.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


fluxEtat Affichage::Open (string nom, Modes mode )
{
	ifstream flux ( nom , ios::in );
	if( flux && mode == Modes::ABORT )
	{
		flux.close();
		return fluxEtat::ERR_wr;
	}
	if( flux )
	{
		flux.close();
	}
	//test  
	fluxSortant.open(nom,ios::out|ios::trunc);
	if( !fluxSortant )
	{
		return fluxEtat::ERR_open;
	}
	nomFichier = nom;
	return fluxEtat::VALIDE;
}


bool Affichage::AfficherGraphe( const map < string , Noeud > & liens )
{
	if(!fluxSortant)
	{
		return false;
	}
	fluxSortant << "digraph " <<  "{" << endl;
	//Ecriture des noeuds du graphe
	for ( map <string , Noeud >::const_iterator it = liens.cbegin() ; it !=  liens.cend() ; it++ ) 
	{
		fluxSortant << "node" << it->second.getNumNoeud() << " [label = \"" << it->first << "\"];" << endl;
	}
	//Parcours de la strcuture pour récupérer les liens entre noeuds
	for ( map <string , Noeud >::const_iterator it = liens.cbegin() ; it !=  liens.cend() ; it++ ) 
	{
		for ( map < string, int >::const_iterator itInterne = it->second.getLiens().cbegin() ; itInterne != it->second.getLiens().cend() ; itInterne++)
		{
			fluxSortant << "node" << liens.at(itInterne->first).getNumNoeud() << " -> node" << it->second.getNumNoeud();
			fluxSortant << " [label=\"" << itInterne->second << "\"];" << endl;
		}
	}
	fluxSortant << "}"<< endl;
	return true;
}	



bool Affichage::AfficherLiensGraphe( const vector < Noeud > & graphe )
{
	if(!fluxSortant)
	{
		return false;
	}
	fluxSortant << "digraph " << "{" <<endl;
	for( vector < Noeud > ::const_iterator it = graphe.cbegin() ; it !=  graphe.cend() ; it++ ) //parcours des noeuds du graphe et ecriture
	{
		fluxSortant << "node" << it->getNumNoeud() << " [label = \"" << it->getNomNoeud() << "\"];" << endl;
	}
	for( vector < Noeud > ::const_iterator itCible = graphe.cbegin() ; itCible !=  graphe.cend() ; itCible++ )
	{
		for( vector < Noeud > ::const_iterator itSource = graphe.cbegin() ; itSource!=  graphe.cend() ; itSource++ )
		{
			if(itCible->valeurArc( itSource->getNomNoeud() ) != -1) //verification du lien entre les noeuds
			{
				fluxSortant << "node" << itSource->getNumNoeud() << " -> node" << itCible->getNumNoeud() << " [label=\"" << itCible->valeurArc( itSource->getNomNoeud() ) << "\"];" << endl;
			}
		}
	}
	fluxSortant << "}"<< endl;
	return true;
}


void Affichage::Close()
{
	if (fluxSortant) fluxSortant.close();
}


void Affichage::AfficherNoeuds( const vector < Noeud > & liste )
{
	for ( unsigned int i = 0 ;i < liste.size(); i ++ )
	{
		cout << liste[i].getNomNoeud() << " (" << liste[i].getNombreLiens() << " hits)" << endl; 
	}
}


Affichage::Affichage ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Affichage>" << endl;
#endif
} //----- Fin de Affichage


Affichage::~Affichage ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Affichage>" << endl;
#endif
} //----- Fin de ~Affichage
