#pragma once

#include <iostream>
#include <memory>

#include "../ast/ast.h"
#include "../lexer/lexer.h"
#include "../tokens/token.h"
#include "../tokens/keywords.h" // * will see if this is need or can be deleted

class Parser {
  Lexer *lex;
  Token *currToken;
  Token *peekToken;
  
  bool expectPeek(Tokenlist ty);
  LetStatement* parseLetStatement();
  
public:
  Parser(Lexer *l);
  
  Token *getCurrToken();
  Token *getPeekToken();
  void getNextToken();
  
  Statement* parseStatement();
};