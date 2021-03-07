#include <iostream>
#include "Triangle.h"

using namespace std;

void TriangleType::angleSum()
{
    total = side_1+side_2+side_3;
    cout << "The total values inputted is: " << total << endl << endl;

    // Acute Triangle
    if (total == 180 && side_1 < 90 && side_2 < 90 && side_3 < 90 && side_1 == side_2 && side_2 != side_3 && side_1 != side_3
        || total == 180 && side_1 < 90 && side_2 < 90 && side_3 < 90 && side_2 == side_3 && side_1 != side_2 && side_1 != side_3
        || total == 180 && side_1 < 90 && side_2 < 90 && side_3 < 90 && side_1 == side_3 && side_1 != side_2 && side_2 != side_3)
    {
        cout << "This is an acute isosceles triangle. " << endl;
    }
    else if (total == 180 && side_1 == side_2 && side_2 == side_3)
    {
        cout << "This is an acute equilateral triangle" << endl;
    }
    else if (total == 180 && side_1 < 90 && side_2 < 90 && side_3 < 90 && side_1 != side_2 && side_1 != side_3 && side_2 != side_3)
    {
        cout << "This is an acute scalene triangle" << endl;
    }

    // Right Triangle
    else if (total == 180 && side_1 == 90 && side_1 == side_2 && side_2 != side_3 && side_1 != side_3 || side_2 == 90 && side_1 == side_2 && side_2 != side_3 && side_1 != side_3 || side_3 == 90 && side_1 == side_2 && side_2 != side_3 && side_1 != side_3
        || total == 180 && side_1 == 90 && side_2 == side_3 && side_1 != side_2 && side_1 != side_3 || side_2 == 90 && side_2 == side_3 && side_1 != side_2 && side_1 != side_3 || side_3 == 90 && side_2 == side_3 && side_1 != side_2 && side_1 != side_3
        || total == 180 && side_1 == 90 && side_1 == side_3 && side_1 != side_2 && side_2 != side_3 || side_2 == 90 && side_1 == side_3 && side_1 != side_2 && side_2 != side_3 || side_3 == 90 && side_1 == side_3 && side_1 != side_2 && side_2 != side_3)
    {
        cout << "This is an right isosceles triangle" << endl;
    }

    else if (total == 180 && side_1 == 90 && side_1 != side_2 && side_1 != side_3 && side_2 != side_3 || side_2 == 90 && side_1 != side_2 && side_1 != side_3 && side_2 != side_3 || side_3 == 90 && side_1 != side_2 && side_1 != side_3 && side_2 != side_3)
    {
        cout << "This is an right scalene triangle." << endl;
    }

    // Obtuse Triangle
    else if (total == 180 && side_1 > 90 && side_1 <= 180 && side_1 == side_2 && side_2 != side_3 && side_1 != side_3 || total == 180 && side_2 > 90 && side_2 <= 180 && side_1 == side_2 && side_2 != side_3 && side_1 != side_3 || total == 180 && side_3 > 90 && side_3 <= 180 && side_1 == side_2 && side_2 != side_3 && side_1 != side_3
        || total == 180 && side_1 > 90 && side_1 <= 180 && side_2 == side_3 && side_1 != side_2 && side_1 != side_3 || total == 180 && side_2 > 90 && side_2 <= 180 && side_2 == side_3 && side_1 != side_2 && side_1 != side_3 || total == 180 && side_3 > 90 && side_3 <= 180 && side_2 == side_3 && side_1 != side_2 && side_1 != side_3
        || total == 180 && side_1 > 90 && side_1 <= 180 && side_1 == side_3 && side_1 != side_2 && side_2 != side_3 || total == 180 && side_2 > 90 && side_2 <= 180 && side_1 == side_3 && side_1 != side_2 && side_2 != side_3 || total == 180 && side_3 > 90 && side_3 <= 180 && side_1 == side_3 && side_1 != side_2 && side_2 != side_3)
    {
        cout << "This is an obtuse isosceles triangle." << endl;
    }
    else if (total == 180 && side_1 > 90 && side_1 <= 180 && side_1 != side_2 && side_2 != side_3 || total == 180 && side_2 > 90 && side_2 <= 180 && side_1 != side_2 && side_2 != side_3 || total == 180 && side_3 > 90 && side_3 <= 180 && side_1 != side_2 && side_2 != side_3)
    {
        cout << "This is an obtuse scalene triangle." << endl;
    }
    // Invalid Triangle
    else
    {
        cout << "The inputted values do not make a valid triangle. Please try again!" << "\n" "\n";
    }
}

int main()
{
    TriangleType ans;

    double side_1; // 1st side of triangle.
    double side_2; // 2nd side of triangle.
    double side_3; // 3rd side of triangle.

    cout << "This program determines the triangle type based on the inputted values, (must add up to 180)." << endl << endl;

    cout << "Enter measure of first side: ";
    cin >> side_1;
    ans.side_1 = side_1;
    cout << "Enter measure of second side: ";
    cin >> side_2;
    ans.side_2 = side_2;
    cout << "Enter measure of third side: ";
    cin >> side_3;
    ans.side_3 = side_3;
    cout << "\n";
    ans.angleSum();

   system("pause");

   return 0;
}
