#include <iostream>
using namespace std;

void f(int n) {
    int* p = new int[n];
    p[0] == 99;
    p[n-1] = 102;

    // should be releasing memory to prevent memory leakage
    // delete [] p;
}

int main() {
    int a;
    int* p = new int[10];

    p = new int[10];

    delete [] p;        // using the [] is IMPORTANT so it deletes all the p objects
//     for (int i = 0; i < 1000000; i++)
//         f(100);
}