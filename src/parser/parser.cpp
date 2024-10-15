#include "parser.h"

Parser::Parser(Lexer *l) { 
  lex = l; 
  
  currToken = nullptr;
  peekToken = nullptr;

  consumeToken();
  consumeToken();
  
  if(peekToken->Type == Tokenlist::EOFC || currToken->Type == Tokenlist::EOFC) {
    std::cerr << "Empty file" << std::endl;
    exit(EXIT_FAILURE);
  }
}

Statement* Parser::parseStatement() {
  switch (currToken->Type) {
    case Tokenlist::LET:
      return parseLetStatement();
    case Tokenlist::RETURN:
      return parseReturnStatement();
    default:
      std::cout << "Ehh..." << std::endl;
  }

  return nullptr;
}

LetStatement* Parser::parseLetStatement() {
  LetStatement* ls = new LetStatement();

  if(!expectPeek(Tokenlist::IDENT)) {
    std::cerr << "Incorrect syntax. Did not find identifier near Let statement" << std::endl;
    return nullptr;
  }

  ls->setIdentifier(currToken->Literal);

// Currently, there are no plans to support default garbage values in this language
  if(!expectPeek(Tokenlist::ASSIGN)) {
    std::cerr << "Incorrect syntax. Did not find assignment near Let statement" << std::endl;
    return nullptr;
  }

  // * I could check the peekToken type in a switch-case. And based on that type have the value and the type of identifier set.
  // TODO: Will have to add an error checking step here
  // TODO: And also at the end to check semicolon error
  consumeToken();

  ls->setValue(currToken->Literal);

  consumeToken();

  return ls;
}

ReturnStatement* Parser::parseReturnStatement() {
  ReturnStatement* rs = new ReturnStatement();

  consumeToken();

  rs->setValue(currToken->Literal);
  consumeToken();

  return rs;
}

void Parser::consumeToken() {
  currToken = peekToken;
  peekToken = lex->generateToken();
}

Token* Parser::getCurrToken() { return currToken; }
Token* Parser::getPeekToken() { return peekToken; }

bool Parser::expectPeek(Tokenlist ty) {
  if(peekToken->Type == ty) {
    consumeToken();
    return true;
  }
  return false;
}