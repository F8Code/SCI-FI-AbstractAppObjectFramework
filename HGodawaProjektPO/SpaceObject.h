#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class SpaceObject {
public:
    SpaceObject(string sOName, int sOHealth) {
        this->name = sOName;
        this->health = sOHealth;
    }
    string name;
    int health;
    virtual void PrintInfo() = 0;
    ~SpaceObject() {
        cout << "ObiektKosmiczny " << this->name << " zostal usuniety..." << endl;
    }
};