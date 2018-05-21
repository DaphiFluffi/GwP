#include "swap.hpp" //Einbinden der swap.hpp, damit man auf die swap-Funktionen zugreifen kann
#include <iostream>

using namespace std;

int main ()
{
	int zahl1, zahl2; //Deklarieren der zwei Integer zahl1 und zahl2
	//Einlesen der Werte fuer zahl1 und zahl2 vom User:
	cout << "1.Zahl: "; 
	cin >> zahl1;
	cout << "2.Zahl: ";
	cin >> zahl2;
	
	cout << "Ergebnisse von ref_swap(): " << endl;
	//Erstellen von References fuer zahl1 und zahl2:
	int& ref_zahl1 = zahl1; 
	int& ref_zahl2 = zahl2; 
	swap_ref(ref_zahl1, ref_zahl2); //Aufrufen der Funktion swap_ref() mit Uebergabe von ref_zahl1 und ref_zahl2
	//Ausgabe der vertauschten References:
	cout << "ref_zahl1 = " << ref_zahl1 << endl;
	cout << "ref_zahl2 = " << ref_zahl2 << endl;

	cout << "Ergebnisse von ref_ptr(): " << endl;
	//erneutes Aufrufen von swap_ref() zum "Zuruecktauschen" der Werte von zahl1 und zahl 2, 
	//damit swap_ptr() dieselben Anfangswerte hat wie swap_ref():
	swap_ref(ref_zahl1, ref_zahl2); 
	//Erstellen von Pointern, die auf die References fuer zahl1 und zahl2 zeigen:
	int* ptr_zahl1 = &ref_zahl1;
	int* ptr_zahl2 = &ref_zahl2;
	
	swap_ptr(ptr_zahl1, ptr_zahl2) ; //Aufrufen von swap_ptr()
	//Ausgabe der Werte auf die die Pointer nach swap_ptr() zeigen:
	cout << "*ptr_zahl1 = " << *ptr_zahl1 << endl; 
	cout << "*ptr_zahl2 = " << *ptr_zahl2 << endl;
}
