TARGET = bin/interpreter
CFLAGS = -o
ODIR = bin/.o_files

all: main lexer token keywords parser ast program
	g++ -o bin/interpreter $(ODIR)/main.o $(ODIR)/lexer.o $(ODIR)/token.o $(ODIR)/keywords.o $(ODIR)/parser.o $(ODIR)/ast.o $(ODIR)/program.o

main: main.cpp
	g++ -c -o bin/.o_files/main.o main.cpp

lexer: src/lexer/lexer.cpp
	g++ -c -o bin/.o_files/lexer.o src/lexer/lexer.cpp

token: src/tokens/token.cpp
	g++ -c -o bin/.o_files/token.o src/tokens/token.cpp

keywords: src/tokens/keywords.cpp
	g++ -c -o bin/.o_files/keywords.o src/tokens/keywords.cpp

parser: src/parser/parser.cpp
	g++ -c -o bin/.o_files/parser.o src/parser/parser.cpp

ast: src/ast/ast.cpp
	g++ -c -o bin/.o_files/ast.o src/ast/ast.cpp

program: src/program/program.cpp
	g++ -c -o bin/.o_files/program.o src/program/program.cpp

clean:
	rm $(ODIR)/main.o $(ODIR)/lexer.o $(ODIR)/token.o $(ODIR)/keywords.o $(ODIR)/parser.o $(ODIR)/ast.o $(ODIR)/program.o
