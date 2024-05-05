#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>
#include <variant>

using namespace std;

class Planet : public HabitableMassiveObject {
    friend class Leader; friend class System; friend class WarShip; friend class Fleet; friend class StarBase;
public:
    Planet(string pName, string pType, int pSize, int pHealth, int pPopulation, Leader *pLeader, Shield *pShield)
           : HabitableMassiveObject(pName, pHealth, pSize, pLeader, pShield) {
        this->type = pType;
        this->population = pPopulation;
    }
    string type;
    int population;
    void PrintInfo();
};

void Planet::PrintInfo() {
    cout << "Nazwa: " << this->name << endl;
    cout << "   Zycie: " << this->health << ", Typ: " << this->type << ", Populacja: " << this->population << ", Lider: " << this->leader->name << this->leader->surname << ", Tarcza: " << this->shield->name << endl;
    cout << "       Budynki: ";
    for (list<Building>::iterator i = buildingList.begin(); i != buildingList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "       Bronie: ";
    for (list<Weapon>::iterator i = weaponList.begin(); i != weaponList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "           Floty: ";
    for (list<Fleet>::iterator i = fleetList.begin(); i != fleetList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "           OkretyWojenne: ";
    for (list<WarShip>::iterator i = warShipList.begin(); i != warShipList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "           StatkiCywilne: ";
    for (list<variant<CivilianShip, CargoShip, ConstructionShip, ResearchShip, TouristShip>>::iterator i = civilianShipList.begin(); i != civilianShipList.end(); i++) {
        if (auto *p = get_if<CivilianShip>(&*i)) {
            cout << p->name << ", ";
        }
        else if (auto *p = get_if<CargoShip>(&*i)) {
            cout << p->name << ", "/* << "(Health: " << p->health << "), "*/;
        }
        else if (auto *p = get_if<ConstructionShip>(&*i)) {
            cout << p->name << ", ";
        }
        else if (auto *p = get_if<ResearchShip>(&*i)) {
            cout << p->name << ", ";
        }
        else if (auto *p = get_if<TouristShip>(&*i)) {
            cout << p->name << ", ";
        }
    }
    cout << endl;
}