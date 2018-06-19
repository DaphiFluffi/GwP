#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>

using namespace std;

typedef long long unsigned int bigint;

/*Definition des Konstruktors
 *randGen nimmt beim Erstellen alle Variablen optional entgegen:
 * x: Startwert, der Zufallskette
 * a, b, c: Integer, um die x in der Xorshift-Methode verschoben wird
 * mlcg_a, mlcg_c, mlcg_m: long long unsigned int Variablen fuer die MLCG-Methode
 * Werden die Variablen nicht angegeben, werden sie mit den empfohlenden Standartwerten besetzt. */
randGen::randGen(bigint x_, int a_, int b_, int c_, bigint mlcg_a_, bigint mlcg_c_, bigint mlcg_m_)
{
	x = x_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	a = a_; 
	b = b_;
	c = c_;
	mlcg_a = mlcg_a_;
	mlcg_c = mlcg_c_;
	mlcg_m = mlcg_m_;
}

// ersetzt das aktuelle X mit einem durch Binaerverschiebung neu erstelltem X
bigint randGen::xorshift(){
	x ^= x << a;
	x ^= x >> b;
	x ^= x << c;
	return x;
}

// ersetzt das aktuelle X mit einem durch lineare Kongruenz neu erstelltem X
bigint randGen::mlcg(){
	x = ((mlcg_a*x + mlcg_c) % mlcg_m);
	return x;
}

// wendet Xorshift und MLCG hintereinender an: MLCG(Xorshift)
bigint randGen::mlcgXorshift(){
	xorshift();
	mlcg();
	return x;
}

/* castIn nimmt zwei Integers entgegen und gibt ein Double zurueck,
 * das an der selben Position im angegebenen Intervall steht wie X in [0, 2^64],
 * dabei wird X (aus randGen) selbst nicht veraendert!
*/
double randGen::castIn(int a, int b){
	return  (double(x/2) / pow(2,63)  *  (b-a)) + a; // rechne mit  2 * 2^63 um das nutzen von 2^64 zu vermeiden so kommt es zu keinen speicherproblemen.
}
