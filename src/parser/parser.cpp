/* 
  ? Instead of running the lexer till EOF is reached, Will do the following steps:
  ? 1. Build a method in the lexer that will return one token at a time.
  ? 2. Remove the switch case lexing from the constructor of the lexer and put it inside that method.
  ? 3. Now, will run the method in the parser one by one until EOF token is received.
  ? 4. This will allow us to actually parse statements as soon as they are received
    * Wonder if the above thing, running the lexer through the parser and parsing a token at a time is valid for both interpreters and compilers or is it only for interpreters
    * Bcoz, just by straight feeling which could be wrong, it could be that compilers will first run the Lexical Analysis of the entire source code, store the tokens and then run the next phases.

*/