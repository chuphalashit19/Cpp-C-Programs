#include<bits/stdc++.h>
using namespace std;

void EncryptMsg(string msg, int key)
{
    char ch;
    for(int i = 0; msg[i] != '\0'; ++i) {
        ch = msg[i];
        //encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        //encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if (ch > 'Z'){
               ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
         }
      }
      cout << "Encrypted message: " << msg << endl;
}
void DecryptMsg(string msg, int key)
{
    char ch;
      for(int i = 0; msg[i] != '\0'; ++i) {
         ch = msg[i];
         //decrypt for lowercase letter
         if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a'){
               ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
         }
         //decrypt for uppercase letter
         else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
               ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
         }
      }
      cout << "Decrypted message: " << msg << endl;
}
int main() {
    int choice,key;
    string text;
    cout << "1. Encryption \n2. Decryption \n" << endl;
    cout << "Enter your choice:";
    cin>>choice;
    if (choice==1){ //for encryption
        cout<<"Enter the message to encrypt:-" << endl;
        cin.ignore();
        getline(cin, text);          //take the message as input
        cout << "Enter key: ";
        cin >> key;                     //take the key as input
        EncryptMsg(text, key);
    }
    else if (choice == 2) {             //for decryption
        cout<<"Enter the message to decrypt:- " << endl;
        cin.ignore();
        getline(cin,text);           //take the message as input
        cout << "Enter key: ";
        cin >> key;                      //take the key as input
        DecryptMsg(text, key);
    }
}
