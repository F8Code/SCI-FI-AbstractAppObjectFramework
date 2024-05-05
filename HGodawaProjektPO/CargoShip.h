#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class CargoShip : public CivilianShip {
    friend class Leader; friend class Fleet; friend class WarShip; friend class StarBase; friend class System; 
public:
    CargoShip(string cSName, int cSHealth, string cSCargoType, int cSCargoSpace, int cSCargoTaken, int cSCrew, Leader *cSLeader, Engine *cSEngine, Shield *cSShield, string cSID) 
    : CivilianShip(cSName, cSHealth, cSCrew, cSLeader, cSEngine, cSShield, cSID) {
        this->cargoType = cSCargoType;
        this->cargoSpace = cSCargoSpace;
        this->cargoTaken = cSCargoTaken;
    }
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Zycie: " << this->health << ", Zaloga: " << this->crew << ", Lider: " << this->leader->name << this->leader->surname << ", Silnik: " << this->engine->name << ", Tarcza: " << this->shield->name << ", ID: " << this->ID << endl;
        cout << "       Pojemnosc: " << this->cargoSpace << ", Typ towaru: " << this->cargoType << ", Zajeta przestrzen: " << this->cargoTaken << endl;
    }
    string cargoType;
    int cargoSpace;
    int cargoTaken;
};