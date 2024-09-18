#pragma once

#include <iostream>
#include <vector>

#include "../ast/ast.h"
#include "../parser/parser.h"

class Program {
  std::vector<Statement> Statements;
  Parser *parser;
  
public:
  Program(Parser *p);
};