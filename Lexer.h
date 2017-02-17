/*************************************************************************
                           Lexer  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Lexer> (fichier ${file_name}) ------
#ifndef LEXER_H
#define LEXER_H

using namespace std; 

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
enum TokenType { ENDOF, PLUS, MULT, LPAR, RPAR, VAL, EXPR };


typedef struct Token{
	TokenType type = ENDOF;
	int value = 0;
	string strValue = "0";
} Token;


//------------------------------------------------------------------------ 
// Rôle de la classe <Lexer>
//
//
//------------------------------------------------------------------------ 

class Lexer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	Token readNext();
    
    Token consume();

	void printInput();
	

//------------------------------------------------- Surcharge d'opérateurs
    Lexer & operator = ( const Lexer & unLexer );

//-------------------------------------------- Constructeurs - destructeur
    Lexer ( string input );
    
	Lexer ( const Lexer & unLexer);

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

void purifyInput();
void defineType(Token &t, string s);
void defineCurToken();

protected:
//----------------------------------------------------- Attributs protégés
string input;
Token curToken;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Lexer>

#endif // LEXER_H
