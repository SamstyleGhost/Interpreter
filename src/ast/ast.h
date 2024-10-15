#pragma once

#include <iostream>
#include <vector>

#include "../tokens/token.h"

class Expression {
public:
  virtual void expressionNode() const = 0;
  virtual Tokenlist getReturnType() const = 0;
  
  virtual ~Expression() = default;
};

class IntExpression : public Expression {
  int literalValue = 0; // Initializing the INT token with 0
  
  void expressionNode() const override;
  Tokenlist getReturnType() const override;
};

class Identifier {
public:
  Tokenlist identifierType; // This should be the Identifier token only since the expression is the one that has a type
  std::string variableName;
};

class Statement {
public:
  virtual void statementNode() const = 0;
  virtual void printContents() const = 0;

  virtual ~Statement() = default; // I need this destructor here because if I dont have this, then if I delete a child object through Statement class will not call the derived class's destructor
};

class LetStatement : public Statement {
  Tokenlist tokenType; // LET token
  Identifier identifier;
  // Expression* expression;
  std::string value; // ! Currently for testing purposes
  
  void statementNode() const override;
  void printContents() const override;

public:
  LetStatement();
  void setIdentifier(std::string name); // TODO: Am initializing the tokentype as IDENT rn, will change this later
  void setValue(std::string val);
};

class ReturnStatement : public Statement {
  Tokenlist tokenType;
  // Expression* expression;
  std::string value; // !Testing
  
  void statementNode() const override;
  void printContents() const override;

public:
  ReturnStatement();
  void setValue(std::string val);
};