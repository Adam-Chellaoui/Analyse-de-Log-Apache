/*************************************************************************
        Analog  -  Analyse de logs apache
                             -------------------
    début                : 15/01/21
    copyright            : (C) 2021 par Chellaoui A, Benzekri R
*************************************************************************/

//---------- Interface du module <Analog> (fichier Analog.h) ----------------
#if ! defined ( ANALOG_H )
#define ANALOG_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

#include "LectureLog.h"

//------------------------------------------------------------------ Types définis
typedef struct Parametres
{
    string strParametre;
    unsigned int intParametre;
} Parametres;

int main( int argc, char** argv );
// Mode d'emploi : 
// Appelé à l'éxécution du programme
// Contrat : 

//-----------------------------------------------------------Fontions définies

int convertHeure (string heure);

bool checkNombre (string nombre);

bool checkHeure (Log & LogaEssayer , Parametres param);
    
bool verifModes(Log LogaEssayer,vector < bool (*)(Log & ,Parametres) > & tests, vector < Parametres > & refr);

bool castExtensions (Log & LogaEssayer , Parametres param);

bool choixSurEcritureFichier ();




#endif // Analog_H

