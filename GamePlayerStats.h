#ifndef GAMEPLAYERSTATS_H
#define GAMEPLAYERSTATS_H

#include <string>
using namespace std;

class GamePlayerStats{
    private:

    static int money;
    static string currentLocation;
    static int turnsLeft;
    static int CurrentDay;

    static string inventory[5];

    static int lyfPath;
    static string name;
    
    
    public:

    static void setMONEY(int amount);
    static int getMONEY();

    static string getCurrentLocation();
    static void setCurrentLocation(string location);

    static int getTurnsLeft();
    static void setTurnsLeft();
    static void resetTurnsLeft();

    static int getCurrentDay();
    static void setCurrentDay();

    static void displayinventory();
    static void addtoinventory(string addnewthing);
    static void subtractfrominventory(string deleteit);
    static bool isInInventory(string item);

    static void setname(string name);
    static string getname();

    static void setLyfPath(int choice);
    static int getLyfPath();

};

#endif