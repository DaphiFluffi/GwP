#include <iostream>
#include <cmath>

using namespace std;

//Wie machen wir die Modularisierung und das includen? Gerade funkioniert es nicht
//welche dateien sind abzugeben
//mein sortieralgorithmus funktioniert nicht wk perfekt
//brauchen wir die ganzen getter setter methoden wenn ir eh mlcg nicht nutzen?

typedef long long unsigned int bigint;
const bigint M = 18446744073709551615UL;  //(pow(2,64)-1) wuerde die Speicherstelle ueberladen

class randGen
{
	private:
	bigint x; 	// Startwert 
	int a, b, c; // variablen fuer xorverschiebung 
	bigint mlcg_a, mlcg_c, mlcg_m; // variablen fuer MLCG
	
	public:
	randGen (bigint , int , int , int , bigint , bigint , bigint );
	bigint xorshift();
	bigint mlcg();
	bigint mlcgXorshift();
	double castIn(int a = 0, int b = 1);
	
	// Noetig ?
	int getA () {return (a);}; 
	int getB () {return (b);}; 
	int getC () {return (c);}; 
	//bigint getX() {return (x);};
	void setA (int neua) { a = neua;}
	void setB (int neub) { b = neub;}
	void setC (int neuc) { c = neuc;}
	void setX (bigint neux) { x = neux;};
	
}; 

//Definition des Konstruktors
randGen::randGen(bigint x_= 4101842887655102017, int a_= 21, int b_= 35, int c_ = 4, bigint mlcg_a_ = 2685821657736338717, bigint mlcg_c_ = 0, bigint mlcg_m_ = M)
{
	x = x_; //setzt die Klassenattribute mit den Konstruktorparametern gleich
	a = a_; 
	b = b_;
	c = c_;
	mlcg_a = mlcg_a_;
	mlcg_c = mlcg_c_;
	mlcg_m = mlcg_m_;
}

bigint randGen::xorshift(){
	x ^= x << a;
	x ^= x >> b;
	x ^= x << c;
	return x;
}

bigint randGen::mlcg(){
	x = ((mlcg_a*x + mlcg_c) % mlcg_m);
	return x;
}

bigint randGen::mlcgXorshift(){
	xorshift();
	mlcg();
	return x;
}

double randGen::castIn(int a, int b){
	return  (double(x/2) / pow(2,63)  *  (b-a)) + a; // rechne mit  2 * 2^63 um das nutzen von 2^64 zu vermeiden so kommt es zu keinen speicherproblemen.
}

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
			for (int i=0; i<10;i++){
				cout <<  array[i] << endl;
			}
			cout << "blubb" << endl;
        }
     }
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false){
        break;
	}
  }
}
 
// Function to print an array 
void printArray(double array[], double size)
{
	for (int i = 0; i < size; i++)
	cout << array[i] << endl;
}

double* arrayBefuellen ()
{
	int i = 0; 
	double* array = new double[i];
	randGen probe(4101842887655102017); 
	while(i<10){
		probe.mlcgXorshift();
		array[i]=probe.castIn(-5,5);
		cout << array[i]<< "\n";
		i++;
		cout << i << endl;
	}
	return array;
}

int main()
{
	//double array[] = {-64., 34., 25., 12., 22., 11., 90., 0.5466860};
	double* array = 0;
	array = arrayBefuellen();
    double n = 10;
    bubbleSort(array, n);
    cout << "Sorted array: " << "\n";
    printArray(array, n);
    delete[] array;
    return 0;
	
}
