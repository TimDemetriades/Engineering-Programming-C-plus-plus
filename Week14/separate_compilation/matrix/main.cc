#include <iostream>
using namespace std;

#include "matrix.hh"

int main() {
    try{
        const matrix a(3, 4, 2.5);

        matrix b = a;

        b(1, 2) = 1.1;

        cout << b << endl;

        matrix c = a + b;

        cout << c << endl;

        matrix d(2, 2, 1.9);

        matrix e = c + d;       // should throw exception
    } catch(const bad_size &e) {
        cerr << e << endl;
    }
}