#include<iostream>
#include<string>
using namespace std;
string bodymass(double, double);

string bodymass(double height_meters, double weight_kilos){
    double bmi;
    bmi = (weight_kilos)/(height_meters*height_meters);

    if (bmi >= 30)
        return "Obese";
    else if (30 < bmi >= 24)
        return "Over weight";
    else if (24 < bmi >= 18)
        return "Over weight";
    else
        return "Under weight";
}
int main(){
    double height_meters, weight_kilos;

    cout<<"Enter weight in Kilograms : ";
    cin>>weight_kilos;
    cout<<"Enter height in meters : ";
    cin>>height_meters;
    cout<<"You are in category of ";
    //Function bodymass called
    cout<< bodymass (height_meters,weight_kilos)<<endl;
    return 0;
}//end of main program
