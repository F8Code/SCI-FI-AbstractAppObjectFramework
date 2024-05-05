#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

class Upgradeable{
public:
    Upgradeable(string uName) {
        this->name = uName;
    }
    string name;
    void operator==(int num) {
        this->name += "V" + to_string(num);
    }
    void operator>>(int num1) {
        int num2 = (int)this->name.back();
        this->name.back() = num1 + num2; 
    }
    virtual void PrintInfo() = 0;
    ~Upgradeable() {
        cout << "Modul " << this->name << " zostal usuniety..." << endl;
    }
};