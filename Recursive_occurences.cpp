#include<bits/stdc++.h>

using namespace std;
int j = 0;
int c = 0;

int findOccurences(int arr[], int len){
    while(j < len){
        if (arr[j] == 1){
            c = c + 1;
            j = j + 1;
            findOccurences(arr, len);
        }
        else{
            j = j + 1;
        }
    }
    return c;
}

int main(){
    int arr[] = {1, 1, 2, 1, 2, 1, 4, 7 ,2 ,8 };
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << endl;
    cout << " Array: ";
    for(int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl << endl;
    cout << " Length of Array: " << len;
    cout << endl << endl;
    cout << " Number 1 occurs " << findOccurences(arr, len) << " times";
    cout << endl << endl;
    return 0;
}
