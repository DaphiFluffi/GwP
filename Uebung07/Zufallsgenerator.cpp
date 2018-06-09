#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*Definition des Konstruktors aus der Klasse LCG.*/
LCG::LCG (int a_, int c_, int m_)
{
	a = a_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	c = c_;
	m = m_;
}
