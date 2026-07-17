#ifndef WORLDBUILDING_H
#define WORLDBUILDING_H

#include <string>
//#include <vector>

#include "CharacterDialogue.h"
#include "GamePlayerStats.h"

using namespace std;

//characters in the game and locations around town

class WorldBuilding : public GamePlayerStats{
    /*private:
    vector<string> Location = {"VILLAGE", "MINES", "FOREST", "PIER"};
    //the trader is the first person you find, the farmer is the second, then after going to the village you bump into the old woman,then you find the fisher, and finally the mayor
    vector<string> npc = {"Traveler with Donkey", "Farmer", " Trader","Fisher", "Mayor"};
    vector<string> bundle = {"carrot", "pufferfish", "amethyst", "tooth", "stick"};
    
    vector<string> jojatradeoffLIMIT = {"", "", "", ""};

    int lyfPath[5] = {0, 0, }
    //farm yes or no


    int onelessday = 14;

        
    bool getquestcomplete_Fisher = true;
    bool getquestcomplete_Miner = true;
    bool getquestcomplete_charactername = true;

    public:
    string setweather();

    void setLOCATION();
    string getcurrentLOCATION();

    string getjojatradeoffLIMIT();
    string jojatradeoffLIMIT();

    string placestovisitnext();

    string getnpc();

    bool goodendingTOF();// this dictates from then on whether they just miss the thing of not

    int suddenlyitstartsto(); //this is a random weather event

    int setonelessday();
    void getonelessday();

    int setLyfPath();



    string getName();


    bool isUnlocked();
    void unlockLocation();
    void displayLocation();
    Item searchForItem();

    weather();

    shortcutavalible();


    //bool questcomplete_charactername();
        
    bool getquestcomplete_Fisher(){return true;}
    bool getquestcomplete_Miner(){return true;}
    bool getquestcomplete_charactername(){return true;}

    */
   public:
    static void Endofday();
    static int getLocationsLeftToReportOn();

    static string displayavaliblepeople(string currentlocation);

    
    //static string reportlefttodo()

};

#endif