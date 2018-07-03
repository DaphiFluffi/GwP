#ifndef DERIVE_HPP
#define DERIVE_HPP 1

/*Lediglich Auslagerung in die derive.hpp, weil man template-Klassen im besten Fall nicht auslagert oder 
 * wenn doch dann ohne Auslagerung der Funktionen in eine zusaetzliche cpp-Datei.
 * Grund dafuer ist die Abhaengigkeit der template-Klasse von dem uebergebenen Datentyp. 
 * Somit benoetigt der Kompiler zwei Durchlaeufe, um die Klasse zu "verstehen".
 * Das fuehrt zu grossen Problemen bei einer Modularisierung.*/
template <class T> 
class Ableitung
{
	private: //private Variablen 
	T func;
	double h;
	public:
	Ableitung(T _func, double _h = 10e-5) : func(_func), h(_h) { } 
	/* Uebergabe von den Variablen x und verfahren. Die Integer-Variable verfahren ist mit dem optionalen Wert 0 versehen. 
	 * Somit wird per default die Ableitung mit der einfachen Differentiation berechnet.*/
	double operator() (double x, int verfahren = 0) //Ueberladen des ()-Operators zur Berechnung der Ableitung 
	{
		if (verfahren == 0){
			volatile double temp = x+h; // h+x kann binaer nicht exakt dargestellt werden. Damit der Kompiler x+h nicht weggoptimiert, wird temp = h+x als volatile definiert.
			h = temp - x;
			return (func(temp) - func(x))/h;  //einfache Differentiation
		}else{ 
			volatile double temp = x + h/2;
			h = (temp - x)*2;
			volatile double temp2 = x-h/2;
			x = temp2 + h/2;
			return (func(temp)-func(temp2))/h; //symmetrische Differentiation
		}
	}
	//Getter- und Setter-Methoden fuer h 
	double getH () { return h;} 
	void setH (double neuh) { h = neuh;}
};

#endif
