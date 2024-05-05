//Hubert Godawa - Imperium galaktyczne
//obiekty posiadają std::list czasem też listy std::variant, niestety przy tym rozwiązaniu bardzo ciężko przesłać referencje obiektów,
//w związku z tym przesyłane są kopie. Następnym razem lepiej spróbować z std::vector
//alternatywnie tworzyc obiekty bez operatora new

#include <iostream>
#include <array>
#include <cstdlib>
#include <iterator>
#include <cstdarg>
#include <variant>
#include <list>
#include <vector>

#include "PreClassFunctions.h"

#include "Upgradeable.h"
#include "Building.h"       //subclass of Upgradeable
#include "Engine.h"         //
#include "Weapon.h"         //
#include "Shield.h"         //
#include "Leader.h"         

#include "SpaceObject.h"                                                        //abstract
#include "SpaceShip.h"      //subclass of SpaceObject                           //
#include "WarShip.h"            //subclass of SpaceShip
#include "CivilianShip.h"       //                                         
#include "CargoShip.h"              //subclass of CivilianShip
#include "ConstructionShip.h"       //
#include "ResearchShip.h"           //
#include "TouristShip.h"            //

#include "Fleet.h" //contains many WarShips

#include "MassiveObject.h"          //subclass of SpaceObject                   //abstract
#include "Star.h"                   //
#include "HabitableMassiveObject.h"     //subclass of MassiveObject             //abstract
#include "StarBase.h"                       //subclass of HabitableMassiveObject
#include "SuperStructure.h"                 //
#include "Planet.h"                         //

#include "System.h" //contains many SpaceObjects

#include "PostClassFunctions.h"

using namespace std;
  
int main()
{
    Building *building1 = new Building("Laboratorium", "Laboratorium", 100, 5, "BUI1");
    Engine *engine1 = new Engine("Silnik", "Nadprzestrzenny", "Czarna meteria", 100, "ENG1");
    Weapon *weapon1 = new Weapon("DzialoGaussa", "Kinetyczna", "Tytan10x200cm", 7, 25, "W1");
    Weapon *weapon2 = new Weapon("DzialoEMP", "Energetyczna", "HighVoltCurrent", 0, 0, "W2");
    Shield *shield1 = new Shield("Tarcza", "Fazowa", 95, 100, "S1");
    Leader *leader1 = new Leader("Hubert", "Godawa", "Informatyka", 20);
    Leader *leader2 = new Leader("Donald", "Trump", "Dywersja", 666);
    
    WarShip *warShip1 = new WarShip("Spokojny", "Niszczyciel", 500, 48, leader1, engine1, shield1, "WARS1");
    WarShip *warShip2 = new WarShip("Niezlomny", "Krazownik", 1500, 120, leader1, engine1, shield1, "WARS2");
    CivilianShip *civilianShip1 = new CivilianShip("Cywilny1", 100, 12, leader1, engine1, shield1, "CIVS1");
    CargoShip *cargoShip1 = new CargoShip("Towarowy1", 100, "RudaZelaza", 50, 35, 12, leader1, engine1, shield1, "CARS1");
    ConstructionShip *constructionShip1 = new ConstructionShip("Konstrukcyjny1", 100, 5, 12, leader1, engine1, shield1, "CONS1");
    ResearchShip *researchShip1 = new ResearchShip("Badawczy1", 100, 10, 12, leader1, engine1, shield1, "RESS1");
    TouristShip *touristShip1 = new TouristShip("Turystyczny1", 100, "5/10", "7/10", 12, leader1, engine1, shield1, "TOUS1");

    Fleet *fleet1 = new Fleet("Flota1", leader1);

    Star *star1 = new Star("Slonce", 1000000, 5000, "Typ G", 6000, "Hel");
    StarBase *starBase1 = new StarBase("BazaSlonce1", 3, 3000, 300, leader1, shield1, "STAB1");
    SuperStructure *superStructure1 = new SuperStructure("SferaDysona", 12000, 500000, 400, "10/10", leader1, shield1, "SS1");
    Planet *planet1 = new Planet("Ziemia", "Kontynentalna", 10, 100000, 800, leader1, shield1);

    System *system1 = new System("UkladSloneczny");

    PrintInfo(weapon1);
    *weapon1 == 2; *weapon2 == 3; *engine1 == 1; *shield1 == 4; *building1 == 1; //przeładowanie operatora
    PrintInfo(weapon1);
    *weapon1>>2;
    PrintInfo(weapon1);

    cout << endl;
    leader1->AddSecrets({"Uwielbia kawe", "Toleruje herbate"}); //wyswietlanie prywatnych sekretow innego lidera
    leader2->PrintSecrets(leader1);
    
    cout << endl;
    system1->PrintCoreEl(star1);

    warShip1->AddWeapons(4, weapon1, weapon2, weapon2, weapon1); //dodawanie wielu obiektow do obiektu (niestety kopie (prawodopodobnie wina va_list))

    cout << endl;
    fleet1->AddElements("WarShip", 2, warShip1, warShip2);

    PrintInfo(cargoShip1);
    cout << endl;

    planet1->MOAddElements("WarShip", 1, warShip1);
    planet1->MOAddElements("CargoShip", 1, cargoShip1);
    planet1->MOAddElements("ResearchShip", 1, researchShip1);
    planet1->MOAddElements("CivilianShip", 1, civilianShip1);
    planet1->HMOAddElements("Building", 1, building1);
    cout << endl;
    PrintInfo(planet1);

    star1->MOAddElements("Fleet", 1, fleet1);
    PrintInfo(star1);

    system1->AddElements("Fleet", 1, fleet1);
    system1->AddElements("CargoShip", 1, cargoShip1);
    system1->AddElements("ResearchShip", 1, researchShip1);
    system1->AddElements("CivilianShip", 1, civilianShip1);
    system1->AddElements("Planet", 1, planet1);
    system1->AddElements("Star", 1, star1);
    system1->AddElements("SuperStructure", 1, superStructure1);
    system1->AddElements("StarBase", 1, starBase1);
    PrintInfo(system1);
    
    cout << endl;
    Comparer<int> int_comparer(researchShip1->health); //testowanie klasy generycznej "int<int?"
    cout << int_comparer(warShip1->health) << endl;
    cout << int_comparer(cargoShip1->health);
    cout << endl;

    cout << endl;
    Comparer<string> string_comparer(shield1->name); //testowanie klasy generycznej "string<string?"
    cout << string_comparer(weapon2->name) << endl;
    cout << string_comparer(planet1->name);
    cout << endl;

    cout << endl;
    Array<string> string_array;
    string_array.AddElement(shield1->name);
    string_array.AddElement(planet1->type);
    string_array.printArray();

    cout << endl;
    Array<int> int_array;
    int_array.AddElement(weapon1->damage);
    int_array.AddElement(building1->size);
    int_array.printArray();

    cout << endl;
    delete building1;
    delete engine1;
    delete weapon1;
    delete weapon2;
    delete shield1;
    delete leader1;
    delete constructionShip1;
    delete touristShip1;
    delete star1;
    delete starBase1;
    delete superStructure1;
    delete planet1;
    delete system1;

    return 0;
}