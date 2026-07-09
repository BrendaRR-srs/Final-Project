#ifndef GAMEPLAYERSTATS_H
#define GAMEPLAYERSTATS_H

#include <string>
#include <vector>
using namespace std;

//creates main character and displays bundle


class GamePlayerStats{
    private:
    string name;
    string CurrentDay;
    int ENERGY;
    int MONEY;
    int Friendshippoints;
    string currentLocation;
    //plans to include inventory later
    //plans to include community center progress later 
    //plans to include joja influence later
    int Finalscore;

    ///
    vector<string> bundlegrabbed = {""};

    int TIMELIMIT = 14; // this stands for 2 weeks also known as days till end of season
    int ENERGYLIMIT = 500; // i made this up for now
    

    public:

    //make constructor for inventory later

    void setName();
    void setENERGY();
    void setMONEY();
    void setFriendshippoints();
    void setcurrentLocation();

    string getName();
    int getENERGY();
    int getMONEY();
    int getFriendshippoints();
    string getcurrentLocation();

    ///
    void bundle(); //this couts the vector
    void getbundlegrabbed(); //couts what was grabbed by the user
    void setbundlegot(); //changes the vector to add what player got

};

#endif