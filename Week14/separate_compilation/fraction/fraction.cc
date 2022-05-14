#include "fraction.hh"
using namespace std;

fraction::fraction(int n, int d) : num(n), den(d) {}

fraction fraction::operator +(const fraction &f) const {
    return fraction(num * f.den + f.num * den, den * f.den);
}

ostream &operator <<(ostream &s, const fraction &f) {
    return s << f.num << "/" << f.den << endl;
}