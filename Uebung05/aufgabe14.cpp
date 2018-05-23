#include <iostream>
#include <cmath>

using namespace std;

class Polynom
{
	double a, b, c, d, e, f;
	public:
	Polynom (double, double, double, double, double, double); //Konstruktordeklaration
	Polynom ableitung (); //Methodenkopf von Ableitung
	double operator() (double x) //Ueberladen des ()-Operators
	{
		return a + b*x + c*pow(x,2) + d*pow(x,3) + e*pow(x,4) + f*pow(x,5);
	}
	//ich kann an dieser stelle eine print funktion definieren mit void die mir die skalara zurückgibt
	void print ()
	{
		cout << a << " + " << b << "*x + " << c << "*x^2 + " << d << "x^3 + " << e << "x^4 + " << f << "x^5 + " << endl;
		
	}
	
}; //wichtig: wenn man klassen erstellt muss ans ende der geschlossenen klammer ein semikolon

// Konstruktordefinition
Polynom::Polynom (double a_ = 0, double b_ = 0, double c_ = 0, double d_ = 0, double e_ = 0, double f_ = 0)
{
	a = a_; //setzt die Klassenattribute mit den Konstruktorparasmetern gleich
	b = b_;
	c = c_;
	d = d_;
	e = e_;
	f = f_;
}
// Definition der Funktion Ableitung
Polynom Polynom::ableitung ()
{
	Polynom ergebnis(b, 2*c, 3*d, 4*e, 5*f, 0);
	return ergebnis;
}

int main() 
{
	Polynom p(1,2,3,4,5,6);
	Polynom q(12, 13, 14, 15, 16, 17);
	
	p.print();
	q.print();
	
	cout << p(1) << endl;
	Polynom xy = p.ableitung();
	Polynom abc = q.ableitung();
	
	/*cout << "Polynom x = " << endl;
    for (float i = -2;i <= 2;i += 0.01){
        cout << i << "\t";
        cout << polynom(i,6,-1,-1,2,1,-1) << endl;  // viele lokale Maxima und f(2) rund 0
    }  */
    //um ueberschriften zu machen koennte ich eine if bedingung mmachen mit if 1.durchlauf gib mir die ueberschriften danach die werte
}

