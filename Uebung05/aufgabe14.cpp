#include <iostream>
#include <cmath>

using namespace std;

class Polynom
{
	float a, b, c, d, e, f; //Klassenvariablen fuer die Skalare von a_0 bis a_5
	public:
	Polynom (float, float, float, float, float, float); //Konstruktordeklaration
	Polynom ableitung (); //Methodenkopf von der Ableitungsfunktion
	float operator() (float x) //Ueberladen des ()-Operators
	{
		return a + b*x + c*pow(x,2) + d*pow(x,3) + e*pow(x,4) + f*pow(x,5);
	}
}; //wichtig: Wenn man Klassen erstellt muss ans Ende der geschlossenen Klammer ein Semikolon

/*Definition des Konstruktors aus der Klasse Polynom. Uebergeben werden die Skalare a_-f_ als optionale Parameter, 
 * die mit 0 initialisiert werden. Im Konstruktor werden die Klassenvariablen mit diesen optionalen Paramtern 
 * gleichgesetzt.*/
Polynom::Polynom (float a_ = 0, float b_ = 0, float c_ = 0, float d_ = 0, float e_ = 0, float f_ = 0)
{
	a = a_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	b = b_;
	c = c_;
	d = d_;
	e = e_;
	f = f_;
}
/* Definition der Funktion Ableitung. Es gibt keine Uebergabeparameter, der Rueckgabewert ist vom Typ Polynom.
In der Funktion wird das Polynom-Objekt ergebnis mit den Werten, die bei der Ableitung eines Polynoms 5.Grades 
entstehen, erstellt und zurueckgegeben.*/
Polynom Polynom::ableitung ()
{
	Polynom ergebnis(b, 2*c, 3*d, 4*e, 5*f, 0);
	return ergebnis;
}

int main() 
{
	// Erstellen von zwei Polynomobjekten p und q mit den Werten aus aufgabe11
	Polynom p(6,-1,-1,2,1,-1);
	Polynom q(5,1,1,-2,-1,1);
	/*Erstellen zwei weiterer Polynome, die jeweils die Ableitung von p oder q 
	durch den Funktionsaufruf von ableitung speichern*/
	Polynom ableitungvonp = p.ableitung(); 
	Polynom ableitungvonq = q.ableitung();

	// Ausgabe der ersten Zeile der Tabelle, damit bekannt ist was der Inhalt jeder Spalte bedeutet
	cout << "x-Wert" << "\t";
	cout << "p(x)" << "\t";
	cout << "q(x)" << "\t";
	cout << "Ableitung p(x)" << "\t";
	cout << "Ableitung q(x)" << endl;
	
	/*Ausgabeschleife, die im Intervall von -2 bis 2, inkrementiert mit 0,01, jeweils x, p(x), q(x), p'(x) und q'(x)
	an der entsprechenden Stelle ausgibt*/
	for (float i = -2; i <= 2; i += 0.01){
			cout << i << "\t";
			cout << p(i) << "\t";
			cout << q(i) << "\t";
			cout << ableitungvonp(i) << "\t";
			cout << ableitungvonq(i) << endl;
	}
}
