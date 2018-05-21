#include <iostream>
#include <cmath>

using namespace std;

/*Funktion die zwei als Parameter uebergebene Interger References, 
 * die zwei verschieden Zahlen refernzieren, vertauscht*/
void swap_ref (int& ref_zahl1, int& ref_zahl2)
{
	int temp_ref; //eine temporaere Integer-Variable, die dazu da ist den Wert, auf den sich ref_zahl1 urspruenglich bezog, zu speichern
	temp_ref = ref_zahl1; 
	ref_zahl1 = ref_zahl2;
	ref_zahl2 = temp_ref; 
}

/*Funktion, die als Parameter zwei Pointer uebergeben bekommt, 
 * die auf die References fuer zahl1 und zahl2 zeigen und dise vertauscht.*/
void swap_ptr (int* ptr_zahl1, int* ptr_zahl2)
{
	int temp_ptr; //eine temporaere Integer-Variable, die den Wert, in der Reference auf den sich der ptr_zahl1 bezieht zwischenspeichert.
	temp_ptr = *ptr_zahl1;
	*ptr_zahl1 = *ptr_zahl2; //über das Sternchen kann man den Pointer derefenzieren und auf den eigentlichen Wert, auf den der Pointer zeigt zugreifen
	*ptr_zahl2 = temp_ptr;
}
