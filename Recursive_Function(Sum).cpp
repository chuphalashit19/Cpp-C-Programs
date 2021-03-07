#include<bits/stdc++.h>

using namespace std;

int sum = 0;

int recursiveSum(int n)
{
    if(n <= 225){
        sum += n;
        n += 15;
        recursiveSum(n);
    }
    return sum;
}

int main(void){
    int n = 15;
    cout << endl;
    cout << " The sum is: ";
    cout << recursiveSum(n) << endl << endl;

}
