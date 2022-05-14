#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Robot {
private:
    string name;
    double x, y;

public:
    Robot(string name, double x = 0, double y = 0) 
        : name(name), x(x), y(y) {}
};

int main() {
    // vector <int> my_list;
    // my_list.push_back(3);
    // my_list.push_back(1);

    // for (int i = 0; i < 100; i++) {
    //     my_list.push_back(i);
    // }

    vector <Robot> robots;

    // 2 ways to put a robot object into the robots vector
    robots.push_back(Robot("fred", 1.0, 2.5));
    robots.emplace_back("fred", 1.0, 2.5);


    // String comparison (for hw)

    string a = "hello";
    a += "test";    // concatenate test to a
    cout << a.length() << endl;     // print out length of string

    if (a != "hello") {
        cout << a << endl;
    }

    return 0;
}