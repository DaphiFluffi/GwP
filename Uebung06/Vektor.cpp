#include "Vektor.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*Definition des Konstruktors aus der Klasse Vektor.*/
Vektor::Vektor(double x_, double y_, double z_)
{
	x = x_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	y = y_;
	z = z_;
}

double Vektor::betrag ()
{
	return sqrt(x*x+y*y+z*z);
}
//das ist unser kompilierbefehl: c++ -Wall -o aufgabe15 aufgabe15.cpp Vektor.cpp
Vektor operator + (Vektor a, Vektor b) //Ueberladen des +-Operators //deklaration der friend-Funktion in der vektor.hpp
	{
		Vektor ergebnis;
		ergebnis.x = a.x + b.x;
		ergebnis.y = a.y + b.y;
		ergebnis.z = a.z + b.z;
		return ergebnis;
	}

Vektor operator * (Vektor a, Vektor b) //Ueberladen des +-Operators //deklaration der friend-Funktion in der vektor.hpp
	{
		Vektor ergebnis;
		ergebnis.x = a.y * b.z - a.z * b.y;
		ergebnis.y = a.z * b.x - a.x * b.z;
		ergebnis.z = a.x * b.y - a.y * b.x;
		return ergebnis;
	}

double skalar(Vektor a, Vektor b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z ;
}
//Spat Funktion nimmt 3 Vektoren entgegen und gibt deren Spatprodukt zurück
double spat(Vektor a, Vektor b, Vektor c)
{
	return skalar( (a * b), c);
}

/* Ueberladen des Cout << Operators
 * Da der << Operator an das ostream Modul gebunden ist muss dieses mit in die 
 * Funktionsdefinition eingebunden werden. Deshalb gibt die Funktion als Rueckgabewert
 * eine Reference an die cout Klasse zurueck. Indem der momentane Stand der cout
 * von der Funktion mit entgegen genommen und mit dem neuen Str  des angegebenen Vektors 
 * ergaenst zurückgegeben wird.
*/
ostream& operator << (ostream& Stream, Vektor const& a)
{
	return Stream << '[' << a.x << ',' << a.y << ',' << a.z << ']';
}
