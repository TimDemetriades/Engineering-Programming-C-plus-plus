#include <iostream>
using namespace std;

// n Factorial
int nFactorial(int num) {
    int factorial = 1.0;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    float num = 0.0;
    cout << "Please enter a positive integer. \n";
    cin >> num;
    while (num <= 0 || num != (int)num)    // check if positive and whole number
    {
        if (num <= 0)
        {
            cout << "No! Enter a POSITIVE integer. \n";
        }
        if (num != (int)num)
        {
            cout << "No! Enter a positive INTEGER ('whole number'). \n";
        }
        cin >> num;
    }
    cout << "The factorial of " << num << " is " << nFactorial(num);
    return 0;
}