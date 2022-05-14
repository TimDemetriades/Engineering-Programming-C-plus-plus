#include <iostream>
using namespace std;

int main() {

    const int SIZE = 10;
    int x[SIZE] = {5, 6, 1};

    // Print array x
    for (int i = 0; i < SIZE; i++)
        cout << x[i] << ' ';
    cout << endl;

    // Print array using pointers   
    for (int* p = &x[0]; p < x + SIZE; p++)     // create a pointer p and point to first element of array x
                                                // x is the memory address of the first element of array x
                                                // so we go to this address plus the size of the array
                                                // we incremenent pointer p each iteration
        //cout << p << ' ';                     // this prints address of pointer p
        cout << *p << ' ';                      // this prints out values of what p points to (elements of array x)
    cout << endl;       

    // Another way to print array using pointers
    for (int *p = x; p < x + 10; p++)
        cout << *p << ' ';
    cout << endl;

    return 0;
}