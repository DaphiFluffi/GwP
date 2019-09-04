#include <iostream>
#include <cmath>

/*Funktion, die bestimmt ob eine uebergebene Zahl eine Primzahl ist.
 * Sie gibt einen Wahrheitswert zurueck und bekommt eine unsigned Integer-Variable "zahl" uebergeben*/
bool isPrime (unsigned int zahl)
{
	if (zahl <= 1){ //Zahlen <= 1 werden ausgeschlossen, weil sie keine Primzahlen sind, jedoch vom Algorithmus als solche ausgegeben werden wuerden.
		return false;
	}else{
		for (unsigned int p = 2 ; p <= sqrt(zahl) ; p++){ //die Bedingung der for-Schleife leitet sich aus der Probedivision, einem Prizahltest, ab
			if (zahl % p == 0){ //Modulo-Operator (%) prueft, ob die uebergebene Zahl restlos durch p teilbar ist
				return false; 
				}
		}
		return true;
	}
}

/*Funktion zur Bestimmung der n.Primzahl. Uebergeben wird der integer n, 
 * von dem abhaengt, welche Primzahl gesucht wird.*/
int nPrime (int n)
{
	int counter = 0; //Zaehlervariable, die nur inkrementiert wird, falls isPrime() in der if-Bedingung true zurueckgibt, also an der Stelle i eine Primzahl vorliegt.
	int i = 1; //Zaehlervariable, die bei jedem Durchlauf der while-Schleife unabhaengig von dem Ergebnis von isPrime() inkementiert wird.
	while (counter < n){
		if (isPrime(i)){ //Aufruf der isPrime()-Funktion
		  counter ++;
		}
	  i++;
	}
	return i-1;
}
