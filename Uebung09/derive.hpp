#ifndef DERIVE_HPP
#define DERIVE_HPP 1

template <class T> 
class Ableitung
{
	private:
	T func;
	double h; // private Variablen
	public:
	Ableitung(T _func, double _h = 0.1) : func(_func), h(_h) { } //10e-5
	double operator() (double x, int verfahren = 0)
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

#endif
