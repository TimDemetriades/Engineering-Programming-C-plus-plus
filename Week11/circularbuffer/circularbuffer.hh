#pragma once

#include <iostream>
#include <cstdint>

class circularbuffer {
private:
    uint32_t *p;
    uint32_t capacity;
    uint32_t head, tail;

public:
    // capacity should always be a power of 2 (for more efficiency in enqueue)
    circularbuffer(uint32_t capacity);
    ~circularbuffer();

    // Copy constructor
    circularbuffer(const circularbuffer &orig);
    // Assignment operator = (old way)
    //circularbuffer &operator =(const circularbuffer &orig);
    // Assignment operator = (new way)
    circularbuffer &operator =(circularbuffer copy);
    // Move constructor
    circularbuffer(circularbuffer&& orig);

    void enqueue(uint32_t v);
    uint32_t dequeue();
    void grow();

    bool isEmpty() const;
};