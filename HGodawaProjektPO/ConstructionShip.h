#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class ConstructionShip : public CivilianShip {
    friend class Leader; friend class Fleet; friend class WarShip; friend class StarBase; friend class System; 
public:
    ConstructionShip(string cSName, int cSHealth, int cSRepairSpeed, int cSCrew, Leader *cSLeader, Engine *cSEngine, Shield *cSShield, string cSID) 
    : CivilianShip(cSName, cSHealth, cSCrew, cSLeader, cSEngine, cSShield, cSID) {
        this->repairSpeed = cSRepairSpeed;
    }
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Zycie: " << this->health << ", Zaloga: " << this->crew << ", Lider: " << this->leader->name << this->leader->surname << ", Silnik: " << this->engine->name << ", Tarcza: " << this->shield->name << ", ID: " << this->ID << endl;
        cout << "       Predkosc naprawy: " << this->repairSpeed << endl;
    }
    int repairSpeed;
};