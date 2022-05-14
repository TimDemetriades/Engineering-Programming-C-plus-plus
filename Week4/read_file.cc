#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream f("grades.txt");   // class for reading from files

    double v;

    while (!f.eof()) {
        f >> v;
        cout << v << ' ';
    }

    return 0;
}