#include <iostream>
using namespace std;

class BadGrowArray {
    private:
        int* p;
        uint32_t len;
    public:
        // Constructor
        BadGrowArray() : p(nullptr), len(0) {
        cout << "Constructor called" << endl;
        }

        // Destructor
        ~BadGrowArray() {
            cout << "Destructor called" << endl;
            delete [] p;
        }

        // Copy Constructor
        // Used when a new object is created from an existing object, as a copy of the existing object
        BadGrowArray(const BadGrowArray& orig) : p(new int[orig.len]), len(orig.len) {
            cout << "Copy constructor called" << endl;
            for(int i = 0; i < len; i++)
                p[i] = orig.p[i];
        }

        // // Operator = for Copy Constructor (OLD WAY)
        // // Used when an already initialized object is assigned a new value from another existing object of the same class
        // BadGrowArray& operator =(const BadGrowArray& orig) {
        //     cout << "Assignment operator = called (old)" << endl;
        //     if (this != &orig) {
        //         delete [] p;
        //         p = new int[orig.len];
        //         len = orig.len;

        //         for (int i = 0; i < len; i++)
        //             p[i] = orig.p[i];
        //     }
        //     return *this;
        // }

        // Operator = for Copy Constructor (NEW WAY for C++11, calls copy constructor first to create a new object called copy) 
        // Used when an already initialized object is assigned a new value from another existing object of the same class
        BadGrowArray& operator =(BadGrowArray copy) {
            cout << "Assignment operator = called (new)" << endl;
            swap(p, copy.p);    // swap array p points to and array copy.p points to
            len = copy.len;     // sets length of the array to the length of the array being copied
            return *this;       // returns the object (this is a pointer to the object)
        }

        // Move Constructor
        BadGrowArray(BadGrowArray &&orig) : len(orig.len), p(orig.p) {
            orig.p = nullptr;       // why not delete [] p??
        }

        // Add elements to the end of the array
        void add_to_end(int v) {
            const int* old = p;     // remember what p currently points to with a new pointer called old
            p = new int[len + 1];   // point p to new array of size 1 greater than current array
            for (int i = 0; i < len; i++)
                p[i] = old[i];      // copy values from old array to new array
            delete [] old;          // unallocate memory from old (to prevent memory leak)
            p[len] = v;             // set last element to v
            len++;                  // increase length since we added a new element
            // or do it in one step: p[len++] = v
        }

        friend ostream& operator <<(ostream& s, BadGrowArray& array) {      // don't make copies of dynamic elements! use referenes (&)
            for (int i = 0; i < array.len; i++)
                s << array.p[i] << ' ';
            return s;
        }
};

int main() {
    BadGrowArray a;
    for (int i = 0; i < 10; i++)
        a.add_to_end(i);    // 0 1 2 3 4 5 6 7 8 9 
    cout << "Array a: " << a << endl;;

    BadGrowArray b = a;     // create a copy of BadGrowArray a (using the copy constructor!)
    b.add_to_end(10);
    cout << "Array a: " << a << endl;
    cout << "Array b: " << b << endl;

    BadGrowArray c;
    c = b;                  // assign b to c (uses the assignment operator =)
    cout << "Array b: " << b << endl;
    cout << "Array c: " << c << endl;
}