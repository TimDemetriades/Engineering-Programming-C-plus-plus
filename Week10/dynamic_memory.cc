#include <iostream>
using namespace std;

class world {
private:
    uint32_t n;         // size
    int32_t *map;

public:
    // Constructor
    world(uint32_t size) : n(size), map(new int32_t[n * n]) {
        for(uint32_t i = 0; i < n * n; i++)
            map[i] = 0;
    }

    // Destructor
    ~world() {
        delete [] map;
    }

    // Copy constructor
    world(const world &orig) : n(orig.n), map(new int32_t[orig.n * orig.n]) {
        for(uint32_t i = 0; i < n * n; i++) {
            map[i] = orig.map[i];
        }
    }

    // // Assignment (old way)
    // world &operator =(const world & orig) {
    //     if(this != &orig) {     // if the address of this object is not the same as the address of the orig (comparing pointers)
    //         delete [] map;
    //         n = orig.n;
    //         map = new int32_t[n * n];
    //         for(uint32_t i = 0; i < n * n; i++)
    //             map[i] = orig.map[i];
    //     }
    //     return *this;
    // }

    // Assignment (new way, uses copy constructor)
    world &operator =(world copy) {
        n = copy.n;
        swap(map, copy.map);    // after the swap, copy object will go away (destructor is called)
        return *this;
    }
};

int main() {


    return 0;
}