#include <iostream>
using namespace std;

#include "Complex.hh"

int main() {
    Complex<double> a(1.5, 2.1);
    Complex<double> b(1.5, 2.1);
    Complex<double> c = a + b;
    cout << c << endl;

    Complex<float> d(1.5f, 2.3f);
    Complex<float> e(-1.25f, 9.1f);
    Complex<float> f = d + e;
    cout << f << endl;
}