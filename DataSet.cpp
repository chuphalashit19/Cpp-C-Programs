#include<iostream>
#include<iomanip>
using namespace std;

const int NO_OF_ROWS = 3;
const int NO_OF_COLS = 4;
typedef float NewType[NO_OF_ROWS][NO_OF_COLS];

NewType val;

void getData();
void displayData(NewType array);
void setCalculate(NewType array);

int main()
{
    getData();  //call getData function and transfer nothing

    system("pause");
    return 0;
}

void getData()
{
    int noOfInput=0;
    cout << "You are required to enter " << NO_OF_ROWS * NO_OF_COLS << " integer numbers." << endl <<endl;

    for(int row_pos = 0; row_pos < NO_OF_ROWS; row_pos++)
    {
        for(int col_pos = 0; col_pos < NO_OF_COLS; col_pos++)
        {
            noOfInput++;
            cout << "Input #" << noOfInput << " : ";
            cin >> val[row_pos][col_pos];
        }
    }

    displayData(val);   //call displayData function and transfer array val
}

void displayData (NewType array)
{
    for(int row_pos = 0; row_pos < NO_OF_ROWS; row_pos++)
    {
        cout << endl << "Data Set " << row_pos+1;
        cout << setw(10);
        for(int col_pos = 0; col_pos < NO_OF_COLS; col_pos++)
            cout << val[row_pos][col_pos] << setw(5);
    }
    cout << endl << endl;
    setCalculate(val);
}

void setCalculate(NewType array)
{
    int sum = 0;
    for(int row_pos = 0; row_pos < NO_OF_ROWS; row_pos++)
    {
        cout << "Sum of Data Set " << row_pos+1;
        cout << setw(5);
        for(int col_pos = 0; col_pos < NO_OF_COLS; col_pos++)
        {
            sum += val[row_pos][col_pos];
        }
        cout << sum << endl;
    }
    cout << endl << endl;
}
