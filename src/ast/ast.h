#pragma once

/*
  Every line would be considered as a node. But what kind of node?
  Will it be a statement node or an expression node.
  That is what I have to decide
*/

#include <iostream>
#include <vector>

#include "../tokens/token.h"
/*
class Node {
public:
  virtual std::string tokenLiteral() const = 0;

  virtual ~Node() = default;
};

class Statement : public Node {
public:
  virtual void statementNode() const = 0;

  virtual ~Statement() = default;
};

class Expression : public Node {
public:
  virtual void expressionNode() const = 0;

  virtual ~Expression() = default;
};

class Program : public Node {
  std::vector<std::unique_ptr<Statement>> statements; // shared_ptr helps manage dynamic memory efficiently. Dont have to worry about deleting it when no longer in use
  
  std::string tokenLiteral() const override;
};

class Identifier : public Expression {
  // ! Might have to convert this from Token to Tokenlist
  Token token;
  std::string value;
    
public:
  Identifier(Token tok, const std::string val);

  void expressionNode() const override;

  std::string tokenLiteral(); 
};

class LetStatement : public Statement {
  // ! Might have to convert this from Token to Tokenlist
  Token token;
  std::shared_ptr<Identifier> name;
  std::shared_ptr<Expression> value;

public:
  LetStatement(Token tok, std::shared_ptr<Identifier> n, std::shared_ptr<Expression> val); 

  void statementNode() const override;

  std::string tokenLiteral(); 
};

*/

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