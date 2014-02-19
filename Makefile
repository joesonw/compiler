CXX = g++ $(CFLAGS)
CFLAGS = -std=c++11 -g

tube7: parser.tab.o lexer.o vtable.o ast.o
	$(CXX) -o tube7 parser.tab.o lexer.o vtable.o ast.o -ll -ly -g
vtable.o: vtable.h vtable.cpp
	$(CXX) -Wall -c vtable.cpp
ast.o: ast.h ast.cpp lib.h
	$(CXX) -Wall -c ast.cpp
parser.tab.c: parser.y driver.h
	bison -b parser -d parser.y
lexer.c: lexer.l driver.h
	flex -olexer.c lexer.l
parser.tab.o: parser.tab.c driver.h icstruct.h ast.h
	$(CXX) -Wall -c parser.tab.c
lexer.o: lexer.c
	$(CXX) -Wall -c lexer.c
clean:
	rm parser.tab.h lexer.c lex.yy.cc tube7 parser.tab.c *.o *.tube.diff *.tmp -f

