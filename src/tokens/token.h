#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <iostream>

enum class Tokenlist {
	ILLEGAL,
	EOFC, // custom EOF
	IDENT, // Identifier
	ASSIGN,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	COMMA,
	SEMICOLON,
	LPAREN,
	RPAREN,
	LBRACE,
	RBRACE,
	LBRACK,
	RBRACK,
	FUNCTION,
	LET 
};

struct Token {
	Tokenlist Type;
	std::string Literal;
	
	friend std::ostream& operator<<(std::ostream& os, const Token& tok);
};

#endif