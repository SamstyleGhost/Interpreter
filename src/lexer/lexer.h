#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "../tokens/token.h"

class Lexer {
  char ch;
  bool dq = false; // To check if it the current words are inside a string double quotes
  bool slc = false, mlc = false; // Single-line & Multi-linecomments
  int mls = 0; // Multi-line comment start
  std::string buffer = "";
  int lineNum = 1;
  FILE* input;

  char peekChar(); // gives the next character in the input
  Token* newToken(Tokenlist type, char literal); // Will generate a Token object and return it
  Token* newToken(Tokenlist type, std::string literal); // Overloaded the function in case the literal value is directly a string
  void skipWhitespace();
  Token* readLetters();
  Token* readDigits();

public:
  Lexer(FILE* inputFile);
  Token* generateToken();
};
#endif