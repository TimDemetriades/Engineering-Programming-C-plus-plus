#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}

    Complex operator +(Complex c2) {
        return Complex(real + c2.real, imag + c2.imag);
    }

    Complex operator *(Complex c2) {
        return Complex(real * c2.real, imag * c2.imag);
    }

    Complex operator *(double num) {
        return Complex(real * num, imag * num);
    }

    friend ostream &operator <<(ostream &s, Complex c) {
        s << c.real << " + " << c.imag << "i";
        return s;
    }

    friend istream &operator >>(istream &s, Complex &c) {
        cout << "Please enter a complex number in the form - real, imaginary: " << endl;
        s >> c.real >> c.imag;
        return s;
    }

};



int main() {

    Complex c1(1.5, -0.2);
    Complex c2(0.6, 2.1);
    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;
    Complex c5 = c1 * 2.0;
    
    cout << c3 << " | " << c4 << " | " << c5 << endl;

    Complex c8;     // create empty complex number
    cin >> c8;      // read in complex num from keyboard
    cout << c8 << endl;

    return 0;
}