#include "ast.h"

std::string Program::tokenLiteral() const {
  if (statements.empty()) return "";

  return statements[0]->tokenLiteral();
}

// Identifier
Identifier::Identifier(Token tok, const std::string val) : token(tok), value(val) {}
void Identifier::expressionNode() const {};
std::string Identifier::tokenLiteral() { return token.Literal; }

// Let Statements
LetStatement::LetStatement(Token tok, std::shared_ptr<Identifier> n, std::shared_ptr<Expression> val) : token(tok), name(n), value(val) {}
void LetStatement::statementNode() const {}
std::string LetStatement::tokenLiteral() { return token.Literal; }