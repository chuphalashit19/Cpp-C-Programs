#include<bits/stdc++.h>
#include<fstream>
#include <string>

using namespace std;

int main(){
    string word;
    int num;
    int pos_count=0, neg_count=0, pos_sum=0, neg_sum=0, zero_count = 0;
    string myFile;
    cout << "\n Enter filename with .txt: ";
    cin >> myFile;
    ifstream file(myFile);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream ss(line.c_str());
            string word;
            while (ss >> word)
            {
                num = stoi(word);
                if(num > 0){
                    pos_sum += num;
                    pos_count += 1;
                }
                else if (num < 0){
                    neg_sum += num;
                    neg_count += 1;
                }
                else if (num == 0){
                    zero_count += 1;
                }
            }
        }
        file.close();
    }
    cout << "\n Positive Sum: " << pos_sum;
    cout << "\n Negative Sum: " << neg_sum;
    cout << "\n Positive Count: " << pos_count;
    cout << "\n Negative Count: " << neg_count;
    cout << "\n Zero Count: " << zero_count;
    cout << "\n";
}
