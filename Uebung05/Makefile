CC = c++ #Compiler

CFLAGS = -Wall #Optionen

all: aufgabe12 aufgabe13 aufgabe14 #Target: all

aufgabe13: aufgabe13.cpp #Target: aufgabe13
	$(CC) $(CFLAGS) -o aufgabe13 aufgabe13.cpp
	
aufgabe14: aufgabe14.cpp #Target: aufgabe14
	$(CC) $(CFLAGS) -o aufgabe14 aufgabe14.cpp
	
aufgabe12: aufgabe12.o bitmuster.o #Target: aufgabe12
	$(CC) $(CFLAGS) -o aufgabe12 aufgabe12.o bitmuster.o
	
aufgabe12.o: aufgabe12.cpp bitmuster.hpp #Target:aufgabe12.o
	$(CC) $(CFLAGS) -c aufgabe12.cpp

bitmuster.o: bitmuster.cpp  #Target:bitmuster.o
	$(CC) $(CFLAGS) -c bitmuster.cpp

clean: #Target: clean
	rm aufgabe12
	rm aufgabe13
	rm aufgabe14 
	rm *.o
