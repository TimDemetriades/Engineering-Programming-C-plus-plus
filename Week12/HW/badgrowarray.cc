#include <iostream>
using namespace std;

class BadGrowArray {
private:
    uint32_t size;
    int *data;
public:
    // Constructor
    BadGrowArray() : size(0), data(nullptr) {}

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

    // Printing with cout
    friend ostream &operator <<(ostream &s, const BadGrowArray &array) {
        for (int i = 0; i < array.size; i++)
            s << array.data[i] << " ";
        return s;
    }

    // Adding elements to end of array
    void addEnd(int value) {
        const int *old = data; // make pointer to hold current array
        data = new int[size + 1]; // allocate array that is one element bigger than current array
        for (int i = 0; i < size; i++) 
            data[i] = old[i]; // copy data to new array
        delete [] old; // unallocate old array
        data[size] = value; // add new element to end of array
        size++; // increase size by 1
    }

    // Adding elements to start of array
    void addStart(int value) {
        const int *old = data;
        data = new int[size + 1];
        for (int i = 0; i < size; i++)
            data[i + 1] = old[i];
        delete [] old;
        data[0] = value;
        size++;
    }
};

int main() {

    BadGrowArray a;
    a.addEnd(3);
    a.addEnd(1);
    a.addStart(5);
    a.addEnd(4);

    cout << a;

    return 0;
}