#ifndef FRACTION_HH_
#define FRACTION_HH_

#include <iostream>

class Fraction {
private:
  int num, den;
public:
	Fraction(int num, int den);		// constructor 

	friend Fraction operator +(Fraction a, Fraction b);		// friend function

	friend std::ostream& operator <<(std::ostream& s, Fraction f);  // friend function
	// notice the std:: is used here
	// although you can use using namespace std instead, it is better to use the fully qualified now
	// this is the convention for header files so that there are no conflicts

	Fraction operator -() const;  
	// const means you won't change the variable it returns, you make a copy instead

};
#endif
