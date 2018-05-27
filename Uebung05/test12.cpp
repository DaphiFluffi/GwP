#include <iostream>
#include <string>

using namespace std;

string bitmuster(char zeichen)
{
	string muster;
	
	for( int i = 1; i <= 128; i = i * 2){ 	// zaehlt die Bitstellen hoch 00000001 = 1, 00000010 = 2, ...
		int a;	// Speicherstelle fuer das ergebnis vom bit vergleich
		a = i & int(zeichen); 	// darf nicht in der if bedingung ausgeführt werden
		if(a == 0){
			muster = "0" + muster;
		}else{
			muster = "1" + muster;
		}
	}
	return muster;
}

int main()
{
	cout << "A = " + bitmuster('A') << endl;
	cout << "a = " + bitmuster('a') << endl;
	cout << "% = " + bitmuster('%') << endl;
	cout << "6 = " + bitmuster('6') << endl;
}

