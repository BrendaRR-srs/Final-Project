#include <iostream>
#include <string>

using namespace std;


int main(){

    //main menu
    int mainmenuchoice;

    cout << "Here are the choices and what they stand for" << endl;
    cin>>mainmenuchoice;
    
    while(mainmenuchoice != 3)
        switch (mainmenuchoice) {
            case 0:
                // Code to execute if expression == constant1
                break;
            case 1:
                // Code to execute if expression == constant2
                break;
            default:
                cout << "Enter valid option" << endl;
                break;
    }

    return 0;
}