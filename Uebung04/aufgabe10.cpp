#include "swap.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int a = 1;
	int x =2;
	int& b=a;
	int& c=x;
	cout << swap_ref(b,c);
	cout << "blubb";	
}
