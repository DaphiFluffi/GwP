CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe10 aufgabe11 #Target: all

aufgabe11: aufgabe11.cpp #Target: aufgabe11
	$(CC) $(CFLAGS) -o aufgabe11 aufgabe11.cpp
	
aufgabe10: aufgabe10.o swap.o #Target: aufgabe10
	$(CC) -o aufgabe10 aufgabe10.o swap.o
	
aufgabe10.o: aufgabe10.cpp swap.hpp #Target:aufgabe10.o
	$(CC) $(CFLAGS) -c aufgabe10.cpp

swap.o: swap.cpp  #Target:swap.o
	$(CC) $(CFLAGS) -c swap.cpp

clean: #Target: clean
	rm aufgabe11
	rm aufgabe10 
	rm *.o

