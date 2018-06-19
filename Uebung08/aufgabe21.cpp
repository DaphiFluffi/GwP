#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*Funktion, die die aus einem Array ausgelesenen Zahlen nach dem Bubblesort-Algorithmus aufsteigend sortiert.
Die Funktion gibt nichts zurück und bekommt ein Array und dessen Groesse (n) uebergeben*/
void bubbleSort(double* array, double n)
{
   bool swapped; //boolesche Variable zur Bestimmung, ob zwei Werte vertauscht wurden
   double temp; //temporare Variable zum zwischenspeichern einer Zufallszahl 
   do {
	   swapped = false; //zunaechst werden keine Zufallszahlen getauscht
	   for (int i = 0; i < n-1; i++){ 
		   if (array[i] > array[i+1]){ //Sofern eine Zahl im Array groesser ist als die Folgende muessen die Zahlen getauscht werden.
			   temp = array[i]; //Speichern des urspruenglichen Werts der ersten Zahl in der temporaeren Variable
			   array[i] = array[i+1]; //Speichern des Werts der zweiten Zahl an der Speicherstelle der ersten Zahl
			   array[i+1] = temp; //Speichern des uspruenglichen Werts der ersten Zahl an der Speicherstelle der zweiten Zahl
			   swapped = true;
		   }
	   }
	   n = n-1; //n (also die Groesse des Arrays) wird dekrementiert
   }
   while (swapped); //Vorgang wird ausgefuert solange swapped true ist
}
 
/*Funktion bekommt ein array und dessen Groesse uebergeben und gibt es aus*/
void printArray(double array[], double n)
{
	for (int i = 0; i < n; i++){
	cout << array[i] << endl;
	}
}

/*Funktion befuellt ein array mit Zufallswerten aus der mlcgXorshift-Methode in der Zufallsgenerator.hpp.
 * Sie bekommt als Parameter die Groesse des Arrays und gibt ein double Array zurueck*/
double* arrayBefuellen (int n)
{
	double* array = new double[n]; //Erstellen eines double Arrays der Groesse n 
	randGen probe(4101842887655102017); //Erstellen eines randGen-Obejekts auf das die Elementfunktionen der Klasse zugreifen koennen.
	for (int i=0; i < n; i++){
		probe.mlcgXorshift(); 
		array[i] = probe.castIn(-5,5); //Verwenden der castIn-Methode aus der randGen-Klasse zur Erzeugung von Zufallszahlen im Intervall [-5,5].
	}
	return array;
}

int main()
{
	double* array = 0; //Erstellen eines double arrays namens array
	double n = 100; //Groesse des arrays ist 100
	array = arrayBefuellen(n); //Befuellen des Arrays mit der arrayBefuellen-Methode
    bubbleSort(array, n); //Anwenden der Bubblesort-Methode
    cout << "Sortiertes Array: " << "\n";
    printArray(array, n); //Ausgabe des sortierten Arrays
    delete[] array; //speicherfreigabe des arrays
    return 0;
	
}
