CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe17 aufgabe18 aufgabe19

aufgabe19: aufgabe19.o Zufallsgenerator.o
	$(CC) -o aufgabe19 aufgabe19.o Zufallsgenerator.o
	
aufgabe18: aufgabe18.o Zufallsgenerator.o
	$(CC) $(CFLAGS) -o aufgabe18 aufgabe18.cpp
	
aufgabe17: aufgabe17.cpp
	$(CC) $(CFLAGS) -o aufgabe17 aufgabe17.cpp
	
aufgabe19.o: aufgabe19.cpp Zufallsgenerator.hpp
	$(CC) $(CFLAGS) -c aufgabe19.cpp
	
aufgabe18.o: aufgabe18.cpp Zufallsgenerator.hpp
	$(CC) $(CFLAGS) -c aufgabe18.cpp
	
Zufallsgenerator.o: Zufallsgenerator.cpp Zufallsgenerator.hpp
	$(CC) $(CFLAGS) -c Zufallsgenerator.cpp
	
clean: 
	rm aufgabe17
	rm aufgabe18
	rm aufgabe19
	rm *.o
