#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>

using namespace std;

class HabitableMassiveObject : public MassiveObject {
     friend class Leader; friend class Fleet; friend class WarShip; friend class StarBase; friend class System; friend class Planet; friend class SuperStructure;
public:
    HabitableMassiveObject(string hMOName, int hMOHealth, int hMOSize, Leader *hMOLeader, Shield *hMOShield)
    : MassiveObject(hMOName, hMOHealth, hMOSize) {
        this->leader = hMOLeader;
        this->shield = hMOShield;
    }
    Leader *leader;
    list<Building> buildingList;
    void HMOAddElements(string type, int num, ...);
    void HMORemoveElements(string type);
private:
    Shield *shield;
    list<Weapon> weaponList;
    virtual void PrintInfo() = 0;
};

void HabitableMassiveObject::HMOAddElements(string type, int num, ...) {
    va_list valist;
    va_start(valist, num);
    if (type == "Weapon")
        for (int i = 0; i < num; i++)
            weaponList.push_back(va_arg(valist, Weapon));
    else if (type == "Building")
        for (int i = 0; i < num; i++)
            buildingList.push_back(va_arg(valist, Building));
    va_end(valist);
}

void HabitableMassiveObject::HMORemoveElements(string type) {
    if (type == "Weapon")
        weaponList.clear();
    if (type == "Building")
        buildingList.clear();
}
