#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class Shield : public Upgradeable {
    friend class CivilianShip; friend class WarShip; friend class Planet; friend class StarBase; friend class SuperStructure;
    public:
    Shield(string sName, string sType, int sResistance, int sHealth, string sID) : Upgradeable(sName) {
        this->type = sType;
        this->resistance = sResistance;
        this->health = sHealth;
        this->ID = sID;
    }
    string type;
    int resistance; //% modyfikator od otrzmanych obrazen
    void PrintInfo() {
        cout << "Nazwa " << this->name << endl;
        cout << "   Typ: " << this->type << ", Odpornosc: " << this->resistance << ", Zycie: " << this->health << ", ID: " << this->ID << endl; 
    }
private:
    int health;
    string ID;
};