CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe23

#aufgabe23: aufgabe23.cpp
#	$(CC) -o aufgabe23 aufgabe23.cpp
	
aufgabe23: aufgabe23.o derive.o 
	$(CC) -o aufgabe23 aufgabe23.o derive.o
	
aufgabe23.o: aufgabe23.cpp derive.hpp
	$(CC) $(CFLAGS) -c aufgabe23.cpp

derive.o: derive.cpp derive.hpp
	$(CC) $(CFLAGS) -c derive.cpp
	
clean: 
	rm aufgabe23
	#rm aufgabe21
	rm *o

	
