/*************************************************************************
                           State1  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State1> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "State1.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State1::nextState(Automate &automate, Token t) 
{
	switch(t.type) 
	{
		case MULT:
			automate.decalage(t, 5);
			break;
		case PLUS:
			automate.decalage(t, 4);
			break;
		case ENDOF:
			automate.accepter();
			break;
		default:
			stringstream nbConsume;
			nbConsume << automate.nbDeConsume();
			string type = "" + convertTokenToString(t);
			throw string("[State1] Erreur apres lecture du caractere " + nbConsume.str() + " : \ncaractere attendu : \"+,*,$\";\ncaractere trouve : " + type);
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State1::State1 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State1>" << endl;
#endif
	
} //----- Fin de State1


State1::~State1 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State1>" << endl;
#endif
} //----- Fin de ~State1


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
