#include <iostream>
#include <string>

using namespace std;

#ifndef ZUFALLSGENERATOR_HPP
#define ZUFALLSGENERATOR_HPP 1

typedef long long unsigned int bigint;
const bigint M = 18446744073709551615UL;  //(pow(2,64)-1) wuerde die Speicherstelle ueberladen

/*randGen ist eine Zufallsmodul, das von einenem X Anfangswert aus Pseudozufallszahlen erstellt.
 *Unter verwendung der MLCG- und der Xorshift Methode. */
class randGen
{
	private:
	bigint x; 	// Startwert/Seed
	int a, b, c; // Variablen fuer Xorverschiebung 
	bigint mlcg_a, mlcg_c, mlcg_m; // Variablen fuer MLCG
	
	public:
	randGen (bigint x_= 4101842887655102017, int a_= 21, int b_= 35, int c_ = 4, bigint mlcg_a_ = 2685821657736338717, bigint mlcg_c_ = 0, bigint mlcg_m_ = M);
	bigint xorshift();
	bigint mlcg();
	bigint mlcgXorshift();
	double castIn(int a = 0, int b = 1);
	
	// Getter und setter Methoden (ungenutzt)
	
	//bigint getX() {return (x);};
	//void setX (bigint neux) { x = neux;};
	int getA () {return (a);}; 
	int getB () {return (b);}; 
	int getC () {return (c);}; 
	
	void setA (int neua) { a = neua;}
	void setB (int neub) { b = neub;}
	void setC (int neuc) { c = neuc;}
}; 
#endif
