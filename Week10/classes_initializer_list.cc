#include <iostream>
using namespace std;

class kidney {
private:
    double health;
public:
    // Kidney function 0 to 100%
    kidney(double health) : health(health) {}

    friend ostream &operator <<(ostream& s, kidney k) {
        s << "health = " << k.health;
        return s;
    }
};

class heart {
private:
    uint16_t bpm;  
    uint16_t systolic;      // pressure
    uint16_t diastolic;     // pressure
public:
    heart(uint16_t bpm, uint16_t sys, uint16_t dia) : bpm(bpm), systolic(sys), diastolic(dia) {}

    friend ostream &operator <<(ostream& s, heart h) {
        s << "bpm = " << h.bpm << ", blood pressure = " << h.systolic << "/" << h.diastolic;
        return s;
    }
};

class person {
private:
    heart h;
    kidney left_kidney, right_kidney;
public:
    person(uint16_t bpm, uint16_t systolic, uint16_t diastolic, double left_kidney_health, double right_kidney_health)
        : h(bpm, systolic, diastolic),  left_kidney(left_kidney_health), right_kidney(right_kidney_health) {}

    friend ostream &operator <<(ostream &s, const person &p) {
        s << "person " << p.h << " |" << " left " << p.left_kidney << ", right " << p.right_kidney << endl;
        return s;
    }

};

int main() {

    person p(60, 125, 75, 100, 100);
    cout << p;  // person bpm = 60, blood pressure = 125/75, left kidney = 100%, right kidney = 100%

    return 0;
}