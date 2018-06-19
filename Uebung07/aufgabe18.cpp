#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

typedef long long unsigned int bigint; 

int main (){
	ofstream datei;
	datei.open ("xorshift.dat", ios::out); //Oeffnen der Datei xorshift.dat zum Schreiben
	randGen probe(4101842887655102017); //Erstellen eines randGen-Objekts aus der randGen Klasse aus der Zufallsgenerator.hpp
	for (int i = 0; i <= 30000; i++){
		for (int x =0; x<=2; x++){
			bigint zufallszahl = probe.mlcgXorshift(); //Speichern der Zufallszahlen aus dem Generator in einer Variable zufallszahl
			datei << to_string(zufallszahl) << "\t" ; //Casten der zufallszahl-Variable in string, damit sich die Zufallszahlen in der Datei speichern lassen.
		}
		datei << endl;
	}
}
