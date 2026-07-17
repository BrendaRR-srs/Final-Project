#include "DisplayandCheckifEnd.h"
#include "CharacterDialogue.h"
#include "GamePlayerStats.h"
#include "WorldBuilding.h"


#include <string>
#include <iostream>

using namespace std;

    void DisplayandCheckifEnd::displaydashboard(){
        cout<< "==================================================" << endl;
        cout << "                  MAIN MENU" <<endl;
        cout << "=================================================="<<endl;
        
        cout << "Day: "<< GamePlayerStats::getCurrentDay() <<" / 14        Turns Left: "<< GamePlayerStats::getTurnsLeft() <<" / 3        "<< endl; //add this laterMoney: "<< GamePlayerStats::getmoneyamountleft()<<" gold" << endl;
        cout << "Report Progress: "<< WorldBuilding::getLocationsLeftToReportOn() <<" / 8 reports gathered" <<endl;
        cout << endl;
        //display the necessary map
        if(GamePlayerStats::getLyfPath() == 1){//display dilias map
            DisplayandCheckifEnd::displayTownMapone();}
        else{//display normal map
            DisplayandCheckifEnd::displayTownMaptwo();}

        cout << endl;

        cout << "You are currently in the " << GamePlayerStats::getCurrentLocation() << endl;
        cout << "What would you like to do? (choose between 1-4)" << endl;
        cout << "1. Talk to:" << WorldBuilding::displayavaliblepeople(GamePlayerStats::getCurrentLocation()) << endl;
        cout << "2. Move to another location" << endl;
        cout << "3. View inventory" << endl;
        cout << "4. View Report" << endl;
    }

    void DisplayandCheckifEnd::mainmenuchoice(int choice){

        switch (choice){
        //1. Talk to someone
            case 1: 
                cout << "Talk to " << WorldBuilding::displayavaliblepeople(GamePlayerStats::getCurrentLocation()) << endl;                
                CharacterDialogue::playerpick(GamePlayerStats::getCurrentLocation());
                
                GamePlayerStats::setTurnsLeft(); // this sets the current turn to one minus
                break;

        //2. Move to another location
            case 2:
                {
                    cout<< "Where would you like to move to: (type the name of the place you would like to go)"<< endl;
                    
                    string newlocation;
                    cin >> newlocation;

                    GamePlayerStats::setCurrentLocation(newlocation);
                    GamePlayerStats::setTurnsLeft(); // this sets the current turn to one minus
                    break;
                }

        //3. View inventory
            case 3:
                GamePlayerStats::displayinventory();

/*
this may or maynot be useful later
                cout << "Would you like to use something from your inventory (press 1 for yes 2 for no)" << endl;                
                int useitemfrominventory;
                cin >> useitemfrominventory
                if(useitemfrominventory == 1){
                    cout << "What Item would you like to use? (type the item you need)" << endl;
                    string useitemforturnfrominventory;
                    cin >> useitemforturnfrominventory;

                    GamePlayerStats::subtractfrominventory(useitemforturnfrominventory);

                }else if (useitemfrominventory ==2 ){
                    break;
                }else{
                    cout << "Invalid option, please choose again" << endl;

                    GamePlayerStats::displayinventory();
                    cout << "Would you like to use something from your inventory (press 1 for yes 2 for no)" << endl;
                }
*/              GamePlayerStats::setTurnsLeft(); // this sets the current turn to one minus
                break;

       //4. View report of locations left

            case 4:
                DisplayandCheckifEnd::reportlefttodo();
                GamePlayerStats::setTurnsLeft(); // this sets the current turn to one minus
                break;

            default:
                cout << "Invalid choice, enter a number from the choices given above. " << endl;
                
                cout << "What would you like to do? (choose between 1-4)" << endl;
                cout << "1. Talk to:" << WorldBuilding::displayavaliblepeople(GamePlayerStats::getCurrentLocation()) << endl;
                cout << "2. Move to another location" << endl;
                cout << "3. View inventory" << endl;
                cout << "4. View Report" << endl;
                break;
        }
                        
    }

    void DisplayandCheckifEnd::displayTownMaptwo(){
        cout << "+------------------ Sunny Cliffs ------------------+" << endl;
        cout << endl;
        cout << " [Water Dam] " << endl;
        cout << "   |" << endl;
        cout << " [Mines]                          [Doctor Fix it]  [Lookout Tower] [     ]" <<endl;
        cout << "   |                                      |                 |      [     ]" <<endl;
        cout << "[Forest] -- [Farm] -- [Apartments][Town Square] -- [Pier] --       [Beach]" <<endl;
        cout << "               |           |                            |          [     ]" <<endl;
        cout << "        [Water Tower]  [Nancy's]                  [Mayor's Office] [     ]" <<endl;
        cout << endl;
        cout << "Current Location: " << GamePlayerStats::getCurrentLocation() <<endl;
    }

    void DisplayandCheckifEnd::displayTownMapone(){ //this is the one dalia gives you for listening to her rambling
        cout << "+------------------ Sunny Cliffs ------------------+" << endl;
        cout << endl;
        cout << " [Water Dam] " << endl;
        cout << "   |" << endl;
        cout << " [Mines]            [Grandma's Shack] [Doctor Fix it] [Lookout Tower]  [     ]" <<endl;
        cout << "   |                       |               |            |              [     ]" <<endl;
        cout << "[Forest] -- [Farm] -- [Apartments][Town Square] -- [Pier] --           [Beach]" <<endl;
        cout << "               |           |              |             |              [     ]" <<endl;
        cout << "         [Water Tower]  [Nancy's]  [Lost and Found]  [Mayor's Office]  [     ]" <<endl;
        cout << endl;
        cout << "Current Location: " << GamePlayerStats::getCurrentLocation() <<endl;
    }

    string DisplayandCheckifEnd::reportlefttodo(){
        string coutthething = ""; 
        coutthething += "+------------------------------------------------+ \n";
        coutthething += "| Farm     |\n";
        coutthething += "| Livesock Report        | Water Report      | Farm Machinary Fixed|\n";
        
        
        coutthething += "|   ";
        if (CharacterDialogue::LiveStockReportCollected() == true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}
        
        coutthething += "         |   ";

        if (CharacterDialogue::WaterReportCollected() == true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}

        coutthething += "         |   ";

        if (CharacterDialogue::Farmmachinarymixed() == true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}

        coutthething += "                | \n";
        

        coutthething += "+------------------------------------------------+ \n" ;
        coutthething += "| Martime       | \n" ;
        coutthething += "| Pier Report          | Beach Report          | Loook Out Tower Report | \n" ;
        
        
        coutthething += "|   ";
        if (CharacterDialogue::PierReportCollected() ==true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}
        
        coutthething += "         |   ";

        if (CharacterDialogue::BeachReportCollected() == true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}

        coutthething += "         |   ";

        if (CharacterDialogue::LookOutTowerReportCollected() == true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}

        coutthething += "                | \n";

        coutthething += "+------------------------------------------------+" ;
        coutthething += "|Forest    |";
        coutthething += "| Trails Report | Boar Captured     |" ;
        
        
        coutthething += "|   ";
        if (CharacterDialogue::TrailsReportCollected() ==true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}
        
        coutthething += "         |   ";

        if (CharacterDialogue::BoarCaptured() ==true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}

        coutthething += "         |   ";


        coutthething += "+------------------------------------------------+\n" ;
        coutthething += "|Mines     |";
        coutthething += "| MinesMachinary Report| Dam Report       |" ;
        
        coutthething += "|   ";
        if (CharacterDialogue::MinesMachinearyReportCollected() ==true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}
        
        coutthething += "         |   ";

        if (CharacterDialogue::ReportFromMayorAboutDamConstruction() ==true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}
        coutthething += "                | \n";


        coutthething += "+------------------------------------------------+" ;
        coutthething += "|Nancy's    |";
        coutthething += "| Machinary Report | Food Saftey Certificate From Pier and Farm     |" ;
        
        
        coutthething += "|   ";
        if (CharacterDialogue::NMachinaryReportCollected() ==true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}
        
        coutthething += "         |   ";

        if (CharacterDialogue::pierfoodsaftey() ==true && CharacterDialogue::farmfoodsaftey() == true)
        {
            coutthething += "X";
        }else{ coutthething += " ";}


        coutthething += "                | \n";


        coutthething += "X = Report Gathered \n";
        

        coutthething += "Locations left to REPORT: "; 
        coutthething += to_string(WorldBuilding::getLocationsLeftToReportOn());
        coutthething += "/ 10";

        return coutthething;
    }




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    string DisplayandCheckifEnd::startofgame(){
        string coutthething = "";
        string name = "";

        coutthething += "Hey! Welcome to the game! \n";
        coutthething += "Your goal is to collect information about this town to report to your boss by the end of this MONTH (30 days). \n";
        coutthething += "First lets name you! What would you like to be named?: ";

        cin >> name;
        GamePlayerStats::setname(name);

        coutthething += GamePlayerStats::getname() + ", since you are new here, your current stats dont seem like much now, \n"; //insert constructor that was created earlier here maybe
        coutthething += " BUT HOLD HOPE, you are capable of achieving this goal if you put your HEART into it!!!";
        coutthething += "\n To look at your stats pull up your main menu by clicking (mm) ";
        coutthething += "Your boss has already given you this handy map to help gather more information, 300 gold, and an apartment that serves as your home for these next 30 days.";
        coutthething += "Best of luck," + GamePlayerStats::getname() + "!";

        return coutthething;
    }

    string DisplayandCheckifEnd::onea(){
        string coutthething = " ";

        coutthething += "As you walk down the Mountain, you look over, and below you is a clearance, where land seems to be filled with life. Do you choose to explore it? or do you leave for the village? \n";
        coutthething += "(Mind you, if you choose to go the farm land, you lose 1 day) Enter 1 to stay at the farm and 2 to continue on the path.  ";

        int choice;
        cin >> choice;
        GamePlayerStats::setLyfPath(choice);


        if(GamePlayerStats::getLyfPath() == 1){
            coutthething += "At clearance, you knock on the door, and a kind woman with a warm smile greets you, inviting you to stay for the night. You wake up and find that you have lost the day. You are given the chance to extend the kindness that was offered to you.";
            
            GamePlayerStats::setCurrentDay(); //this subtracts a day 


            coutthething += "Her kindness inspires you to spend another day at the Farm to help with some chores to repay the kindness.";
            coutthething += "In return, Terra, the woman who owns the farm, gives you a bundle of carrots to take on your journey, and wishes you the guidance of the forset by the tree spirits.";
                //setinventory add the carrots (6) to the inventory
                GamePlayerStats::addtoinventory("6 carrots");
        }

        coutthething += "You decide to keep trudging toward the Village. After a few hours of walking, you settle at a place to rest behind a rock when you see a squirrel approach you.";
        coutthething += "Before you realize it, you find yourself chasing the squirell to retrieve your stolen items. Once the squirrel climbs up a tree, you look around, and find yourself far away from the path you were meant to follow.";
        coutthething += "then a voice comes from behind you.";

        if(GamePlayerStats::getLyfPath() == 1){
            coutthething += "Hello there good simaritan, you seem lost, do you need assistance? \n";
            coutthething += "You turn around and find yourself looking at a man, his carriage, and a donkey. The man holding a curious expression on his face, points towards the squirell and asks you, 'you know him?' with a playful tone.";
            coutthething += "once he helps you regain your backpack, you both settle down as you see the sun setting, and he offers to share his company with you.";
            coutthething += "Grateful for the company that was shared, you decide to give a carrot to his cute companion and ask for her name , which happens to be faithful, in return for the food. ";
            //replace the carrot ammount to 3
            GamePlayerStats::subtractfrominventory("6 carrots");
            GamePlayerStats::addtoinventory("3 carrots");


            coutthething += "In the morning, he offers to take you into the village, which by donkey takes a day. ";
            GamePlayerStats::setCurrentDay();

        } else{
            coutthething += "You seem lost, do you need assistance? \n";
            coutthething += "You turn around and find yourself looking at a man, acarriage, and a donkey. The man, holding a skeptical expression on his face, asks you what you are doing wandering the forest so far from the path";
            coutthething += "once he helps you regain your backpack, you both settle down as you see the sun setting, and he offers to share his company with you.";
            coutthething += "Once he falls asleep, you see something catch your eye. A gold compass seems like something that might be useful to get back to the village as quickly as possible. You are running out of time after all.";

            coutthething += "You decide to leave before dawn breaks, from here, you are still 2 days away from the village. Using the compass, you head off.";
            GamePlayerStats::setCurrentDay();
            GamePlayerStats::setCurrentDay();
        }

        return coutthething;
    }



    string DisplayandCheckifEnd::oneb(){
        string coutthething = " ";

        coutthething += "You finally arrive to the edge of the village. Wandering around, you bump into a little girl.";
        coutthething += "Before you know it, she introduces herself to you and asks: 'what brings you here?', 'are you a tourist?', 'Do you speak any other languages?', 'what you are looking for?', 'Would you like to meet my grandma?'.";

        if(GamePlayerStats::getLyfPath() == 1){
            coutthething += "Although abit alarmed at her confidence at talking to strangers, you find her endearing as she continues to rattle off, and follow her through the town as she explains everything she knows about the world around her.";
            coutthething += "She analyzes your confused, but friendly face, and decides instead to draw a map for you, including giving you a list of helpfult tips about the people around the village, along with how to contact her grandma.";
            coutthething += "You thank her the time and the map, and hope to find her again. ";
            coutthething += "You gift her a coin to buy herself some sweet treats from the store.";
            GamePlayerStats::addtoinventory("dalia's map");

        }else{
            coutthething += "Annoyed at this kid for talking about things she doesn't undrstand, you smile warmly, but lightly push her aside and continue to wander the village.";
        }

        coutthething += "After wandering for a hot minute, you feel you are familiar enough to feel ready to complete the quest.";

        return coutthething;
    }

    string DisplayandCheckifEnd::onec(){
        string coutthething = " ";
        coutthething += "Now that you have explored the majority of the places and its surroundings, its important that you also fulfill what you came to do";
        coutthething += "from here you are allowed to travel freeley to gather the report as quickly as possible to return it to your boss, but be warned, you have ";
        coutthething += to_string(GamePlayerStats::getCurrentDay());
        coutthething += " days left";
        
        if(GamePlayerStats::getLyfPath() == 1){
            coutthething += "Somehow, the world seems to feel in your favor";
        }else{
            coutthething += "Somehow, the world is starting to feel as if it is turning against you";
        }
        return coutthething;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    

/*

    void ezra(){
        if(first time == true || recomended by niece){
            welcome! 
        }
        cout << "buying a missing bundle item" << endl;
        cout << "Buying food or energy drinks" << endl;
        cout << "Paying money to unlock a location faster" << endl;
        cout << "Accepting a Joja repair plan" << endl;
        cout << "Trading friendship or Community Points for a shortcut" << endl;
        cout << "buying a missing bundle item" << endl;
        cout << "Receiving a different ending if the player relies on Joja too much" << endl;
    }

void unavaliblemerchandise(string takenfromstore){
    vector<string> unavalible;

    unavalible.push_back(takenfromstore);
}
string avaliblethings(vector<string> unavalible){
    vector<string> merchandise;


}


    void schedualegivenbydalia(){
        //this should come directly from the txt file change this later
    }


didn't have enough time to finish this, but was hoping to implement system that allows for bartering with different stores depending on your lyfPath

*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    string DisplayandCheckifEnd::final(){
        string coutthething = " ";

        if(GamePlayerStats::getLyfPath() == 1 && WorldBuilding::getLocationsLeftToReportOn() == 6){
            coutthething += "you are finally at the end of your journey, you have done your job and more. Boarding the ship feels heavier each step. You look back and feel the that something is calling you. Returning isn't an option now, besides, you still have work to do.";

        }else{
            coutthething += "you are finally at the end of your journey, you have done your job, and as you board the ship, you look back and feel the that something is calling you. Returning isn't an option now, besides, you still have work to do.";
        }


        return coutthething;
    }

    
