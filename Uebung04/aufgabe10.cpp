#include "swap.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int a,x;
	cout << "1.Zahl: ";
	cin >> a;
	cout << "2.Zahl: ";
	cin >> x;
	int& b=a;
	int& c=x;
	//cout << "b: " << b << " c: " << c << endl;
	int* ptr_1 = &b;
	int* ptr_2 = &c;
	cout << "Adresse ptr_1 vorher: " << ptr_1 << endl;
	cout << "Wert ptr_1 vorher: " << (*ptr_1) << endl;	
	cout << "Adresse ptr_2 vorher: " << ptr_2 << endl;
	cout << "Wert ptr_2 vorher: " << (*ptr_2) << endl;

	cout << swap_ptr(ptr_1,ptr_2) << endl;	
	cout << "Adresse ptr_1 danach: " << ptr_1 << endl;
	cout << "Wert ptr_1 danach: " << *ptr_1 << endl;
	cout << "Adresse ptr_2 danach: " << ptr_2 << endl;
	cout << "Wert ptr_2 danach: " << *ptr_2 << endl;
	/*cout << swap_ref(b,c) << endl;*/
}
