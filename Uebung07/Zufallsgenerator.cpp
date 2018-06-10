#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*Definition des Konstruktors aus der Klasse LCG.*/
MLCG::MLCG (int a_, int c_, int m_, int x_i)
{
	a = a_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	c = c_;
	m = m_;
	x_i = x_i;
}

long long int MLCG::XIplus1 (){
	a = getA();
	c = getC();
	m = getM();
	x_i = getX();
	setX((a*x_i + c) % m);
	return x_i;
}
