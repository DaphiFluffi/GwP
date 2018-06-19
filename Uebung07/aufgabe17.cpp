#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class MLCG
{
	private:
	int a, c, m, x_i; //Klassenvariablen fuer a, c, m, x_i
	public:
	MLCG (int, int, long long int, int); //Konstruktor der MLCG Klasse
	int getA () {return (a);}; //Getter- und Setter-Methoden fuer die privaten Klassenvariablen
	int getC () {return (c);}; 
	long long int getM () {return (m);}; 
	int getX() {return (x_i);};
	void setA (int neua) { a = neua;}
	void setC (int neuc) { c = neuc;}
	void setM (long long int neum) { m = neum;}
	void setX (int neux) { x_i = neux;};
	long long int XIplus1 (); //Funktion zur Berechnung der nächsten Zufallszahl ausgehend von einem Startwert x_i
	
}; 

/*Definition des Konstruktors aus der Klasse LCG.*/
MLCG::MLCG (int a_ = 0, int c_ = 0, long long int m_ = 0, int x_i = 0)
{
	a = a_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	c = c_;
	m = m_;
	x_i = x_i;
}

//Funktion gibt eine Zufallszahl (x_i) zurueck, die durch die Verwendung der MLCG-Formel berechnet wird.
long long int MLCG::XIplus1 ()
{
	setX((a*x_i + c) % m); //Verwendung der Formel fuer den linearen Kongruenzgenerator
	return x_i;
}

int main ()
{
	//Ausprobieren des Genrators mit a = 4, c = 0, m = 200 und x 0 = 1
	for (int i =0; i<12; i++){
	MLCG probe(4,0, 200, 1); //Erstellen eines MLCG-Objekts mit den obigen Werten
	cout << probe.XIplus1() << endl;
	}
	//Verwenden der Parameter von RANDU von IBM
	ofstream datei; //Erstellen des ofstream-Objekts datei
	datei.open ("ibm.dat", ios::out); //Oeffnen der Datei ibm.dat zum Schreiben
	MLCG probe(65539, 0, pow(2,31), 1); 
	for (int i = 0; i <= 30000; i++){
		for (int x = 0; x <= 2; x++){ //for-Schleife bewirkt eine dreispaltige Ausgabe der Zufallswerte
			long long int zufallszahl = probe.XIplus1(); //Speichern der Zufallszahlen aus dem Generator in einer Variable
			datei << to_string(zufallszahl) << "\t" ; //Casten der zufallszahl-Variable in string 
		}
		datei << endl;
	}
}
/*Es faellt auf, dass sobald man mehr als 10 Zahlen ausgibt sich mindestens eine "Zufallszahl"
 *  wiederholt. Oft stimmt die erste mit der elften oder die zweite in der zwoelften ueberein. 
 * In jedem Fall geschieht die Wiederholung so oft wie wir es probiert haben in 10er Schritten.
 * Ausserdem ist uns aufgefallen, dass die Zahlen am Ende der ZUfallszahlen ein Muster bilden, 
 * z.B. dass die Endzahlen sich immer zwischen 4 und 6 abwechseln.*/
