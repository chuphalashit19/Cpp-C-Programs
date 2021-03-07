#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

double calcAverage(double total){
    return total/3;
}

double calcPrice(double totalRate){
    double fp;
    if (totalRate < 35)
        fp = totalRate-(totalRate*0.10);
    else if(35 < totalRate <= 60)
        fp = totalRate-(totalRate*0.15);
    else
        fp = totalRate-(totalRate*0.25);

    return fp;
}

void getInput(double *mt1, double *mt2, double *mt3){
    cout << "Movie Type 1: ";
    cin >> *mt1;
    cout << "Movie Type 2: ";
    cin >> *mt2;
    cout << "Movie Type 3: ";
    cin >> *mt3;
}

void displayRentalSummary(double overallTotalRate, double tot_mt1, double tot_mt2, double tot_mt3){
    cout << "<<<<<<<<<<<<<< RENTAL SUMMARY >>>>>>>>>>>>>>>" << endl;
    cout << "Overall Total Rate (RM)             : " << overallTotalRate << endl;
    cout << "Average for 3 types of rented movies: " << calcAverage(tot_mt1+tot_mt2+tot_mt3) << endl;
    if (tot_mt1 > tot_mt2 && tot_mt1 > tot_mt3)
        cout << "Highest type of movie rented       : Movie Type 1 (" << tot_mt1 << ")" << endl;
    else if (tot_mt2 > tot_mt1 && tot_mt2 > tot_mt3)
        cout << "Highest type of movie rented       : Movie Type 2 (" << tot_mt2 << ")" << endl;
    else
        cout << "Highest type of movie rented       : Movie Type 3 (" << tot_mt3 << ")" << endl;
}

int main(){
    char ch;
    double mt1, mt2, mt3, totalRate, tot_mt1=0, tot_mt2=0, tot_mt3=0;
    double overallTotalRate=0;
    string name;
    do{
        cout << "<<<<<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>>>>>>>>\n";
        cout << "Renter name : ";
        cin.ignore();
        getline(cin, name);
        getInput(&mt1, &mt2, &mt3);
        totalRate = (mt1*2) +(mt2*5)+(mt3*3.5);
        overallTotalRate += totalRate;
        cout << "\n";
        cout << "<<<<<<<<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>>>>>>>>>\n" << endl;
        cout << "Total Rate (RM): " << totalRate << endl;
        cout << "Final Price (RM): " << calcPrice(totalRate) << endl;

        cout << "\nPress [N] to stop...";
        cin >> ch;
        tot_mt1 += mt1;
        tot_mt2 += mt2;
        tot_mt3 += mt3;
        cout << "\n";
        if (ch == 'n' || ch == 'N')
            displayRentalSummary(overallTotalRate, tot_mt1, tot_mt2, tot_mt3);
    }while(ch != 'n');
    cout << "\n\n";
    return 0;
}
