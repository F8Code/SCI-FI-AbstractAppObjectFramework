#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>
#include <variant>

using namespace std;

class Star : public MassiveObject {
    friend class ResearchShip; friend class System;
public:
    Star(string sName, int sHealth, int sSize, string sType, int sHeat, string sCoreEl) 
    : MassiveObject(sName, sHealth, sSize){
        this->type = sType;
        this->heat = sHeat;
        this->coreEl = sCoreEl;
    }
    string type;
    int heat;
    void PrintInfo();
private:
    string coreEl;
};

void Star::PrintInfo() {
    cout << "Nazwa: " << this->name << endl;
    cout << "   Zycie: " << this->health << ", Rozmiar: " << this->size << ", Typ: " << this->type << ", Cieplo: " << this->heat << ", Jadro: " << this->coreEl << endl;
    cout << "       Floty: ";
    for (list<Fleet>::iterator i = fleetList.begin(); i != fleetList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "       OkretyWojenne: ";
    for (list<WarShip>::iterator i = warShipList.begin(); i != warShipList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "       StatkiCywilne: ";
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
    cout << endl;
}