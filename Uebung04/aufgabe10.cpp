#include "swap.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int a,x;
	cout << "1.Zahl: ";
	cin >> a;
	cout << "2.Zahl: ";
	cin >> x;
	int& b=a;
	int& c=x;
	cout << swap_ref(b,c);
}
