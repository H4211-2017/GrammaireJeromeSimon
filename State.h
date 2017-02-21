/*************************************************************************
                           State -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <State> (fichier State.h) ------
#if ! defined ( STATE_H )
#define STATE_H

#include "Automate.h"
#include "Lexer.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <State>
//
//
//------------------------------------------------------------------------ 

class Automate;

class State
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void nextState(Automate &automate, Token t)  = 0; 
    
    Token getToken() const {return curToken;}
	void setToken(Token t) {this->curToken = t;}
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    State(Token t){this->curToken = t;}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~State( ) {};
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

Token curToken;


private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <State>

#endif // STATE_H
