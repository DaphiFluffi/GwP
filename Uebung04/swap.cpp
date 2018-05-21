#include <iostream>
#include <cmath>

using namespace std;

int swap_ref (int& ref_zahl1, int& ref_zahl2)
{
	/*cout << "Wert von ref_zahl1 = " << ref_zahl1 << endl;
	cout << "Wert von ref_zahl2 = " << ref_zahl2 << endl;*/
	int temp = ref_zahl1;
	/*cout << "Wert von temp = " << temp << endl;	
	cout << "Adresse von temp: " << &temp << endl;*/
	ref_zahl1 = ref_zahl2;
	//cout << "Wert von ref_zahl1 danach= " << ref_zahl1 << endl;
	//cout << "Adresse von ref_zahl1 danach: " << &ref_zahl1 << endl;
	ref_zahl2 = temp;
	//cout << "Wert von ref_zahl2 danach= " << ref_zahl2 << endl;
	//cout << "Adresse von ref_zahl2 danach: " << &ref_zahl2 << endl;
	return ref_zahl1;
}

int swap_ptr (int* ptr_zahl1, int* ptr_zahl2)
{

	int temp = *ptr_zahl1;
	//cout << "Wert von temp: " << temp << endl;
	//cout << "Adresse von temp: " << &temp << endl;
	*ptr_zahl1 = *ptr_zahl2; //über das * kann man den Pointer derefenzieren und auf den eigentlichen Wert auf den der Pointer zeigt zugreifen
	*ptr_zahl2 = temp;
	return *ptr_zahl1;
}
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
