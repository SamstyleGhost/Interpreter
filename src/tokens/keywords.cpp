#include "keywords.h"

std::unordered_map<std::string, Tokenlist> keywordsMap = {
  {"fn", Tokenlist::FUNCTION},
  {"let", Tokenlist::LET},
  {"return", Tokenlist::RETURN},
  {"true", Tokenlist::TRUE},
  {"false", Tokenlist::FALSE},
  {"if", Tokenlist::IF},
  {"else", Tokenlist::ELSE},
};