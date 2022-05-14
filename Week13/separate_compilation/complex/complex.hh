#pragma once
#include <iostream>

// or #ifndef COMPLEX_HH_
// #define COMPLEX_HH_
// #endif

template<typename T>
class Complex {
private:
    T real;
    T imag;
public:
    Complex(T r, T i) : real(r), imag(i) {}
    friend Complex operator +(const Complex &a, const Complex &b) {
        return Complex(a.real + b.real, a.imag + b.imag);
    }
    friend std::ostream &opeator <<(ostream &s, const Comlex &c) {
        return s << "(" << c.real << ", " << c.imag << ")";
    }
};