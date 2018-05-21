#include <iostream>
#include <cmath>

using namespace std;

//input:
/*int swap_ref (int& a, int& b)
{
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
}*/

void swap_ptr (int* ptr_1, int* ptr_2)
{
	//int a,x;
	/*cout << "a = " << a << endl;
	cout << "x = " << x << endl;*/
	/*int& b=a;
	int& c=x;*/
	/*cout << "b = " << b << endl;
	cout << "Adresse von b: " << &b << endl;
	cout << "c = " << c << endl;
	cout << "Adresse von c: " << &c << endl;*/
	/*ptr_1 = &b;
	ptr_2 = &c;*/
	/*cout << "Wert von ptr_1 = " << (*ptr_1) << endl;
	cout << "ptr_1 = " << ptr_1 << endl;
	cout << "Wert von ptr_2 = " << (*ptr_2) << endl;
	cout << "ptr_2 = " << ptr_2 << endl;*/
	int temp = *ptr_1;
	cout << "Wert von temp: " << temp << endl;
	cout << "Adresse von temp: " << &temp << endl;
	*ptr_1 = *ptr_2; //über das * kann man den Pointer derefenzieren und auf den eigentlichen Wert auf den der Pointer zeigt zugreifen
	*ptr_2 = temp;
	//return *ptr_1;
}
