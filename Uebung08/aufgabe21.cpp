#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>

using namespace std;

// An optimized version of Bubble Sort
void bubbleSort(double* array, double n)
{
   bool swapped;
   double temp;
   do {
	   swapped = false;
	   for (int i = 0; i < n-1; i++){
		   //cout << array[i] << endl;
		   if (array[i] > array[i+1]){
			   temp = array[i];
			   array[i] = array[i+1];
			   array[i+1] = temp ;
			   swapped = true;
		   }
	   }
	   n = n-1;
   }
   while (swapped);
}
 
// Function to print an array 
void printArray(double array[], double size)
{
	for (int i = 0; i < size; i++){
	//cout << i << endl;
	cout << array[i] << endl;
	}
}

double* arrayBefuellen (int n)
{
	double* array = new double[n];
	randGen probe(4101842887655102017); 
	for (int i=0; i < n; i++){
		probe.mlcgXorshift();
		array[i] = probe.castIn(-5,5);
	//	cout << array[i]<< "\n";
	//	cout << i << endl;
	}
	return array;
}

int main()
{
	//double array[] = {-64., 34., 25., 12., 22., 11., 90., 0.5466860};
	double* array = 0;
	double n = 100;
	array = arrayBefuellen(n);
    bubbleSort(array, n);
    cout << "Sortiertes Array: " << "\n";
    printArray(array, n);
    return 0;
	
}
