#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>
//#include <fstream>
//#include <string>

using namespace std;

int main ()
{
	cout << "jei" << endl;
	for (int i =0; i<11; i++){
	MLCG probe(4,0, 200, 1); //x_0 = 1
	cout << probe.XIplus1() << endl;
}
}

//Kompilierbefehl: c++ -Wall -o aufgabe17 aufgabe17.cpp Zufallsgenerator.cpp
