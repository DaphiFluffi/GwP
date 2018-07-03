#include <boost/random.hpp>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

typedef long long unsigned int bigint;

int main()
{
	//Speicherplaeze zum mitzaehlen der Treffer und Versuche
	bigint throws;
	bigint hits;
	//Speicherplaeze fuer die Zufallszahlen und das Ergebnis der Funktion
	double result;

	double x;
	double y;
	double z;
	//erstellen der Zufallszahlen (Objekte)
	boost::mt19937 Random;
	boost::uniform_real<> x1 (1,4);
	boost::uniform_real<> y1 (-2,3);
	boost::uniform_real<> z1 (0,1);
	
	//erstellen der Datei, in die die Ergebnisse gespeichert werden.
	ofstream datei;
	datei.open ("Monte-Carlo-Intigration", ios::out);
	
	// fuert die Berechnung mehrmals mit n vielen Throws durch
	for(bigint n = 1000; n <= 10000; n = n*2) 
	{
		throws = n; // restettet Throws und Hits
		hits= 0;
		
		// berechnet throws viele zufaellige Punkte und prueft, ob sie im Körper liegen (hits)
		for(bigint i = 0; i <= throws; i++) 
		{
			// "wuerfelt" neu 
			x = x1(Random);
			y = y1(Random);
			z = z1(Random);
			cout << x << "\n" << y << "\n" << z << "\n"<< endl;
			/* Die Grenzen muessen möglichst eng an dem Koerper liegen, so das der zu pruefende bereich möglichst klein bleibt.
			 * In einem kleineren Feld liegt die gleiche Anzahl an Punkten naeher aneinander als in einem grossen Feld.
			 * Deshalb wird das Ergebnis schon mit weniger Punkten praeziser.*/
			
			// prueft ob der Punkt im Koerper liegt
			//result = pow(z,2) + pow(  ( sqrt( pow(x,2)+pow(y,2) ) - 3) , 2);
			result = z*z + pow(  (sqrt( x*x+y*y )-3) , 2);
			
			if( 0.25 <= result && result <= 1){ hits++; } //zaehlt hits hoch falls der punkt im Koerper liegt 
		}
		
		double volume;
		volume = (15.0)* hits / throws; // Volumen des Zielbereichs/trefferverhaelniss
		
		// Schreib das Ergebnis in die Monte-Carlo-Intigations datei
		datei <<"volumen: "<< volume << "\t" << "bei " << n << " Wiederholungen" << endl;

		//Ergebnis ausgeben
	}
	datei.close();
	cout << "Datei erstellt." << endl;
}
