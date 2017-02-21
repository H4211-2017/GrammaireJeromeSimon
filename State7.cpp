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
#include <sstream>

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
		case PLUS:
		case RPAR:
		case ENDOF:
			automate.reduction(2);
			break;
		default:
			stringstream nbConsume;
			nbConsume << automate.nbDeConsume();
			string type = "" + convertTokenToString(t);
			throw string("[State7] Erreur apres lecture du caractere " + nbConsume.str() + " : \ncaractere attendu : \"*, +, ), $\";\ncaractere trouve : " + type);
			
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
