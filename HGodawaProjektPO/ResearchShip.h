#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class ResearchShip : public CivilianShip {
    friend class Leader; friend class Fleet; friend class WarShip; friend class StarBase; friend class System;
public:
    ResearchShip(string rSName, int rSHealth, int rSResearchSpeed, int rSCrew, Leader *rSLeader, Engine *rSEngine, Shield *rSShield, string rSID) 
    : CivilianShip(rSName, rSHealth, rSCrew, rSLeader, rSEngine, rSShield, rSID) {
        this->researchSpeed = rSResearchSpeed;
    }
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Zycie: " << this->health << ", Zaloga: " << this->crew << ", Lider: " << this->leader->name << this->leader->surname << ", Silnik: " << this->engine->name << ", Tarcza: " << this->shield->name << ", ID: " << this->ID << endl;
        cout << "       Predkosc badan: " << this->researchSpeed << endl;
    }
    int researchSpeed;
};