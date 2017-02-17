/*************************************************************************
                           State5  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State5> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "State5.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State5::nextState(Automate &automate, Token t) 
{
	switch(t.type) 
	{
		case EXPR:
			automate.decalage(t, 8);
			break;
		case LPAR:
			automate.decalage(t, 2);
			break;
		case VAL:
			automate.decalage(t, 3);
			break;
			
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

State5::State5 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State5>" << endl;
#endif
	
} //----- Fin de State5


State5::~State5 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State5>" << endl;
#endif
} //----- Fin de ~State5


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
