- Add Decrement and Increment functionality
- Also +=, -=, *=, /=
- Add support for comments
- To abstract away the methods for two charcter tokens when I add them

- To have function calls, we will have to check for a parenthesis:
  - So, right now, we directly return an IDENT token, but we need to have a token for function call wherein if the direct next token after IDENT is '(' we need to have a function call token