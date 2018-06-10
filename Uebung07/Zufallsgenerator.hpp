#include <iostream>
#include <string>

using namespace std;

#ifndef ZUFALLSGENERATOR_HPP
#define ZUFALLSGENERATOR_HPP 1

class MLCG
{
	private:
	int a, c, m, x_i; //Klassenvariablen fuer x, y, z 
	public:
	MLCG (int a_= 0, int c_= 0, int m_= 0, int x_i = 0);
	int getA () {return (a);}; 
	int getC () {return (c);}; 
	int getM () {return (m);}; 
	int getX() {return (x_i);};
	void setA (int neua) { a = neua;}
	void setC (int neuc) { c = neuc;}
	void setM (int neum) { m = neum;}
	void setX (int neux) { x_i = neux;};
	long long int XIplus1 ();
	
}; 

#endif
/*double betrag (); //Methodenkopf von der Ableitungsfunktion. Hier steht nur der Rueckgabetyp und der Name der Funktion
	friend Vektor operator + (Vektor a, Vektor b); //Ueberladen des +Operators. friend bewirkt, dass man die Uerberladung ausserhalb der Klasse machen kann, weil Funktionen innerhalb der Klasse maximal einen Parameter uebergeben bekommen duerfen.
	friend Vektor operator * (Vektor a, Vektor b);
	friend double skalar(Vektor a, Vektor b);
	friend double spat(Vektor a, Vektor b, Vektor c);
	friend ostream& operator << (ostream& Stream, Vektor const& a); //Ueberladen von cout <<*/
