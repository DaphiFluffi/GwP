#include <iostream>
#include <cmath>

using namespace std;

/* Rekursiv definierte Funktion zur Berechnung Fakultaet.  
 * Uebergeben wird das Parameter "fak" vom Typ unsigned Integer, von dem die Fakultaet berechnet werden soll.*/
unsigned int fakultaet (unsigned int fak)
{
	if (fak == 0) { //Abbruchbedingung (die Fakultaet von 0 muss 1 sein)
		return 1;
	} else {
		return fak * fakultaet(fak - 1); //rekursiver Aufruf der fakultaet-Funktion
	}
}
/*Rekursive Funktion zur Berechnung der Potenz. Uebergeben werden ein Double x, 
 * welches die Basis und ein unsigned Integer n, welcher den Exponenten repraesentiert. 
 * Die Funkion berechnet die Gleichung x^n.*/
double power (double x, unsigned int n)
{
	if(n == 0) { //erste Abbruchbedingung (x^0 = 1)
		return 1;
	}else if(n == 1){ //zweite Abbruchbedingung (x^1 = x)
		return x;
	}else{
		return x * power(x,n-1); //rekursiver Aufruf der Power-Funktion		
	}
}
/* Funktion zur Berechnung von e^x konstruiert nach der Reihendarstellung der Exponentialfunktion.
Uebergeben wird das Double x, welches den Exponenten von e^x darstellt und "steps=5", 
* welches ein optionaler Parameter ist, der bestimmt bis zu welcher oberen Schranke die Berechnung fortgefuert wird.*/
double myExp (double x, unsigned int steps = 5)
{
	double exp = 0; //in dem double exp wird das Ergenis er Summenformel in der for-Schleife gespeichert
	for(unsigned int n = 0; n <= steps; n++){
		exp += power(x,n)/fakultaet(n); //Aufruf der Funktionen fakultaet() und power()
	}
	return exp;
}

int main ()
{
	double x = 0; //im double a wird die vom User eingeggebene Zahl gespeichert
	cout << "Exponent: ";
	cin >> x;
	double ergebnis = myExp(x);  //im Double ergebnis wird der Wert aus der myExp()-Funktion gespeichert
	cout << "Ergebnis: " << endl;
	cout << ergebnis << endl; //Ausgabe des Ergebnisses
}
/*Bildet man die Differenz aus dem Ergebnis von der exp-Funktion aus der cmath-Bibliothek und 
 * unserer myExp-Funktion, laesst sich feststellen, dass die Differenz mit zunehmenden Exponenten
 * vermutlich sogar exponentiell, aber auf jeden Fall rapide zunimmt. 
 * So betraegt die Abweichung bei e^7, sofern steps auf 5 gestellt ist, 
 * schon 766,866. Erhoet man steps auf 10 wird e^x praeziser berechnet, 
 * sodass an derselben Stelle nur eine Abweichung von 108 zustande kommt. 
 * Als Erfahrungswert hat sich nach laengerem Probieren herausgestellt, 
 * dass mit Erhoehen von steps zwar die Abweichung von der exp-Funktion geringer wird, 
 * jedoch je hoeher steps gewaehlt wird, umso schneller der Exponent erreicht ist, 
 * bei dem die Funktion fehlerhafte Werte ausgibt.
 * Beispiel: Bis steps = 12 lassen sich die Exponenten bis 10 mit relativ geringen Abweichungen bestimmen. 
 * Beginnend bei steps = 13, gibt die Funktion schon bei Exponenten ueber 2 komplett falsche Werte aus,
 * wahrend bei Exponenten bis 2 sehr geringe Differenzen entstehen.
 * Diese Probleme entstehe u.a. dadurch, dass z.B. alleine die fakultaet-Funktion, 
 * auf die man in myExp zurückgreifen muss, nur bis 12! richtige Werte ausgibt, 
 * weil dann die Speicherkapazitaet von unsigned int mit dem Ergebnis ueberschritten wird.
 * Als Loesungsansatz habe ich probiert, den Datentypen auf unsigned long long int umszustellen, 
 * sodass ich 8 Byte Speicherkapaziaet hatte. 
 * Diese Aenderung bewirkte aber nur, dass die Fakultaeten bis einschlilich 20! richtig berechnet wurden.
 * Das Problem mit der Speicherkapazitaet setzt sich auch in der power-Funktion fort. 
 * Wuerde man die vorhandenen Datentypen durch welche mit hoeherer Speicherkapaziaet austauschen, 
 * koennte man erneut richtige Ergebnisse bei hoeheren Zahlen erzielen, 
 * jedoch wie zuvor nur bis zu einer gewissen Schranke.*/
