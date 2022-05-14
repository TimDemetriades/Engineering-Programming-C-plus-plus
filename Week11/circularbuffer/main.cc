#include "circularbuffer.hh"
#include <iostream>
using namespace std;



int main() {
    circularbuffer b(32);
    b.enqueue(3);     // add to queue
    for(int i = 0; i < 10; i++)
        b.enqueue(i);   // queue should be - 3 0 1 2 3 4 5 6 7 8 9

    while(!b.isEmpty()) {
        cout << b.dequeue() << ' ';
    }

}