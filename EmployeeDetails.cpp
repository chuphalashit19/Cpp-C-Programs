#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<fstream>

using namespace std;
string employeefile   = "Employee.txt";
class employee
{
	string fname;
	string lname;
    int empid;
	string address;
    string phone;
    string dept;
    string officeno;
	public:
	void get()
	{
    	cout<<"\n Enter Employee first name : ";
    	cin.ignore();
    	getline(cin, fname);
    	cout<<"\n Enter Employee last name : ";
    	getline(cin, lname);
		cout<<"\n Enter Employee ID : ";
		cin>>empid;
   		cout<<"\n Enter Address :  ";
   		cin.ignore();
		getline(cin, address);
    	cout<<"\n Enter Department Name:(ACCT/MKT/IS/SALES)  :  ";
		getline(cin, dept);
    	cout<<"\n Enter Office no (ex:- R234, R244):  ";
		getline(cin, officeno);
	}
	void display()
    {
        cout<<"\n"<<fname<<"\t"<<lname<<"\t"<<empid<<"\t"<<address<<"\t"<<dept<<"\t"<<officeno;
	}
};
int main()
{
    int i, n;
    cout<<"\n Enter No. of Records You Want? : ";
    cin>>n;
	employee e[n];           //Statement 3 : Creating Array of 3 Employees
	
    for(i=0;i<n;i++)
    {
    	cout<<"\nEnter details of "<<i+1<<" Employee";
        e[i].get();
    }
    cout<<"\nDetails of Employees";
    for(i=0;i<3;i++)
    	e[i].display();
    
    ofstream myfile ("example.txt");
  	if (myfile.is_open())
  	{
    	for(i=0;i<n;i++)
        	myfile << "Ashit" ;
    	myfile.close();
	}
	myfile.close();
}
