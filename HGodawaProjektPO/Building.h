#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class Building : public Upgradeable {
    friend class Planet; friend class StarBase;
public:
    Building(string bName, string bType, int bHealth, int bSize, string bID) : Upgradeable(bName) {
        this->type = bType;
        this->health = bHealth;
        this->size = bSize;
        this->ID = bID;
    }
    string type; 
    int health; 
    int size;
    void PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Typ: " << this->type << ", Rozmiar: " << this->size << ", Zycie: " << this->health << ", ID: " << this->ID << endl; 
    }
private:
    string ID;
};