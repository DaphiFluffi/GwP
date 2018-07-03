#include "derive.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*Test-Klasse, die f(x) = x^3 zurueckgibt. Zum Testen des Templates*/
class Test 
{
	double x;
	public:
	double operator () (double x) 
	{
		return x*x*x;
	}
};

/*Funktion-Klasse. die f(x)= x^2 + 2*x + 3 zurueckgibt. Zum Testen des Templates.*/
class Funktion  
{
	public:
		double operator() (double x)
		{
			return x*x + 2*x + 3;
		}
};

int main() 
{
	Test test; //Erstellen eines Test-Objektes
	Ableitung <Test> beispiel(test); //Erstellen eines Ableitungsobjekts 
	cout << "Klasse Test (einfache Differentiation): " << beispiel(2.0) << endl; //Ausgabe der Ableitung des Beispiel-Objekts (berechnet mit der einfachen Differentiation)
	cout << "Klasse Test (symmetrische Differentiation): " << beispiel(2.0,12) << endl; //Ableitung mit symmetrischer Differentiation
	//dasselbe Prozedere mit der Funktion-Klasse
	Funktion func;
	Ableitung<Funktion> funktion(func);
	cout << "Klasse Funktion (einfache Differentiation): " << funktion(5.5) << endl;
	cout << "Klasse Funktion (symmetrische Differentiation): " << funktion(5.5,1) << endl;
}
