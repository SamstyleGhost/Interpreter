#include "../tokens/token.h"
#include "lexer.h"

Lexer::Lexer(FILE *inputFile) {
  input = inputFile;
}

Token* Lexer::generateToken() {
  ch = getc(input);

  skipWhitespace();

  Token *tok = nullptr;

  switch (ch) {
    case '=':
      if (peekChar() == '=') {
        tok = newToken(Tokenlist::EQ, "==");
        ch = getc(input);
      } else if (peekChar() == '<') {
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
      if (peekChar() == '=') {
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
      if (peekChar() == '=') {
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
        tok = readLetters();
      } else if (isDigit(ch)) {
        tok = readDigits();
      } else if (ch == EOF) {
        tok = newToken(Tokenlist::EOFC, ch);
      } else {
        tok = newToken(Tokenlist::ILLEGAL, ch);
      }
  }
  if (tok == nullptr) {
    std::cerr << "Error: Token was not created successfully!" << std::endl;
    // Handle error accordingly
  } else {
    std::cout << *tok;
  }
  
  return tok;
}

// gives the next character in the input
char Lexer::peekChar() {
  char next = getc(input);
  ungetc(next, input);

  return next;
}

// Will generate a Token object and return it
Token* Lexer::newToken(Tokenlist type, char literal) {
  Token *tok = new Token{type, std::string(1, literal)};
  if(!tok) {
    std::cerr << "Memory not allocated\n";
  }
  return tok; // * Here, I had initially used std::to_string instead of std::string(1,c), that lead to me getting the ASCII numbers of the characters as strings instead of the actual characters.
}

// Overloaded the function in case the literal value is directly a string
Token* Lexer::newToken(Tokenlist type, std::string literal) {
  return new Token{type, literal};
}

void Lexer::skipWhitespace() {
  while(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') ch = getc(input);
}

Token* Lexer::readLetters() {
  do {
    buffer.push_back(ch);
    ch = getc(input);
  } while (isLetter(ch));
  Tokenlist tp = lookupIdentifier(buffer);
  Token *tok = new Token{tp, buffer};
  buffer = "";
  ungetc(ch, input); // Added because there was an error that did not process the next character after the digits and letter
  return tok;
}

Token* Lexer::readDigits() {
  do {
    buffer.push_back(ch);
    ch = getc(input);
  } while (isDigit(ch));
  Token *tok = new Token{Tokenlist::INT, buffer};
  buffer = "";
  ungetc(ch, input); // Added because there was an error that did not process the next character after the digits and letters
  return tok;
}