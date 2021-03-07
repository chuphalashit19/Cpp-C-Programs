#include<bits/stdc++.h>

using namespace std;

int product=1;

int recursiveProduct(int n)
{
    if(n == 2){
        product = product * n;
        n += 1;
        return recursiveProduct(n);
    }
    else if(n == 13 || n == 19 || n == 37){
        product = product * n;
        n += 4;
        return recursiveProduct(n);
    }
    else if(n == 23 || n == 31){
        product = product * n;
        n += 6;
        return recursiveProduct(n);
    }
    else if(n > 2 && n <= 41){
        product = product * n;
        n += 2;
        return recursiveProduct(n);
    }
    else
        return product;
}

int main(void){
    int n = 2;
    cout << endl;
    cout << " The product is: ";
    cout << recursiveProduct(n) << endl << endl;
}
