#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

int sumDigits(long val);
long sumUp(long value);
double average2(double num1, double num2);
char up(char letter);

void printHeader(){
    cout << "This assignment uses and has us write-several functions!!!" << endl;
}

int main()
{
    double num1, num2, absnum1, average;
    long inlong, sumd, sumup;
    char letter;

    printHeader();          // #2

    cout << "Enter a number (double): " << fixed << setprecision(4) ;
    cin >> num1;
    absnum1 = abs(num1);             // add function call #1
    cout << "Absolute value: " << absnum1 << endl << endl;

    cout << "Enter a long number: ";
    cin >> inlong;
    sumd = sumDigits(inlong);                // add function call #3
    cout << "Digit sum: " << sumd << endl << endl;

    sumup = sumUp(inlong);               // add function call #4
    cout << "Sum up: " << sumup << endl << endl;

    cout << "Enter 2 numbers(doubles): ";
    cin>> num1 >> num2;
    average = average2(num1, num2);             // add function call #5
    cout << "The average value: " << average << endl << endl;

    cout << "Enter a letter(char): ";
    cin >> letter;
    letter = up(letter);              // add function call #6
    cout << "The uppercase: " << letter << endl << endl;

    return 0;
}

int sumDigits(long val)
{
    int rem, sum = 0;
    while(val != 0){
        rem = val%10;
        sum += rem;
        val = val/10;
    }
    return sum;
}

long sumUp(long value)
{
    long sum = 0;
    if(value > 111111){
        cout << "Too big!" << endl;
        return 0;
    }
    for(int i=1; i<=value; i++)
    {
        sum += i;
    }
    return sum;
}

double average2(double num1, double num2)
{
    double avg;
    avg = (num1+num2)/2;
    return avg;
}

char up(char letter)
{
    if(letter>='a' && letter<='z'){
        letter = letter-32;
        return letter;
    }

    return letter;
}
