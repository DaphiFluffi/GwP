#include <iostream>
#include <cmath>

using namespace std;

template <class T> class Ableitung
{
	private:
	T func;
	double h; // private Variablen
	public:
	Ableitung(T _func, double _h = 0.1) : func(_func), h(_h) { } //10e-5
	// Implementierung
	double operator() (double x, bool b = false)
	{
		if (b == false){
			volatile double temp = x+h;
			h = temp - x;
			return (func(temp) - func(x))/h;
		}else{
			volatile double temp = x+h;
			h = temp - x;
			volatile double temp2 = x-h;
			h = temp2 - x; //es liegt hieran 
			//donothing(temp){};
			return (func(temp)-func(temp2))/2*h; 
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
	cout << "Beispiel abgeleitet: " << beispiel(2.0,false) << endl; //funktioniert warum auch immer nicht
	cout << "Beispiel abgeleitet: " << beispiel(2.0,true) << endl; //funktioniert warum auch immer nicht
	//beispiel.waehlen();
	cout << "Blubb" << endl;
}
