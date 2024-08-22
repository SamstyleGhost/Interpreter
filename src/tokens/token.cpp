#include "token.h"
#include "keywords.h"

// Operator overloaded to print the tokens directly
std::ostream &operator<<(std::ostream &os, const Token &tok) {
	os << int(tok.Type) << " " << tok.Literal << "\n";
	return os;
}

bool isLetter(char ch) {
  return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

bool isDigit(char ch) {
  return '0' <= ch && ch <= '9';
}

Tokenlist lookupIdentifier(std::string literal) {
  if(keywordsMap.find(literal) != keywordsMap.end()) {
    return keywordsMap[literal];
  }

  return Tokenlist::IDENT;
}