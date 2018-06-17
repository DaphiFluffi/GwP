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
	MLCG (int a_= 0, int c_= 0, long long int m_= 0, int x_i = 0);
	int getA () {return (a);}; 
	int getC () {return (c);}; 
	long long int getM () {return (m);}; 
	int getX() {return (x_i);};
	void setA (int neua) { a = neua;}
	void setC (int neuc) { c = neuc;}
	void setM (long long int neum) { m = neum;}
	void setX (int neux) { x_i = neux;};
	long long int XIplus1 ();
	
}; 

class randGen
{
	private:
	bigint x; 	// Startwert 
	int a, b, c; // variablen fuer xorverschiebung 
	bigint mlcg_a, mlcg_c, mlcg_m; // variablen fuer MLCG
	
	public:
	randGen (bigint x_= 4101842887655102017, int a_= 21, int b_= 35, int c_ = 4, bigint mlcg_a_ = 2685821657736338717, bigint mlcg_c_ = 0, bigint mlcg_m_ = M);
	bigint xorshift();
	bigint mlcg();
	bigint mlcgXorshift();
	double castIn(int a = 0, int b = 1);
	
	// Noetig ?
	int getA () {return (a);}; 
	int getB () {return (b);}; 
	int getC () {return (c);}; 
	//bigint getX() {return (x);};
	void setA (int neua) { a = neua;}
	void setB (int neub) { b = neub;}
	void setC (int neuc) { c = neuc;}
	void setX (bigint neux) { x = neux;};
	
}; 

#endif
/*double betrag (); //Methodenkopf von der Ableitungsfunktion. Hier steht nur der Rueckgabetyp und der Name der Funktion
	friend Vektor operator + (Vektor a, Vektor b); //Ueberladen des +Operators. friend bewirkt, dass man die Uerberladung ausserhalb der Klasse machen kann, weil Funktionen innerhalb der Klasse maximal einen Parameter uebergeben bekommen duerfen.
	friend Vektor operator * (Vektor a, Vektor b);
	friend double skalar(Vektor a, Vektor b);
	friend double spat(Vektor a, Vektor b, Vektor c);
	friend ostream& operator << (ostream& Stream, Vektor const& a); //Ueberladen von cout <<*/
