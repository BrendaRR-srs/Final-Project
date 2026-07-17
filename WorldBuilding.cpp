#include "WorldBuilding.h"
#include "GamePlayerStats.h"
#include "CharacterDialogue.h"
#include <string>
#include <iostream>
using namespace std;

/*

    string coutplacestovisitnext(){
        //first check if both of arrays are the same, then call the thing here
        coutthething = "";

        coutthething += "Report Progress: ";
        couthething +=  to_string(WorldBuildling::getLocationsLeftToReportOn());
        couthething += "/ 8 locations reported";
        couthething +=  "Still Needed:" ;

        for(int i = 0; i < array.size(); i++ ){
            couthething +=  "- "
            couthething += array[i];
        }
    }


    void suddenlyitstartsto(){
        //sunny days have a higher chance (if good)
        //rainy days have a higher chance (if bad)
            
        int random = 0;

        if(good == true){
            rand = higher chance of sun
            switch(random){
            case 0:
                cout << "You wake up in your __ and find yoruself waking up to the tapping of rain on the glass." << endl
                WorldBuilding::setweather("Sunny");
                break;
            case 1:
                cout << "You wake up in your __ and find yoruself waking up to the sun hitting your eyes." << endl
                WorldBuilding::setweather("Rainy");
                break;
            }


        }else if (good == false){
            rand = higher chance of sun
            switch(random){
            case 0:
                cout << "You wake up in your __ and find yoruself waking up to the tapping of rain on the glass." << endl
                WorldBuilding::setweather("Sunny");
                break;
            case 1:
                cout << "You wake up in your __ and find yoruself waking up to the sun hitting your eyes." << endl
                WorldBuilding::setweather("Rainy");
                break;
            }
        }

    }
*/
 

    void WorldBuilding::Endofday(){
        if (getTurnsLeft() == 0){
            cout << "Its getting late, and its time to return back home" << endl;
            resetTurnsLeft(); 
            setCurrentLocation("Apartments");
        }

        //if i had more time to finish, I would have also made something that checks if they have a report or not, and they can leave it at the apartment so that its not taking up inventory space
    }

    int WorldBuilding::getLocationsLeftToReportOn(){
        int report = 0;
        int locationsleft[6] = {0,0,0,0,0,0};

        if(CharacterDialogue::Farmreportcompleted() == 3){
            locationsleft[0] = 1;
        }
        
        if(CharacterDialogue::MartimeCompleted() == 3){
            locationsleft[1] = 1;
        }
        
        if(CharacterDialogue::ForestReportComplete() == 2){
            locationsleft[2] = 1;
        }
        
        if(CharacterDialogue::MinesReportcompleted() == 2){
            locationsleft[3] = 1;
        }
        
        if(CharacterDialogue::RestaurantReportCompleted() ==2 ){
            locationsleft[4] = 1;
        }
        
        if (CharacterDialogue::MayorsOfficeCompleted() == 2){
            locationsleft[5] = 1;
        }

        for(int i = 0; i < 6; i++ ){
            report = locationsleft[i] + report;
        }

        return report;
    }


    string WorldBuilding::displayavaliblepeople(string currentlocation){
        if(currentlocation == "Mines"){
            return "Talk to Carrie about the Mines Report" ;
        }else if(currentlocation == "Farm"){
            return "Talk to Terra about her Farm";
        }else if(currentlocation == ""){
            return "Talk to Miner" ;        // replace later
        }else if(currentlocation == "Nancy's"){
            return "Talk to Restaurant Manager" ;
        }else if(currentlocation == "Nana's"){
            return "Talk to Nana" ;   
        }else if(currentlocation == "Pier"){
            return "Talk to Gary about the Pier" ;
        }else if(currentlocation == "Mayor's Office"){
            return "Talk to Mayor" ;
        }else if(currentlocation == "Forest"){
            return "Talk to Ranger Raff about the Forest conditions" ;
        }else if(currentlocation == "Look Out Tower"){
            return "Talk to Workers about the Lookout Tower" ; 
        }else{
            return "You are alone in your apartment, dont forget to leave the reports on the table.";
        }
    }