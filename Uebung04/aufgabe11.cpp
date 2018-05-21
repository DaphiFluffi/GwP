#include <iostream>
#include <cmath> 

using namespace std;

/* Berechnet ein Polynom 5.Ordnung. Uebergeben werden x und die sechs Skalare a bis f, 
 * die standardmaessig auf 0 gesetzt werden. Die Skalare werden hintereinander jeweils mit einer Potenz von x 
 * multipliziert, wobei die Exponenten von x bis fünf aufsteigen.*/
float polynom (float x, float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float f = 0)
{
    //return a+b*x+c*x*x+d*x*x*x+e*x*x*x*x+f*x*x*x*x*x; // erspart Einbinden von cmath, ist aber unsauber
    return a+b*x+c*pow(x,2)+d*pow(x,3)+e*pow(x,4)+f*pow(x,5);
}

int main()
{
	//Dieses Ṕolynom hat vier Extrema und schneidet die y-Achse bei x = 2.
    cout << "Erstes Polynom: 6 - x - x^2 + 2x^3 + x^4 - x^5" << endl;
    for (float i = -2;i <= 2;i += 0.01){	//zaehlt das vorgegebende Interwall durch
        cout << i << "\t";
        cout << polynom(i,6,-1,-1,2,1,-1) << endl; //Aufrufen der polynom()-Funktion
    }
    
    // Beschreibt die Speigelung des ersten Polynoms an y = 5.5.
    cout << "Zweites Polynom: 5 + x + x^2 - 2x^3 + x^4 - x^5" << endl;
    for (float i = -2;i <= 2;i += 0.01){	 
        cout << i << "\t";
        cout << polynom(i,5,1,1,-2,-1,1) << endl;  
    }    
}

