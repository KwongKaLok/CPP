#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

enum Department
{
    Game, 
    FrontEnd, 
    Backend, 
    Operation, 
    HumanResource
};

class Employee
{
    protected:
        int id;
        string name;
        char gender;
        Date entry_date;
        string post;
        Department dept;
        int salary;

    public:
        Employee();
        Employee(int id, const string& name, char gender, const Date& entry_date, string post, Department dept);
        virtual ~Employee();

        string get_name() const { return name; };
        void print_salary() const;

        virtual void calculate_salary() = 0;
        virtual void print_description() const = 0 ;
};

string enum_to_str(Department department);

#endif