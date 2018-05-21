#include "swap.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int zahl1, zahl2; //Deklarieren der zwei Integer zahl1 und zahl2
	cout << "1.Zahl: "; //Einlesen von zahl1 und zahl2
	cin >> zahl1;
	cout << "2.Zahl: ";
	cin >> zahl2;
	
	cout << "Ergebnisse von ref_swap(): " << endl;
	int& ref_zahl1 = zahl1; //Erstellen von References fuer zahl1 und zahl2
	int& ref_zahl2 = zahl2; 
	cout << swap_ref(ref_zahl1, ref_zahl2) << endl; //Aufrufen der Funktion swap_ref() mit Uebergabe von ref_zahl1 und ref_zahl2
	cout << "Neuer Wert von ref_zahl1: " << ref_zahl1 << endl; //Ausgabe der vertauschten References
	cout << "Neuer Wert von ref_zahl2: " << ref_zahl2 << endl;

	cout << "Ergebnisse von ref_ptr(): " << endl;
	/*erneutes Aufrufen von swap_ref() zum "Zuruecktauschen" der Werte von zahl1 und zahl 2, 
	 * damit swap_ptr() dieselben Anfangswerte hat wie swap_ref(): */
	cout << swap_ref(ref_zahl2, ref_zahl1) << endl; 
	int* ptr_zahl1 = &ref_zahl1; //Erstellen von Pointern, die auf die References fuer zahl1 und zahl2 zeigen
	int* ptr_zahl2 = &ref_zahl2;
	
	cout <<  swap_ptr(ptr_zahl1, ptr_zahl2) << endl; //Aufrufen von swap_ptr()
	cout << "Neuer Wert von ptr_zahl1: " << *ptr_zahl1 << endl; //Ausgabe der Werte auf die die Pointer nach swap_ptr() zeigen
	cout << "Neuer Wert von ptr_zahl2: " << *ptr_zahl2 << endl;
}
