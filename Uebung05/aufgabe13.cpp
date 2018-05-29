#include "bitmuster.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*Zaehlt die ausgebbaren Werte aus der ASCII-Tabelle hoch*/
	for(int i = 32; i < 128 ; i++){	
		cout << char(i) << "\t";
		cout << dec << i << "\t"; 	//Fuert zur Ausgabe von i in Dezimal
		cout << hex << i << "\t";   //Fuert zur Ausgabe von i in Hexadezimal
		cout << bitmuster(i) << endl;
	}
}
