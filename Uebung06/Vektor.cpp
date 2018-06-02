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
Vektor operator+ (Vektor a, Vektor b) //Ueberladen des +-Operators //deklaration der friend-Funktion in der vektor.hpp
	{
		Vektor ergebnis;
		ergebnis.x = a.x + b.x;
		ergebnis.y = a.y + b.y;
		ergebnis.z = a.z + b.z;
		return ergebnis;
	}
