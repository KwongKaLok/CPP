#include "Manager.h"

// TODO: Implement Manager.cpp
Manager::Manager() {}

Manager::Manager(int id, const string &name, char gender, const Date &entry_date, Department dept) : Employee(id, name, gender, entry_date, "Manager", dept)
{
    num_staff = 0;
    staffs = new Employee *[MAX_STAFF_NUM];
    for (int i = 0; i < MAX_STAFF_NUM; i++)
    {
        staffs[i] = nullptr;
    }
};

void Manager::manage(Technician *t)
{

    // cout<<staffs<<endl;
    staffs[num_staff] = t;
    num_staff++;
    cout << t->get_name() << " is managed by " << name << " now!" << endl;
}

void Manager::calculate_salary()
{
    salary = 20000 + 2000 * num_staff;
}

void Manager::print_description() const
{
    cout << "ID: " << id << ", "
         << "Name: " << name << ", "
         << "Gender: " << gender << ", "
         << "Entry date: " << entry_date.year << '-' << entry_date.month << '-' << entry_date.day << ", "
         << "Post: " << post << ", "
         << "Group: " << enum_to_str(dept) << endl;
}

void Manager::print_staff() const
{
    cout << name << " is managing " << num_staff << " staffs: ";
    for (int i = 0; i < num_staff; i++)
        cout << staffs[i]->get_name() << ", ";
    cout << endl;
}

Manager::~Manager()
{
    for (int i = 0; i < num_staff; i++)
    {
        delete staffs[i];
    }

    cout << "Resign: Manager " << name << endl;
}
