#ifndef WORLDBUILDING_H
#define WORLDBUILDING_H

#include <string>
#include <vector>

using namespace std;

//characters in the game and locations around town

class WorldBuilding : public GamePlayerStats{
    private:
    vector<string> Location = {"VILLAGE", "MINES", "FOREST", "PIER"};
    vector<string> npc = {"npc1", "npc2", "npc3", "npc4"};
    vector<string> bundle = {"notebook", "diamond", "stick", "tooth"};
    
    vector<string> jojatradeoffLIMIT = {"", "", "", ""};

    public:
    void setLOCATION();
    string getcurrentLOCATION();

    string getjojatradeoffLIMIT();
    string jojatradeoffLIMIT();

    string getnpc();
};

#endif