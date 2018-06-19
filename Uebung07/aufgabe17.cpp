#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class MLCG
{
	private:
	int a, c, m, x_i; //Klassenvariablen fuer x, y, z 
	public:
	MLCG (int, int, long long int, int);
	int getA () {return (a);}; 
	int getC () {return (c);}; 
	long long int getM () {return (m);}; 
	int getX() {return (x_i);};
	void setA (int neua) { a = neua;}
	void setC (int neuc) { c = neuc;}
	void setM (long long int neum) { m = neum;}
	void setX (int neux) { x_i = neux;};
	long long int XIplus1 ();
	
}; 
/*Definition des Konstruktors aus der Klasse LCG.*/
MLCG::MLCG (int a_ = 0, int c_ = 0, long long int m_ = 0, int x_i = 0)
{
	a = a_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	c = c_;
	m = m_;
	x_i = x_i;
}

long long int MLCG::XIplus1 (){
	a = getA();
	//cout << "a:" <<a<<endl;
	c = getC();
	m = getM();
	x_i = getX();
	setX((a*x_i + c) % m);
	return x_i;
}

int main ()
{
	//cout << "Aufgabe 1:" << endl;
	/*for (int i =0; i<12; i++){
	MLCG probe(4,0, 200, 1); //x_0 = 1
	cout << probe.XIplus1() << endl;
	}*/
	//cout << "RANDU von IBM: " << endl;
	ofstream datei;
	datei.open ("ibm.dat", ios::out);
	MLCG probe(65539, 0, pow(2,31), 1); //x_0 = 1
	for (long long int i = 0; i <= 30000; i++){
		for (int x =0; x<=2; x++){
			long long int a = probe.XIplus1();
			datei << to_string(a) << "\t" ;
		}
		datei << endl;
	}
}
//counter examples for analysis free
/*Es faellt auf, dass sobald man mehr als 10 Zhalen ausgibt sich mindestens eine "Zufallszahl"
 *  wiederholt. Oft stimmt die erste mit der elften oder die zweite in der zwoelften ueberein. 
 * In jedem Fall geschieht die Wiederholung so oft wie wir es probiert haben in 10er Schritten.
 * Ausserdem ist uns aufgefallen, dass die Zahlen am Ende der ZUfallszahlen ein Muster bilden, 
 * z.B. dass die Endzahlen sich immer zwischen 4 und 6 abwechseln.*/
