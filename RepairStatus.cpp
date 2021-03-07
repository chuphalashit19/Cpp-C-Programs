#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;

int main(){
    int ch, i = 0, k = 0;
    string name, prob_desc, sol_desc, stime, status;
    string arr [100][7];

    do{
        cout << "\n";
        cout << "1. Initialize (clear all records)" << endl;
        cout << "2. Save repair records to file" << endl;
        cout << "3. Read repair records from file" << endl;
        cout << "4. Add a new repair task" << endl;
        cout << "5. Perform fix" << endl;
        cout << "6. Display 3 most difficult repairs" << endl;
        cout << "7. Print a report which lists all repairs" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter you choice: ";
        cin >> ch;
        cout << "\n";

        if (ch == 1){
            ofstream file("RepairStatus.txt");
            cout << "Cleared all records !!" << endl;
        }
        else if (ch == 2){
            ofstream myfile;
            myfile.open("RepairStatus.txt", ios::app);
            for(; k < i; k++){
                myfile << "\n";
                for(int l = 0; l < 5; l++){
                    myfile << arr[k][l];
                    myfile << " ";
                }
            }
            myfile.close();
            cout << "Done!!!!!!" << "\n" << endl;
        }
        else if (ch == 3){
            ifstream newfile;
            newfile.open("RepairStatus.txt");
            cout << "--------------REPAIR STATUS------------\n";
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
            cout << "Name of the client:";
            cin.ignore();
            getline(cin, name);
            arr[i][j] = name;
            j++;
            cout << "Problem description: ";
            getline(cin, prob_desc);
            arr[i][j] = prob_desc;
            j++;
            cout << "Status (Completed / Pending): ";
            getline(cin, status);
            arr[i][j] = status;
            j++;
            i++;
        }
        else if (ch == 5){
            int n;
            ifstream newfile;
            newfile.open("RepairStatus.txt");
            ofstream temp;
            temp.open("temp.txt");
            cout << "--------------REPAIR STATUS------------\n";
            if (newfile.is_open()){
                string tp;
                while(getline(newfile, tp)){
                    cout << tp << "\n";
                }
                newfile.close();
            }
            cout << "Perform fix for which repair: ";
            cin >> n;
            cout << "\nAdd solution: ";
            cin.ignore();
            getline(cin, sol_desc);
            cout << "Time spent to an existing task: ";
            getline(cin, stime);
            string filename = "RepairStatus.txt", line;
            ifstream fin(filename.c_str(), std::ios::in);
            string arr1[20];
            int m = 0;
            if (fin.good())
            {
                for (int lineno = 1; getline (fin,line); lineno++){
                    if (lineno == n){
                        string nl;
                        string nline =  line + sol_desc + " " + stime;
                        istringstream iss(nline);
                        string ss = "";
                        while ( getline(iss, ss, ' ' ) ) {
                            if (ss == "Pending"){
                                nl = nl + "Completed" + " ";
                            }
                            else
                                nl = nl + ss + " ";
                        }
                        arr1[m] = nl;
                    }
                    else{
                        arr1[m] = line;
                    }
                    m++;
                }
            }
            fin.close();
            ofstream myfile;
            myfile.open("RepairStatus.txt");
            for(int b = 0 ; b < m; b++){
                myfile << arr1[b];
                myfile << "\n";
            }
            myfile.close();
            cout << "\nPerformed Fixed !!\n" << endl<<endl<<endl;
        }
        else if (ch == 6){
            int s = 0, num;
            int new_arr[20];
            string new_arr1[3];
            cout << "Three most difficult repairs based on time spent are: " << endl;
            ifstream newfile;
            newfile.open("RepairStatus.txt");
            if (newfile.is_open()){
                string tp;
                while(getline(newfile, tp)){
                    size_t i = 0;
                    for ( ; i < tp.length(); i++ ){
                        if (isdigit(tp[i]) )
                            break;
                    }
                    tp = tp.substr(i, tp.length() - i );
                    num = atoi(tp.c_str());
                    new_arr[s] = num;
                    s++;
                }
            }
            newfile.close();
            sort(new_arr, new_arr + (s+1), greater<int>());
            for(int a = 0; a < 3; a++)
                new_arr1[a] = to_string(new_arr[a]);
            newfile.open("RepairStatus.txt");
            if (newfile.is_open()){
                string tp;
                while(getline(newfile, tp)){
                    string ss;
                    istringstream iss(tp);
                    while (getline(iss, ss, ' ')) {
                        for(int a = 0; a < 3; a++)
                            if (ss == new_arr1[a])
                                cout << tp << "\n";
                    }
                }
            }
        }
        else if (ch == 7){
            ifstream newfile;
            newfile.open("RepairStatus.txt");
            if (newfile.is_open()){
                string tp;
                cout << "\n--------Completed Repairs Status---------" << endl;
                while(getline(newfile, tp)){
                    istringstream iss(tp);
                    string ss;
                    while(getline( iss, ss, ' ')){
                        if (ss == "Completed")
                            cout << tp << "\n";
                    }
                }
            }
            newfile.close();
            newfile.open("RepairStatus.txt");
            if (newfile.is_open()){
                string tp;
                cout << "\n--------Pending Repairs Status----------" << endl;
                while(getline(newfile, tp)){
                    string ss;
                    istringstream iss(tp);
                    while ( getline( iss, ss, ' ' ) ) {
                        if (ss == "Pending")
                            cout << tp << "\n";
                    }
                }
            }
        }
        else{
            cout << "Exiting !!!!!!!!\n";
            break;
        }

    }while(ch != 8);
}
