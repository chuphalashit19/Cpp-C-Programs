#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
    int i, fuelspend;
    string id;
    double mntn_low = 99999;
    string cars[6][4] = {{"1", "Sport", "V6", "69"}, {"2", "Work", "XM2", "92"}, {"3", "Work", "V6", "78"}, {"4", "Sport", "XM2", "65"}, {"5", "Sport", "XM2", "57"}, {"6", "Work", "V6", "87"}};
    cout << "Car ID\t" << "Car Type\t" << "Engine Type\t" << "Fuel Spending\t" << "Maint. cost\t" << "Fuel costs(% of maint.)" << endl;
    for(i=0; i<6; i++){
        double mntn_fees = 0, fuel_cost;
        fuelspend = atoi(cars[i][3].c_str());
        if (cars[i][2] == "V6"){
            int engine_eco = 25;
            double mntn_fees = engine_eco+(30*0.15)+((fuelspend-30)*0.20);
            double fuel_cost = ((mntn_fees-engine_eco)/mntn_fees)*100;
            cout << cars[i][0] << "\t" << cars[i][1] << "\t\t  " << cars [i][2] << "\t\t  " << cars[i][3] <<"\t\t  " << mntn_fees <<"\t\t  " << setprecision(2) << fuel_cost << endl;
        }
        if (cars[i][2] == "XM2"){
            int engine_eco = 70;
            double mntn_fees = engine_eco+(25*0.05)+((fuelspend-25)*0.10);
            double fuel_cost = ((mntn_fees-engine_eco)/mntn_fees)*100;
            cout << cars[i][0] << "\t" << cars[i][1] << "\t\t  " << cars [i][2] << "\t\t  " << cars[i][3] <<"\t\t  " << mntn_fees <<"\t\t  " << setprecision(2) << fuel_cost << endl;
        }

        mntn_low = min(mntn_low, mntn_fees);
        if (mntn_low == mntn_fees)
            id = cars[i][0];
    }
    cout << "\n Car ID " << id << " is with lowest maint cost " << mntn_low << endl;
}
