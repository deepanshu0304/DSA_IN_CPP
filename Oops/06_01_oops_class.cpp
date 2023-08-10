#include <iostream>
using namespace std;
class Employee
{
public: /* there are three type of access modifier
 public , private , protected
 public --> u can access element out of class
 private --> u can  not access element out of class
 protected--> somewhere between public and private...means u can access them in derived classes

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
      Q) Suppose u have to create 100 employees then how will u create ?

      Ans - By help of constructor
    */

    return 0;
}