#include <iostream>
using namespace std;

// 1^1 + 2^2 + 3^3 = ???
int sumSquareUpTo(int n) {
    
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i * i;
    
    return sum;
}

int divideByTwo(int n) {
    for (int i = n; i >= 1; i /= 2)
        cout << i << " ";
}

int countDownByOne(int n) {
    for (int i = n; i >= 0; i--)
        cout << i << " ";
}

int main()
{
    cout << sumSquareUpTo(5) << endl;

    divideByTwo(100);

    cout << endl;

    countDownByOne(10);

    return 0;
}