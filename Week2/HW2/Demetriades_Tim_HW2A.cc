#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    // Formula: Wind Chill = 35.74 + 0.6215T - 35.75(V^0.16) + 0.4275T(V^0.16)

    double wind_chill = 0.0;

    // Print Column Labels (Temperatures in F)
    for (int col = 40; col >= -45; col -= 5)
    {
        if (col == 40)
        {
            cout << "\t" << col << "\t";    // put tab before first T
        }
        else
        {
            cout << col << "\t";
        }
    }

    cout << endl;

    for (int V = 5; V <= 60; V += 5)    // loop through each row
    {
        // Print Row Labels (Wind in mph)
        cout << V << "\t";

        for (int T = 40; T >= -45; T -= 5)      // loop through each column
        {
            wind_chill = 35.74 + (0.6215 * T) - (35.75 * (pow(V, 0.16))) + (0.4275 * T * (pow(V, 0.16)));

            if (T == -45)
            {
                cout << round(wind_chill) << endl;      // new row once we reach T = -45
            }
            else
            {
                cout << round(wind_chill) << "\t";
            }
        }
    }
    
    return 0;
}