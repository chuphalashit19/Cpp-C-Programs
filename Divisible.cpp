#include<bits/stdc++.h>

using namespace std;

int main(void){
    int num = 51;
    cout << endl;
    while(1){
        if(num > 50 && num%44==0 && num%5!=0){
            cout << " The first integer is: " << num;
            cout << endl << endl << endl;
            break;
        }
        num =  num+1;
    }
}
