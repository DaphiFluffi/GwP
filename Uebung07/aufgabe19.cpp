#include "Zufallsgenerator.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

typedef long long unsigned int bigint;

double gauss(double x, const double SIGMA = 1, const double MY = 0)
{	
	return 1/( SIGMA * sqrt(2 * M_PI) ) * exp( -(x - MY)*(x -MY) / (2 * SIGMA * SIGMA) );
}

double* histogramm (double* array, int len, int n)
{
	// max und min ermitteln
	double max = array[0];
	double min = array[0];
	for(int i = 0; i < len; i++){
		if( array[i] < min ){min = array[i];}
		if( array[i] > max){max = array[i];}
	}
	//cout << min << "\t" << max << endl;
	double intervall = (max - min) / n;
	
	double* histogramm = new double[n];
	double bereich;
	for(int balken = 0; balken < n; balken++){
		bereich =  intervall * balken + min;
		for(int i = 0; i < len; i++){	
			if( bereich <= array[i] && array[i] < (bereich + intervall) ) {histogramm[balken]++;}
		}
	}
	
	return histogramm;
}

int main()
{
	const int LEN = 100000;
	double* array = new double[LEN];
	
	randGen xRand(92305972093508);
	randGen yRand(598769760);
	double x;
	double y;
	int i = 0;
	
	while ( i < LEN ){
		xRand.mlcgXorshift();
		yRand.mlcgXorshift();
		x = xRand.castIn(-1,1);
		y = yRand.castIn(0,1);

		if (y+0.25<= gauss(x)){
			array[i] = x;
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
	cout << "Gauss datei erstellt." << endl;
	
	
	const int N = 15;
	double* ausgabe = histogramm(array,LEN,N);
	
	// In histogramm.dat speichern
	ofstream dateiH;
	dateiH.open ("histogramm.dat", ios::out);
	
	for(int i = 0; i < N; i++){
		dateiH << ausgabe[i] << endl;	
	}
	dateiH.close();
	cout << "Histogramm datei erstellt." << endl;
}

