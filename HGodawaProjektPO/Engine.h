#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class Engine : public Upgradeable {
    friend class CivilianShip; friend class WarShip;
public:
    Engine(string eName, string eType, string eFuelType, int eFuelAmmount, string eID) : Upgradeable(eName) {
        this->type = eType;
        this->fuelType = eFuelType;
        this->fuelAmmount = eFuelAmmount;
        this->ID = eID;
    }
    string type;
    string fuelType;
    int fuelAmmount;
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Typ: " << this->type << ", Rodzaj paliwa: " << this->fuelType << ", Ilosc paliwa: " << this->fuelAmmount << ", ID: " << this->ID << endl; 
    }
private:
    string ID; 
};