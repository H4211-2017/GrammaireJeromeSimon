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
	automate.reduction(3);
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
