/*************************************************************************
                           State3  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State3> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "State3.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State3::nextState(Automate &automate, Token t) 
{
	switch(t.type)
	{
		case PLUS:
		case MULT:
		case RPAR:
		case ENDOF:
			automate.reduction(5);
			break;
			
		default:
			stringstream nbConsume;
			nbConsume << automate.nbDeConsume();
			string type = "" + convertTokenToString(t);
			throw string("[State3] Erreur apres lecture du caractere " + nbConsume.str() + " : \ncaractere attendu : \"+, *, ), $\";\ncaractere trouve : " + type);
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State3::State3 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State3>" << endl;
#endif
	
} //----- Fin de State3


State3::~State3 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State3>" << endl;
#endif
} //----- Fin de ~State3


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
