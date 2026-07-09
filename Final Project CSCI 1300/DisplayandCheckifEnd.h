#ifndef DISPLAYANDCHECKIFEND_H
#define DISPLAYANDCHECKIFEND_H

#include <string>
#include "GamePlayerStats.h"
#include "WorldBuilding.h"


using namespace std;

//characters in the game and locations around town

class DisplayandCheckifEnd: public GamePlayerStats{
    private:
    string MAPDISPLAY = "";

    string LOCATIONDISPLAY = "";

    string TERMINALUSERINTERFACE = "";

    public:


    //town map / location display
    void setLOCATIONDISPLAY();
    void getLOCATIONDISPLAY();

    void setTERMINALUSERINTERFACE();
    void getTERMINALUSERINTERFACE();

};