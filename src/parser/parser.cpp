/* 
  ? Instead of running the lexer till EOF is reached, Will do the following steps:
  ? 1. Build a method in the lexer that will return one token at a time.
  ? 2. Remove the switch case lexing from the constructor of the lexer and put it inside that method.
  ? 3. Now, will run the method in the parser one by one until EOF token is received.
  ? 4. This will allow us to actually parse statements as soon as they are received
    * Wonder if the above thing, running the lexer through the parser and parsing a token at a time is valid for both interpreters and compilers or is it only for interpreters
    * Bcoz, just by straight feeling which could be wrong, it could be that compilers will first run the Lexical Analysis of the entire source code, store the tokens and then run the next phases.
*/

#include "parser.h"

Parser::Parser(Lexer *l) { 
  lex = l; 
  
  currToken = nullptr;
  peekToken = nullptr;
  
  // ! Havent done it here, but it is probably a good idea to check if the file is empty by checking if the initial tokens are CEOF.
  // TODO: check if initial tokens are EOF

  getNextToken();
  getNextToken();
  
  if(peekToken->Type == Tokenlist::EOFC || currToken->Type == Tokenlist::EOFC) {
    std::cerr << "Empty file" << std::endl;
    exit(EXIT_FAILURE);
  }
}

Statement* Parser::parseStatement() {
  switch (currToken->Type) {
    case Tokenlist::LET:
      return parseLetStatement();
    default:
      std::cout << "Ehh..." << std::endl;
  }

  return nullptr;
}

LetStatement* Parser::parseLetStatement() {
  std::cout << "Inside Let Statement parser\n";

  LetStatement* ls = new LetStatement();

  if(peekToken->Type != Tokenlist::IDENT) {
    std::cerr << "Incorrect syntax. Did not find identifier near Let statement" << std::endl;
    return nullptr;
  }

  getNextToken();

  ls->setIdentifier(currToken->Literal);

  if(peekToken->Type != Tokenlist::ASSIGN) {
    std::cerr << "Incorrect syntax. Did not find assignment near Let statement" << std::endl;
    return nullptr;
  }

  getNextToken();

  // TODO: Will have to add an error checking step here
  getNextToken();

  ls->setValue(currToken->Literal);

  getNextToken();

  return ls;
}

void Parser::getNextToken() {
  currToken = peekToken;
  peekToken = lex->generateToken();
}

Token* Parser::getCurrToken() { return currToken; }
Token* Parser::getPeekToken() { return peekToken; }