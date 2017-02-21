/*************************************************************************
                           Automate  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Automate> (fichier Automate) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Automate.h"
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

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Automate::decalage(Token t, int etat) 
{
	State* etatPt;
	switch(etat)
	{
		case 0:
			etatPt = new State0(t);
			break;
		case 1:
			etatPt = new State1(t);
			break;
		case 2:
			etatPt = new State2(t);
			break;
		case 3:
			etatPt = new State3(t);
			break;
		case 4:
			etatPt = new State4(t);
			break;
		case 5:
			etatPt = new State5(t);
			break;
		case 6:
			etatPt = new State6(t);
			break;
		case 7:
			etatPt = new State7(t);
			break;
		case 8:
			etatPt = new State8(t);
			break;
		case 9:
			etatPt = new State9(t);
			break;
			
	}
	
	if(t.type != EXPR)
	{
		lexer.consume();
	}
	this->pileEtat.push(etatPt);
	this->pileToken.push(t);
	etatPt->nextState(*this, lexer.readNext());
}

void Automate::reduction(int regle) 
{
	switch(regle)
	{
		case 2:
			reduction2();
			break;
		case 3:
			reduction3();
			break;
		case 4:
			reduction4();
			break;
		case 5:
			reduction5();
			break;
	}
}

void Automate::accepter() 
{
	fini = true;
}

int Automate::value()
{
	this->pileEtat.top()->nextState(*this, lexer.readNext());
	return this->pileToken.top().value;
}

int Automate::nbDeConsume()
{
	return this->lexer.getNbConsume();
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


Automate::Automate (string input) : pileEtat(), pileToken(), lexer("")
{
#ifdef MAP
    cout << "Appel au constructeur de <Automate>" << endl;
#endif
	
	this->lexer = Lexer(input);
	Token t;
	State* etatPremier = new State0(t);
	this->pileEtat.push(etatPremier);
	this->fini = false;
} //----- Fin de Automate


Automate::~Automate ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Automate>" << endl;
#endif

	while(this->pileEtat.size() > 0)
	{
		delete this->pileEtat.top();
		this->pileEtat.pop();
	}
} //----- Fin de ~Automate


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

void Automate::reduction2()
{
	State* etat = this->pileEtat.top();
	this->pileEtat.pop();
	Token t1 = this->pileToken.top();
	this->pileToken.pop();
	delete etat;
	
	etat = this->pileEtat.top();
	this->pileEtat.pop();
	this->pileToken.pop();
	delete etat;
	
	etat = this->pileEtat.top();
	this->pileEtat.pop();
	Token t2 = this->pileToken.top();
	this->pileToken.pop();
	delete etat;
	
	t1.type = EXPR;
	t1.value += t2.value;
	t1.strValue = ("" + t1.value);
	
	this->pileEtat.top()->nextState(*this, t1);
}

void Automate::reduction3()
{
	State* etat = this->pileEtat.top();
	this->pileEtat.pop();
	Token t1 = this->pileToken.top();
	this->pileToken.pop();
	delete etat;
	
	etat = this->pileEtat.top();
	this->pileEtat.pop();
	this->pileToken.pop();
	delete etat;
	
	etat = this->pileEtat.top();
	this->pileEtat.pop();
	Token t2 = this->pileToken.top();
	this->pileToken.pop();
	delete etat;
	
	t1.type = EXPR;
	t1.value *= t2.value;
	t1.strValue = ("" + t1.value);
	
	this->pileEtat.top()->nextState(*this, t1);
}

void Automate::reduction4()
{
	State* etat = this->pileEtat.top();
	this->pileEtat.pop();
	this->pileToken.pop();
	delete etat;
	
	etat = this->pileEtat.top();
	this->pileEtat.pop();
	Token t = this->pileToken.top();
	this->pileToken.pop();
	delete etat;
	
	etat = this->pileEtat.top();
	this->pileEtat.pop();
	this->pileToken.pop();
	delete etat;
	
	t.type = EXPR;
	this->pileEtat.top()->nextState(*this, t);
}

void Automate::reduction5()
{
	State* etat = this->pileEtat.top();
	this->pileEtat.pop();
	Token t = this->pileToken.top();
	this->pileToken.pop();
	t.type = EXPR;
	this->pileEtat.top()->nextState(*this, t);
	delete etat;
}

