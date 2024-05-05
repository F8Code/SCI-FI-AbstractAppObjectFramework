#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdarg>

using namespace std;

class Leader {
    //friend class Leader; nie trzeba pisac, jest tak domyslnie
public:
    Leader(string lName, string lSurname, string lSpec, int lAge) {
        this->name = lName;
        this->surname = lSurname;
        this->specialization = lSpec;
        this->age = lAge;
    }
    string name;
    string surname;
    string specialization;
    int age;
    void PrintInfo() {
        cout << "Imie: " << this->name << ", Nazwisko: " << this->surname << endl;
        cout << "   Wiek: " << this->age << ", Specjalizacja: " << this->specialization << endl; 
    }
    void AddSecrets(initializer_list<string> list) {
        for (const auto &str : list)
            this->secret.push_back(str);
    }
    void PrintSecrets(Leader *leader) {
        for (int i = 0; i < leader->secret.size(); i++)
            cout << "Sekret " << i+1 << ": " << leader->secret[i] << endl;
    }
    ~Leader() {
        cout << "Przywodca " << this->name << ' ' << this->surname << " umarl na rzadka chorobe..." << endl;
    }
private:
    vector<string> secret;
};