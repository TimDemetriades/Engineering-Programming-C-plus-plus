#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

template<typename T>
class GrowArray {
private:
    uint32_t capacity;  // max size of array
    uint32_t size;      // current size of array
    T *data;

    // private bc only used internally
    void checkGrow() {
        if (size < capacity) 
            return;
        cout << "Max capacity reached! Doubling capacity." << endl;
        const T *old = data;  // hold old data
        data = new T[capacity * 2];   // allocate new array, double capacity (big O = 2n)
        memcpy(data, old, size * sizeof(T));  // copy data from old array
        capacity *= 2;
    }

public:
    // Constructor
    GrowArray(uint32_t c) : capacity(c), size(0), data(new T[capacity]) {}

    // Destructor
    ~GrowArray() {
        delete [] data;
    }

    // Copy Constructor
    GrowArray(const GrowArray &orig) : capacity(orig.capacity), size(orig.size), data(new T[orig.capacity]) {
        memcpy(data, orig.data, size * sizeof(T));
    }

    // Assignment Operator =
    GrowArray &operator =(GrowArray copy) {
        capacity = copy.capacity;
        size = copy.size;
        swap(data, copy.data);
        return *this;
    }

    // Move Constructor
    GrowArray(GrowArray &&orig) : capacity(orig.capacity), size(orig.size), data(orig.data) {
        orig.data = nullptr;
    }

    // Printing with cout
    friend ostream &operator <<(ostream &s, const GrowArray &array) {
        for (int i = 0; i < array.size; i++)
            s << array.data[i] << " ";
        return s;
    }

    // Adding elements to end of array
    void addEnd(const T &value) {
        checkGrow();
        data[size] = value;
        size++;
    }

    uint32_t getCapacity() {
        return capacity;
    }

    uint32_t getSize() {
        return size;
    }
};

int main() {
    GrowArray<double> a(5);
    cout << "Capcity = " << a.getCapacity() << endl;
    cout << "Size = " << a.getSize() << endl;

    a.addEnd(3.5);
    a.addEnd(2.4);
    a.addEnd(1.3);
    cout << "Array a:\n" << a << endl;
    cout << "Capcity = " << a.getCapacity() << endl;
    cout << "Size = " << a.getSize() << endl;

    GrowArray<double> b = a;
    b.addEnd(12);
    cout << "Array b:\n" << b << endl;

    GrowArray<string> c(5);
    c.addEnd("this");
    c.addEnd("is");
    c.addEnd("a");
    c.addEnd("test");
    cout << "Array c:\n" << c << endl;

    // a.addEnd(3);
    // a.addEnd(2);
    // a.addEnd(1);
    // cout << a << endl;
    // cout << "Capcity = " << a.getCapacity() << endl;
    // cout << "Size = " << a.getSize() << endl;

    // for (int i = 0; i < 25; i++) {
    //     a.addEnd(i);
    // }
    // cout << a << endl;
    // cout << "Capcity = " << a.getCapacity() << endl;
    // cout << "Size = " << a.getSize() << endl;
}