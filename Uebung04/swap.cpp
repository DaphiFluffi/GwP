#include <iostream>
#include <cmath>

using namespace std;

//input:
int swap_ref (int& a, int& b){
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	int temp = a;
	cout << "temp = " << temp << endl;	
	//cout << "Adresse von temp: " << &temp << endl;
	a = b;
	cout << "a = " << a << endl;
	cout << "Adresse von a: " << &a << endl;
	b = temp;
	cout << "b = " << b << endl;
	cout << "Adresse von b: " << &b << endl;
	return b;
}

/*int swap_ptr (int* a, int* b){
	return a;
}*/
