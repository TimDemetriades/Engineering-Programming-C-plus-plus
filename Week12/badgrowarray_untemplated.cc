#include <iostream>
#include <utility>
using namespace std;

class BadGrowArray {
private:
    int *data;
    uint32_t size;
public:
    // Constructor
    BadGrowArray() : size(0), data(nullptr) {}      // starts empty

    // Destructor
    ~BadGrowArray() {
        delete [] data;
    }

    // Copy Constructor
    BadGrowArray(const BadGrowArray &orig) : size(orig.size), data(new int[orig.size]) {
        for (int i = 0; i < size; i++)
            data[i] = orig.data[i];
    }

    // Assignment Operator =
    BadGrowArray &operator =(BadGrowArray copy) {
        size = copy.size;
        swap(data, copy.data);
        return *this;
    }

    // Move Constructor
    BadGrowArray(BadGrowArray &&orig) : size(orig.size), data(orig.data) {
        orig.data = nullptr;
    }

    // Printing array with cout
    friend ostream &operator <<(ostream &s, const BadGrowArray &array) {
        for (int i = 0; i < array.size; i++) 
            s << array.data[i] << ' ';
        return s;
    }

    // Adding new elements to array
    void addEnd(int value) {
        const int *old = data;          // save old array
        data = new int[size+1];         // allocate new array one bigger than old array
        for (int i = 0; i < size; i++)  
            data[i] = old[i];           // copy all elements in old array to new array
        delete [] old;                  // delete old array (deallocate memory to prevent leak)
        data[size] = value;             // put new element at end of new array
        size++;                         // increase size variable
    }

};


int main() {
    BadGrowArray a;
    a.addEnd(3);
    a.addEnd(1);
    a.addEnd(4);
    for (int i = 0; i < 10; i++)    // o(n^2)   SLOW!!!
        a.addEnd(i);
}