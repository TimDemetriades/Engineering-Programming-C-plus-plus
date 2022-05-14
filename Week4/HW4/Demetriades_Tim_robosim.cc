#include <iostream> 
#include <fstream>  // file stream
#include <sstream>  // string stream
#include <vector>   // for creating vectors
using namespace std;

// Class for beacons
class Beacon {
private:
    string beacon_name;
    double x, y;

public:
    // Initialization
    Beacon(string beacon_name, double x, double y) : beacon_name(beacon_name), x(x), y(y) {}

    // Printing beacon objects
    friend ostream& operator <<(ostream& s, Beacon b) {
        s << "(" << b.beacon_name << ", " << b.x << ", " << b.y << ")" << endl;
        return s;
    }
};

// Class for robots
class Robot {
private:
    string robot_name;
    double x, y;

public:
    // Initialization
    Robot(string robot_name, double x, double y) : robot_name(robot_name), x(x), y(y) {}

    // Printing robot objects
    friend ostream& operator <<(ostream& s, Robot r) {
        s << "(" << r.robot_name << ", " << r.x << ", " << r.y << ")" << endl;
        return s;
    }
};

// Functions for printing the vectors

void print_vector(vector<Beacon> const &a) {
    cout << "The beacons are: " << endl;

    for(int i=0; i < a.size(); i++)
        cout << a.at(i);
}

void print_vector(vector<Robot> const &a) {
    cout << "The robots are: " << endl;

    for(int i=0; i < a.size(); i++)
        cout << a.at(i);
}

int main() {

    ifstream f("rsim.conf");    // class for reading from files
    char buffer[4096];  // make a buffer definitely big enough to hold a line

    string type;
    string name;
    double loc_x;
    double loc_y;

    vector<Beacon> beacons;
    vector<Robot> robots;

    while (f.getline(buffer, sizeof(buffer))) { // if there is a line
        istringstream line(buffer);  // read each line from a string stream attached to the buffer
        line >> type >> name >> loc_x >> loc_y;     // grab type, name, loc_x, and loc_y from the current line

        if (type == "beacon") {
            beacons.emplace_back(name, loc_x, loc_y);
        }
        if (type == "robot") {
            robots.emplace_back(name, loc_x, loc_y);
        }
    }

    f.close();      // close file

    print_vector(beacons);
    print_vector(robots);

    return 0;
}