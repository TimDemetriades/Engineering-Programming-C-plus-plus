#include <iostream>
using namespace std;

int main()
{
    for (uint8_t i = 0; i < 300; i++)
    {
        cout << (int)i << "\n";
    }
    
    for (uint32_t i = 10; i >= 0; i--)
    {
        cout << i << "\n";
    }

    for (uint32_t i = 0; i < 10; i++)
    {
        cout << (i + 1) << "\n";
    }

    for (uint32_t i = 0; i > 10; i--)
    {
        cout << i << "\n";
    }

    return 0;
}