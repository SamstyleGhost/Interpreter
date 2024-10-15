#include "ast.h"

void LetStatement::statementNode() const {};

void LetStatement::printContents() const {
  std::cout << identifier.variableName << " " << value << "\n";
}

LetStatement::LetStatement() {
  tokenType = Tokenlist::LET;
}

void LetStatement::setIdentifier(std::string name) {
  identifier.identifierType = Tokenlist::IDENT;
  identifier.variableName = name;
}

void LetStatement::setValue(std::string val) {
  value = val;
}

// Return Statement
void ReturnStatement::statementNode() const {};

void ReturnStatement::printContents() const {
  std::cout << value << "\n";
}

ReturnStatement::ReturnStatement() {
  tokenType = Tokenlist::RETURN;
}

void ReturnStatement::setValue(std::string val) {
  value = val;
}