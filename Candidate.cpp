#include<bits/stdc++.h>
#include<iostream>
#include<fstream>

using namespace std;

bool beat(unsigned candidate_1, unsigned candidate_2, unsigned noOfCandidates, string profile){
    int arr[8][6];
    ifstream file("profile.txt");
    string str;
    int c1, c2, cc1 = 0, cc2 = 0;
    int num, k=0;
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            str = line.c_str();
            int j = 0;
            for(int i=0; i<str.length(); i++){
                if(str[i] != ' '){
                    num = str[i] - '0';
                    arr[k][j] = num;
                    j++;
                }
            }
            k++;
        }
        file.close();
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<6; j++){
            if(arr[i][j] == candidate_1)
                c1 = j;
            else if(arr[i][j] == candidate_2)
                c2 = j;
        }
        if(c1 < c2)
            cc1 += 1;
        else
            cc2 += 1;
    }
    if(cc1 > cc2)
        return true;
    else
        return false;

}
int main(){
    if(beat(1, 4, 6, "profile.txt"))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if(beat(3, 4, 6, "profile.txt"))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
