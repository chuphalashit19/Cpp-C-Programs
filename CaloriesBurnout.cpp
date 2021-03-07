#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int age;
    int weight;
    int heartRate;
    int time;
    double menCalories, womenCalories;
    cin >> age >> weight >> heartRate >> time;

    womenCalories = ((age * 0.074) - (weight * 0.05741) + (heartRate * 0.4472) - 20.4022) * time/ 4.184;
    menCalories = ((age * 0.2017) + (weight * 0.09036) + (heartRate * 0.6309) - 55.0969) * time/ 4.184;

    cout << fixed << setprecision(2) << "Women: " << womenCalories << " calories\n";
    cout << fixed << setprecision(2) << "Men: " << menCalories << " calories\n";
}
