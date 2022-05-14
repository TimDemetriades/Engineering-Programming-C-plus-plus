#include <iostream>
#include "fraction.hh"
using namespace std;

fraction::fraction(int n, int d) : num(n), den(d) {
    if (d == 0) {
        throw "Divide by zero!";        // throw error if 0 given as den
    }
}

fraction fraction::operator +(const fraction &b) const{
    return fraction(num * b.den + b.num * den, den * b.den);
}

fraction fraction::operator -() const {
    return fraction(-num, den);
}

ostream &operator <<(ostream &s, const fraction &f) {
    return s << f.num << "/" << f.den;
}

int fraction::getNum() const {
    return num;
}

int fraction::getDen() const {
    return den;
}

void fraction::setNum(int val) {
    num = val;
}