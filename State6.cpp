/*************************************************************************
                           State6  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State6> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "State6.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State6::nextState(Automate &automate, Token t) 
{
	switch(t.type) 
	{
		case PLUS:
			automate.decalage(t, 4);
			break;
		case MULT:
			automate.decalage(t, 5);
			break;
		case RPAR:
			automate.decalage(t, 9);
			break;
			
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State6::State6 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State6>" << endl;
#endif
	
} //----- Fin de State6


State6::~State6 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State6>" << endl;
#endif
} //----- Fin de ~State6


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
