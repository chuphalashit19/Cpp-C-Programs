#include<bits/stdc++.h>

using namespace std;

int main(){
    int op;
    string str;
    cout << " Enter your option:" << endl;
    cout << "   1. to encrypt the file" << endl;
    cout << "   2. to decrypt the file" << endl;
    cout << " Option: ";
    cin >> op;
    if (op == 1){
        ifstream ReadFile("decrypted_msg.txt");
        while (getline(ReadFile, str)){
            char ch;
            for(int i=0; i<str.length(); i++){
                ch = str[i];
                if(ch >= 'a' && ch <= 'z') {
                    ch = ch + 19;
                    if(ch < 'a'){
                        ch = ch + 'z' - 'a' + 1;
                    }
                    str[i] = ch;
                }
                else if (ch >= 'A' && ch <= 'Z'){
                    ch = ch + 19;
                    if (ch > 'Z'){
                    ch = ch - 'Z' + 'A' - 1;
                    }
                    str[i] = ch;
                }
                else if(isdigit(ch)){
                    int num = 0;
                    num = ((ch - '0') + 5);
                    if (num >= 10){
                        num = num - 10;
                        ch = num + '0';
                        str[i] = ch;
                    }
                    else{
                        ch = num + '0';
                        str[i] = ch;
                    }
                }
            }
            ofstream WriteFile("encrypted_msg.txt", ios::out | ios::app);
            WriteFile << str << endl;
        }
        cout << " The encryption result of the input file is stored in 'encrypted_msg.txt'" << endl;
    }
    else if(op == 2){
        ifstream ReadFile("encrypted_msg.txt");
        while (getline(ReadFile, str)){
            char ch;
            for(int i = 0; i < str.length(); ++i) {
                ch = str[i];
                if(ch >= 'a' && ch <= 'z') {
                    ch = ch - 19;
                    if(ch < 'a'){
                        ch = ch + 'z' - 'a' + 1;
                    }
                    str[i] = ch;
                }
                else if(ch >= 'A' && ch <= 'Z') {
                    ch = ch - 19;
                    if(ch < 'A') {
                        ch = ch + 'Z' - 'A' + 1;
                    }
                    str[i] = ch;
                }
            }
            ofstream WriteFile("decrypted_msg.txt", ios::out | ios::app);
            WriteFile << str << endl;
        }
        cout << " The decryption result of the input file is stored in 'decrypted_msg.txt'" << endl;
    }
    else{
        cout << " Exiting the menu!!" << endl << endl;
        return 0;
    }
    cout << endl << endl;
}
