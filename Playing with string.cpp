#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cctype> 
using namespace std;

void vowelsVsConsonants(string s)
{
    int i, vowels=0, consonants=0;
    for(i=0;s[i];i++)  
    {
		if(s[i]=='a'|| s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O' ||s[i]=='U')
            vowels++;
        else
        	consonants++;
 	}
 	if (vowels == consonants)
 	    printf("# vowels = # consonants.");
 	else
 	    printf("# vowels != # consonants.");
}
void letterSwap(string s)
{
	char c1, c2;
    string new_string = "";
	int i,j;
    c1 = s[0];
    for(i=0; s[i]; i++)
    {
    	if(s[i] == ',')
			c2 = s[i+2];
	}
	for(i=0;i < s.length()-1; i++){
		if(s[i] == c1 || s[i] == c1+32){
			if(isupper(s[i]))
				new_string += toupper(c2);
			else
				new_string += tolower(c2);
		}
		else
			new_string += s[i];
	}
	cout << new_string << "\n\n";
}
void reverseString(string s)
{
	int i,j = 0;
	string str;
    for (i=s.length()-1; i>=0; i--){
		str += s[i];
	}
	cout << str;
}
bool is_Palindrome(string s)
{
    int i, len;
	len = s.length();
    for (i = 0; i > len / 2; ++i) {
		if (toupper(s[i]) != toupper(s[len-i-1])) {
    	    return false;
        }
    }
    return true;
}
void wordsFrequency(string s)
{
	int i,j,n;
	string new_str;
	string arr[100];
	cout << "Enter number of words to search:";
	cin >> n;
	map<string, int > m;
	for(i=0; i<n; i++){
		cin >> arr[i];
		m[arr[i]] = 0;
	}
	cout << "\n";
	map<string, int >::iterator itr;
    for(i=0; i<s.length(); i++)
	{
		if(s[i] != ' ')
			new_str += s[i];
    	else if(s[i] == ' ')
		{
			
			for(j=0; j<n; j++)
			{
    			if(arr[j] == new_str)
					m[arr[j]] += 1;
			}
			new_str = "";
		}
	}
	for(j=0; j<n; j++)
	{
    	if(arr[j] == new_str)
			m[arr[j]] += 1;
	}
	new_str = "";
    for(itr=m.begin(); itr!=m.end(); itr++)
        cout<<itr->first<<" - "<<itr->second<<endl;
    cout << "\n\n";
}

string purge_string(string s)
{	
	string str_new = "";
	int i, j = 0;
	for (i = 0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            str_new = str_new + s[i];
        }
    }
	return str_new;
}
string purge_string1(string s)
{	
	string str_new = "";
	int i, j = 0;
	for (i = 0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' ') {
            str_new = str_new + s[i];
        }
    }
	return str_new;
}
int main()
{
    int i,j,ch = 0;
    while(ch != 6){
        cout << "1. Vowels Vs Consonants\n";
        cout << "2. Letter Swap\n";
        cout << "3. Flip(reverse) the string\n";
        cout << "4. Palindrome Detector\n";
        cout << "5. Words Frequency\n";
        cout << "6. Quit\n\n";
        cout << "Enter your choice: ";
        cin >> ch ;
        if (ch == 1){
            string s, str_new = "";
            cout << "\nEnter a string : ";
            cin.ignore();
			getline(cin, s);
			str_new = purge_string(s);
			vowelsVsConsonants(str_new);
            cout << "\n\n";
        }
        else if(ch == 2){
            string s;
            cout << "\nEnter a string : ";
            cin.ignore();
			getline(cin, s);
			letterSwap(s);
        }
        else if(ch == 3){
            string s;
            cout << "\nEnter a string : ";
            cin.ignore();
			getline(cin, s);
			reverseString(s);
            cout << "\n\n";
        }
        else if (ch == 4){
        	string s, str_new = "";
            cout << "\nEnter a string : ";
            cin.ignore();
			getline(cin, s);
			str_new = purge_string(s);
            cout << boolalpha << is_Palindrome(str_new) << "\n\n";
        }
        else if (ch == 5){
        	int n;
			string s, arr[100];
            cout << "\nEnter a string : ";
            cin.ignore();
            getline(cin, s);
            int i, j = 0;
			s = purge_string1(s);
			for(i=0; s[i]; i++){
				s[i] = tolower(s[i]);
			}
            wordsFrequency(s);
        }
    }
}
