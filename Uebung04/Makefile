CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe10 #Target: all

#aufgabe07: aufgabe07.cpp #Target: aufgabe07
#	$(CC) $(CFLAGS) -o aufgabe07 aufgabe07.cpp
	
aufgabe10: aufgabe10.o swap.o #Target: aufgabe08
	$(CC) -o aufgabe10 aufgabe10.o swap.o
	
aufgabe10.o: aufgabe10.cpp swap.hpp #Target:aufgabe10.o
	$(CC) $(CFLAGS) -c aufgabe10.cpp

swap.o: swap.cpp  #Target:swap.o
	$(CC) $(CFLAGS) -c swap.cpp

clean: #Target: clean
	#rm aufgabe07
	rm aufgabe10 
	rm *.o

