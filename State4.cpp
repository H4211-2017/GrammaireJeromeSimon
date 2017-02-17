/*************************************************************************
                           State4  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <State4> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "State4.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void State4::nextState(Automate &automate, Token t) 
{
	switch(t.type) 
	{
		case EXPR:
			automate.decalage(t, 7);
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

State4::State4 (Token t) : State(t)
{
#ifdef MAP
    cout << "Appel au constructeur de <State4>" << endl;
#endif
	
} //----- Fin de State4


State4::~State4 ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <State4>" << endl;
#endif
} //----- Fin de ~State4


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
