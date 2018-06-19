#include <iostream>   
#include <cmath>
using namespace std;

int main () {
	double ergebnis1 = 0; //Variable in der das Ergebnis der ersten Summe gespeichert wird
	double ergebnis2 = 0; //Variable in der das Ergebnis der zweiten Summe gespeichert wird
	double n; //Variable n aus der Summenformel
	n = pow(2,32)-1;
	for( double i = 1; i <= n; i++){
		ergebnis1 += 1./(i*i); 
	}
	for ( double i = n; i >= 1; i--){
		ergebnis2 += 1./(i*i);
	}
	cout.unsetf (ios::floatfield); //Bewirkt die Ausgabe von 15 Nachkommastellen
	cout.precision(16);
	cout << "Summe von 1 bis n: ";
	cout << ergebnis1 << '\n';
	cout << "Summe von n bis 1: ";
	cout << ergebnis2 << '\n';
}
/*Ausgabe:
 * Summe bis n: 1.644934057834575
Summe bis 1: 1.644934066615396
*/
