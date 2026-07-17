#include "GamePlayerStats.h"
#include <string>
#include <iostream>

using namespace std;


    int GamePlayerStats::money = 300;
    int GamePlayerStats::turnsLeft = 3;
    int GamePlayerStats::CurrentDay = 30;
    string GamePlayerStats::currentLocation = "Apartments";
    string GamePlayerStats::inventory[5] = {"", "", "", "", ""};
    int GamePlayerStats::lyfPath = 0;
    string GamePlayerStats::name = "";


    void GamePlayerStats::setMONEY(int amount){money = amount;}
    int GamePlayerStats::getMONEY(){return money;}

    string GamePlayerStats::getCurrentLocation(){return currentLocation;}
    void GamePlayerStats::setCurrentLocation(string location){currentLocation = location;}


    int GamePlayerStats::getTurnsLeft(){return turnsLeft;}
    void GamePlayerStats::setTurnsLeft(){turnsLeft--;}
    void GamePlayerStats::resetTurnsLeft(){turnsLeft = 3;}

    int GamePlayerStats::getCurrentDay(){return CurrentDay;}
    void GamePlayerStats::setCurrentDay(){CurrentDay--;}


//inventory
    void GamePlayerStats::displayinventory(){
        for(int i = 0; i < 5; i++){ //the player should only be able to hold 5 things at a certain time
            cout << inventory[i] << ", " ;   
        }
    }

    void GamePlayerStats::addtoinventory(string addnewthing){
        for(int i = 0; i < 5; i++){
            if(inventory[i] == ""){
                inventory[i] = addnewthing;
                return;
            }
        }

        cout << "Inventory is full!!" << endl;
    }

    void GamePlayerStats::subtractfrominventory(string deleteit){
        for(int i = 0; i < 5; i++){
            if(inventory[i] == deleteit){
                inventory[i] = "";
                return;
            }
        }

    }

    bool GamePlayerStats::isInInventory(string item){
        //this just checks if something is missing from the inventory or not

        for(int i = 0; i < 5; i++){
            if(inventory[i] == item){
                return true;
            }
        }

        return false;
    }

int GamePlayerStats::getLyfPath(){return lyfPath;}
void GamePlayerStats::setLyfPath(int value){lyfPath = value;}
string GamePlayerStats::getname(){return name;}
void GamePlayerStats::setname(string value){name = value;}
