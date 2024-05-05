#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class Weapon : public Upgradeable {
    friend class WarShip; friend class Planet; friend class StarBase;
public:
    Weapon(string wName, string wType, string wAmmoType, int wMagazineSize, int wDamage, string wID) : Upgradeable(wName) {
        this->type = wType;
        this->ammoType = wAmmoType;
        this->magazineSize = wMagazineSize;
        this->damage = wDamage;
        this->ID = wID;
    }
    string type;
    string ammoType;
    int magazineSize;
    int damage;
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Typ: " << this->type << ", Rodzaj amunicji: " << this->ammoType << ", Rozmiar magazynka: " << this->magazineSize << ", Obrazenia: " << this->damage << ", ID: " << this->ID << endl; 
    }
private:
    string ID;
};