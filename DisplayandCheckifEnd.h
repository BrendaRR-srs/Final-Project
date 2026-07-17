#ifndef DISPLAYANDCHECKIFEND_H
#define DISPLAYANDCHECKIFEND_H

#include <string>
#include <vector>

#include "GamePlayerStats.h"
#include "WorldBuilding.h"

using namespace std;

class DisplayandCheckifEnd : public GamePlayerStats {
private:
    /*
    string MAPDISPLAY = "";
    string LOCATIONDISPLAY = "";
    string TERMINALUSERINTERFACE = "";
    */

    //vector<bool> completedreport = {false, false, false, false, false};

public:
    static string startofgame();
    static string onea();
    static string oneb();
    static string onec();
    static string final();

    /*static bool setdisplayvillagerschedual();
    static void getdisplayvillagerschedual();
    static string displayvillagerschedual();
    */

    static void displaydashboard();
    static void mainmenuchoice(int choice);

    static void displayTownMapone();
    static void displayTownMaptwo();

    static string displayavaliblepeople(string currentlocation);
    //static void schedualegivenbydalia();

    static string reportlefttodo();


};

#endif