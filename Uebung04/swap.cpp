#include <iostream>
#include <cmath>

using namespace std;

void swap_ref (int& ref_zahl1, int& ref_zahl2)
{
	int temp = ref_zahl1;
	ref_zahl1 = ref_zahl2;
	ref_zahl2 = temp;
}

void swap_ptr (int* ptr_zahl1, int* ptr_zahl2)
{
	int temp = *ptr_zahl1;
	*ptr_zahl1 = *ptr_zahl2; //über das * kann man den Pointer derefenzieren und auf den eigentlichen Wert auf den der Pointer zeigt zugreifen
	*ptr_zahl2 = temp;
}
