#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

int main(){
    int n;
    cout << "Enter the length of integers: ";
    cin >> n;
    int lis[n];
    for(int i=0; i<n ; i++){
        cout << "Element " << i+1 << " :";
        cin >> lis[i];
    }

    while(1){
        int ch, i;
        cout << endl;
        cout << "1. Count of the numbers in the list." << endl;
        cout << "2. Sum of the numbers in the list." << endl;
        cout << "3. Average of the numbers in the list." << endl;
        cout << "4. Maximum of the numbers in the list." << endl;
        cout << "5. Minimum of the numbers in the list." << endl;
        cout << "6. Otherwise" << endl;
        cout << endl << "Enter you choice:";
        cin >> ch;
        int sum = 0, len = 0, maximum = -1, minimum = INT_MAX;
        float total = 0, avg;
        switch(ch){
        case 1:
            for(i=0; i<n; i++)
                len++;
            cout << "Count of the numbers in the list: " << len << endl;
            break;

        case 2:
            for(i=0; i<n ;i++)
                sum += lis[i];
            cout << "Sum of the numbers in the list: " << sum << endl;
            break;

        case 3:
            for(i=0; i<n; i++)
                total += lis[i];
            avg = total/n;
            cout << setprecision(2) << "Average of the numbers in list: " << avg << endl;
            break;

        case 4:
            for(i=0; i<n; i++)
                if(maximum < lis[i])
                    maximum = lis[i];
            cout << "Maximum number in list: " << maximum << endl;
            break;

        case 5:
            for(i=0; i<n; i++)
                if(minimum > lis[i])
                    minimum = lis[i];
            cout << "Minimum number in list: " << minimum << endl;
            break;

        default:
            cout << "Exiting the menu!!" << endl << endl;
            return 0;
        }
    }
    return 0;
}
