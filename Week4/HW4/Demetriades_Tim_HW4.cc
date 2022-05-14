#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Class for 3D Vector
class vec_3d {
    private:
        string name;
        double len_x, len_y, len_z;     // hold lengths of each vector dimension

    public:
        // Initialization
        vec_3d(string name, double x = 0, double y = 0, double z = 0) : name(name), len_x(x), len_y(y), len_z(z) {

        }

        // Vector addition
        vec_3d operator +(vec_3d v2) const {
            return vec_3d("Addition of " + name + v2.name, len_x + v2.len_x, len_y + v2.len_y, len_z + v2.len_z);
        }

        // Below is vector addition using a friend function instead of a method
        // friend vec_3d operator +(vec_3d v1, vec_3d v2) {
        //     return vec_3d(v1.len_x + v2.len_x, v1.len_y + v2.len_y, v1.len_z + v2.len_z);
        // }

        // Vector subtraction
        friend vec_3d operator -(vec_3d v1, vec_3d v2) {
            return vec_3d("Subtraction of " + v1.name + v2.name, v1.len_x - v2.len_x, v1.len_y - v2.len_y, v1.len_z - v2.len_z);
        }

        // Vector negation
        friend vec_3d operator -(vec_3d v1) {
            return vec_3d("Negation of " + v1.name, v1.len_x * -1, v1.len_y * -1, v1.len_z * -1);
        }

        // Vector dot product
        friend double dot(vec_3d v1, vec_3d v2) {
            return double(v1.len_x * v2.len_x + v1.len_y * v2.len_y + v1.len_z * v2.len_z);
        }

        // Magnitude of vector
        double mag() const {
            return double(sqrt(len_x * len_x + len_y * len_y + len_z * len_z));
        }

        // Magnitude squared of vector
        double magsq() const {
            return double(len_x * len_x + len_y * len_y + len_z * len_z);
        }

        // Outputting vector
        friend ostream& operator <<(ostream& s, vec_3d& v1) {
            s << v1.name << ": (" << v1.len_x << ", " << v1.len_y << ", " << v1.len_z << ")";
            return s;
        }

        // Inputting vector
        friend istream& operator >>(istream& s, vec_3d& v1) {
            cout << "Enter a vector in the format x y z:" << endl;
            s >> v1.len_x >> v1.len_y >> v1.len_z;
            return s;
        }

        // Get vector name
        string get_name() {
            return name;
        }

};

int main()
{
    vec_3d v1("a", 1.5, 2.2, -3.1);  // x=1.5, y=2.2, z=-3.1
    vec_3d v2("b", -2.2, 1.2);       // z=0
    vec_3d v3("c", 5.6);             // y=z=0
    vec_3d v4("d");                  // x=y=z=0

    vec_3d v5 = v1 + v2;

    vec_3d v6 = v1 - v2;

    vec_3d v7 = -v2;    // negation
    
    double d = dot(v1, v5);     // dot product

    cout << v1 << '\n';
	cout << v2 << '\n';
	cout << v3 << '\n';
	cout << v4 << '\n';
	cout << v5 << '\n';
	cout << v6 << '\n';
	cout << v7 << '\n';

    cin >> v1;      // read in x, y, z from keyboard
    
    cout << "Magnitude of " << v1.get_name() << ": " << v1.mag() << endl;   // magnitude (absolute value)
    cout << "Squared Magnitude of " << v1.get_name() << ": " << v1.magsq() << endl; // magnitude squared (x*x + y*y + z*z)

    return 0;
}