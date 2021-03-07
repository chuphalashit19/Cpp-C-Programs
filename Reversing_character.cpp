#include<bits/stdc++.h>
using namespace std;

void myProgram(void);
void reverseOrder(char []);
void OriginalOrder(char []);

int main(void)
{
    myProgram();    //calls myProgram and transfers nothing
    system ("pause");
    return 0;
}

void myProgram(void)
{
    char c[10];
    cout << "Enter up to 10 characters. (Enter. to stop the input):" << endl;
    cin >> c;
    cout << "\n\n";
    reverseOrder(c);
    OriginalOrder(c);
}

void reverseOrder(char c[])
{
    int len=0;
    for (int i=0; i<10; i++){
        if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122))
        {
            len++;
        }
    }
    cout << "----- Display in reverse order ------" <<endl;
    for(int i=len-1; i>=0; i--)
    {
        cout << c[i];
    }
    cout << "\n\n\n";
}

void OriginalOrder(char c[])
{
    int len=0;
    for (int i=0; i<10; i++){
        if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122))
        {
            len++;
        }
    }
    cout << "----- Display in original order ------" <<endl;
    for(int i=0; i<len; i++)
    {
        cout << c[i];
    }
    cout << "\n\n\n";
}
