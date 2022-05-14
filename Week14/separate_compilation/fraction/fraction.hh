#pragma once

#include <iostream>

class fraction {
private:
    int num, den;
public:
    fraction(int n = 0, int d = 1);
    fraction operator +(const fraction &f) const;
    friend std::ostream &operator <<(std::ostream &s, const fraction &f);
};