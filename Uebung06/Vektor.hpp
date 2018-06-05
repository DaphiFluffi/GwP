#include <iostream>
#include <string>

using namespace std;

#ifndef VEKTOR_HPP
#define VEKTOR_HPP 1

class Vektor
{
	double x, y, z; //Klassenvariablen fuer x, y, z 
	public:
	Vektor (double x_= 0, double y_=0, double z_=0); //Konstruktordeklaration. Da die Klasse aus Vektor.cpp ausgelagert wurde muessen die default-Werte hier eingetragen werden
	double betrag (); //Methodenkopf von der Ableitungsfunktion. Hier steht nur der Rueckgabetyp und der Name der Funktion
	friend Vektor operator + (Vektor a, Vektor b); //Ueberladen des +-Operators. friend bewirkt, dass man die Uerberladung ausserhalb der Klasse machen kann, weil Funktionen innerhalb der Klasse maximal einen Parameter uebergeben bekommen duerfen.
	friend Vektor operator * (Vektor a, Vektor b);
	friend double skalar(Vektor a, Vektor b);
	friend double spat(Vektor a, Vektor b, Vektor c);
	friend ostream& operator << (ostream& Stream, Vektor const& a); //Ueberladen von cout <<
}; 

#endif


