#include <iostream>

using namespace std;

class Fraction {
    private:

    public:
    int num, den;

    Fraction(int n = 0, int d = 1) : num(n), den(d){

    }

    friend Fraction operator +(Fraction a, Fraction b) {
        return Fraction(a.num * b.den + b.num * a.den, a.den * b.den);
    }

    friend Fraction operator -(Fraction a) {
        return Fraction(a.num * -1, a.den);
    }

    friend ostream& operator <<(ostream& s, Fraction f) {
        s << f.num << '/' << f.den;
        return s;
    }
};


int main()
{
    int f1_num, f2_num = 0;
    int f1_den, f2_den = 1;
    cout << "Give me 2 fractions: " << endl;
    cin >> f1_num;
    cin >> f1_den;
    cin >> f2_num;
    cin >> f2_den;
    Fraction f1(f1_num, f1_den);
    Fraction f2(f2_num, f2_den);
    Fraction f3 = f1 + f2;

    cout << "The sum of fraction 1 and fraction 2 is: " << f3 << endl;

    Fraction f4 = -f1;

    cout << "The negation of fraction 1 is: " << f4 << endl;

    return 0;
}