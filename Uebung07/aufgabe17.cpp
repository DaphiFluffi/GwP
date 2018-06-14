#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
	//cout << "Aufgabe 1:" << endl;
	/*for (int i =0; i<12; i++){
	MLCG probe(4,0, 200, 1); //x_0 = 1
	cout << probe.XIplus1() << endl;
	}*/
	//cout << "RANDU von IBM: " << endl;
	ofstream datei;
	datei.open ("ibm.dat", ios::out);
	MLCG probe(65539, 0, pow(2,31), 1); //x_0 = 1
	for (long long int i = 0; i <= 30000; i++){
		for (int x =0; x<=2; x++){
			long long int a = probe.XIplus1();
			datei << to_string(a) << "\t" ;
		}
		datei << endl;
	}
}
//counter examples for analysis free
//Kompilierbefehl: c++ -Wall -o aufgabe17 aufgabe17.cpp Zufallsgenerator.cpp
/*Es faellt auf, dass sobald man mehr als 10 Zhalen ausgibt sich mindestens eine "Zufallszahl"
 *  wiederholt. Oft stimmt die erste mit der elften oder die zweite in der zwoelften ueberein. 
 * In jedem Fall geschieht die Wiederholung so oft wie wir es probiert haben in 10er Schritten.
 * Ausserdem ist uns aufgefallen, dass die Zahlen am Ende der ZUfallszahlen ein Muster bilden, 
 * z.B. dass die Endzahlen sich immer zwischen 4 und 6 abwechseln.*/
