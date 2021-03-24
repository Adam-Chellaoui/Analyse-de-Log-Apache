/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 15/01/2021
    copyright            : (C) 2021 par BENZEKRI Rim & CHELLAOUI Adam
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <map>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"

//----------------------------------------------------------------- PUBLIC
unsigned int Noeud::nombreNoeuds = 0;
//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud ()
{
	#ifdef MAP
        cout << "Appel au constructeur de <Noeud>" << endl;
    #endif
    nomNoeud = "INCONNU";
	nombreLiens = 0;
    numNoeud = nombreNoeuds;
    nombreNoeuds++;
    liens = map < string, int>();
}//----- Fin du constructeur de Noeud

Noeud::Noeud (string NomNoeud)
{
	#ifdef MAP
        cout << "Appel au constructeur de <Noeud>" << endl;
    #endif
    nomNoeud = NomNoeud;
	nombreLiens = 0;
    numNoeud = Noeud::nombreNoeuds; 
    Noeud::nombreNoeuds++;
}//----- Fin du constructeur de Noeud

Noeud::~Noeud()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Noeud>" << endl;
    #endif
}//----- Fin du destructeur de Noeud

unsigned int Noeud::getNombreLiens() const
{
	return nombreLiens;
} //----- Fin de getNombreliens

const map < string, int > & Noeud::getLiens() const
{
    return liens;
} //----- Fin de getliens

const string Noeud::getNomNoeud() const
{
    return nomNoeud;
} //----- Fin de getNomNoeud

unsigned int Noeud::getNumNoeud() const
{
    return numNoeud;
} //----- Fin de getNumNoeud

void Noeud::ajouterLien(string nomNoeud, bool condition)
{
    if(condition)
    {
        if(liens.count(nomNoeud)!= 0)
        {
            liens[nomNoeud]++;
        }
        else
        {
            liens.emplace(nomNoeud,1);
        }
    }

	nombreLiens++;
} //----- Fin de ajouterLien

int Noeud::valeurArc(string doc) const
{
    int valeur = -1;
    if(liens.count(doc) != 0 )
    {
        valeur = liens.at(doc);
    }
    return valeur;
} //----- Fin de valeurArc

//------------------------------------------------- Surcharge d'opérateur
bool Noeud::operator > (const Noeud & nouveauNoeud) const
{
    bool comparaison;
    if(nouveauNoeud.getNombreLiens() != nombreLiens)
    {
    	comparaison = (nombreLiens > nouveauNoeud.getNombreLiens());
    }
    else
    {
    	comparaison = (nomNoeud > nouveauNoeud.getNomNoeud());
    }
    return comparaison;
} //----- Fin de la surcharge de operator >