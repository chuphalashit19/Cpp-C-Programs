#include<bits/stdc++.h>

using namespace std;

int pow(int*, int*);
int square(int *);
int cube(int *);

int main()
{
    cout << "The MatheMagic App" << endl;

    while(1)
    {
        string choice;
        cout << "------Command Menu------" << endl;
        cout << "square: peforming square of a number" << endl;
        cout << "cube: performing cube of a number" << endl;
        cout << "pow: raise a number to an integer power" << endl;
        cout << "quit: quit the program" << endl << endl;

        cout << "Command: ";
        cin >> choice;

        int num;
        int res = 0;

        if(choice == "square")
        {
            cout << "Enter a number to square: ";
            cin >> num;
            res = square(&num);
            cout << "Result: " << res << endl;
        }
        else if(choice == "cube")
        {
            cout << "Enter a number to cube: ";
            cin >> num;
            res = cube(&num);
            cout << "Result: " << res << endl;
        }

        else if(choice == "pow")
        {
            int base, exp;
            cout << "Enter the base: ";
            cin >> num;
            cout << "Enter the integer exponent: ";
            cin >> exp;
            res = pow(&num, &exp);
            cout << "Result: " << res << endl;
        }

        else if(choice == "quit")
        {
            cout << "Bye!" << endl;
            return 0;
        }
        else
        {
            cout << "Wrong choice!! Please enter choice again" << endl;
        }
        cout << endl;
    }

}

int pow(int *num, int *base)
{

    int pow = 1;
    for(int i=0; i<*base; i++)
    {
        pow = (pow * *num);
    }
    return pow;
}

int square(int *num)
{
    *num = (*num * *num);
    return *num;
}

int cube(int *num)
{
    *num = (*num * *num * *num);
    return *num;
}
