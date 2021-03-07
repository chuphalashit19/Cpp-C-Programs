#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(){
    int i, j=0, num, num1;
    char str[100];
    string newstr[100];
    string s, ns;
    getline(cin, s);
    for(i=0; i<s.length(); i++){
        if(s[i] != ','){
            str[j] = s[i];
            j++;
        }
    }
    for(i=0; i<j-1; i++){
        getline(cin, s);
        newstr[i] = s;
    }
    int k;
    for(i=0; i<j-1; i++){
        if (str[i] == newstr[i][0]){
            ns += newstr[i];
            break;
        }
    }
    for(i=0; i<j-1; i++){
        if (ns[ns.length()-1] == newstr[i][0]){
            string str1 = newstr[i];
            size_t i = 0;
            for ( ; i < str1.length(); i++ )
            {
                if ( isdigit(str1[i]) ) break;
            }
            str1 = str1.substr(i, str1.length() - i );
            num = atoi(str1.c_str());
            i = 0;
            for ( ; i < ns.length(); i++ )
            {
                if ( isdigit(ns[i]) ) break;
            }
            str1 = ns.substr(i, ns.length() - i );
            num1 = atoi(str1.c_str());
            ns += "=";
            ns += to_string(num*num1);
            ns += newstr[i][newstr[i].length()-1];
        }
    }
    for(i=0; i<j-1; i++){
        if (ns[ns.length()-1] == newstr[i][0]){
            string str1 = newstr[i];
            size_t i = 0;
            for ( ; i < str1.length(); i++ )
            {
                if ( isdigit(str1[i]) ) break;
            }
            str1 = str1.substr(i, str1.length() - i );
            int num2 = atoi(str1.c_str());
            ns += "=";
            ns += to_string(num*num1*num2);
            ns += newstr[i][newstr[i].length()-1];
        }
    }
    cout << ns <<endl;
}
