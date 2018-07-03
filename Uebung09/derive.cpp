#include "derive.hpp"
/*#include <iostream>
#include <cmath>

using namespace std;

template <class T>
T Ableitunng <T> double operator() (double x, int verfahren = 0);
	{
		if (verfahren == 0){ //einfache Differentiation
			volatile double temp = x+h;
			h = temp - x;
			return (func(temp) - func(x))/h;
		}else{ //symmetrische Differentiation
			volatile double temp = x + h/2;
			h = (temp - x)*2;
			volatile double temp2 = x-h/2;
			x = temp2 + h/2;
			return (func(temp)-func(temp2))/h; 
		}
	}*/
