#include<bits/stdc++.h>

using namespace std;

int main(void){
    string arr[7][7];

    //creating $1 box
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if((i==0) && (0<=j<7))
                arr[i][j] = "$1";
            if(j==0 && (0<=i<7))
                arr[i][j] = "$1";
            if(j==6 && (0<=i<7))
                arr[i][j] = "$1";
            if(i==6 && (0<=j<7))
                arr[i][j] = "$1";
        }
    }
    //creating $2 box
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(i==1 && (j==1||j==2||j==3||j==4||j==5))
                arr[i][j] = "$2";
            if(j==1 && (i==2||i==3||i==4||i==5))
                arr[i][j] = "$2";
            if(j==5 && (i==2||i==3||i==4||i==5))
                arr[i][j] = "$2";
            if(i==5 && (j==2||j==3||j==4))
                arr[i][j] = "$2";
        }
    }
    //creating $3 box
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(i==2 && (j==2||j==3||j==4))
                arr[i][j] = "$3";
            if(j==2 && (i==3||i==4))
                arr[i][j] = "$3";
            if(j==4 && (i==3||i==4))
                arr[i][j] = "$3";
            if(i==4 && (j==3||j==4))
                arr[i][j] = "$3";
        }
    }
    //putting $4 in middle
    arr[3][3] = "$4";
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
