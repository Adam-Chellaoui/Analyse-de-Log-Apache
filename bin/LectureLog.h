/*************************************************************************
                           LectureLog  -  Récuperation des log
                             -------------------
    début                : 15/01/2021
    copyright            : (C) 2021 par BENZEKRI Rim & CHELLAOUI Adam
*************************************************************************/

//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.h) --
#if ! defined (LECTURE_LOG_H)
#define LECTURE_LOG_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

//------------------------------------------------------------------ Types
typedef struct{
    unsigned int seconde;
    unsigned int minute;
    unsigned int heure;
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
    bool diffGMT;
    unsigned int heureCreneau;
    unsigned int minuteCreneau;
} Date;

typedef struct{
    string ipClient;
    string nomUtilisateur;
    string nomUtilisateurAuth;
    string typeAction;
    string URL;
    string typeDoc;
    string referer;
    string clientNav;
    Date date;
    int status, dataQuantite;
} Log;

// Rôle de la classe <LectureLog>
//
//
//------------------------------------------------------------------------

class LectureLog
{
//----------------------------------------------------------------- PUBLIC
public :
//----------------------------------------------------- Méthodes publiques
	
	bool OuvrirFichier (string nomFichier);
    // Mode d'emploi :
    // Permet d'ouvrir le fichier de log

	bool LogSuivant();
    // Mode d'emploi :
    // Entre dans logActuel toutes les informations convcernant le log

	Log GetLog();
    // Mode d'emploi :
    //Getter sur logActuel

	string isoler(string & ligne, string separateur);
    // Mode d'emploi :
    //Permet d'isoler la chaine de caractères jusqu'à separateur

	LectureLog();

	virtual ~LectureLog();

//------------------------------------------------------------------ PRIVE

protected :
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés 
	Log logActuel;
	ifstream fichier;


};

#endif //LectureLog_H