#include "./src/lexer/lexer.h"
#include "./src/parser/parser.h"

int main (int argc, char *argv[]) {
	
	FILE* inputFile = fopen("/home/rohan/Work/Interpreter/tests/test2.txt", "r");

	if(!inputFile) {
		std::cout << "Cannot open file";
		return EXIT_FAILURE;
	}

	Lexer newLexer = Lexer(inputFile);
	Parser newParser = Parser(&newLexer);
	
	return 0;
}
