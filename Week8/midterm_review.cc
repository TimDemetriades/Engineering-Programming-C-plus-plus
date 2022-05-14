#include <iostream>
#include <cmath>
using namespace std;

void demean(double x[], int n)
{
    double sum = 0.0;
    double mean = 1.0;
    for(int i = 0; i < n; i++)
    {
        sum += x[i];
    }
    mean = sum / n;

    for(int i = 0; i < n; i++)
        x[i] -= mean;
}

int main() {

    const int n = 4;
    double x[n] = {3, 4, 5, 6};
    for(int i = 0; i < n; i++)
        cout << x[i] << " ";
    demean(x, n);
    for(int i = 0; i < n; i++)
        cout << x[i] << " ";

    // // Type Promotion
    // double a = 3 / 2;   // 1.0
    // double b = 3 / 2 + 5 / 2;   // 3.0
    // double c = 3.0 / 2 + 5 / 2; // 3.5
    // int d = 3.0 / 2 + 5.0 / 2;  // 4
    // int e = 1.6 * 3;    // 4

///////////////////////////////////////////////////////////////////////////////////////

    // // Math library, rules of inf and nan
    // // Floating point division by zero to return NaN (if numerator is 0.0f),
    // // infinity (if numerator is positive) or -infinity (if numerator is negative).
    // //int x = 1 / 0;  // nan  (since int and not double)
    // double a = 1.0 / 0.0;   // inf
    // double b = -1.0 / 0.0;  // neg inf
    // double a2 = a * 2;      // inf
    // double b2 = b + 1;      // neg inf 
    // double c = a + b;       // nan
    // double d = 0.0 / 0.0;   // nan
    // double e = sqrt(a);     // inf
    // double f = sqrt(b);     // nan
    // double g = sin(a);      // nan
    // bool test = isinf(g);

///////////////////////////////////////////////////////////////////////////////////////

    // // Code snippets
    // // count from 1 to 10
    // for (int i = 1; i <= 10; i++)
    //     cout << i << " ";

    // // count from 0 to 9
    // for (int i = 0; i < 10; i++)
    //     cout << i << " ";

    // // count from 10 to 0
    // for (int i = 10; i >= 0; i--)
    //     cout << i << " ";

    // // sum the unsigned whole numbers from a to b inclusive.
    // REMEMBER - You can't have a function within a function (main is a function)
    // uint32_t sum(uint32_t a, uint32_t b);

    // // Function takes 2 params x and y and computes r and theta returning them by reference
    // void rect2polar(double x, double y, double &r, double &theta) 
    // {
    //     r = sqrt(x*x + y*y);
    //     theta = atan(y / x);
    // }

///////////////////////////////////////////////////////////////////////////////////////

    // // Write a loop to:
    // // count from 1 to 1024 doubling each time
    // for (uint32_t i = 1; i <= 1024; i *= 2)
    //     cout << i << " ";

    // // start with 100 dividing by 3 each time,
    // // stopping when 0 is reached (don't print 0)
    // for (int i = 100; i > 0; i /= 3)
    //     cout << i << " ";

    // // write a nested loop to print an n by n multiplication table
    // void mult(int &n)
    // {
    //     int num = 1.0;

    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= n; j++) {
    //             if (j == n)
    //                 cout << num * j << "\n";
    //             else
    //                 cout << num * j << "\t";
    //         }
    //         num += 1;
    //     }
    // }

    // or

    // void mult(int &n)
    // {
    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= n; j++) {
    //             if (j == n)
    //                 cout << i * j << "\n";
    //             else
    //                 cout << i * j << "\t";
    //         }
    //     }
    // }

///////////////////////////////////////////////////////////////////////////////////////

    // // Write a function to compute the following sums and products
    // // sum numbers from 5 to 15 inclusive
    // int sum(int a = 5, int b = 15)
    // {
    //     int summation = 0;
    //     for(int i = a; i <= b; i++)
    //         summation += i;
    //     return summation;
    // }

    // // compute product from 3 to 7 inclusive
    // int prod(int a = 3, int b = 7)
    // {
    //     int product = 1;
    //     for(int i = a; i <= b; i++)
    //         product *= i;
    //     return product;
    // }

    // // compute sum of squares from 3 to 6 inclusive
    // int sumsquares(int a = 3, int b = 6)
    // {
    //     int sum = 0;
    //     for(int i = a; i <= b; i++)
    //         sum += (i * i);
    //     return sum;
    // }

    // sum odd numbers between 4 and 9
    // int sumOdd(int a = 4, int b = 9)
    // {
    //     int sum = 0;
    //     for(int i = a; i <= b; i++)
    //         if(i % 2 == 1)
    //             sum += i;
    //     return sum;
    // }

    // // choose (n,r) = n! / (r! (n-r)!)
    // int choose(int n, int r)
    // {
    //     double combination = 1.0;
    //     int numerator = 1;
    //     for(int i = 1; i <= n; i++) // compute factorial to n
    //         numerator *= i;

    //     int denominator_1 = 1;
    //     int denominator_2 = 1;
    //     for(int i = 1; i <= r; i++) // compute factorial to r
    //         denominator_1 *= i;
    //     for(int i = 1; i <= (n-r); i++) // compute factorial to n-r
    //         denominator_2 *= i;

    //     return (numerator / (denominator_1 * denominator_2));
    // }

    // // rect2polar with r and theta passed using pointers to double
    // void rect2polar(double x, double y, double *r, double *theta)
    // {
    //     *r = sqrt(x * x + y * y);
    //     *theta = atan2(y, x);   // or atan(y / x)
    //     cout << *r << endl;
    //     cout << *theta << endl;
    // }

    // double x = 5;
    // double y = 5;
    // double r = 0;
    // double theta = 0;
    // rect2polar(x, y, &r, &theta);

    ///////////////////////////////////////////////////////////////////////////////////////

    // // Write functions to perform computations on arrays
    // // double mean(int x[], int n)
    // // answer should be double even though the numbers are ints
    // double mean(int x[], int n)
    // {
    //     double sum = 0.0;
    //     for(int i = 0; i < n; i++)
    //     {
    //         sum += x[i];
    //     }
    //     return sum / n;
    // }

    // void demean(double x[], int n);
    // compute the mean, then the mean from each element
    // void demean(double x[], int n)
    // {
    //     double sum = 0.0;
    //     double mean = 1.0;
    //     for(int i = 0; i < n; i++)
    //     {
    //         sum += x[i];
    //     }
    //     mean = sum / n;

    //     for(int i = 0; i < n; i++)
    //         x[i] -= mean;
    // }

    ///////////////////////////////////////////////////////////////////////////////////////

    // // Class fill-in
    // // robot.hh
    // #pragma once
    // #include "vec_3d.hh"
    // class robot {
    // private:
    //     vec_3d pos; // store position of the robot
    // public:
    //     robot(const vec_3d &pos) : pos(pos) {}
    // };

    ///////////////////////////////////////////////////////////////////////////////////////

    // Classses
    // Write a class Complex 

    return 0;
}