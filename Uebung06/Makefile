CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe15 aufgabe16

aufgabe15: aufgabe15.o Vektor.o
	$(CC) -o aufgabe15 aufgabe15.o Vektor.o
	
aufgabe16: aufgabe16.cpp
	$(CC) $(CFLAGS) -o aufgabe16 aufgabe16.cpp
	
aufgabe15.o: aufgabe15.cpp Vektor.hpp
	$(CC) $(CFLAGS) -c aufgabe15.cpp
	
Vektor.o: Vektor.cpp Vektor.hpp
	$(CC) $(CFLAGS) -c Vektor.cpp
	
clean: 
	rm aufgabe15
	rm aufgabe16
	rm *.o
