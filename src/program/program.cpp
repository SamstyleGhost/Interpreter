#include "program.h"

Program::Program(Parser *p) {
  parser = p;
  
  while(parser->getCurrToken()->Type != Tokenlist::EOFC) {
    Token *tok = parser->getCurrToken();

    Statement *currStatement = parser->parseStatement(tok);

    if(currStatement) statements.push_back(std::unique_ptr<Statement>(currStatement));

    parser->getNextToken();
  }
}
