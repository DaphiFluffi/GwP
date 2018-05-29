#include "bitmuster.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	for(int i = 32; i < 128 ; i++){	
		cout << char(i) << "\t";
		cout << dec << i << "\t"; 	//dec und hex bestimmen ob i in hexadezimal oder dezimal ausgegeben werden soll
		cout << hex << i << "\t";
		cout << bitmuster(i) << endl;
	}
}
