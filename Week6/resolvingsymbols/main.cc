// We can use extern to declare a variable or function that exists elsewhere
// i.e. they are defined in a different file
// All variables and functions MUST be defined somewhere, but only once!
// You can make as many declarations as you want

// A C++ object file is an intermediate file produced by a C++ compiler 
// from a C++ implementation file and the C++ header files that the 
// implementation file includes. 

#include <iostream>
using namespace std;

extern void f(); // declaration that function f exists
void f(); // function prototype (same)

extern float x; // declaration (we are saying x is defined in a separate file)
extern float x;
extern float x;
extern float x;
extern float x;
//extern int y;  // undefined symbol
float x = 1.5f; //globals are binary zero
double pi = 3.141592653589793;
int main() {
	cout << x << '\n';
	cout << pi << '\n';
	f();
	cout << pi << '\n';
	//	cout << y << '\n';
}