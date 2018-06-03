#include <iostream>
#include <string>

using namespace std;

#ifndef VEKTOR_HPP
#define VEKTOR_HPP 1

class Vektor
{
	double x, y, z; //Klassenvariablen fuer x, y, z 
	public:
	Vektor (double x_= 0, double y_=0, double z_=0); //wichtig: weil die konstruktordeklaration aus der Vektor.cpp ausgelagert wurde muessen die default werte hier eingetragen werden !
	double betrag (); //Methodenkopf von der Ableitungsfunktion hier steht nur der ruekcgabetyp und der name der funktion
	friend Vektor operator + (Vektor a, Vektor b); //Ueberladen des +-Operators // friend bewirkt, dass man die Uerberladung ausserhalb der klasse machen kann weil in der kasse nimmt ne funktion 0-1 argument
	friend Vektor operator * (Vektor a, Vektor b);
	friend double skalar(Vektor a, Vektor b);
	friend double spat(Vektor a, Vektor b, Vektor c);
	friend ostream& operator << (ostream& Stream, Vektor const& a);
}; //wichtig: Wenn man Klassen erstellt muss ans Ende der geschlossenen Klammer ein Semikolon

#endif

//man definiert operatoren immer nur fuer die objektklasse
//außerhalb der elementfunktionen er klassse und allem was sonst dazu gehoert sind die operatoren so definiert wie standardmaessig

