#include <iostream>
using namespace std;

// fill the array x with zeros (using pointer)
void fill(int x[], int size) {
	//x[i] = 0; // NO, use pointer!!! *p++ = 0
	for (int *p = x; p < x + size; p++)
		*p = 0;
}

// add 1 to every element of x
void increment(int x[], int size) {
	for (int *p = x; p < x + size; p++)
		*p += 1;
}

// double every element of x
void doubleMe(int x[], int size) {
	for (int *p = x; p < x + size; p++)
		*p *= 2;
}

// print out every element of x separated by spaces then newline
void print(const int x[], int size) {
	// for (int i = 0; i < size; i++)
	// 	cout << *(x + i) << " ";
	// 	// or cout << x[i] << " ";
	for (const int *p = x; p < x + size; p++)
		cout << *p << " ";
	cout << endl;
}

int main() {
    int x[10] = {1};
    const int size = sizeof(x) / sizeof(int);
    print(x, size);
	fill(x, size);
	print(x, size);
	increment(x, size);
	print(x, size);
	doubleMe(x, size);
	print(x, size);

    return 0;
}