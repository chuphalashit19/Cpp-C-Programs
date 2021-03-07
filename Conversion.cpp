#include<bits/stdc++.h>
#include<string>

using namespace std;

void milesToKilometers(double miles){
    double kilometers;
    kilometers = miles * 1.609;
    cout << miles << " miles is " << kilometers << " kilometers." << endl << endl;
}
void kilometersToMiles(double kilometers){
    double miles;
    miles = kilometers * 0.621;
    cout << kilometers << " kilometers is " << miles << " miles." << endl << endl;
}
void hours12ToMilitaryTime(int hrs, int mins, string meridiem){
    string h;
    if (meridiem == "AM"){
        if (hrs < 10){
            h += "0" + to_string(hrs) + to_string(mins);
            hrs = atoi(h.c_str());
        }
        else{
            h += to_string(hrs) + to_string(mins);
            hrs = atoi(h.c_str());
        }
    }
    else{
        h += to_string(hrs+12) + to_string(mins);
        hrs = atoi(h.c_str());
    }
    cout << "The military time is: " << hrs << "." << endl << endl;
}
void militaryTimeTo12Hours(string t){
    int hrs, mins;
    string h = "", m = "", meridiem;
    if(t == "0000"){
        hrs = 12;
        mins = 00;
        meridiem = "AM";
    }
    else if (atoi(t.c_str()) < 1200){
        h += t[0];
        h += t[1];
        m += t[2];
        m += t[3];
        hrs = atoi(h.c_str());
        mins = atoi(m.c_str());
        meridiem = "AM";
    }
    else if(atoi(t.c_str()) == 1200){
        h += t[0];
        h += t[1];
        m += t[2];
        m += t[3];
        hrs = atoi(h.c_str());
        mins = atoi(m.c_str());
        meridiem = "PM";
    }
    else{
        h += t[0];
        h += t[1];
        m += t[2];
        m += t[3];
        hrs = atoi(h.c_str());
        hrs = hrs-12;
        mins = atoi(m.c_str());
        meridiem = "PM";
    }
    cout << "The twelve-hour time is: " << hrs << " " << mins << " (PM = ";
    if(meridiem == "PM")
        cout << "true";
    else
        cout << "false";
    cout << ")." << endl << endl;
}

int main(){
    char c;
    do{
        cout << "**** MENU ****" << endl;
        cout << "a. miles to kilometers" << endl;
        cout << "b. kilometers to miles" << endl;
        cout << "c. 12-hour time to military time" << endl;
        cout << "d. military time to 12- hour time" << endl;
        cout << "e. Exit" << endl;
        cout << endl << "Enter you choice: ";
        cin >> c;

        switch(c){
            case 'a':{
                double miles;
                cout << "How many miles?" << endl;
                cin >> miles;
                milesToKilometers(miles);
                break;
            }

            case 'b':{
                double kilometers;
                cout << "How many kilometers?" << endl;
                cin >> kilometers;
                kilometersToMiles(kilometers);
                break;
            }

            case 'c':{
                int hrs, mins;
                string meridiem;
                cout << "Please enter time in 12-hour format. Do not use colon and separate by spaces." << endl;
                cout << "Example input: ''3 14 PM''. Please make sure to capitalize AM/PM" << endl;
                cin >> hrs >> mins >> meridiem;
                hours12ToMilitaryTime(hrs, mins, meridiem);
                break;
            }

            case 'd':{
                string t;
                cout << "Please enter a time in military format. Example input: ''1512''." << endl;
                cin >> t;
                militaryTimeTo12Hours(t);
                break;
            }

            default :
                cout << "Exiting!!!" << endl;
                return 0;
        }

    }while(c != 'e');
    cout << endl << "Exiting!!!!" << endl << endl;
}
