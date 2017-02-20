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
#include "State0.h"
#include "State1.h"
#include "State2.h"
#include "State3.h"
#include "State4.h"
#include "State5.h"
#include "State6.h"
#include "State7.h"
#include "State8.h"
#include "State9.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Automate>
//
//
//------------------------------------------------------------------------

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
