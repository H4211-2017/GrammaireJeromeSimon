/*************************************************************************
                           Automate  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Automate> (fichier Automate) ------
#if ! defined ( AUTOMATE_H )
#define AUTOMATE_H

#include <stack>
#include <string>

#include "Lexer.h"
#include "State.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Automate>
//
//
//------------------------------------------------------------------------ 

class State;

class Automate
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void decalage(Token t, int etat);
    void reduction(int regle);
    void accepter();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    Automate (string input);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Automate ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

void reduction2();
void reduction3();
void reduction4();
void reduction5();

protected:
//----------------------------------------------------- Attributs protégés

stack<State*> pileEtat;
stack<Token> pileToken;
bool fini;
Lexer lexer;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Automate>

#endif // AUTOMATE_H
