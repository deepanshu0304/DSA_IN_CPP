#include <iostream>
using namespace std;
class Employee
{

Variable declared in class is called Properties
Function declared in class is called Methods.


public: /* there are three type of access modifier
 public , private , protected

 public --> we can access properties and methods out of class

 private --> we can access properties and methods  only inside the class.

 protected-->  we can access properties and methods in derived classes

 By default in C++ class is private....
  */
    string Name;
    string Company;
    int Age;
    void IntroduceYourself()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};

int main()
{
    Employee employee1;
    employee1.Name = "Deepanshu";
    employee1.Company = "NIT-Calicut";
    employee1.Age = 19;
    employee1.IntroduceYourself();

    cout << endl;

    Employee employee2;
    employee2.Name = "Virat";
    employee2.Company = "Google";
    employee2.Age = 35;
    employee2.IntroduceYourself();
    /*
 

    return 0;
}