#include "../tokens/token.h"
#include "lexer.h"

Lexer::Lexer(FILE *input) {
  
  while(!feof(input)) {
    ch = getc(input);
    Token tok;

    switch (ch) {
      case '=':
        tok = newToken(Tokenlist::ASSIGN, ch);
        display(tok);
        break;
      case '+':
        tok = newToken(Tokenlist::PLUS, ch);
        display(tok);
        break;
      case '-':
        tok = newToken(Tokenlist::MINUS, ch);
        display(tok);
        break;
      case '*':
        tok = newToken(Tokenlist::MULTIPLY, ch);
        display(tok);
        break;
      case '/':
        tok = newToken(Tokenlist::DIVIDE, ch);
        display(tok);
        break;
      case ',':
        tok = newToken(Tokenlist::COMMA, ch);
        display(tok);
        break;
      case ';':
        tok = newToken(Tokenlist::SEMICOLON, ch);
        display(tok);
        break;
      case '(':
        tok = newToken(Tokenlist::LPAREN, ch);
        display(tok);
        break;
      case ')':
        tok = newToken(Tokenlist::RPAREN, ch);
        display(tok);
        break;
      case '{':
        tok = newToken(Tokenlist::LBRACE, ch);
        display(tok);
        break;
      case '}':
        tok = newToken(Tokenlist::RBRACE, ch);
        display(tok);
        break;
      case '[':
        tok = newToken(Tokenlist::LBRACK, ch);
        display(tok);
        break;
      case ']':
        tok = newToken(Tokenlist::RBRACK, ch);
        display(tok);
        break;
      default:
        tok = newToken(Tokenlist::ILLEGAL, ch);
        display(tok);
    }
  }
}
  // gives the next character in the input
char Lexer::peekChar(FILE * input) {
  char next = getc(input);
  ungetc(next, input);

  return next;
}

// Will generate a Token object and return it
Token Lexer::newToken(Tokenlist type, char literal) {
  return Token{type, std::to_string(literal)};
}

// Overloaded the function in case the literal value is directly a string
Token Lexer::newToken(Tokenlist type, std::string literal) {
  return Token{type, literal};
}

void Lexer::display(Token tok) {
  std::cout << int(tok.Type) << " " << tok.Literal << "\n";
}