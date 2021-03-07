#include<bits/stdc++.h>

using namespace std;

void Order(int x, int y, int z){
    cout << endl;
    if(x>y && x>z)
        if(y>z)
            cout << " (X=" << x << " " << "Y=" << y << " " << "Z=" << z << ")" << endl;
        else
            cout << " (X=" << x << " " << "Z=" << z << " " << "Y=" << y << ")" << endl;

    else if(y>x && y>z)
        if(x>z)
            cout << " (Y=" << y << " " << "X=" << x << " " << "Z=" << z << ")" << endl;
        else
            cout << " (Y=" << y << " " << "Z=" << z << " " << "X=" << x << ")" << endl;

    else if(z>x && z>y)
        if(x>y)
            cout << " (Z=" << z << " " << "X=" << x << " " << "Y=" << y << ")" << endl;
        else
            cout << " (Z=" << z << " " << "Y=" << y << " " << "X=" << x << ")" << endl;
}

int main(void){
    int X=3, Y=2, Z=5;
    Order(X, Y, Z);
    cout << endl <<endl;
}
