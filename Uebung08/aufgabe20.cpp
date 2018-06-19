// modify precision
#include <iostream>     // std::cout, std::ios
#include <cmath>
using namespace std;


/*Summe bis n: 1.644934057834575
Summe bis 1: 1.644934066615396
*/
int main () {
	double ergebnis1 = 0 ;
	double ergebnis2 = 0 ;
	double n;
	n = pow(2,32)-1;
	for(double i = 1; i <= n; i++){
		ergebnis1 += 1./(i*i);
	}
	for ( double i = n; i >= 1; i--){
		ergebnis2 += 1./(i*i);
	}
	cout.unsetf (ios::floatfield); 
	cout.precision(16);
	cout << "Summe bis n: ";
	cout << ergebnis1 << '\n';
	cout << "Summe bis 1: ";
	cout << ergebnis2 << '\n';
 
  return 0;
}


