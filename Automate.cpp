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

		lexer.consume();
		this->pileEtat.push(etatPt);
		this->pileToken.push(t);
	}

    void Automate::reduction(int regle)
    {
		switch(regle)
		{
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
		}
	}

    void Automate::accepter()
    {
		this->fini = true;
	}



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


Automate::Automate (string input) : pileEtat(), pileToken()
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
		delete this->pileEtat.pop();
	}
} //----- Fin de ~Automate


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

void Automate::reduction2()
{

}

void Automate::reduction3()
{

}

void Automate::reduction4()
{

}

void Automate::reduction5()
{
	State* etat = this->pileEtat.pop();
	Token t = this->pileToken.pop();
	t.type = EXPR;
	this->pileEtat.push(etat);
	this->pileToken.push(t);
}

