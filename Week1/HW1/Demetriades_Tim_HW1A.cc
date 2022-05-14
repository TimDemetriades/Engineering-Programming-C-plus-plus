#include <iostream>
using namespace std;

// 3n+1 Conjecture
void threeNPlusOne(int num) {

    cout << "Computing 3n+1 Conjecture\n" << num << "\n";
    
    while (num != 1)
    {
        if (num % 2 == 1)
        {
            num = num * 3 + 1;
        }
        else 
        {
            num /= 2;
        }
        cout << num << "\n";
    }
}

int main()
{
    int num = 0;
    cout << "Please enter a positive integer.\n";
    cin >> num;
    threeNPlusOne(num);
    return 0;
}