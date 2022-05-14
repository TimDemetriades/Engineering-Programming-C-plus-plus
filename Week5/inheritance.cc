#include <iostream>
using namespace std;

// parent,  C++ = base class
class Car {
private:
	string color;
	int speed;
public:
	Car(const string& c, int s) : color(c), speed(s) {}

	int payToll() {
		return 15; }
};

// child, c++ = derived class
// a sportscar is a kind of a car
class SportsCar : public Car { // IS_A IS A KIND OF ....
private:
	double horsePower;  // in addition to color and speed, you also have HP
public:
    // You first initialize the Car, then you initialize the SportCar
	SportsCar(const string& c, int s, double hp) : Car(c, s), horsePower(hp) {}
	
	int payToll() { return 25; }
};

/*
this -->   string color        p p p p p p p p
                               s s s s c c c c
           int    speed        s s s s - - - - 
           double horsepower   h h h h h h h h
*/


int main() {
	Car c1("red", 55);
	SportsCar s("red", 180, 280.0); // use inheritance
	cout << c1.payToll();
	cout << s.payToll();

	int x;
	// CRASH!	Car* cp = (Car*)&x;

	Car* cp = &c1;                      // cp is a pointer to the address of the car object c1
	cout << (*cp).payToll() << '\n';
	cout << cp->payToll() << '\n';      // this is the shorthand for the above line

	cp = &s;                            // this takes pointer cp and points it at the address of sports car s
                                        // this is allowed bc a sports car is a type of car (inheritance)
                                        // "the first part of a sports car is a car"
	cp->payToll(); // $15               // does not call sports car pay toll (need VIRTUAL keyword to fix this)


	// if (you are pointing at a car)
	// 	call Car::payToll();
	// else if (you are pointing at a sportscar)
	// 	call SportsCar::payToll();
	

	
}