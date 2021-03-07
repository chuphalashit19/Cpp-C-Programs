#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Student {
public:
   Student();
   Student(string, int, char);
   ~Student();

   string getName() const;
   int getAge() const;
   char getGrade() const;

   void setName(string);
   void setAge(int);
   void setGrade(char);

private:

   string newName;
   int newAge;
   char newGrade;

};
void fillVector(vector<Student>& infoClass);
void deleteVector(std::vector<Student>& studentInfo);
void printVector(const vector<Student>& studentInfo);

/****************************
* Function: main
* Description: The main control. allow to enter and use as much it wants.
*****************************/
int main()
{
   vector<Student>infoClass;
   int pick;
   //ask student to enter the options
   cout << "Please enter your number to pick your options" << endl;
   cout << "1: Add\t2: View\t 3:Delete 4:Exit" << endl;
   //let students read the options
   cout << "Enter your choice: ";
   cin >> pick;
   while (1)
   {

       switch (pick) {
       case 1:fillVector(infoClass);
           cout << "your information added! " << endl;
           break;
       case 2: printVector(infoClass);
           break;

       case 3: deleteVector(infoClass);
           break;
       case 4: exit(0);
           cin.clear();
       default:cout << "Invalid choice." << endl;
       }

       //again read the user choice until user presses exit button
       cout << endl << "1: Add\t2: View\t3:Delete 4:Exit" << endl;
       cout << "Enter your choice:";
       cin >> pick;
       cout << endl;
   }

   return 0;
}




/****************************
* Function: fillVector
* Description: let the function to read the values and add the vector
*****************************/
void fillVector(vector<Student>& infoClass) {
   string name;
   int age;
   char grade;
   cout << endl << "Enter your name: ";
   cin.ignore();
   getline(cin,name);
   cout << "Enter your age: ";
   cin >> age;
   cout << "Enter your Grade: ";
   cin >> grade;

   Student infoStudent(name, age, grade);
   infoClass.push_back(infoStudent);
   cout << endl;
}
/****************************
* Function: deleteVector
* Description: let the function to delete the objects
*****************************/
void deleteVector(std::vector<Student>& studentInfo)
{
   if (studentInfo.size() == 0 ) {
       cout << "Unable to delete please enter your information first" << endl;
       cin.clear();
   }
   else {
       string name;
       cout << "Please enter a valid name on your info to remove: ";
       cin.ignore();
       getline(cin, name);
       int error = 0;
       string deleteName;
       vector<int>::iterator it; int i = 0;

       for (i = 0; i < studentInfo.size(); i++) {
           deleteName = studentInfo[i].getName();

           if (deleteName == name)
           {
               error = 1;
               break;
           }
       }
       if (error == 0)
           cout << endl << "Unable to find your name in the system" << endl;
       else
       {
           studentInfo.erase(studentInfo.begin() + i);
           cout << endl << "your infomation is deleted." << endl;
       }
   }
}
/****************************
* Function: printVector
* Description: let the function read
*****************************/
void printVector(const vector<Student>& studentInfo) {
   if (studentInfo.size() == 0) {
       cout << "should not be blank please enter again" << endl;
       cin.clear();
   }
   else {
       cout << "Student Name \ Student age\ Student Grade" << endl;

       for (int i = 0; i < studentInfo.size();i++) {
           cout << studentInfo[i].getName() << "\t\t" <<
               studentInfo[i].getAge() << "\t\t" <<
               studentInfo[i].getGrade() << endl;
       }
   }
}

Student::Student() {
   newName = "";
   newAge = 0;
   newGrade = ' ';

}
Student::Student(string name, int age, char grade) {
   newName = name;
   newAge = age;
   newGrade =grade;
}
Student::~Student() {
}
   string Student::getName() const {
       return newName;
   }

   int Student::getAge() const {
       return newAge;
   }

   char Student::getGrade() const {
       return newGrade;
   }

   void Student::setName(string name) {
       newName = name;
   }

   void Student::setAge(int age) {
       newAge = age;
   }

   void Student::setGrade(char grade) {
       newGrade = grade;
   }
