#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "../ast/ast.h"
#include "../lexer/lexer.h"
#include "../tokens/token.h"
#include "../tokens/keywords.h" // * will see if this is need or can be deleted

class Parser {
  Lexer *lex;
  Token *currToken;
  Token *peekToken;
  
  void getNextToken();
  
public:
  Parser(Lexer *l);

};

#endif