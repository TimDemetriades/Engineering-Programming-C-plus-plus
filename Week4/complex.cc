#include <iostream>
using namespace std;

// Class for Complex numbers
class Complex {
    private:
        double real, imaginary;
    
    public:
        Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    // Adding by overriding the + operator
    friend Complex operator +(Complex a, Complex b) {
        return Complex(a.real + b.real, 
                        a.imaginary + b.imaginary);
    }

    // Multiplying by overriding the * operator
    friend Complex operator *(Complex a, Complex b) {
        return Complex(a.real * b.real - a.imaginary * b.imaginary, 
                        a.real * b.imaginary + a.imaginary * b.real);
    }

    // Multiplying a complex by a scalar
    friend Complex operator *(Complex a, double s) {
        return Complex(a.real * s, a.imaginary * s);
    }

    // Subtracing by overriding the - operator
    friend Complex operator -(Complex a, Complex b) {
        return Complex(a.real - b.real, 
                        a.imaginary - b.imaginary);
    }

    // Negating by overriding the - operator (it's smart enough to see this has one argument so it uses this one)
    friend Complex operator -(Complex a) {
        return Complex (-a.real, -a.imaginary);
    }

    friend ostream& operator <<(ostream& s, Complex c) {
        return s << "(" << c.real << ", " << c.imaginary << ")";
    }

    friend istream& operator >>(istream& s, Complex& c) {
        return s >> c.real >> c.imaginary;
    }
};

int main() {

    Complex c1(1.5, -0.2);
    Complex c2(0.6, 2.1);
    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;
    Complex c5 = c1 * 2.0;
    
    cout << c3 << ' ' << c4 << ' ' << c5 << endl;

    Complex c8;     // create empty complex number
    cin >> c8;      // read in complex num from keyboard
    cout << c8 << endl;

    return 0;
}