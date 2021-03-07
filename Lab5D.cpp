#include<bits/stdc++.h>
#include<cmath>
using namespace std;
vector<int> split(string s, char d) {
    vector<int> v;
    stringstream ss(s);
    string token;
    while(getline(ss, token, d)) {
        v.push_back(atoi(token.c_str()));
    }
    return v;
}
int main(void)
{
    string line;
    ifstream file("Lab5D.txt");
    float taxRate = 0.0825;
    float sp = 10.50;
    float mp = 12.00;
    float lp = 14.75;
    if(file.is_open()){
        while(getline(file,line)){
            int arr[3];
            int i = 0;
            float subtotal = 0, tax = 0, total;
            vector<int> vec = split(line, ' ');
            for(int i = 0; i < vec.size(); ++i)
                cout << vec[i] << endl;
            cout << endl;
            subtotal += vec[0]*sp;
            subtotal += vec[1]*mp;
            subtotal += vec[2]*lp;
            tax = subtotal * taxRate;
            total = subtotal + tax;
            cout << fixed << setprecision(2) << "subtotal=" << subtotal << ", tax=" << tax << " and total=" << total << endl << endl;
        }
    }
}
