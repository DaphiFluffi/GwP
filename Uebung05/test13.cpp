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
;
		}else{
			muster = "1" + muster;
		}
	}
	return muster;
}

int main()
{
	for(int i = 32; i < 128 ; i++){	
		cout << char(i) << "\t";
		cout << dec << i << "\t"; 	//dec und hex bestimmen ob i in hexadezimal oder dezimal ausgegeben werden soll
		cout << hex << i << "\t";
		cout << bitmuster(i) << endl;
	}
}

