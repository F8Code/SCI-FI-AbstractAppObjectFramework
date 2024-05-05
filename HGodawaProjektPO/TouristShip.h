#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class TouristShip : public CivilianShip {
    friend class Leader; friend class Fleet; friend class WarShip; friend class StarBase; friend class System; 
public:
    TouristShip(string cSName, int cSHealth, string tSComfort, string tSRating, int cSCrew, Leader *cSLeader, Engine *cSEngine, Shield *cSShield, string cSID) 
    : CivilianShip(cSName, cSHealth, cSCrew, cSLeader, cSEngine, cSShield, cSID) {
        this->comfort = tSComfort;
        this->rating = tSRating;
    }
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Zycie: " << this->health << ", Zaloga: " << this->crew << ", Lider: " << this->leader->name << this->leader->surname << ", Silnik: " << this->engine->name << ", Tarcza: " << this->shield->name << ", ID: " << this->ID << endl;
        cout << "       Komfort: " << this->comfort << ", Ocena: " << this->rating << endl;
    }
    string comfort; //from 1 to 10
    string rating;  //
};