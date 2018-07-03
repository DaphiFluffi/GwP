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
	// passt die Zufallszahlen auf den gewuenschen Zahlenbereich an
	boost::uniform_real<> xur (1,4);
	boost::uniform_real<> yur (-2,3);
	boost::uniform_real<> zur (0,1);
	/* Die Grenzen muessen moeglichst eng an dem Koerper liegen, sodass der zu pruefende Bereich möglichst klein bleibt.
	* In einem kleineren Feld liegt die gleiche Anzahl an Punkten naeher aneinander als in einem grossen Feld.
	* Deshalb wird das Ergebnis schon mit weniger Punkten praeziser.*/

	//Erstellen der Datei, in die die Ergebnisse gespeichert werden.
	ofstream datei;
	datei.open ("Monte-Carlo-Integration", ios::out);
	
	// fuert die Berechnung mehrmals mit n vielen Throws durch
	for(bigint n = 1000; n <= 20000000; n = n*2) 
	{
		throws = n; // resettet Throws und Hits
		hits= 0;
		
		// berechnet throws-viele zufaellige Punkte und prueft, ob sie im Körper liegen (hits)
		for(bigint i = 0; i <= throws; i++) 
		{
			// "wuerfelt" neu 
			x = xur(Random);
			y = yur(Random);
			z = zur(Random);
						
			// prueft, ob der Punkt im Koerper liegt
			//result = pow(z,2) + pow(  ( sqrt( pow(x,2)+pow(y,2) ) - 3) , 2);
			result = z*z + pow(  (sqrt( x*x+y*y )-3) , 2);
			
			if( 0.25 <= result && result <= 1){ hits++; } //zaehlt hits hoch falls der Punkt im Koerper liegt 
		}
		
		double volume;
		volume = (15.0)* hits / throws; //Volumen = Volumen des Zielbereichs * Trefferverhaeltnis
		
		// Schreib das Ergebnis in die Monte-Carlo-Intigations datei
		datei <<"Volumen: "<< volume << "\t" << "bei " << n << " Wiederholungen" << endl;

		//Ergebnis ausgeben
	}
	datei.close();
	cout << "Datei erstellt." << endl;
}
