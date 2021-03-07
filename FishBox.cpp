#include<iostream>
#include <string.h>

using namespace std;

int main(){
    int i, len, num_of_fish, box1 = 0, box2 = 0, box3 = 0 ;
    string boxes, status;

    cin >> num_of_fish;
    cin.ignore();
    getline(cin, boxes);
    len = boxes.length();
    for(i=0; i<len; i++){
        if (boxes[i] == '1')
            box1 += 1;
        else if (boxes[i] == '2')
            box2 += 1;
        else if (boxes[i] == '3')
            box3 += 1;
        else
            continue;
    }
    if (box2 == 3)
        status = "FULL";
    else
        status = "NOT FULL";

    cout << "\n";
    cout << box1 << " fish in first box" << endl;
    cout << box2 << " fish in second box" << endl;
    cout << box3 << " fish in third box" << endl;
    cout << "Status of second box: " << status << endl;

    return 0;
}
