#include <iostream>

using namespace std;

float polynom (float x, float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float f = 0)
{
    return a+b*x+c*x*x+d*x*x*x+e*x*x*x*x+f*x*x*x*x*x; // erspart math include
}

int main()
{
    cout << "Polynom w = " << endl;
    for (float i = -2;i <= 2;i += 0.01){
        cout << i << "\t";
        cout << polynom(i,0,5,-4,3,-2,1) << endl; // ich hatte noch niee ein 5stelliges Lieblingspolynom -_-
    }
    
    cout << "Polynom x = " << endl;
    for (float i = -2;i <= 2;i += 0.01){
        cout << i << "\t";
        cout << polynom(i,6,-1,-1,2,1,-1) << endl;  // viele lokale Maxima und f(2) rund 0
    }    
}

