#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>

using namespace std;

class System {
public:
    System(string sName) {
        this->name = sName;
    }
    string name;
    list<Star> starList;
    list<Planet> planetList;
    list<SuperStructure> superStructureList;
    list<StarBase> starBaseList;
    list<Fleet> fleetList;
    list<WarShip> warShipList;
    list<CivilianShip> civilianShipList;
    void AddElements(string type, int num, ...);
    void RemoveElements(string type);
    void PrintInfo();
    void PrintCoreEl(Star *star) {
        cout << "Gwiazda " << star->name << " ma jadro z: " << star->coreEl << endl;
    }
    ~System() {
        cout << "System " << this->name << " przestal istniec" << endl;
    }
};

void System::AddElements(string type, int num, ...) {
    va_list valist;
    va_start(valist, num);
    if (type == "Star")
        for (int i = 0; i < num; i++)
            this->starList.push_back(va_arg(valist, Star));
    else if (type == "Planet")
        for (int i = 0; i < num; i++)
            this->planetList.push_back(va_arg(valist, Planet));
    else if (type == "SuperStructure")
        for (int i = 0; i < num; i++)
            this->superStructureList.push_back(va_arg(valist, SuperStructure));
    else if (type == "StarBase")
        for (int i = 0; i < num; i++)
            this->starBaseList.push_back(va_arg(valist, StarBase));
    else if (type == "Fleet")
        for (int i = 0; i < num; i++)
            this->fleetList.push_back(va_arg(valist, Fleet));
    else if (type == "WarShip")
        for (int i = 0; i < num; i++)
            this->warShipList.push_back(va_arg(valist, WarShip));
    else if (type == "CivilianShip")
        for (int i = 0; i < num; i++)
            this->civilianShipList.push_back(va_arg(valist, CivilianShip));
    va_end(valist);
}

void System::RemoveElements(string type) {
    if (type == "Star")
        starList.clear();
    else if (type == "Planet")
        planetList.clear();
    else if (type == "SuperStructure")
        superStructureList.clear();
    else if (type == "StarBase")
        starBaseList.clear();
    else if (type == "Fleet")
        fleetList.clear();
    else if (type == "WarShip")
        warShipList.clear();
    else if (type == "CivilianShip")
        civilianShipList.clear();
}

void System::PrintInfo() {
    cout << "Nazwa: " << this->name << endl;
    cout << "   Gwiazdy: ";
    for (list<Star>::iterator i = starList.begin(); i != starList.end(); i++)
        cout << i->name << ", ";
     cout << endl << "   Planety: ";
    for (list<Planet>::iterator i = planetList.begin(); i != planetList.end(); i++)
        cout << i->name << ", ";  
    cout << endl << "   SuperStruktury: ";
    for (list<SuperStructure>::iterator i = superStructureList.begin(); i != superStructureList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "   BazyGwiezdne: ";
    for (list<StarBase>::iterator i = starBaseList.begin(); i != starBaseList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "   Floty: ";
    for (list<Fleet>::iterator i = fleetList.begin(); i != fleetList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "   OkretyWojenne: ";
    for (list<WarShip>::iterator i = warShipList.begin(); i != warShipList.end(); i++)
        cout << i->name << ", ";
    cout << endl << "   StatkiCywilne: ";
    for (list<CivilianShip>::iterator i = civilianShipList.begin(); i != civilianShipList.end(); i++)
        cout << i->name << ", ";
    cout << endl;
}