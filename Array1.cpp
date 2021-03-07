#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr [2][3];
    for(int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout << "Array " << "[" << i+1 << "]" "[" << j+1 << "] :";
            cin >> arr[i][j];
        }
    }
    cout << endl << "Array contains:" << endl;
    for(int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}
