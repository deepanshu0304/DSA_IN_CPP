#include <iostream>
using namespace std;
class Employee
{

private:
    string Name;
    string Company;
    int Age;
public:
    void IntroduceYourself()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    /* 
     Below we created constructor which is  like function but it does not have any return value  and
     it's name should be same as of Class. It should also be public..
    */
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employee1 = Employee("Deepanshu", "NIT-Calicut", 19);
    employee1.IntroduceYourself();
    cout << endl;
    Employee employee2 = Employee("Virat", "Google", 35);
    employee2.IntroduceYourself();

    Employee employee3 = Employee("Elon", "SpaceX", 52);
    employee3.IntroduceYourself();
}