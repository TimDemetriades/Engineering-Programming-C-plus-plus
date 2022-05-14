#include "circularbuffer.hh"
#include <utility>

using namespace std;

circularbuffer::circularbuffer(uint32_t capacity) 
    : p(new uint32_t[capacity]), capacity(capacity - 1), head(0), tail(0) {}

circularbuffer::~circularbuffer() {
    delete [] p;
}

circularbuffer::circularbuffer(const circularbuffer &orig) 
    : p(new uint32_t[orig.capacity + 1]), capacity(orig.capacity), head(orig.head), tail(orig.tail) {
    if (head < tail){
    for (uint32_t i = head; i < tail; i++)
        p[i] = orig.p[i];
    }
    else if (head == tail) {
        // copy nothing, queue is empty
    }
    else {      // when tail is less than head
        for (uint32_t i = head; i <= capacity; i++) {
            p[i] = orig.p[i];
        }
        for (uint32_t i = 0; i < tail; i++)
            p[i] = orig.p[i];
    }
}

#if 0
// Assignment operator = (old way)
circularbuffer &circularbuffer::operator =(const circularbuffer &orig) {
    if (this != &orig) {
        delete [] p;
        p = new uint32_t[orig.capacity];
        capacity = orig.capacity;
        head = orig.head;
        tail = orig.tail;
        
        if (head < tail){
        for (uint32_t i = head; i < tail; i++)
            p[i] = orig.p[i];
        }
        else if (head == tail) {
            // copy nothing, queue is empty
        }
        else {      // when tail is less than head
            for (uint32_t i = head; i <= capacity; i++) {
                p[i] = orig.p[i];
            }
            for (uint32_t i = 0; i < tail; i++)
                p[i] = orig.p[i];
        }
    }
    return *this;
}
#endif

// Assignemnt operator = (new way)
circularbuffer &circularbuffer::operator =(circularbuffer copy) {
    capacity = copy.capacity;
    head = copy.head;
    tail = copy.tail;
    swap(p, copy.p);
    return *this;
}

// Move constructor
circularbuffer::circularbuffer(circularbuffer &&orig) 
    : p(orig.p), capacity(orig.capacity), head(orig.head), tail(orig.tail) {
    orig.p = nullptr;
}

//TODO: double in size
void circularbuffer::grow() {}

void circularbuffer::enqueue(uint32_t v) {
    p[tail] = v;
    tail = (tail + 1) & (capacity);     // this is more efficient than the if statement below

    // if (tail >= capacity)
    //     tail = 0;

    //if (tail == head)   // queue is full
        //grow();
}

uint32_t circularbuffer::dequeue() {
    uint32_t temp = p[head];
    head = (head + 1) & capacity;
    return temp;
}

bool circularbuffer::isEmpty() const {
    return head == tail;        // empty when head and tail are equal
}