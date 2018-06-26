#include <iostream>
#include <cmath>

using namespace std;

template <class T> class Ableitung
{
	private:
	T func;
	double h; // private Variablen
	public:
	Ableitung(T _func, double _h = 10e-5) : func(_func), h(_h) { }
	// Implementierung
	T operator() (double x, bool b = 0)
	{
		if (b == 0){
			volatile double temp = x+h;
			h = temp - x;
			return func(x+h) - func(x)/h;
		}else{
			//volatile double temp = x+h;
			//h = temp - x;
			//volatile double temp2 = x-h;
			return func(x+h)-func(x-h)/2*h;
		}
	}
	double getH () { return h;}
	void setH (double neuh) { h = neuh;}
	/*void waehlen(){
		cout << "Bitte 0(einfach) oder 1 (symmetrisch) angeben!" <<endl;
		bool frage;
		cin >> frage;
		if (frage == 0){
			//mach einfache Differentiation
		}else if (frage == 1){
			//mach symmetrische Differentiation
		}
	}*/
};

class Test {
	double x;
	public:
	Test();
	double operator () (double x) {return x*x;} //gibt mir x^2 zurueck
};

Test::Test (){
}

int main() 
{
	//Ableitung <double> beispiel(24,12);//omg warum auch immer das funktioniert
	Test a;
	a(2.0);
	cout << a(2.0) << endl;//Test Klasse funktioniert es kommt 4 raus 
	Ableitung <Test> beispiel(a);
	cout << "Beispiel abgeleitet: " << beispiel(2.0,0) << endl; //funktioniert warum auch immer nicht
	//beispiel.waehlen();
	cout << "Blubb" << endl;
}
