#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

typedef long long unsigned int bigint;

// Gauss Funktion gauss(x)=y alternativ koennen noch SIGMA und MY mit angegeben werden
double gauss(double x, const double SIGMA = 1, const double MY = 0)
{	
	return 1/( SIGMA * sqrt(2 * M_PI) ) * exp( -(x - MY)*(x -MY) / (2 * SIGMA * SIGMA) );
}

// histogramm nimmt ein Array und dessen Laenge entgegen und erstellt daraus ein Histogramm mit n-vielen Intervallen
// x entspricht den Intervallen und y der Anzahl der Punkte in diesem Intervall
double* histogramm (double* array, int len, int n)
{
	// max und min ermitteln
	double max = array[0];
	double min = array[0];
	for(int i = 0; i < len; i++){ // Zaehlt das Array durch, und ermittelt dabei das Maximum und Minimum
		if( array[i] < min ){min = array[i];}
		if( array[i] > max){max = array[i];}
	}
	double intervall = (max - min) / n; //bestimmt die Groesse eines einzelnen Intervalls 
	
	double* histogramm = new double[n]; // erstellt das Rueckgabe-Array
	double bereich; //Punkt an dem das momentane Intervall steht
	for(int balken = 0; balken < n; balken++){ //zaehlt die einzelnen Intervalle / Balken hoch und fuellt sie
		bereich =  intervall * balken + min; // passt den Zahlenbereich auf das momentane Intervall an
		for(int i = 0; i < len; i++){	// geht das auszuwertende Array durch und zahlt die im Intervall liegenden Punkte
			if( bereich <= array[i] && array[i] < (bereich + intervall) ) {histogramm[balken]++;}
		}
	}
	return histogramm;
}

int main()
{
	//Setup
	const int LEN = 100000; //Anzahl der Gauss Werte
	double* array = new double[LEN];
	//Initialisiert 2 Zufallszahlketten
	randGen xRand(92305972093508);
	randGen yRand(598769760);
	double x; // Speicherstellen für castIn
	double y;
	
	int i = 0; // Whileschleife, die nach LEN-vielen Werten sucht
	while ( i < LEN ){
		xRand.mlcgXorshift(); // "wuerfelt" neu
		yRand.mlcgXorshift();
		x = xRand.castIn(-1,1); // Speicher x und y Zufallswerte in den gewuenschen Intervallen ab
		y = yRand.castIn(0,1);

		if (y+0.25<= gauss(x)){ // Ueberprueft ob der zufaellige y-Wert im Bereich der Gausskurve liegt
			array[i] = x; // speichert den passenden wert ab und zaehlt hoch
			i++;
		}	
	}
	
	// In gauss.dat speichern 
	ofstream dateiG;
	dateiG.open ("gauss.dat", ios::out);
			
	for(int i = 0; i < LEN; i++){
		dateiG << array[i] << endl;	
	}

	dateiG.close();
	cout << "Gauss-Datei erstellt." << endl;
	
	
	// Erstellt ein Histogramm aus den gespeicherten Gauss-Werten
	const int N = 15; // Anzahl der Intervalle des Histogramms
	double* ausgabe = histogramm(array,LEN,N);
	
	// In histogramm.dat speichern
	ofstream dateiH;
	dateiH.open ("histogramm.dat", ios::out);
	
	for(int i = 0; i < N; i++){
		dateiH << ausgabe[i] << endl;	
	}
	dateiH.close();
	cout << "Histogramm-Datei erstellt." << endl;
}

