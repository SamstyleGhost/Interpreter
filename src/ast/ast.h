#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>
#include <memory>

#include "../tokens/token.h"

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
  std::vector<std::shared_ptr<Statement>> statements; // shared_ptr helps manage dynamic memory efficiently. Dont have to worry about deleting it when no longer in use
  
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

#endif