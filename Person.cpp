#include<bits/stdc++.h>
using namespace std;

class Person { 
	string name;
	public:
		
		virtual void getData() = 0;
		virtual bool isOutstanding() = 0;
		void getName(){	cout<<"Enter Name :";cin>>name;}
		void putName(){ cout<<"Name is "<<name<<endl;	}
};

class Student: public Person {
	public :
	float gpa;	
	void getData(){		cout<<"Enter GPA : ";scanf("%f",&gpa);return;	}
	bool isOutstanding(){	return (gpa>3.5); }
};

class Professor: public Person {
	public:
		int publishes;
		void getData(){	cout<<"Enter Publications :";scanf("%d",&publishes); }
		bool isOutstanding(){	return (publishes>100); 	}
};

int main(){
	int choice=0;
	Student *s = new Student;
	Professor *p = new Professor;
	int sidx = 0;
	int pidx = 0;
	while(choice!=3){
		cout<<"1. Add Student\n2. Add Professor\n3. Quit\nEnter Choice : ";
		cin>>choice;
		switch(choice){
			case 1: {   s->getName();
						s->putName();
						s->getData();
						s->isOutstanding()?cout<<"True\n\n":cout<<"False\n\n";
						sidx++;
						break;
					}
			case 2:	{	p->getName();
						p->putName();
						p->getData();
						p->isOutstanding()?cout<<"True\n\n":cout<<"False\n\n";
						pidx++;
						break;
				}
			default:	cout<<"BYE"<<endl;
		}
	}
}
