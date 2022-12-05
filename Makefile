OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Evaluator.o Cjt_cursos.o Cjt_problemes.o Cjt_sessions.o Problema.o Usuari.o Sessio.o Curs.o Cjt_usuaris.o

	g++ -o program.exe program.o Evaluator.o Cjt_cursos.o Cjt_problemes.o Cjt_sessions.o Problema.o Usuari.o Sessio.o Curs.o Cjt_usuaris.o 
	
Curs.o: Curs.cc

	g++ -c Curs.cc $(OPCIONS)

Cjt_cursos.o: Cjt_cursos.cc

	g++ -c Cjt_cursos.cc $(OPCIONS)

Usuari.o: Usuari.cc

	g++ -c Usuari.cc $(OPCIONS)

Cjt_usuaris.o: Cjt_usuaris.cc

	g++ -c Cjt_usuaris.cc $(OPCIONS)

Problema.o: Problema.cc

	g++ -c Problema.cc $(OPCIONS)

Cjt_problemes.o: Cjt_problemes.cc

	g++ -c Cjt_problemes.cc $(OPCIONS)

Sessio.o: Sessio.cc BinTree.hh

	g++ -c Sessio.cc $(OPCIONS)

Cjt_sessions.o: Cjt_sessions.cc

	g++ -c Cjt_sessions.cc $(OPCIONS)

Evaluator.o: Evaluator.cc

	g++ -c Evaluator.cc $(OPCIONS)

program.o: program.cc

	g++ -c program.cc $(OPCIONS)

clean:

	rm *.exe 
	rm *.o
	rm *.tar
	
practica.tar: Curs.hh Curs.cc Cjt_cursos.hh Cjt_cursos.cc Problema.hh Problema.cc Cjt_problemes.hh Cjt_problemes.cc Sessio.hh Sessio.cc Cjt_sessions.hh Cjt_sessions.cc Evaluator.hh Evaluator.cc Usuari.hh Usuari.cc Cjt_usuaris.hh Cjt_usuaris.cc program.cc Makefile

	tar -cvf practica.tar Curs.hh Curs.cc Cjt_cursos.hh Cjt_cursos.cc Problema.hh Problema.cc Cjt_problemes.hh Cjt_problemes.cc Sessio.hh Sessio.cc Cjt_sessions.hh Cjt_sessions.cc Evaluator.hh Evaluator.cc Usuari.hh Usuari.cc Cjt_usuaris.hh Cjt_usuaris.cc program.cc Makefile


