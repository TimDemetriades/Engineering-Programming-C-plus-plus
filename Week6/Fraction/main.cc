#include "Fraction.hh"
using namespace std; // in a C++ file, we can use "using namespace"
int main() {
	Fraction a(1,2); // 1/2
	Fraction b(1,3); // 1/3
	Fraction c = a + b;
	cout << c;
}
	
