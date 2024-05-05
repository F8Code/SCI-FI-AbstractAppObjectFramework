//Hubert Godawa - Imperium galaktyczne
//wiele klas/funkcji do uzupelnienia (dodac wczytywanie tablic obiektow)

#include <iostream>
#include <array>
#include <cstdlib>

#include "Building.h"
#include "Engine.h"
#include "Weapon.h"
#include "Shield.h"
#include "Leader.h"
#include "CivilianShip.h"
#include "WarShip.h"
#include "Fleet.h"
#include "Planet.h"
#include "Star.h"
#include "StarBase.h"
#include "SuperStructure.h"
#include "System.h"

using namespace std;

int main()
{
    Shield *shield1 = new Shield("Najlepsza tarcza", "Tarcza fazowa", 95, 100, "T1");
    Leader *lider1 = new Leader("Hubert", "Godawa", "Informatyka", 20);
    Building *building1 = new Building("Laboratorium1", "Laboratorium", 100, 5, "B1");
    building1->PrintInfo();

    building1->health = 95;
    building1->size = 6;
    building1->PrintInfo();

    Planet *planet1 = new Planet("Ziemia", "Skalista", 10, 1000, 800, lider1, 1, shield1, 0, 0, 0, 0);
    planet1->PrintInfo();

    delete planet1;
    return 0;
};