//#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

typedef long long unsigned int bigint;
const bigint M = 18446744073709551615L;  //(pow(2,64)-1) wuerde die Speicherstelle ueberladen

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

//Definition des Konstruktors
randGen::randGen(bigint x_, int a_, int b_, int c_, bigint mlcg_a_, bigint mlcg_c_, bigint mlcg_m_)
{
	x = x_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	a = a_; 
	b = b_;
	c = c_;
	mlcg_a = mlcg_a_;
	mlcg_c = mlcg_c_;
	mlcg_m = mlcg_m_;
}

bigint randGen::xorshift(){
	x ^= x << a;
	x ^= x >> b;
	x ^= x << c;
	return x;
}

bigint randGen::mlcg(){
	x = ((mlcg_a*x + mlcg_c) % mlcg_m);
	return x;
}

bigint randGen::mlcgXorshift(){
	xorshift();
	mlcg();
	return x;
}

double randGen::castIn(int a, int b){
	return  (double(x/2) / pow(2,63)  *  (b-a)) + a; // rechne mit  2 * 2^63 um das nutzen von 2^64 zu vermeiden so kommt es zu keinen speicherproblemen.
}


double gauss(double x, const double SIGMA = 1, const double MY = 0)
{	
	return 1/( SIGMA * sqrt(2 * M_PI) ) * exp( -(x - MY)*(x -MY) / (2 * SIGMA * SIGMA) );
}

//double histogramm ;


int main()
{
	randGen xRand(42);
	randGen yRand(50);
	double x;
	double y;
	
	ofstream datei;
	datei.open ("gauss.dat", ios::out);
	
	int i = 0;
	while ( i < 100000 ){
		xRand.mlcgXorshift();
		yRand.mlcgXorshift();
		x = xRand.castIn(0,1);
		y = yRand.castIn(0,1);
		
		cout << y << "\t" << gauss(x) << endl;
		if (y <= gauss(x)){
			datei << x << endl;
			i++;
		}
	}
	cout << "Gauss datei erstellt." << endl;
}

