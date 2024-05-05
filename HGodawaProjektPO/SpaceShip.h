#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class SpaceShip : public SpaceObject {
public:
    SpaceShip(string cSName, int cSHealth, Leader *cSLeader) : SpaceObject(cSName, cSHealth) {
        this->leader = cSLeader;
    }
    Leader *leader;
    virtual void PrintInfo() = 0;
};