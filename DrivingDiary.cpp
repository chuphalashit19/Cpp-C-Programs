#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;

int main(){
    int ch, i = 0,k=0;
    string sloc, stime, sodomet, eloc, etime, eodomet, amt;
    string arr [100][7];

    do{
        cout << "\n";
        cout << "1. Initialize (clear all trip information)" << endl;
        cout << "2. Save trip data to file" << endl;
        cout << "3. Read trip data from file" << endl;
        cout << "4. Add a new trip" << endl;
        cout << "5. Remove a trip" << endl;
        cout << "6. Calculate average fuel" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter you choice: ";
        cin >> ch;
        cout << "\n";

        if (ch == 1){
            ofstream file("DrivingDiary.txt");
            cout << "Cleared all trip information !!" << endl;
        }
        else if (ch == 2){
            ofstream myfile;
            myfile.open("DrivingDiary.txt", ios::app);
            for(; k < i; k++){
                for(int l = 0; l < 7; l++){
                    myfile << arr[k][l];
                    myfile << " ";
                }
                myfile << "\n";
            }
            myfile.close();
            cout << "Done!!!!!!" << "\n" << endl;
        }
        else if (ch == 3){
            ifstream newfile;
            newfile.open("DrivingDiary.txt");
            cout << "--------------TRIP DATA------------ \n";
            if (newfile.is_open()){
                string tp;
                while(getline(newfile, tp)){
                    cout << tp << "\n";
                }
                newfile.close();
            }
        }
        else if (ch == 4){
            int j = 0;
            cout << "Start location:";
            cin.ignore();
            getline(cin, sloc);
            arr[i][j] = sloc;
            j++;
            cout << "Start time: ";
            getline(cin, stime);
            arr[i][j] = stime;
            j++;
            cout << "Odometer value at the start of the trip: ";
            getline(cin, sodomet);
            arr[i][j] = sodomet;
            j++;
            cout << "End location: ";
            getline(cin, eloc);
            arr[i][j] = eloc;
            j++;
            cout << "End time: ";
            getline(cin, etime);
            arr[i][j] = etime;
            j++;
            cout << "Odometer value at the end of the trip: ";
            getline(cin, eodomet);
            arr[i][j] = eodomet;
            j++;
            cout << "The amount of fuel you bought during the trip: ";
            getline(cin, amt);
            arr[i][j] = amt;
            j++;
            i++;
        }
        else if (ch == 5){
            int n;
            ifstream newfile;
            newfile.open("DrivingDiary.txt");
            ofstream temp;
            temp.open("temp.txt");
            cout << "--------------TRIP DATA------------ \n";
            if (newfile.is_open()){
                string tp;
                while(getline(newfile, tp)){
                    cout << tp << "\n";
                }
                newfile.close();
            }
            cout << "Which trip you want to delete, enter line number: ";
            cin >> n;
            ifstream is("DrivingDiary.txt");
            ofstream ofs;
            ofs.open("temp.txt", ofstream::out);

            char c;
            int line_no = 1;
            while (is.get(c))
            {
                if (c == '\n' && line_no!=n+1)
                    line_no++;
                if (line_no != n)
                ofs << c;
            }
            ofs.close();
            is.close();
            remove("DrivingDiary.txt");
            rename("temp.txt", "DrivingDiary.txt");
            cout << "Trip Deleted !!\n" << endl;
        }
        else if (ch == 6){

        }
        else{
            cout << "Exiting !!!!!!!!\n";
            break;
        }

    }while(ch != 7);
}
