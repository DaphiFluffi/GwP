#include <iostream>
#include <cmath>

using namespace std;

class Polynom
{
	float a, b, c, d, e, f;
	public:
	Polynom (float, float, float, float, float, float); //Konstruktordeklaration
	Polynom ableitung (); //Methodenkopf von Ableitung
	float operator() (float x) //Ueberladen des ()-Operators
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
Polynom::Polynom (float a_ = 0, float b_ = 0, float c_ = 0, float d_ = 0, float e_ = 0, float f_ = 0)
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
	Polynom p(6,-1,-1,2,1,-1);
	Polynom q(5,1,1,-2,-1,1);
	Polynom ableitungvonp = p.ableitung();
	Polynom ableitungvonq = q.ableitung();
	//p.print();
	//q.print();
	//cout << p(1) << endl;
		     cout << "x-Wert" << "\t";
			 cout << "p(x)" << "\t";
			 cout << "q(x)" << "\t";
			 cout << "Ableitung p(x)" << "\t";
			 cout << "Ableitung q(x)" << endl;
	for (float i = -2; i <= 2; i += 0.01){
			cout << i << "\t";
			cout << p(i) << "\t";
			cout << q(i) << "\t";
			cout << ableitungvonp(i) << "\t";
			cout << ableitungvonq(i) << endl;
	}
}

/*cout << "Polynom x = " << endl;
    for (float i = -2;i <= 2;i += 0.01){
        cout << i << "\t";
        cout << polynom(i,6,-1,-1,2,1,-1) << endl;  // viele lokale Maxima und f(2) rund 0
    }  */
    //um ueberschriften zu machen koennte ich eine if bedingung mmachen mit if 1.durchlauf gib mir die ueberschriften danach die werte
