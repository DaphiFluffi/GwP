#include "prime.hpp" //Einbinden von prime.hpp, um auf die nPrime()-Fuktion zugreifen zu koennen
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	unsigned int n = 1; //In n wird die vom User eingegebene Zahl gespeichert.
	cout << "Zum Beenden 0 eingeben" << endl;
	for (;;){ //Endlosschleife fuer die Abfrage
	  cout << "Die wie vielte Primzahl suchen Sie? ";
	  cin >> n;
		if (n == 0){ //Abfrage wird mit der Eingabe 0 vom User beendet
			break;
		}else{
			cout << "Die " << n << ".Primzahl ist: " << nPrime(n) << endl; //Ausgabe der n.Primzahl
		}
	}
}
