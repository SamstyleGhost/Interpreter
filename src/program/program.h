#pragma once

#include <iostream>
#include <vector>
#include <memory> // I will be using unique_ptr to take care of memory allocation and deallocation

#include "../ast/ast.h"
#include "../parser/parser.h"

class Program {
  std::vector<std::unique_ptr<Statement>> statements;
  Parser *parser;
  
public:
  Program(Parser *p);
};