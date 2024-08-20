#include "./src/lexer/lexer.h"

int main (int argc, char *argv[]) {
	
	FILE* inputFile = fopen("./tests/test1.txt", "r");

	if(!inputFile) {
		std::cout << "Cannot open file";
		return EXIT_FAILURE;
	}

	Lexer newLexer = Lexer(inputFile);
	
	return 0;
}
