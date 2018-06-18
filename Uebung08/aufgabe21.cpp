#include <iostream>
#include <cmath>

using namespace std;

void swap(double *xp, double *yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(double array[], double n)
{
   bool swapped;
   for (int i = 0; i < n-1; i++){
     swapped = false;
     for (int j = 0; j < n-i-1; j++){
        if (array[j] > array[j+1]){
           swap(&array[j], &array[j+1]);
           swapped = true;
        }
     }
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false){
        break;
	}
  }
}
 
/* Function to print an array */
void printArray(double array[], double size)
{
	for (int i = 0; i < size; i++)
	cout << array[i] << " ";
}

double* arrayBefuellen (int size){
	double* array = new double;
	for (int i = 0; i < size; i++){
		array[i] = random();
	}
	return array;
	//delete[] array;
}
// Driver program to test above functions
int main()
{
   // int array[] = {64, 34, 25, 12, 22, 11, 90};
    double* array = 0;
    array = arrayBefuellen(100);
    int n = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, n);
    cout << "Sorted array: " << "\n";
    printArray(array, n);
    return 0;
}
/*bubbleSort3(Array A)
  n = A.size
  do{
    newn = 1
    for (i=0; i<n-1; ++i){
      if (A[i] > A[i+1]){
        A.swap(i, i+1)
        newn = i+1
      } // ende if
    } // ende for
    n = newn
  } while (n > 1)*/

// Optimized implementation of Bubble sort
//#include <stdio.h>
