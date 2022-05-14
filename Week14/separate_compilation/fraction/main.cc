#include <iostream>
#include "fraction.hh"

int main() {
    try {
        const fraction a(1, 2);
        const fraction b(1, 3);
        fraction c = a + b;
        std::cout << c << std::endl;
        //fraction d(1, 0);   // this should not work
    }
    catch(const char *msg) {
        std::cout << msg << std::endl;
    }
}