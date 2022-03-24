#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee() {}

Employee::Employee(int id, const string& name, char gender, const Date& entry_date, string post, Department dept)
    : id(id), name(name), gender(gender), entry_date(entry_date), post(post), dept(dept){};

Employee::~Employee()
{
    cout << "Resign: Empolyee " << name << endl;
};

void Employee::print_salary() const
{
    cout << name << " : $" << salary << endl;
}


string enum_to_str(Department department)
{
    switch (department)
    {
    case Game:
        return "Game";
    case FrontEnd:
        return "FrontEnd";
    case Backend:
        return "Backend";
    case Operation:
        return "Operation";
    case HumanResource:
        return "HumanResource";
    default:
        return "??";
    }
};