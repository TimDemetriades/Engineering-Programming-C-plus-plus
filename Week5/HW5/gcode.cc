#include <iostream>
#include <vector>
using namespace std;

// Shape is an abstract class
// It was be used for other shapes to inherit from
class Shape {
//protected:
    // double x, y;     // How to set x and y in Shape instead of in Circle and Square
private:
    
public:
    virtual void print(ostream& s) = 0;   // setting = 0 zero means the code for the method doesnt exist here
                                // we will have the code in the methods of the child objects
};

// Class Circle inherits from class Shape
class Circle : public Shape {
private:
    double x, y;
    double radius;
public:
    void print(ostream& s) {

    }
};

// Class Square inherits from class Shape
class Square : public Shape {
private:
    double x, y;
    double side_len;
public:
    Square(double x, double y, double side_len) : x(x), y(y), side_len(side_len) { }
    void print(ostream& s) {
        double e = 0;
        // g0 and g1 are 3d printer commands
        // g0 means go to this location
        // g1 means print at this location
        s << "g0 x" << x << " y" << y << endl;   // go to x, go to y
        e += side_len;  // how much plastic to extrude
        s << "g1 x "<< (x + side_len) << " y" << (y) << " e" << e << endl;
        e += side_len;
        s << "g1 x "<< (x + side_len) << " y" << (y + side_len) << " e" << e << endl;
        e += side_len;
        s << "g1 x "<< (x) << " y" << (y + side_len) << " e" << e << endl;
        e += side_len;
        s << "g1 x "<< (x) << " y" << (y) << " e" << e << endl;
    }

};

int main() {
    ofstream f("output.txt");

    vector<Shape*> shapes;
    //shapes.push_back(new Circle(0, 0, 3));  // at x = 0, y = 0, radius = 3
    shapes.push_back(new Square(2, 0, 2));  // at x = 2, y = 0, side length = 2

    for (auto s : shapes)
        s->print(f); // print every shape in vector shapes


    return 0;
}


/*
Instruction for HW
1. Write to a file, not to cout
2. Implement printing circle (polygon approximation, use a variable to control number of facets (aka how curved edges are))
3. (Optional) Can you move x, y into Shape class to save effort?
*/