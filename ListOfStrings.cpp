#include<bits/stdc++.h>
using namespace std;
string getString(list<string> mystring){
    list <string> :: iterator it;
    for(it = mystring.begin(); it != mystring.end(); it++)
        return *it;
}
string peekString(){
    return "None";
}
string peek2String(){
    return "None";
}
string nextString(){
    return "None";
}

int main(){
    list<string>mystring;
    mystring = {"Apple", "Banana", "Mango", "Orange", "Kiwi", "Watermelon"};
    cout << getString(mystring);
    peekString();
    peek2String();
    nextString();
}
