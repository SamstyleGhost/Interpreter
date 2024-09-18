#include "program.h"

Program::Program(Parser *p) {
  parser = p;
  
  while(parser->getCurrToken()->Type != Tokenlist::EOFC) {
    Statement *currStatement = parser->parseStatement();

    if(currStatement) statements.push_back(std::unique_ptr<Statement>(currStatement));

    parser->getNextToken();
  }

  for(const auto& ptr : statements) {
    ptr->printContents();
  }
}
