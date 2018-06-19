CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe20 aufgabe21

aufgabe20: aufgabe20.cpp
	$(CC) -o aufgabe20 aufgabe20.cpp
	
aufgabe21: aufgabe21.o Zufallsgenerator.o 
	$(CC) -o aufgabe21 aufgabe21.o Zufallsgenerator.o
	
aufgabe21.o: aufgabe21.cpp Zufallsgenerator.hpp
	$(CC) $(CFLAGS) -c aufgabe21.cpp

Zufallsgenerator.o: Zufallsgenerator.cpp Zufallsgenerator.hpp
	$(CC) $(CFLAGS) -c Zufallsgenerator.cpp
	
clean: 
	rm aufgabe20
	rm aufgabe21
	rm *o

	
