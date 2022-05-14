#include <iostream>
#include <fstream>  // file stream
#include <sstream>  // string stream
using namespace std;

int main() {

    ifstream f("test.txt");    // class for reading from files
    char buffer[4096];  // make a buffer definitely big enough to hold a line

    char name[20];
    double mass;
    double radius;

    while (f.getline(buffer, sizeof(buffer))) { // if there is a line
        istringstream line(buffer);  // read each line from a string stream attached to the buffer
        line >> name >> mass >> radius;
        cout << "name = " << name << " mass = " << mass << " radius = " << radius << endl;
    }

    return 0;
}