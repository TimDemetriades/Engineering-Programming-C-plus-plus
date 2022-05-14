#include <iostream>
using namespace std;

#include "fraction.hh"

int main() {
    try {           // for error handling
        const fraction f1(1, 2);
        fraction f2(1, 0);
        fraction f3 = f1 + f2;
        fraction f4 = -f1;

        cout << f4 << endl;
        cout << f1.getNum() << endl;
        cout << f1.getDen() << endl;
        f2.setNum(13);
    }  
    catch(const char *msg) {
        cerr << msg << endl;    // dislay error mesage (cerr is standard error stream (unbuffered))
    }
}