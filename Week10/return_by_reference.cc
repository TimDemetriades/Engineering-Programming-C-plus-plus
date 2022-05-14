#include <iostream>
using namespace std;

// by reference
void rect_to_polar(double x, double y, double &r, double &theta) {
    r = sqrt(x * x + y * y);
    theta = atan2(y, x);    // with atan(y / x) , if could divide by 0!
}

// by pointer
void rect_to_polar(double x, double y, double *r, double *theta) {
    *r = sqrt(x * x + y * y);
    *theta = atan2(y, x);    // with atan(y / x) , it could divide by 0!
}


// by reference
void minmax(int a, int b, int &min, int &max) {
    if (a < b)  {
        min = a;
        max = b;
    }
    else {
        min = b;
        max = a;
    }
}

// by pointer
void minmax(int a, int b, int *min, int *max) {
    if (a < b) {
        *min = a;
        *max = b;
    }
    else {
        *min = b;
        *max = a;
    }
}


int main() {
    double x = 3, y = 4;
    double r, theta;

    rect_to_polar(x, y, r, theta);
    rect_to_polar(x, y, &r, &theta);

    // the second way is preferred by some (like google) bc it makes it obvious
    // that r and theta are changing (rather than using copies)

    int a = 3, b = 6;
    int min, max;
    minmax(a, b, min, max);
    minmax(a, b, &min, &max);

    return 0;
}