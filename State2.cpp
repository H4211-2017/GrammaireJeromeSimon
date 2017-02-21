/*************************************************************************
                           State2  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State2> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "State2.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State2::nextState(Automate &automate, Token t) 
{
	switch(t.type) 
	{
		case EXPR:
			automate.decalage(t, 6);
			break;
		case LPAR:
			automate.decalage(t, 2);
			break;
		case VAL:
			automate.decalage(t, 3);
			break;
		default:
			stringstream nbConsume;
			nbConsume << automate.nbDeConsume();
			string type = "" + convertTokenToString(t);
			throw string("[State2] Erreur apres lecture du caractere " + nbConsume.str() + " : \ncaractere attendu : \"EXPR, (, VAL\";\ncaractere trouve : " + type);
			
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State2::State2 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State2>" << endl;
#endif
	
} //----- Fin de State2


State2::~State2 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State2>" << endl;
#endif
} //----- Fin de ~State2


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
