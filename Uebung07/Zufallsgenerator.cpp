#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*Definition des Konstruktors aus der Klasse LCG.*/
MLCG::MLCG (int a_, int c_, long long int m_, int x_i)
{
	a = a_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	c = c_;
	m = m_;
	x_i = x_i;
}

long long int MLCG::XIplus1 (){
	a = getA();
	//cout << "a:" <<a<<endl;
	c = getC();
	m = getM();
	x_i = getX();
	setX((a*x_i + c) % m);
	return x_i;
}


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
