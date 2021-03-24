/*************************************************************************
    Analog  -  Analyse de logs apache
                             -------------------
    début                : 01/21
    copyright            : (C) 2021 par Chellaoui A, Benzekri R
*************************************************************************/

//---------- Réalisation du module <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<vector>
#include <iostream>
#include <fstream>

using namespace std;
//------------------------------------------------------ Include personnel
#include"LectureLog.h"

const string LOC_REFERER = "http://intranet-if.insa-lyon.fr";

const string nomMois[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    

bool LectureLog::OuvrirFichier (string nomFichier) //Ouverture Fichier
{
    fichier.open( nomFichier , ios::in );
    if (fichier){
        return true;
    }
    return false;
}//---------Fin de OuvrirFichier

bool LectureLog::LogSuivant()
{
    string ligne;
    getline(fichier,ligne);
    if(ligne.size() == 0)
    {
        return false;
    }
    logActuel.ipClient=isoler(ligne," ");
    logActuel.nomUtilisateur=isoler(ligne," ");
    logActuel.nomUtilisateurAuth=isoler(ligne," ");
    logActuel.date.jour=stoi(isoler(ligne,"/").substr(1));
    string mois=isoler(ligne,"/");
    int indMois(0);
    while (indMois<12 && nomMois[indMois]!=mois) {indMois++;}
    logActuel.date.mois=indMois+1;
    logActuel.date.annee=stoi(isoler(ligne,":"));
    logActuel.date.heure=stoi(isoler(ligne,":"));
    logActuel.date.minute=stoi(isoler(ligne,":"));
    logActuel.date.seconde=stoi(isoler(ligne," "));
    string decalage =isoler(ligne,"]");
    logActuel.date.diffGMT=(decalage[0]=='+');
    logActuel.date.heureCreneau=stoi(decalage.substr(1,2));
    logActuel.date.minuteCreneau=stoi(decalage.substr(3,2));
    isoler(ligne,"\"");
    logActuel.typeAction = isoler(ligne," ");
    logActuel.URL = isoler(ligne," ");
    isoler(ligne,"\" ");
    logActuel.typeDoc = logActuel.URL.substr(logActuel.URL.find_last_of(".")+1);
    logActuel.status=stoi(isoler(ligne," "));

    bool isDig=true;
    string data=isoler(ligne," \"");
    for (int i=0 ; i<data.size() && isDig ; i++) {
        isDig=isdigit(data[i]);
    }
    if (isDig) {
        logActuel.dataQuantite=stoi(data);
    }
    else {
        logActuel.dataQuantite=-1;
    }
    string refr = isoler(ligne, "\"");
    
    if(refr.substr(0,LOC_REFERER.size()) == LOC_REFERER)
    {
        refr = refr.substr(LOC_REFERER.size(),refr.size()-LOC_REFERER.size());
    }
    logActuel.referer = refr;
    isoler(ligne,"\"");
    logActuel.clientNav=isoler(ligne,"\"");
    return true;
}//---------Fin de LogSuivant

Log LectureLog::GetLog() 
{
    return logActuel;
}//---------Fin de GetLog

LectureLog::LectureLog ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog


LectureLog::~LectureLog ( )

{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~LectureLog

string LectureLog::isoler(string & ligne,string separateur)
{
    int index=ligne.find(separateur);
    string debut=ligne.substr(0,index);
    ligne=ligne.substr(index+separateur.size());
    return debut;
} //---------Fin de isoler