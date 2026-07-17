
#ifndef CHARACTERDIALOGUE_H
#define CHARACTERDIALOGUE_H

#include <string>
using namespace std;

class CharacterDialogue{
    private:
    static int farmReportCompleted;
    static int MarTdone;
    static int ForRedone;
    static int MineRedone;
    static int ResRedone;
    static int MayorOffdone;

    static bool LiveSRedone;
    static bool WaterRedone;
    static bool Farmmedone;
    static bool PierRedone;
    static bool BeachRedone;
    static bool LookOutRedone;
    static bool TrailRedone;
    static bool BoarCapdone;
    static bool MinemachRedone;
    static bool ReMayDamdone;
    static bool NmachRedone;
    static bool farmfosafdone;
    static bool pierfosafdone;
    static bool ManFooAskdone;
    static bool Pierkeycoldone;
    static bool Ladkeycoldone;
    static bool WaTounlocked;


    public:

    static void playerpick(string location);

    
    static string TerraDialog(int choice);
    static string GaryDialog(int choice);
    static string RaffDialog(int choice);
    static string CarrieDialog(int choice);
    static string ManagerDialog(int choice);
    static string MayorDialog(int choice);



    

    static void Farmreportcompleted(int amount);
    static int Farmreportcompleted();

    static void MartimeCompleted(int amount);
    static int MartimeCompleted();

    static void ForestReportComplete(int amount);
    static int ForestReportComplete();

    static void MinesReportcompleted(int amount);
    static int MinesReportcompleted();

    static void RestaurantReportCompleted(int amount);
    static int RestaurantReportCompleted();

    static void MayorsOfficeCompleted(int amount);
    static int MayorsOfficeCompleted();

    
    static bool LiveStockReportCollected();
    static void LiveStockReportCollected(bool value);

    static bool WaterReportCollected();
    static void WaterReportCollected(bool value);

    static bool Farmmachinarymixed();
    static void Farmmachinarymixed(bool value);

    static bool PierReportCollected();
    static void PierReportCollected(bool value);

    static bool BeachReportCollected();
    static void BeachReportCollected(bool value);

    static bool LookOutTowerReportCollected();
    static void LookOutTowerReportCollected(bool value);

    static bool TrailsReportCollected();
    static void TrailsReportCollected(bool value);

    static bool BoarCaptured();
    static void BoarCaptured(bool value);

    static bool MinesMachinearyReportCollected();
    static void MinesMachinearyReportCollected(bool value);

    static bool ReportFromMayorAboutDamConstruction();
    static void ReportFromMayorAboutDamConstruction(bool value);

    static bool NMachinaryReportCollected();
    static void NMachinaryReportCollected(bool value);

    static bool farmfoodsaftey();
    static void farmfoodsaftey(bool value);

    static bool pierfoodsaftey();
    static void pierfoodsaftey(bool value);

    static bool ManagerFoodSafteyAsk();
    static void ManagerFoodSafteyAsk(bool value);

    static bool Pierkeycollected();
    static void Pierkeycollected(bool value);

    static bool Ladderkeycollected();
    static void Ladderkeycollected(bool value);

    static bool WaterTowerUnlocked();
    static void WaterTowerUnlocked(bool value);



};

#endif

