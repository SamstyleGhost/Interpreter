#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <iostream>
#include <unordered_map>

enum class Tokenlist {
	ILLEGAL,
	EOFC, // custom EOF
	
	IDENT, // Identifier
	INT,

	ASSIGN,
	PLUS,
	MINUS,
	ASTERISK,
	SLASH,
	BANG,

	GT,
	LT,
	GTE,
	LTE,
	EQ,
	NEQ,

	COMMA,
	SEMICOLON,
	LPAREN,
	RPAREN,
	LBRACE,
	RBRACE,
	LBRACK,
	RBRACK,

	FUNCTION,
	LET,
	RETURN,

	TRUE,
	FALSE,
	IF,
	ELSE,
};

struct Token {
	Tokenlist Type;
	std::string Literal;
	
	friend std::ostream& operator<<(std::ostream& os, const Token& tok);
};

bool isLetter(char ch);
bool isDigit(char ch);
Tokenlist lookupIdentifier(std::string literal);

#endif