#include<bits/stdc++.h>

using namespace std;

class Shape{
protected:
    int length;
    int breadth;
    int height;
public:
    Shape(int l=0, int b=0, int h=0){
        length = l;
        breadth = b;
        height = h;
    }
};

class Square:public Shape{
public:
    Square(int l=0):Shape(l){}
    int getArea(){
        int area = length*length;
        cout << "Total Square Area: " << area << endl;
        return area;
    }
};

class Rectangle:public Shape{
public:
    Rectangle(int l=0, int b=0):Shape(l, b){}
    int getArea(){
        int area = length*breadth;
        cout << "Total Rectangle Area: " << area << endl;
        return area;
    }
};

class Triangle:public Shape{
public:
    Triangle(int l=0, int b=0, int h=0):Shape(l, b, h){}
    int getArea(){
        int area = (breadth * height)/2;
        cout << "Total Triangle Area: " << area << endl;
        return area;
    }
};

class Painting{
public:
    int getCost(int area){
        return area*70;
    }
};

int main(){
    Shape *p;
    Painting *s;
    Square A(5);
    Rectangle B(7, 5);
    Triangle C(7, 12, 5);
    p = &A;
    int area = A.getArea();
    cout << "Total paint cost: $" << s->getCost(area) << endl;
    p = &B;
    area = B.getArea();
    cout << "Total paint cost: $" << s->getCost(area) << endl;
    p = &C;
    area = C.getArea();
    cout << "Total paint cost: $" << s->getCost(area) << endl;
    return 0;
}
