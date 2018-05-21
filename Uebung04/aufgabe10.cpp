#include "swap.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int zahl1, zahl2;
	cout << "1.Zahl: ";
	cin >> zahl1;
	cout << "2.Zahl: ";
	cin >> zahl2;
	
	cout << "Reference-Swapper: " << endl;
	int& ref_zahl1 = zahl1;
	int& ref_zahl2 = zahl2; // c=ref_zahl2, b=ref_zahl1
	cout << swap_ref(ref_zahl1, ref_zahl2) << endl;
	//cout << "ref_zahl1: " << ref_zahl1 << " ref_zahl2: " << ref_zahl2 << endl;
	cout << "Wert von ref_zahl1 danach= " << ref_zahl1 << endl;
	cout << "Wert von ref_zahl2 danach= " << ref_zahl2 << endl;

	cout << "Pointer-Swapper: " << endl;
	cout << swap_ref(ref_zahl2, ref_zahl1) << endl;
	int* ptr_zahl1 = &ref_zahl1;
	int* ptr_zahl2 = &ref_zahl2;
	/*cout << "Adresse ptr_zahl1 vorher: " << ptr_zahl1 << endl;
	cout << "Wert ptr_zahl1 vorher: " << *ptr_zahl1 << endl;	
	cout << "Adresse ptr_zahl2 vorher: " << ptr_zahl2 << endl;
	cout << "Wert ptr_zahl2 vorher: " << *ptr_zahl2 << endl;*/

	cout << swap_ptr(ptr_zahl1, ptr_zahl2) << endl;	
	//cout << "Adresse ptr_zahl1 danach: " << ptr_zahl1 << endl;
	cout << "Wert ptr_zahl1 danach: " << *ptr_zahl1 << endl;
	//cout << "Adresse ptr_zahl2 danach: " << ptr_zahl2 << endl;
	cout << "Wert ptr_zahl2 danach: " << *ptr_zahl2 << endl;
}
