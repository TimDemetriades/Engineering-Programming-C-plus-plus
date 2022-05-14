#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{

    cout << setprecision(7);

    /*
    Utilizing a loop, sum the numbers using the float data type:
    sum1F = 1/1 + 1/2 + 1/3 ... + 1/98 + 1/99 + 1/100 
    sum2F = 1/100 + 1/99 + 1/98 + ... + 1/3 + 1/2 + 1/1
    The result should be approximately 5.18.
    */

    float sum1F = 0.0f;
    float fraction1F = 0.0f;
    float sum2F = 0.0f;
    float fraction2F = 0.0f;

    for (int i = 1; i <= 100; i++)
    {
        fraction1F = 1.0f / i;
        sum1F += fraction1F;

        fraction2F = 1.0f / (101.0f - i);
        sum2F += fraction2F;
    }

    cout << "Float Sum 1 =\t" << sum1F << endl;
    cout << "Float Sum 2 =\t" << sum2F << endl;

    /*
    Utilizing a loop, sum the numbers using the double data type:
    sum1D = 1/1 + 1/2 + 1/3 ... + 1/98 + 1/99 + 1/100 
    sum2D = 1/100 + 1/99 + 1/98 + ... + 1/3 + 1/2 + 1/1
    */

    double sum1D = 0.0;
    double fraction1D = 0.0;
    double sum2D = 0.0;
    double fraction2D = 0.0;

    for (int i = 1; i <= 100; i++)
    {
        fraction1D = 1.0 / i;
        sum1D += fraction1D;

        fraction2D = 1.0 / (101.0 - i);
        sum2D += fraction2D;
    }

    cout << "Double Sum 1 =\t" << sum1D << endl;
    cout << "Double Sum 2 =\t" << sum2D << endl;

    float difference_f = 0.0f;
    double difference_d = 0.0;

    difference_f = sum1F - sum2F;
    difference_d = sum1D - sum2D;

    cout << "Float Difference =\t" << difference_f << endl;
    cout << "Double Difference =\t" << difference_d << endl;

    return 0;
}