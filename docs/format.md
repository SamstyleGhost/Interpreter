# Format of the language
Thinking of the following format for the language:
- Types of variables: 
  - num -> int
  - dec -> float / double
  - bool -> bool
  - str -> string
  - char -> char
- Format for input / output:
  - Input: input()
  - Output: print()
- For conditionals:
  - If-else
- Comments:
  - Single Line Comments: //
  - Multi Line Comments: /* */ 
- Operations:
  - Addition +
  - Subtraction -
  - Multiplication *
  - Division /
  - Modulo %
  - Lesser than <
  - Greate than >
  - Less than equal to <=
  - Greater than equal to >=
  - Equal ==

```

let a = 3; // num
let b : string;

function fun1() {
  print("fun1 called");
}

function fun2(c : num, d : num) returns bool {
  if(c > d)
    return true;

  return false;
}

fun1();

const e = fun2(a, 4);
print("Value of e is: ${e}");

```
