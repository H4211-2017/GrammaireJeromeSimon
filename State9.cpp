/*************************************************************************
                           State9  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State9> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "State9.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State9::nextState(Automate &automate, Token t) 
{
	switch(t.type)
	{
		case PLUS:
		case MULT:
		case RPAR:
		case ENDOF:
			automate.reduction(4);
			break;
			
		default:
			stringstream nbConsume;
			nbConsume << automate.nbDeConsume();
			string type = "" + convertTokenToString(t);
			throw string("[State9] Erreur apres lecture du caractere " + nbConsume.str() + " : \ncaractere attendu : \"+, *, ), $\";\ncaractere trouve : " + type);
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State9::State9 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State9>" << endl;
#endif
	
} //----- Fin de State9


State9::~State9 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State9>" << endl;
#endif
} //----- Fin de ~State9


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
