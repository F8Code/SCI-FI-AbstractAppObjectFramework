#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>
#include <variant>

using namespace std;

class MassiveObject : public SpaceObject {
public:
    MassiveObject(string mOName, int mOHealth, int mOSize) : SpaceObject(mOName, mOHealth) {
        this->size = mOSize;
    }
    int size;
    list<Fleet> fleetList;
    list<WarShip> warShipList;
    list<variant<CivilianShip, CargoShip, ConstructionShip, ResearchShip, TouristShip>> civilianShipList;
    virtual void PrintInfo() = 0;
    void MOAddElements(string type, int num, ...);
    void MORemoveElements(string type);
};

void MassiveObject::MOAddElements(string type, int num, ...) {
    va_list valist;
    va_start(valist, num);
    if (type == "Fleet") {
        for (int i = 0; i < num; i++) {
            Fleet* fleet_ptr = va_arg(valist, Fleet*);
            this->fleetList.push_back(*fleet_ptr);
        }
    }
    else if (type == "WarShip") {
        for (int i = 0; i < num; i++) {
            WarShip* warship_ptr = va_arg(valist, WarShip*);
            this->warShipList.push_back(*warship_ptr);
        }
    }
    else if (type == "CargoShip")
        for (int i = 0; i < num; i++) {
                this->civilianShipList.push_back(*va_arg(valist, CargoShip*));  
        }    
    else if (type == "ConstructionShip")
        for (int i = 0; i < num; i++) {
                this->civilianShipList.push_back(*va_arg(valist, ConstructionShip*));  
        } 
    else if (type == "ResearchShip")
        for (int i = 0; i < num; i++) {
                this->civilianShipList.push_back(*va_arg(valist, ResearchShip*));  
        } 
    else if (type == "TouristShip")
        for (int i = 0; i < num; i++) {
                this->civilianShipList.push_back(*va_arg(valist, TouristShip*));  
        }
    else if (type == "CivilianShip")
        for (int i = 0; i < num; i++) {
                this->civilianShipList.push_back(*va_arg(valist, CivilianShip*));  
        }
    va_end(valist);
}

void MassiveObject::MORemoveElements(string type) {
    if (type == "Fleet")
        fleetList.clear();
    if (type == "WarShip")
        warShipList.clear();
    if (type == "CivilianShip")
        civilianShipList.clear();
}