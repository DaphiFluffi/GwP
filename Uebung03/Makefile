CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe08 aufgabe07 #Target: all

aufgabe07: aufgabe07.cpp #Target: aufgabe07
	$(CC) $(CFLAGS) -o aufgabe07 aufgabe07.cpp
	
aufgabe08: aufgabe08.o prime.o #Target: aufgabe08
	$(CC) -o aufgabe08 aufgabe08.o prime.o
	
aufgabe08.o: aufgabe08.cpp prime.hpp #Target:aufgabe08.o
	$(CC) $(CFLAGS) -c aufgabe08.cpp

prime.o: prime.cpp  #Target:prime.o
	$(CC) $(CFLAGS) -c prime.cpp

clean: #Target: clean
	rm aufgabe07
	rm aufgabe08 
	rm *.o
