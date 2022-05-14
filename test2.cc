#include<iostream>
using namespace std;
  
class Dynamuck {
private:
  int *p;
  int size;

public:
    Dynamuck(int size) : size(size) {
        p = new int[size]; // allocate size integers
        cout << "Constructor called with size: " << size << endl;
    }

    ~Dynamuck() {
        delete [] p;
        cout << "Destructor called" << endl;
    }

    Dynamuck(const Dynamuck &orig) : size(orig.size) {
        p = new int[size];
        cout << "Copy constructor called with size: " << size << endl;
    }

    Dynamuck &operator =(const Dynamuck &orig) {
        cout << "Assignment Operator = called" << endl;
        if (this != &orig) {
            delete [] p;
            p = new int[orig.size];
            size = orig.size;
        }
        return *this;
    }

    // Dynamuck &operator =(Dynamuck copy) {
    //     size = copy.size;
    //     swap(p, copy.p);
    //     cout << "Assignment Operator = called with size: " << size << endl;
    //     return *this;
    // }

};
int main() {
    cout << "Make a" << endl;
  Dynamuck a(50); // allocate 50 integers
    cout << "Make b as a copy of a" << endl;
  Dynamuck b(a); // make a copy of a
    cout << "Make c as a copy of a" << endl;
  Dynamuck c = a; // make another copy
    cout << "Make d" << endl;
  Dynamuck d(20); // make another, smaller object
    cout << "Assign c to d" << endl;
  c = d;          // overwrite c with a copy of the smaller d
}