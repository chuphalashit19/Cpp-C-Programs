#include<bits/stdc++.h>
#include<string>

using namespace std;

int readFile(string filename, int arr[10][4]){
    int i, j;
    ifstream file;
    string str;
    file.open(filename);
    if(file.is_open())
    {
        while(!file.eof())
        {
            for(i = 0; i < 10; i++)
            {
                for(j = 0; j < 4; j++)
                {
                    file >> arr[i][j];
                }
            }
        }
    }
    file.close();
    return arr[10][4];
}
int displayMenu(int arr[10][4]){
    int i, j, ch, br, qt;
    do{
        cout << "\nMenu" << endl;
        cout << "Choose 1 to see a branch's sales for a particular quarter" << endl;
        cout << "Choose 2 to see the total sales for a branch" << endl;
        cout << "Choose 3 to see the total branch sales for a particular quarter" << endl;
        cout << "Choose 4 to see the total sales for all branches" << endl;
        cout << "Choose 5 to see the sales for the highest quarter for a branch" << endl;
        cout << "Choose 6 to see the sales for the lowest quarter for a branch" << endl;
        cout << "Choose 7 to see the average quarterly sales for the company" << endl;
        cout << "Choose 8 to see to see a branch's increase or decrease from a previous quarter" << endl;
        cout << "Choose 9 to see a list of all quarterly sales figures" << endl;
        cout << "Choose 10 to see the company's increase or decrease from the previous quarter" << endl;
        cout << "Choose 12 to exit this program." << endl;
        cout << "Enter your choice and press Return:" << endl;
        cin >> ch;

        if(ch == 1){
            cout << "Enter the branch number: ";
            cin >> br;
            cout<< "Enter the Quarter: ";
            cin >> qt;
            for(i=0; i<10; i++)
                if(i+1 == br)
                    for(j=0; j<4; j++)
                        if(j+1 == qt)
                            cout << "The sales for branch " << br << ", quarter " << qt << " is $" << arr[i][j] << endl;
        }
        else if(ch == 2){
            int total = 0;
            cout << "Enter the branch number: ";
            cin >> br;
            for(i=0; i<10; i++)
                if(i+1 == br)
                    for(j=0; j<4; j++)
                        total += arr[i][j];
            cout << "Total Sales for branch number " << br << " is $" << total << endl;
        }
        else if(ch == 3){
            int total = 0;
            cout << "Enter the quarter: ";
            cin >> qt;
            for(i=0; i<10; i++)
                for(j=0; j<4; j++)
                    if(j+1 == qt)
                        total += arr[i][j];
            cout << "Total Sales for quarter " << qt << " is $" << total << endl;
        }
        else if(ch == 4){
            int total = 0;
            for(i=0; i<10; i++)
                for(j=0; j<4; j++)
                    total += arr[i][j];
            cout << "Total sales for all branches is $" << total << endl;
        }
        else if(ch == 5){
            int maximum = 0;
            cout << "Enter the branch: ";
            cin >> br;
            for(i=0; i<10; i++)
                if(i+1 == br)
                    for(j=0; j<4; j++)
                        if(maximum < arr[i][j])
                            maximum = arr[i][j];
            cout << "Sales for the highest quarter for branch " << br << " is $" << maximum << endl;
        }
        else if(ch == 6){
            int minimum = 9999999;
            cout << "Enter the branch: ";
            cin >> br;
            for(i=0; i<10; i++)
                if(i+1 == br)
                    for(j=0; j<4; j++)
                        if(arr[i][j] < minimum)
                            minimum = arr[i][j];
            cout << "Sales for the lowest quarter for branch " << br << " is $" << minimum << endl;
        }
        else if(ch == 7){
            int average = 0, avg = 0;
            int total = 0;
            for(i=0; i<10; i++){
                int tot = 0;
                for(j=0; j<4; j++)
                    tot += arr[i][j];
                avg = tot/10;
                total += avg;
            }
            average = total/4;
            cout << "The average quarterly sales for all branches is $" << average << endl;
        }
        else if(ch == 8){
            int diff = 0;
            cout << "Enter the branch number: ";
            cin >> br;
            cout << "Enter the Quarter: (Do not enter 1 since that is the first quarter): ";
            cin >> qt;
            for(i=0; i<10; i++)
                if(i+1  ==  br)
                    for(j=0; j<4; j++)
                        if(j+1 == qt)
                            diff = arr[i][j] - arr[i][j-1];

            cout << "For branch " << br << ", quarter " << qt << ", the difference in sales from the previous quarter is $" << diff << endl;
        }
        else if(ch == 9){
            cout << "Branch #\tQtr 1\tQtr 2\tQtr 3\tQtr 4" << endl;
            for(i=0; i<10; i++){
                cout << "Branch " << i+1 << "\t";
                for(j=0; j<4; j++){
                    cout << arr[i][j] << "\t";
                }
                cout << "\n";
            }
        }
        else if(ch == 10){
            int total = 0;
            cout << "Enter the Quarter: (Do not enter 1 since that is the first quarter): ";
            cin >> qt;
            for(i=0; i<10; i++)
                for(j=0; j<4; j++)
                    if(j+1 == qt)
                        total += arr[i][j] - arr[i][j-1];
            cout << "The difference in total sales from the previous quarter is $" << total << endl;
        }
        else{
            cout << "End Of Program" << endl;
            return 0;
        }
    }while(ch != 12);
    return 0;
}

int main(){
    int i, j, arr[10][4];
    string filename = "Branch_Quaterly_Sales.txt";

    arr[10][4] = readFile(filename, arr);
    displayMenu(arr);
    return 0;
}
