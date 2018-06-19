#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

typedef long long unsigned int bigint;

int main (){
ofstream datei;
	datei.open ("xorshift.dat", ios::out);
	randGen probe(4101842887655102017); 
	for (int i = 0; i <= 30000; i++){
		for (int x =0; x<=2; x++){
			bigint a = probe.mlcgXorshift();
			datei << to_string(a) << "\t" ;
		}
		datei << endl;
	}
}
