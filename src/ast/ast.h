#pragma once

#include <iostream>
#include <vector>

#include "../tokens/token.h"

class Expression {
public:
  Token token;
};

// TODO: Will definitely have to convert the Identifier and Expression classes into an abstract one so that I can assign if the current variable is an INT, DOUBLE, etc.
class Identifier {
public:
  Tokenlist identifierType; // ! Currently, this is just the IDENT token
  std::string variableName;
};

class Statement {
public:
  virtual void statementNode() const = 0;
  virtual void printContents() const = 0;

  virtual ~Statement() = default; // I need this destructor here because if I dont have this, then if I delete a child object through Statement class will not call the derived class's destructor
};

class LetStatement : public Statement {
  Token token; // LET token
  Identifier identifier;
  // Expression expression;
  std::string value; // ! Currently for testing purposes
  
  void statementNode() const override;
  void printContents() const override;

public:
  void setIdentifier(std::string name); // TODO: Am initializing the tokentype as IDENT rn, will change this later
  void setValue(std::string val);
};