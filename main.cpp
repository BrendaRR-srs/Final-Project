#include "GamePlayerStats.h"
#include "DisplayandCheckifEnd.h"
#include "WorldBuilding.h"

#include <iostream>
#include <string>

using namespace std;


int main(){

//start game

    int choicemm = 0;

//create Player and items

//here we set from the start whether they are going to get the easier ending or not
    cout << DisplayandCheckifEnd::startofgame()<< endl;
    cout << DisplayandCheckifEnd::onea()<< endl;
    cout << DisplayandCheckifEnd::oneb()<< endl;


//here we start the loop until they have run out of days... every day they have 3 turns (that is what sets if the day has ended or not )
    while ( GamePlayerStats::getCurrentDay() > 0){
        if (GamePlayerStats::getTurnsLeft() > 0){
        //display dashboard
        //ask player what they want to do 
            DisplayandCheckifEnd::displaydashboard();

            cin >> choicemm;
        //process player hoice
            DisplayandCheckifEnd::mainmenuchoice(choicemm);
        //update player stat
        // update inventory or bundle progress
        //^^^ all are done in other classes nothing else should be done here 
        
        }else{
            WorldBuilding::Endofday();
            GamePlayerStats::setCurrentDay();
        }

    }

    cout << DisplayandCheckifEnd::final() << endl;



    return 0;
}