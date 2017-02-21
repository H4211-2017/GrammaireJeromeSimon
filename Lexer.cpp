/*************************************************************************
                           Lexer  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Lexer> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstdlib>

//------------------------------------------------------ Include personnel
#include "Lexer.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

string convertTokenToString(Token t)
{
	switch(t.type)
	{
		case ENDOF:
			return "$";
		case PLUS:
			return "+";
		case MULT:
			return "*";
		case LPAR:
			return "(";
		case RPAR:
			return ")";
		case VAL:
			return "VAL";
		case EXPR:
			return "EXPR";
		
	}
}

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Lexer::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Token Lexer::readNext() 
{
	return this->curToken;
}
    
Token Lexer::consume()
{
	int nbOfChar = this->curToken.strValue.length();
	this->input = this->input.substr(nbOfChar);
	Token copy = this->curToken;
	defineCurToken();
	nbConsume++;
	return copy;
}

void Lexer::printInput()
{
	cout << this->input << endl;
}

int Lexer::getNbConsume() 
{
	return nbConsume;
}

//------------------------------------------------- Surcharge d'opérateurs
Lexer & Lexer::operator = ( const Lexer & unLexer )
{
	this->input = string(unLexer.input);
	this->curToken = unLexer.curToken;
	
	return *this;
} 


//-------------------------------------------- Constructeurs - destructeur

Lexer::Lexer ( string input ) : input(input), nbConsume(0)
{
#ifdef MAP
    cout << "Appel au constructeur de <Lexer>" << endl;
#endif
	purifyInput();
	defineCurToken();
	//Calcul de nextIndex et de currentToken
	
} //----- Fin de Lexer

Lexer::Lexer ( const Lexer & unLexer)
{
	this->input = string(unLexer.input);
	this->curToken = unLexer.curToken;


}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

void Lexer::purifyInput() {
	
	string tampon = "";
	string alphabet = "()+*1234567890";
	for(string::iterator pos = this->input.begin(); pos != this->input.end(); pos++)
	{
		if(alphabet.find(*pos) != string::npos)
		{
			tampon += *pos;
		}
	}
	
	this->input = tampon;
	
}

void Lexer::defineType(Token &t, string s)
{
	switch(s[0]) {
		case '+':
			t.type = PLUS;
			break;
		case '*':
			t.type = MULT;
			break;
		case '(':
			t.type = LPAR;
			break;
		case ')':
			t.type = RPAR;
			break;
		default:
			t.type = VAL;
			break;
	}
}

void Lexer::defineCurToken() 
{
	Token t;
	if(this->input.length() == 0)
	{
		Token t;
		t.type = ENDOF;
		t.value = -1;
		t.strValue = "";
	}
	else
	{
		string tampon = "";
		int index = 0;
		string nombre = "0123456789";
		char car;
		do
		{
			car = this->input[index];
			tampon += car;
			index++;
		} while(nombre.find(car) != string::npos);
		
		if(tampon.length() > 1)
		{
			tampon = tampon.substr(0, tampon.length() - 1);
		}
		
		defineType(t, tampon);
		t.strValue = tampon;
		if(t.type == VAL)
		{
			t.value = atoi(tampon.c_str());
		}
	}
	this->curToken = t;	
}
