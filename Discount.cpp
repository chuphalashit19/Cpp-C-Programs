#include<iostream>

using namespace std;

double discount(double p)
{
    if(p>=500)
        cout << "Your discount is 30%" <<endl;
    else
        cout << "An invalid purchase..." <<endl;
}

int main(){
    double p = 600;

    discount(p);
}
