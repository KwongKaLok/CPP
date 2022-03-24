#include "TechnicianLeader.h"

// TODO: Implement TechnicianLeader.cpp
TechnicianLeader::TechnicianLeader() {}

TechnicianLeader::TechnicianLeader(int id, const string &name, char gender, const Date &entry_date, int num_projects, Department dept) : Technician(id, name, gender, entry_date, num_projects, dept)
{
    Employee::post = "Technician Leader";
}

TechnicianLeader::~TechnicianLeader()
{
    cout << "Resign: TechnicianLeader " << name << endl;
}

void TechnicianLeader::calculate_salary()
{
    salary = 20000 + 1500 * num_projects;
}

void TechnicianLeader::print_description() const
{
    cout << "ID: " << id << ", "
         << "Name: " << name << ", "
         << "Gender: " << gender << ", "
         << "Entry date: " << entry_date.year << '-' << entry_date.month << '-' << entry_date.day << ", "
         << "Post: " << post << ", "
         << "Group: " << enum_to_str(dept) << ", "
         << "Finished num_projects: " << num_projects << endl;
}