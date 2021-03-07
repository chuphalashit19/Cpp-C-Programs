#include<bits/stdc++.h>

using namespace std;

int arr[30];
int i = 0;

void file1Contents(string file1){
    string line;
    int c = 0;
    ifstream fileone(file1);
    if (fileone.is_open())
    {
        while(getline(fileone,line))
        {
            arr[i] = atoi(line.c_str());
            c += 1;
            i++;
        }
        cout << " The list of " << c << " numbers in the " << file1 << " is:" << endl;
        for(int j=0; j<c; j++)
            cout << " " << arr[j] << endl;
    }
    cout << endl;
    fileone.close();
}

void file2Contents(string file2){
    string line;
    int c = 0;
    int n = i;
    ifstream filetwo(file2);
    if (filetwo.is_open())
    {
        while(getline(filetwo,line))
        {
            arr[i] = atoi(line.c_str());
            c += 1;
            i++;
        }
        cout << " The list of " << c << " numbers in the " << file2 << " is:" << endl;
        for(int j=n; j<i; j++)
            cout << " " << arr[j] << endl;
    }
    cout << endl;
    filetwo.close();
}
void mergeFiles(){
    string outfile;
    cout << endl << " The sorted list of " << i << " numbers is:" ;
    sort(arr, arr + i);
    for(int j=0; j<i; j++)
        cout << " " << arr[j];
    cout << endl << " Enter the output file name:";
    cin >> outfile;
    ofstream fileout(outfile);
    for(int j=0; j<i; j++){
        fileout << arr[j];
        fileout << endl;
    }
    cout << " ***Please check the new file - " << outfile << " ***";
    cout << endl << " ***Goodbye.***";
    cout << endl << endl;
}

int main(){
    string file1, file2;
    cout << " ***Welcome to Li's sorting program***" << endl;
    cout << " Enter the first input file name:";
    cin >> file1;
    file1Contents(file1);
    cout << " Enter the second input file name:";
    cin >> file2;
    file2Contents(file2);
    mergeFiles();
}
