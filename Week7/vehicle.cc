#include <string>
#include <iostream>
using namespace std;

class Vehicle {
    private:
        int speed;
    public:
        Vehicle(int s) : speed(s) { }

        virtual void payToll() = 0;     // pure virtual functions
                                        // a class with at least one is an 'abstract class'
};

class Car : public Vehicle {
    private:
        string color;
    public:
        Car(int s, const string& color) : Vehicle(s), color(color) { }

        void payToll() { cout << "pay $15\n"; }
};

class SportsCar : public Car {
    private:
        double hp;
    public:
        SportsCar(int s, const string& color, double hp) : Car(s, color), hp(hp) { }
        
        void payToll() override { cout << "pay $25\n"; }        // override is used so we make sure this overides the virtual function in the base clas
};      

int main() {

    //Vehicle v(55);    // can't make an object of an abstract class since it contains a pure virtual function
    Car c(55, "red");
    SportsCar s(90, "red", 450);

    //v.payToll();      // can't do this bc the payToll method is a pure virtual function in the Vehicle class
    c.payToll();
    s.payToll();

    // this is how we can make a vehicle object using pointers, and then call the payToll method for each child class
    Vehicle* v = &c;
    v->payToll();       // (*v).payToll() is another (longer) way to write this
    v = &s;
    v->payToll();   

    return 0;
}
