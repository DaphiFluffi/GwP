#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>

using namespace std;

typedef long long unsigned int bigint;

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
