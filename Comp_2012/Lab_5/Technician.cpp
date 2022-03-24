#include "Technician.h"

// TODO: Implement Technician.cpp
Technician::Technician() {}

Technician::Technician(int id, const string &name, char gender, const Date &entry_date, int num_projects, Department dept) : Employee(id, name, gender, entry_date, "Technician", dept)
{
    Technician::num_projects = num_projects;
}
Technician::~Technician()
{
    cout << "Resign: Technician " << name << endl;
}

void Technician::calculate_salary()
{
    salary = 10000 + 1000 * num_projects;
}

void Technician::print_description() const
{
    cout << "ID: " << id << ", "
         << "Name: " << name << ", "
         << "Gender: " << gender << ", "
         << "Entry date: " << entry_date.year << '-' << entry_date.month << '-' << entry_date.day << ", "
         << "Post: " << post << ", "
         << "Group: " << enum_to_str(dept) << ", "
         << "Finished num_projects: " << num_projects << endl;
}