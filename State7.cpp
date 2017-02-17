/*************************************************************************
                           State7  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State7> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "State7.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State7::nextState(Automate &automate, Token t) 
{
	switch(t.type) 
	{
		case MULT:
			automate.decalage(t, 5);
			break;
		default:
			automate.reduction(2);
			break;
			
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State7::State7 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State7>" << endl;
#endif
	
} //----- Fin de State7


State7::~State7 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State7>" << endl;
#endif
} //----- Fin de ~State7


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
