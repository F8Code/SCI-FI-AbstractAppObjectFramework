#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>

using namespace std;

class WarShip : public SpaceShip {
    friend class Leader; friend class Fleet; friend class StarBase; friend class System; friend class Planet; friend class Star; friend class SuperStructure;
public:
    WarShip(string wSName, string wSType, int wSHealth, int wSCrew, Leader *wSLeader, Engine *wSEngine, Shield *wSShield, string wSID)
    : SpaceShip(wSName, wSHealth, wSLeader) {
        this->type = wSType;
        this->crew = wSCrew;
        this->engine = wSEngine;
        this->shield = wSShield;
        this->ID = wSID;
    }
    void AddWeapons(int num, ...);
    void RemoveWeapons();
    void PrintInfo();
private:
    string type;
    int crew;
    list<Weapon> weaponList;
    Engine *engine;
    Shield *shield;
    string ID;   
};

void WarShip::AddWeapons(int num, ...) {
    va_list valist;
    va_start(valist, num);
    for (int i = 0; i < num; i++)
        weaponList.push_back(va_arg(valist, Weapon));
    va_end(valist);
}

void WarShip::RemoveWeapons() {
        weaponList.clear();
}

void WarShip::PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Zycie: " << this->health << ", Zaloga: " << this->crew << ", Lider: " << this->leader->name << this->leader->surname << ", Silnik: " << this->engine->name << ", Tarcza: " << this->shield->name << ", ID: " << this->ID << endl;
        cout << "       Bronie: ";
        for (list<Weapon>::iterator i = weaponList.begin(); i != weaponList.end(); i++)
            cout << i->name << "  ";
        cout << endl;
}