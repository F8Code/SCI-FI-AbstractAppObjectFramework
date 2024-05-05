#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>
#include <variant>

using namespace std;

class SuperStructure : public HabitableMassiveObject {
    friend class Leader; friend class Fleet; friend class WarShip; friend class StarBase; friend class System;
public:
    SuperStructure(string sSName, int sSHealth, int sSSize, int sSCrew, string sSSignificance, Leader *sSLeader, Shield *sSShield, string sSID) 
    : HabitableMassiveObject(sSName, sSHealth, sSSize, sSLeader, sSShield) {
        this->crew = sSCrew;
        this->significance = sSSignificance; //od 1 do 10
        this->ID = sSID;
    }
    int crew;
    void PrintInfo();
private:
    string significance;
    string ID;
};

void SuperStructure::PrintInfo() {
    cout << "Nazwa: " << this->name << endl;
    cout << "   Zycie: " << this->health << ", Zaloga: " << this->crew << ", Lider: " << this->leader->name << this->leader->surname << ", Tarcza: " << this->shield->name << ", ID: " << this->ID << endl;
    cout << "       Znaczenie dla imperium: " << this->significance << endl;
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
            cout << p->name << ", ";
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
}