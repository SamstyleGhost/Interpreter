#include "ast.h"

void LetStatement::statementNode() const {};

void LetStatement::printContents() const {
  std::cout << identifier.variableName << " " << value << "\n";
}

void LetStatement::setIdentifier(std::string name) {
  identifier.identifierType = Tokenlist::IDENT;
  identifier.variableName = name;
}

void LetStatement::setValue(std::string val) {
  value = val;
}