#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class CivilianShip : public SpaceShip { 
    friend class Leader; friend class Fleet; friend class WarShip; friend class StarBase; friend class System; friend class CargoShip; friend class ConstructionShip; friend class ResearchShip; friend class TouristShip;
public:
    CivilianShip(string cSName, int cSHealth, int cSCrew, Leader *cSLeader, Engine *cSEngine, Shield *cSShield, string cSID) 
    : SpaceShip(cSName, cSHealth, cSLeader) {
        this->crew = cSCrew;
        this->engine = cSEngine;
        this->shield = cSShield;
        this->ID = cSID;
    }
    int crew;
    Engine *engine;
    Shield *shield;
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Zycie: " << this->health << ", Zaloga: " << this->crew << ", Lider: " << this->leader->name << this->leader->surname << ", Silnik: " << this->engine->name << ", Tarcza: " << this->shield->name << ", ID: " << this->ID << endl;
    }
private:
    string ID;
};