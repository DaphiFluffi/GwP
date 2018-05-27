CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe12 aufgabe13 aufgabe14 

aufgabe13: aufgabe13.cpp 
	$(CC) $(CFLAGS) -o aufgabe13 aufgabe13.cpp
	
aufgabe14: aufgabe14.cpp 
	$(CC) $(CFLAGS) -o aufgabe14 aufgabe14.cpp
	
aufgabe12: aufgabe12.o bitmuster.o 
	$(CC) -o aufgabe12 aufgabe12.o bitmuster.o
	
aufgabe12.o: aufgabe12.cpp bitmuster.hpp 
	$(CC) $(CFLAGS) -c aufgabe12.cpp

bitmuster.o: bitmuster.cpp 
	$(CC) $(CFLAGS) -c bitmuster.cpp

clean: 
	rm aufgabe12
	rm aufgabe13
	rm aufgabe14 
	rm *.o
