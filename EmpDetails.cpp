#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream file;
    file.open("Employee.txt");
    string arr[5][12];
    if(file.is_open())
    {
        cout << "File Opened successfully!!!" << endl;
        for(int i = 0; i <5 ; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                file >> arr[i][j];
            }
        }
    }
    string arr1[5][4];
    for(int i = 0; i <5 ; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if (j == 0){
                string str = arr[i][j];
                arr1[i][1] = str[0];
            }
            if (j == 1)
                arr1[i][0] = arr[i][j];
            if (j == 2)
                arr1[i][2] = arr[i][j] + "/" + arr[1][j+1] + "/" + arr[i][j+2];
            if (j == 9)
            {
                if(arr[i][j] == "AC")
                    arr1[i][3] = "Accounting";
                else if(arr[i][j] == "MD")
                    arr1[i][3] = "Medical";
                else if(arr[i][j] == "EG")
                    arr1[i][3] = "Engineering";
                else if(arr[i][j] == "TE")
                    arr1[i][3] = "Technical";
                else if(arr[i][j] == "PP")
                    arr1[i][3] = "Physical Plant";
                else if(arr[i][j] == "ST")
                    arr1[i][3] = "Staff";
                else if(arr[i][j] == "LW")
                    arr1[i][3] = "Legal";
                else if(arr[i][j] == "RD")
                    arr1[i][3] = "Research";
                else if(arr[i][j] == "TT")
                    arr1[i][3] = "Testing";
                else if(arr[i][j] == "QC")
                    arr1[i][3] = "Quality Control";
                else if(arr[i][j] == "BB")
                    arr1[i][3] = "Biblogy";
            }
        }
    }
    cout << endl;
    ofstream file1("Employee Outfile.txt");
    file1 << "Last Name  First Initial  Begin Date     Department Name" << endl;
    for(int i = 0; i <5 ; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            file1 << arr1[i][j] << "         ";
        }
        file1 << endl;
    }
    cout << "Last Name  First Initial  Begin Date     Department Name" << endl;
    for(int i = 0; i <5 ; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << arr1[i][j] << "         ";
        }
        cout << endl;
    }
    cout << endl << endl;
    file.close();
}
