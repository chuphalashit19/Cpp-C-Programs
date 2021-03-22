#include<bits/stdc++.h>

using namespace std;

int numBoys(char gender[125])
{
    int numOfBoys = 0;
    for(int i=0; i<125; i++)
        if(gender[i] == 'M')
            numOfBoys++;
    return numOfBoys;
}

int numBig(float weight[125])
{
    int weight8 = 0;
    for(int i=0; i<125; i++)
        if(weight[i] > 8)
            weight8++;
    return weight8;
}

int main(void)
{
    char gender[125] = {};
    float weight[125] = {0};
    string line;
    ifstream file("births.txt");
    int j=0;
    while(getline(file, line))
    {
        int k = 0;
        string str = "";
        for(int i=0; i<line.length(); i++){
            if(i == 0)
            {
                gender[j] = line[i];
            }
            if(line[i] != ' ' && i != 0)
            {
                str += line[i];
            }
        }
        float w = stof(str);
        weight[j] = w;
        j++;
    }
    file.close();
    int nb = numBoys(gender);
    int w8 = numBig(weight);

    cout << " Number of babies born that were boys: " << nb << endl << endl;
    cout << " Number of babies born that were weight more than 8 pounds: " << w8 <<  endl << endl;
}
