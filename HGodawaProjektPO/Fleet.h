#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>

using namespace std;

class Fleet {
    friend class Leader; friend class WarShip; friend class StarBase; friend class System; friend class Planet; friend class Star; friend class SuperStructure; friend class MassiveObject;
public:
    Fleet(string fName, Leader *fLeader) {
        this->name = fName;
        this->leader = fLeader;
    }
    void AddElements(string type, int num, ...);
    void RemoveElements(string type);
    void PrintInfo();
    ~Fleet() {
        cout << "Flota kosmiczna " << this->name << " zostala rozwiazana..." << endl;
    }
    string name;
    Leader *leader;
private:
    list<WarShip> warShipList;
};

void Fleet::AddElements(string type, int num, ...) {
    va_list valist;
    va_start(valist, num);
    if (type == "WarShip")
        for (int i = 0; i < num; i++)
            this->warShipList.push_back(va_arg(valist, WarShip));
    va_end(valist);
}

void Fleet::RemoveElements(string type) {
    if (type == "WarShip")
        warShipList.clear();
}

void Fleet::PrintInfo() {
        cout << "Nazwa: " << this->name << endl;
        cout << "   Lider: " << this->leader->name << this->leader->surname << endl;
        cout << "       OkretyWojenne: ";
        for (list<WarShip>::iterator i = warShipList.begin(); i != warShipList.end(); i++)
            cout << i->name << ", ";
        cout << endl;
}