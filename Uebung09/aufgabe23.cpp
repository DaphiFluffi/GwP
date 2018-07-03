#include "derive.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*template <class T> 
class Ableitung
{
	private:
	T func;
	double h; // private Variablen
	public:
	Ableitung(T _func, double _h = 0.1) : func(_func), h(_h) { } //10e-5
	double operator() (double x, int verfahren = 0);
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
	}
	double getH () { return h;}
	void setH (double neuh) { h = neuh;}
};
*/
class Test 
{
	double x;
	public:
	double operator () (double x) 
	{
		return x*x*x;
	}
};

class Funktion  
{
	public:
		double operator() (double x)
		{
			return x*x + 2*x + 3;
		}
};

int main() 
{
	Test a;
	Ableitung <Test> beispiel(a);
	cout << "Klasse Test (einfach): " << beispiel(2.0) << endl; 
	cout << "Klasse Test (symmetrisch): " << beispiel(2.0,12) << endl; 
	Funktion b;
	Ableitung<Funktion> funktion(b);
	cout << "Klasse Funktion (einfach): " << funktion(5.5) << endl;
	cout << "Klasse Funktion (symmetrisch): " << funktion(5.5,1) << endl;
}
