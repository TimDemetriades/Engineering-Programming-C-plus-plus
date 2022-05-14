#include <iostream>
using namespace std;

int main() {

    int a = 2, b = 3;
    // 4 ways to add 1 to a
    a = a + 1;
    a += 1;
    a++;
    ++a;

    b--;

    int c = a++;    // c = 6  a = 7  int c = a; a++;
                    // add a to c and then increment it
    c = ++a;        // first increment a and then add it to c
                    // a = 8  c = 8

    int d = b++ - --a;      // first decrement a, then do the subtraction, then increment b
                            // a = 7  d = 2 - 7  b = 3

    int arr[10] = {6, 9, 1};    // other 7 elements of array are 0
                                // as long as you initailize one elemenet in a array the rest will be set to 0
    int i = 2, j = 1;
    arr[i++] += arr[j--];       // arr[i] += arr[j] // arr[2] = 10  i = 3  j = 0
    arr[++i] *= arr[j++];       // i = 4  arr[i] *= 6 arr[4] = 0  j = 1


    return 0;
}