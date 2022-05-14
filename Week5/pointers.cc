#include <iostream>
using namespace std;

void f(int& x) {
    cout << "Address of reference of x: " << &x << endl;                 // prints out the address of the referenced variable (not x)
    cout << "Size of what x references: " << sizeof(x) << endl;          // prints the size what x references (not x)
    // x = 0;
}

int main() {
    int a;      // order of variables in memory is NOT GUARANTEED
    char c = 'a';     
    // normally, we don't care where a lives, and we do not get to choose

    int b = 2;

    // print the memory address's where this variables live
    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;
    cout << "Address of c: " << &c << endl;

    const int d = 124;

    f(b);

    // a pointer is declared in reverse
    // "what p points to is an int, therefore p is a pointer to int"
    int *p;
    // cout << *p << endl;  // probably crash, looking at random memory location
    // *p = 124;
    int* q = &a;    // spaces make no difference. q is pointing to a
    *q = 5;         // set the value of a  ->  *q is an ALIAS of a
    *q = a;         // same as saying a = a; DOES NOTHING
    q = &b;         // point somewhere else
    cout << *q << endl;
    //int *a, b;    // don't do this: a is a pointer to int, b is an int

    double x[10];
    cout << "Size of array x: " << sizeof(x) << endl;  // sizeof(double) * 10 elements in array = (64bits/8bitsperbyte=8bytes) * 10 = 80
    cout << "Size of point q: " << sizeof(q) << endl;  // sizeof(pointer) = 8 on a 64 bit machine
                                // no one has (4*10^9)^2 = 16 000 000 000 000 000 000 bytes of RAM

    cout << "Address of the start of array x: " << x << endl;   // the name of an array is a pointer to the start

    return 0;
}