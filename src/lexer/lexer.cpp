#include "../tokens/token.h"
#include "lexer.h"

Lexer::Lexer(FILE *input) {
  while (!feof(input)) {
    ch = getc(input);

    skipWhitespace(input);

    Token tok;

    switch (ch) {
      case '=':
        if (peekChar(input) == '=') {
          tok = newToken(Tokenlist::EQ, "==");
          ch = getc(input);
        } else if (peekChar(input) == '<') {
          tok = newToken(Tokenlist::LTE, "=<");
          ch = getc(input);
        } else {
          tok = newToken(Tokenlist::ASSIGN, ch);
        }
        break;
      case '+':
        tok = newToken(Tokenlist::PLUS, ch);
        break;
      case '-':
        tok = newToken(Tokenlist::MINUS, ch);
        break;
      case '!':
        if (peekChar(input) == '=') {
          tok = newToken(Tokenlist::NEQ, "!=");
          ch = getc(input);
        } else {
          tok = newToken(Tokenlist::BANG, ch);
        }
        break;
      case '*':
        tok = newToken(Tokenlist::ASTERISK, ch);
        break;
      case '/':
        tok = newToken(Tokenlist::SLASH, ch);
        break;
      case '<':
        tok = newToken(Tokenlist::LT, ch);
        break;
      case '>':
        if(peekChar(input) == '=') {
          tok = newToken(Tokenlist::GTE, ">=");
          ch = getc(input);
        } else {
          tok = newToken(Tokenlist::GT, ch);
        }
        break;
      case ',':
        tok = newToken(Tokenlist::COMMA, ch);
        break;
      case ';':
        tok = newToken(Tokenlist::SEMICOLON, ch);
        break;
      case '(':
        tok = newToken(Tokenlist::LPAREN, ch);
        break;
      case ')':
        tok = newToken(Tokenlist::RPAREN, ch);
        break;
      case '{':
        tok = newToken(Tokenlist::LBRACE, ch);
        break;
      case '}':
        tok = newToken(Tokenlist::RBRACE, ch);
        break;
      case '[':
        tok = newToken(Tokenlist::LBRACK, ch);
        break;
      case ']':
        tok = newToken(Tokenlist::RBRACK, ch);
        break;
      default:
        if (isLetter(ch)) {
          readLetters(input, &tok);
        } else if (isDigit(ch)) {
          readDigits(input, &tok);
        } else if (ch == EOF) {
          tok = newToken(Tokenlist::EOFC, ch);
        } else {
          tok = newToken(Tokenlist::ILLEGAL, ch);
        }
    }

    std::cout << tok;
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
  return Token{type, std::string(1, literal)}; // * Here, I had initially used std::to_string instead of std::string(1,c), that lead to me getting the ASCII numbers of the characters as strings instead of the actual characters.
}

// Overloaded the function in case the literal value is directly a string
Token Lexer::newToken(Tokenlist type, std::string literal) {
  return Token{type, literal};
}

void Lexer::skipWhitespace(FILE* input) {
  while(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') ch = getc(input);
}

void Lexer::readLetters(FILE* input, Token* tok) {
  do {
    buffer.push_back(ch);
    ch = getc(input);
  } while (isLetter(ch));
  tok->Literal = buffer;
  tok->Type = lookupIdentifier(buffer);
  buffer = "";
  ungetc(ch, input); // Added because there was an error that did not process the next character after the digits and letter
}

void Lexer::readDigits(FILE* input, Token* tok) {
  do {
    buffer.push_back(ch);
    ch = getc(input);
  } while (isDigit(ch));
  tok->Literal = buffer;
  tok->Type = Tokenlist::INT;
  buffer = "";
  ungetc(ch, input); // Added because there was an error that did not process the next character after the digits and letters
}