// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void find_min(int x[], int size, int *min_value) {
    for(int i = 0; i < size; i++){
        if(x[i] < *min_value) {
            *min_value = x[i];
            cout << "New min = " << x[i] << endl;
        }
    }
}

int main() {
    int x[4] = {3, 2, 5, 1};
    int size = 4;
    int min = 999;
    
    find_min(x, size, &min);

    cout << min << endl;

    return 0;
}