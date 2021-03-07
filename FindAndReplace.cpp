#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    string str, find_word, replace_word;
    string arr[20];

    cout << "Input string: ";
    getline(cin, str);
    cout << "Find word: ";
    cin >> find_word;
    cout << "Replace word: ";
    cin >>  replace_word;

    string str1 = "";
    int j = 0;
    for(int i=0; str[i]; i++){
        if (str[i] == ' ' || str[i] == '.'){
            arr[j] = str1;
            str1 = "";
            j += 1;
        }
        else{
            str1 = str1 + str[i];
        }
    }
    int len = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<len; i++){
        if (arr[i] == find_word)
            arr[i] = replace_word;
    }
    cout << endl << endl;
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}
