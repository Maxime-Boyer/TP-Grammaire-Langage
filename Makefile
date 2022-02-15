all: analyse


analyse: lexer.o symbole.o etat.o automate.o main.o
	g++ -o analyse lexer.o symbole.o etat.o automate.o main.o

lexer.o: lexer.cpp lexer.h
	g++ -o lexer.o -c lexer.cpp

symbole.o: symbole.cpp symbole.h
	g++ -o symbole.o -c symbole.cpp

etat.o: Etat.cpp Etat.h
	g++ -o etat.o -c Etat.cpp

automate.o: Automate.cpp Automate.h
	g++ -o automate.o -c Automate.cpp

main.o: main.cpp symbole.h lexer.h Etat.h
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o

mrproper: clean
	rm -rf analyse
