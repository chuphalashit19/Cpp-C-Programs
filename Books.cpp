#include <iostream>
#include<string.h>
//user-defined functions question!
using namespace std;

struct Books
{
char title[50];
char author[50];
char subject[100];
int book_id;
};

void block1(struct Books Book1, double array1[5]){
    strcpy( Book1.title, "C++ Programming");
    strcpy( Book1.author, "D.S Malik");
    strcpy( Book1.subject, "C++ basics");
    Book1.book_id = 6495407;
    cout << "////Block #1//////" << endl;
    int x=4;
    for (x; x>=0; x--){
        cout<<array1[x]<<endl;
    }

    cout<<"///////////////////////"<<endl << endl;
    ////end of Block#1//////
}

void block2(struct Books Book1, double array1[5]){
    cout << "////Block #2//////" << endl;
    int sum=0, i=0;

    for (i; i<5; i++){
        cout<<static_cast<int>(array1[i])<<"   ";

        sum= sum+array1[i];
        cout<<sum<<endl;

    }

    cout<< "final value of sum="<<" "<<sum<<endl;
    cout<< "the average value ="<<" " <<sum/5 <<endl;
    cout<<"//////////////////////"<<endl << endl;
//
}

int main()
{
    double array1[5]= {13.768,4.0,88.7689,9.12,};

    struct Books Book1;
    block1(Book1, array1);
    block2(Book1, array1);
    return 0;
}
