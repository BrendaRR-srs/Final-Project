#include "GamePlayerStats.h"
#include "CharacterDialogue.h"

#include <string>
#include <iostream>

using namespace std;

//If inventory is full, tell the player that they have to drop something off
/*
if full == true{
looks like inventory is full, come back another time to retrieve report
}else{
add to the last element}

*/

//If the written report is gathered by player don't show the line again


int CharacterDialogue::farmReportCompleted = 0;
int CharacterDialogue::MarTdone = 0;
int CharacterDialogue::ForRedone = 0;
int CharacterDialogue::MineRedone = 0;
int CharacterDialogue::ResRedone = 0;
int CharacterDialogue::MayorOffdone = 0;

bool CharacterDialogue::LiveSRedone = false;
bool CharacterDialogue::WaterRedone = false;
bool CharacterDialogue::Farmmedone = false;
bool CharacterDialogue::PierRedone = false;
bool CharacterDialogue::BeachRedone = false;
bool CharacterDialogue::LookOutRedone = false;
bool CharacterDialogue::TrailRedone = false;
bool CharacterDialogue::BoarCapdone = false;
bool CharacterDialogue::MinemachRedone = false;
bool CharacterDialogue::ReMayDamdone = false;
bool CharacterDialogue::NmachRedone = false;
bool CharacterDialogue::farmfosafdone = false;
bool CharacterDialogue::pierfosafdone = false;
bool CharacterDialogue::ManFooAskdone = false;
bool CharacterDialogue::Pierkeycoldone = false;
bool CharacterDialogue::Ladkeycoldone = false;
bool CharacterDialogue::WaTounlocked = false;



void CharacterDialogue::playerpick(string Location){

    int playerchoice;

    if(Location == "Farm"){
        if(CharacterDialogue::Farmreportcompleted() != 3){
            cout << "1. ask about the report on the livestock" << endl;
            cout << "2. ask about water test results" << endl;
            cout << "3. ask about machineary" << endl;

            if(CharacterDialogue::ManagerFoodSafteyAsk() == true){
                cout << "4. food saftey" << endl;
            }

            cin >> playerchoice;
            cout << CharacterDialogue::TerraDialog(playerchoice) << endl;

        }else{
            cout << "Nothing to do here, you've completed the task!" << endl;
        }
    }

    else if(Location == "Beach"){
        if(CharacterDialogue::BeachReportCollected() == false){
            cout << "At the Beach, you were able to take pictures and the water quality. Nothing is left to do here, job completed" << endl;
            CharacterDialogue::MartimeCompleted(2);
            CharacterDialogue::BeachReportCollected(true);
        }else{
            cout << "Nothing to do here, you've completed the task!" << endl;
        }
    }

    else if(Location == "Pier"){
        if(CharacterDialogue::MartimeCompleted() != 3){

            cout << "1. sturdiness and safety of the pier for oncoming ships and general life" << endl;
            cout << "2. Cleanliness of the beach" << endl;
            cout << "3. Lookout Tower status" << endl;

            if(CharacterDialogue::ManagerFoodSafteyAsk() == true){
                cout << "4. food saftey" << endl;
            }

            cin >> playerchoice;
            cout << CharacterDialogue::GaryDialog(playerchoice) << endl;

            if(playerchoice == 3 && LookOutTowerReportCollected() == false){
                cout << "After taking samples, and observing the tower, you are able to create a report for the Tower" << endl;
                CharacterDialogue::MartimeCompleted(3);
                CharacterDialogue::LookOutTowerReportCollected(true);
            }

        }else{
            cout << "Nothing to do here, you've completed the task!" << endl;
        }
    }

    else if(Location == "Forest"){
        if(CharacterDialogue::ForestReportComplete() != 2){

            cout << "1. cleanliness of trails" << endl;
            cout << "2. help capture a wild boar for study" << endl;

            cin >> playerchoice;
            cout << CharacterDialogue::RaffDialog(playerchoice) << endl;

        }else{
            cout << "Nothing to do here, you've completed the task!" << endl;
        }
    }

    else if(Location == "Mines"){
        if(CharacterDialogue::MinesReportcompleted() != 2){

            cout << "1. Machinary report" << endl;
            cout << "2. Dam Report" << endl;

            cin >> playerchoice;
            cout << CharacterDialogue::CarrieDialog(playerchoice) << endl;

        }else{
            cout << "Nothing to do here, you've completed the task!" << endl;
        }
    }

    else if(Location == "Nancy's"){
        if(CharacterDialogue::RestaurantReportCompleted() != 2){

            cout << "1. Restaurant Machinery Report" << endl;
            cout << "2. Food Safety" << endl;

            cin >> playerchoice;
            cout << CharacterDialogue::ManagerDialog(playerchoice) << endl;

        }else{
            cout << "Nothing to do here, you've completed the task!" << endl;
        }
    }

    else if(Location == "Mayor"){
        if(CharacterDialogue::MayorsOfficeCompleted() != 3){

            cout << "1. Dam Signature" << endl;
            cout << "2. Key to Pier" << endl;
            cout << "3. Key to Water Tower" << endl;

            cin >> playerchoice;
            cout << CharacterDialogue::MayorDialog(playerchoice) << endl;

        }else{
            cout << "Nothing to do here, you've completed the task!" << endl;
        }
    }

    else{
        cout << "Please Enter a valid Location" << endl;
    }
}
    

//Farm:: 
string CharacterDialogue::TerraDialog(int choice){
    string coutthething = "";
    coutthething += "Terra - 'Hiya, How can I help you?' ";

    if(choice == 1 && CharacterDialogue::LiveStockReportCollected() == false){
        coutthething += "all are generally healthy, here are some papers for that. ";
        coutthething += "(You have to return to your place to leave those papers there, you shouldn’t keep them on you)"; 
        GamePlayerStats::addtoinventory("Farm Report on LiveStock");
        CharacterDialogue::Farmreportcompleted(1); //this just adds 1 so that after the rest are completed the total is 3 
        CharacterDialogue::LiveStockReportCollected(true);
    }

    if(choice == 2 && GamePlayerStats::isInInventory("Mayor Key to Water Tower") == false && WaterReportCollected() == false){
        coutthething +=  "You can find the water tower on the other side of the farm, it might take you a second to get there, but that is out of my jurisdiction. To get there you’d have to talk to the Mayor. I think you need a key to access the ladder, but really I wouldn’t know about that";
        coutthething +=  "(to get to water tower after you have the key, you have to go to the farm first and then to the water tower)";
    }else if(choice == 2 && GamePlayerStats::isInInventory("Mayor Key to Water Tower") == true && WaterReportCollected() == false){
        coutthething += "Great! It looks like you have the key to the Water Tower! The only way to get to the Water Tower is by changing locations from here, so it looks like you dont need anything else from me! Call if you need assistance!";
        CharacterDialogue::WaterTowerUnlocked(true);
        CharacterDialogue::Farmreportcompleted(2);
        
    }

    if(choice == 3 && CharacterDialogue::Farmmachinarymixed() == false && GamePlayerStats::isInInventory("Part For Farm Machine") == false){
        coutthething += "Currently, I have been having to do things without this machine, and that takes me longer than it should, so right now, the farm needs alittle more help than usual. I take volunteers when I can. There is a part that I can get from Doctor Fix It, but I dont have much time to pass by the store with the amount of things I have to do";
        coutthething += "(if you then have the part, you can give it to her, and change the report to fixed)";
    }else if(choice == 3 && CharacterDialogue::Farmmachinarymixed() == false && GamePlayerStats::isInInventory("Part For Farm Machine") == true){
        coutthething += "Thank you so incredibly much for bringing the part to me! I can finally fix the machinary!";
        CharacterDialogue::Farmmachinarymixed(true);
        CharacterDialogue::Farmreportcompleted(3);
    }

    if(choice == 4 && CharacterDialogue::ManagerFoodSafteyAsk() == true && CharacterDialogue::farmfoodsaftey() == false){
    coutthething += "Looks like you talked to both gary and terra, so everything seems on par with what we have. Let us know if you have any other problems!";
    CharacterDialogue::farmfoodsaftey(true);
    
    }

    return coutthething;

}

// Beach, Pier, Lookout Tower::

string CharacterDialogue::GaryDialog(int choice){
    string coutthething = "";
    coutthething += "Gary - 'Remember, there is always more fish in the sea.";

    if(choice == 1 && CharacterDialogue::PierReportCollected() == false){
        coutthething += "Here are the papers for that, dont lose em";
        coutthething += "(You have to return to your place to leave those papers there, you shouldn’t keep them on you)";
        GamePlayerStats::addtoinventory("Pier Report");
        CharacterDialogue::MartimeCompleted(1);
        CharacterDialogue::PierReportCollected(true);
    }


    if(choice == 2 && CharacterDialogue::BeachReportCollected() == false){
        coutthething +=  "To reach the beach, you have to go to the pier and get to the beach from there, you can't directly go to the beach" ;
    }


    if(choice == 3 && CharacterDialogue::LookOutTowerReportCollected() == false && GamePlayerStats::isInInventory("Mayor Key to Look Out Tower") == false){
        coutthething += "Currently, Ive lost the key to the tower, but so far, it works as it should as far as I know. We have a crew that takes care of that really so I might not be much help. You can get the report from them (Hint : go to the pier to reach the lookout tower).";
        coutthething += "First go to the Mayor to get the key to the Look Out Tower, and go to the pier from there";

    }else if(choice == 3 && CharacterDialogue::LookOutTowerReportCollected() == false && GamePlayerStats::isInInventory("Mayor Key to Look Out Tower") == true){
        coutthething += "Best way to go about this is going to the pier from there, best of luck.";
    }

    if(choice == 4 && CharacterDialogue::ManagerFoodSafteyAsk() == true && CharacterDialogue::pierfoodsaftey() == false){
    coutthething += "Hopefully you didn't have much trouble getting that done, I appreciate your help, let us know if you need help with anything else.";
    CharacterDialogue::pierfoodsaftey(true);
    }
        return coutthething;
    }

// forest
string CharacterDialogue::RaffDialog(int choice){
    string coutthething = "";
    coutthething += "Ranger Raff - 'Good morning! Nice to see another face 'round here' ";


    if(choice == 1 && CharacterDialogue::TrailsReportCollected() == false){
        coutthething += "Here is a report for the trails and what not.";
        coutthething += "(You have to return to your place to leave those papers there, you shouldn’t keep them on you)";


        GamePlayerStats::addtoinventory("Trails Report");
    	CharacterDialogue::TrailsReportCollected(true);
        CharacterDialogue::ForestReportComplete(1);
    }


    if(choice == 2 && GamePlayerStats::isInInventory("Rope") == false && CharacterDialogue::BoarCaptured() == false){
        coutthething += "ran out of rope from the last animal we had to capture. Id like to use another method to capture this boar, but id rather be ready with a net on hand\n";
        coutthething +=  "(You can find this in DoctorFixIt)";


    }else if(choice == 2 && GamePlayerStats::isInInventory("Rope") == true && BoarCaptured() == false){
        coutthething += "Thank you for the assistance! This can really help me with the Boar!";
        CharacterDialogue::BoarCaptured(true);
        CharacterDialogue::ForestReportComplete(2);
    }
    return coutthething;
}


//Mines
string CharacterDialogue::CarrieDialog(int choice){
    string coutthething = " ";
    coutthething += "Carrie - 'Don’t forget your helmet.'";


    if(choice == 1 && CharacterDialogue::MinesMachinearyReportCollected() == false){
        coutthething += "Here is a report for the trails and what not.";
        coutthething += "(You have to return to your place to leave those papers there, you shouldn’t keep them on you)";


        GamePlayerStats::addtoinventory("Mines Machineary Report");
    	CharacterDialogue::MinesMachinearyReportCollected(true);
        CharacterDialogue::MinesReportcompleted(1);
    }


    if(choice == 2 && CharacterDialogue::ReportFromMayorAboutDamConstruction() == false && GamePlayerStats::isInInventory("Report TO BE SIGNED BY MAYOR") == false){
        coutthething += "As for the Water Dam Report, the Mayor needs to sign the report. Otherwise that is all we have for you";


    }else if(choice == 2 && GamePlayerStats::isInInventory("Report TO BE SIGNED BY MAYOR") == true && CharacterDialogue::ReportFromMayorAboutDamConstruction() == false){
        coutthething += "Thank you for the assistance! This can really help me with the Boar!";
        CharacterDialogue::ReportFromMayorAboutDamConstruction(true);
        GamePlayerStats::addtoinventory("Report TO BE SIGNED BY MAYOR");
    }else if(choice == 2 && GamePlayerStats::isInInventory("Report TO BE SIGNED BY MAYOR") == true && CharacterDialogue::ReportFromMayorAboutDamConstruction() == true){
        CharacterDialogue::MinesReportcompleted(2);
    }
    
        return coutthething;
}


// Nancy’s : Restaurant
string CharacterDialogue::ManagerDialog(int choice){
    string coutthething = " ";
    coutthething += "Manager - 'Dont forget to bring an empty stomach!!'";


    if(choice == 1 && CharacterDialogue::NMachinaryReportCollected() == false){
        coutthething += "All machinery is working, and so far no problems. This establishment has been here for years, and gets constant updates based on when things need to be renewed. Here is our report";
        coutthething += "(You have to return to your place to leave those papers there, you shouldn’t keep them on you)";


        GamePlayerStats::addtoinventory("Nancy's Machine Report");
        CharacterDialogue::NMachinaryReportCollected(true);
        CharacterDialogue::RestaurantReportCompleted(1);
    }


    if(choice == 2 && CharacterDialogue::farmfoodsaftey() == false  && CharacterDialogue::pierfoodsaftey() == false){
       coutthething += "Any information you need about the food safety comes from the farm and the pier (first check with nancy and then it should appear with the pier and the farm)";
        CharacterDialogue::ManagerFoodSafteyAsk(true);
    }else if(choice == 2 && CharacterDialogue::farmfoodsaftey() == true  && CharacterDialogue::pierfoodsaftey() == false){
        coutthething += "It looks like yous till have to go to the pier to get that report. Until then its still incomplete.";
    }else if(choice == 2 && CharacterDialogue::farmfoodsaftey() == false  && CharacterDialogue::pierfoodsaftey() == true){
        coutthething += "It looks like yous till have to go to the farm to get that report. Until then its still incomplete.";
    }else if(choice == 2 && CharacterDialogue::farmfoodsaftey() == true  && CharacterDialogue::pierfoodsaftey() == true){
        coutthething += "Nice! thank you for getting those reports";
        CharacterDialogue::RestaurantReportCompleted(2);
    }

    return coutthething;
}



//mayor’s office
string CharacterDialogue::MayorDialog(int choice){
    string coutthething = " ";
    coutthething += "Mayor - You can’t spell community without u.'";

    if(choice == 1 && ReportFromMayorAboutDamConstruction() == false && GamePlayerStats::isInInventory("Report TO BE SIGNED BY MAYOR") == true){
        coutthething += "Ah, it looks like you have something for me to sign, well you've come to to the right place.";

        GamePlayerStats::subtractfrominventory("Report TO BE SIGNED BY MAYOR");
        GamePlayerStats::addtoinventory("Report SIGNED BY MAYOR");
        CharacterDialogue::ReportFromMayorAboutDamConstruction(true);
        CharacterDialogue::MayorsOfficeCompleted(1);
    }

    if(choice == 2 &&  Pierkeycollected() == false){
       coutthething += "Ah yes, the men down there are very hard working, I am glad you are here to help protect our fellow men at sea. Here is the key.";
       GamePlayerStats::addtoinventory("Mayor Key to Look Out Tower");
       CharacterDialogue::Pierkeycollected(true);
       CharacterDialogue::MayorsOfficeCompleted(2);
    }

    if(choice == 3 && Ladderkeycollected() == false){
       coutthething+= "Here is the key to the ladder, let me know if it offers you any trouble.";
       GamePlayerStats::addtoinventory("Mayor Key to Water Tower");  
       CharacterDialogue::Ladderkeycollected(true);
       CharacterDialogue::MayorsOfficeCompleted(3);
    }

    return coutthething;
}


void CharacterDialogue::Farmreportcompleted(int amount){farmReportCompleted = amount;}
int CharacterDialogue::Farmreportcompleted(){return farmReportCompleted;}

void CharacterDialogue::MartimeCompleted(int amount){MarTdone = amount;}
 int CharacterDialogue::MartimeCompleted(){return MarTdone;}

 void CharacterDialogue::ForestReportComplete(int amount){ForRedone= amount;}
 int CharacterDialogue::ForestReportComplete(){return ForRedone;}

 void CharacterDialogue::MinesReportcompleted(int amount){MineRedone= amount;}
 int CharacterDialogue::MinesReportcompleted(){return MineRedone;}

 void CharacterDialogue::RestaurantReportCompleted(int amount){ResRedone= amount;}
 int CharacterDialogue::RestaurantReportCompleted(){return ResRedone;}

 void CharacterDialogue::MayorsOfficeCompleted(int amount){MayorOffdone= amount;}
 int CharacterDialogue::MayorsOfficeCompleted(){return MayorOffdone;}

bool CharacterDialogue::LiveStockReportCollected(){ return LiveSRedone; }
void CharacterDialogue::LiveStockReportCollected(bool value){ LiveSRedone = value; }

bool CharacterDialogue::WaterReportCollected(){ return WaterRedone; }
void CharacterDialogue::WaterReportCollected(bool value){ WaterRedone = value; }

bool CharacterDialogue::Farmmachinarymixed(){ return Farmmedone; }
void CharacterDialogue::Farmmachinarymixed(bool value){ Farmmedone = value; }

bool CharacterDialogue::PierReportCollected(){ return PierRedone; }
void CharacterDialogue::PierReportCollected(bool value){ PierRedone = value; }

bool CharacterDialogue::BeachReportCollected(){ return BeachRedone; }
void CharacterDialogue::BeachReportCollected(bool value){ BeachRedone = value; }

bool CharacterDialogue::LookOutTowerReportCollected(){ return LookOutRedone; }
void CharacterDialogue::LookOutTowerReportCollected(bool value){ LookOutRedone = value; }

bool CharacterDialogue::TrailsReportCollected(){ return TrailRedone; }
void CharacterDialogue::TrailsReportCollected(bool value){ TrailRedone = value; }

bool CharacterDialogue::BoarCaptured(){ return BoarCapdone; }
void CharacterDialogue::BoarCaptured(bool value){ BoarCapdone = value; }

bool CharacterDialogue::MinesMachinearyReportCollected(){ return MinemachRedone; }
void CharacterDialogue::MinesMachinearyReportCollected(bool value){ MinemachRedone = value; }

bool CharacterDialogue::ReportFromMayorAboutDamConstruction(){ return ReMayDamdone; }
void CharacterDialogue::ReportFromMayorAboutDamConstruction(bool value){ ReMayDamdone = value; }

bool CharacterDialogue::NMachinaryReportCollected(){ return NmachRedone; }
void CharacterDialogue::NMachinaryReportCollected(bool value){ NmachRedone = value; }

bool CharacterDialogue::farmfoodsaftey(){ return farmfosafdone; }
void CharacterDialogue::farmfoodsaftey(bool value){ farmfosafdone = value; }

bool CharacterDialogue::pierfoodsaftey(){ return pierfosafdone; }
void CharacterDialogue::pierfoodsaftey(bool value){ pierfosafdone = value; }

bool CharacterDialogue::ManagerFoodSafteyAsk(){ return ManFooAskdone; }
void CharacterDialogue::ManagerFoodSafteyAsk(bool value){ ManFooAskdone = value; }

bool CharacterDialogue::Pierkeycollected(){ return Pierkeycoldone; }
void CharacterDialogue::Pierkeycollected(bool value){ Pierkeycoldone = value; }

bool CharacterDialogue::Ladderkeycollected(){ return Ladkeycoldone; }
void CharacterDialogue::Ladderkeycollected(bool value){ Ladkeycoldone = value; }

bool CharacterDialogue::WaterTowerUnlocked(){ return WaTounlocked; }
void CharacterDialogue::WaterTowerUnlocked(bool value){ WaTounlocked = value; }




////////////////////////

/*
void DoctorFixIt (){
    //this should be another array of things 
}
void LostAndFound (){
    //this should probably just be an array of things
}
void NanasHouse (){
    //this has actual dialog that should be completed later
}

as mentioned in display and check if ending, there wasn't enough time for me to implement the rest of this
*/

