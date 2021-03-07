#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

void distance_between_points(float x0, float x1, float y0, float y1, float z0, float z1)
{
    float diff;

    diff = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2) + pow(z1 - z0, 2) * 1.0);
    cout << setprecision(6) << diff;
    return;
}

int main(){
    float x0, x1, x2, y0, y1, y2, z0, z1, z2;

    cin >> x0 >> y0 >> z0;
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

    x1 = min(x1, x2);
    y1 = min(y1, y2);
    z1 = min(z1, z2);

    distance_between_points(x0, x1, y0, y1, z0, z1);
    return 0;
}
