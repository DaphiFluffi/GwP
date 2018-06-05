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

/*Definition der Funktion Betrag aus der Klasse Vektor. Die Funktion gint den Betrag eines Vektors 
 * in Form eines Skalars zurueck.*/
double Vektor::betrag ()
{
	return sqrt(x*x+y*y+z*z);
}

/*Ueberladen des +Operators. Es werden zwei Vektor-Objekte uebergeben, 
 * ein neues Vektor-Objekt namens ergebnis erstellt und die Attribute von ergbenis 
 * durch die Summe der passenden Attribute von Vektor a und Vektor b definiert.*/
Vektor operator + (Vektor a, Vektor b) 
	{
		Vektor ergebnis; //Attribute des Vektor-Objekt ergebnis werden veraendert und zuerueckgegeben
		ergebnis.x = a.x + b.x;
		ergebnis.y = a.y + b.y;
		ergebnis.z = a.z + b.z;
		return ergebnis;
	}

/*Ueberladen des * Operators. Die Attribute des ergebnis-Vektors werden gemaess der Formel 
 * fuer das Kreuzprodukt definiert. Der Vektor ergebnis wird zurueckgegeben.*/
Vektor operator * (Vektor a, Vektor b) 
	{
		Vektor ergebnis;
		ergebnis.x = a.y * b.z - a.z * b.y;
		ergebnis.y = a.z * b.x - a.x * b.z;
		ergebnis.z = a.x * b.y - a.y * b.x;
		return ergebnis;
	}

/*Funktion skalar gibt das Skalarprodukt von zwei vektoren als double zurueck.*/
double skalar(Vektor a, Vektor b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z ;
}

/*Funktion spat nimmt 3 Vektoren entgegen und gibt deren Spatprodukt zurück. 
 * Dabei wird an die Funktion skalar das Kreuzprodukt von a und b und c einzeln uebergeben.*/
double spat(Vektor a, Vektor b, Vektor c)
{
	return skalar( (a * b), c);
}

/* Ueberladen des cout << Operators.
 * Da der << Operator an das ostream-Modul gebunden ist, muss dieses mit in die 
 * Funktionsdefinition eingebunden werden. Deshalb ist der Rueckgabewert der Funktion
 * eine Reference an die cout Klasse. Von der Funktion wird  der momentane Stand des 
 * cout-Operators uebernommen, mit dem neuen string des angegebenen Vektors 
 * ergaenzt und als Ganzes zurueckgegeben.
*/
ostream& operator << (ostream& Stream, Vektor const& a)
{
	return Stream << '[' << a.x << ',' << a.y << ',' << a.z << ']';
}
