#include "Employee.h"
#include "Technician.h"
#include <iostream>
using namespace std;

const int  MAX_STAFF_NUM = 5;

class Manager : public Employee
{
    private:
        int num_staff;
        Employee** staffs;

    public:
        Manager();
        Manager(int id, const string& name, char gender, const Date& entry_date, Department dept);
        ~Manager();

        void manage(Technician *t);
        void calculate_salary();

        void print_description() const;
        void print_staff() const;
};