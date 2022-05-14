#pragma once
using namespace std;

class fraction {
private:
    int num, den;
public:
    fraction(int n, int d);
    fraction operator +(const fraction &b) const;   // const bc we not changing object, just making a new one
    fraction operator -() const;
    friend std::ostream &operator <<(ostream &s, const fraction &f);
    int getNum() const;
    int getDen() const;
    void setNum(int val);
};