#ifndef _TECHNICIAN_H_
#define _TECHNICIAN_H_
#include "Employee.h"
#include <iostream>
using namespace std;

class Technician : public Employee
{
    protected:
        int num_projects;

    public:
        Technician();
        Technician(int id, const string& name, char gender, const Date& entry_date, int num_projects, Department dept);
        ~Technician();

        void calculate_salary();
        void print_description() const;
};
#endif