#include<bits/stdc++.h>
using namespace std;
string purge_string(string s)
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
	int i,j,n;
	string new_str;
	string arr[100];
	string k;
	string s = "This is a test sentence, is this?";
	s = purge_string(s);
	for(i=0; s[i]; i++){
		s[i] = tolower(s[i]);
	}
	cout<<s<<endl;
	cout << "Enter number of words to search:";
	cin >> n;
	for(i=0; i<n; i++)
		cin >> arr[i];
    map<string, int > m;
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
}
