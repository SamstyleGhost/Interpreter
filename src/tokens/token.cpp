#include "token.h"

// Operator overloaded to print the tokens directly
std::ostream &operator<<(std::ostream &os, const Token &tok) {
	os << int(tok.Type) << " " << tok.Literal << "\n";
	return os;
}