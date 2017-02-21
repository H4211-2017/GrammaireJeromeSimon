/*************************************************************************
                           State8  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State8> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "State8.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State8::nextState(Automate &automate, Token t) 
{
	switch(t.type)
	{
		case PLUS:
		case MULT:
		case RPAR:
		case ENDOF:
			automate.reduction(3);
			break;
			
		default:
			stringstream nbConsume;
			nbConsume << automate.nbDeConsume();
			string type = "" + convertTokenToString(t);
			throw string("[State8] Erreur apres lecture du caractere " + nbConsume.str() + " : \ncaractere attendu : \"+, *, ), $\";\ncaractere trouve : " + type);
	}
	
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State8::State8 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State8>" << endl;
#endif
	
} //----- Fin de State8


State8::~State8 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State8>" << endl;
#endif
} //----- Fin de ~State8


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
