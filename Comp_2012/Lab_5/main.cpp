#include "Employee.h"
#include "Manager.h"
#include "TechnicianLeader.h"
#include "Technician.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    Manager *pm1 = new Manager(101, "Bruce Wayne", 'M', Date{2016, 05, 10}, HumanResource);
    Employee *pe1 = pm1;
    pe1->print_description();

    Technician *pt1 = new Technician(102, "Peter Parker", 'F', Date{2020, 06, 10}, 4, Game);
    Employee *pe2 = pt1;
    pe2->print_description();
    pm1->manage(pt1);
    
    TechnicianLeader *ptl1 = new TechnicianLeader(103, "Tony Stark", 'M', Date{2018, 07, 10}, 2, FrontEnd);
    Employee *pe3 = ptl1;
    pe3->print_description();
    pm1->manage(ptl1);

    Technician *pt2 = new Technician(104, "Steve Rogers", 'F', Date{2021, 11, 11}, 1, Backend);
    Employee *pe4 = pt2;
    pe4->print_description();
    pm1->manage(pt2);

    Technician *ptl2 = new TechnicianLeader(105, "Bruce Banner", 'M', Date{2019, 12, 03}, 3, Operation);
    Employee *pe5 = ptl2;
    pe5->print_description();
    pm1->manage(ptl2);

    pm1->print_staff();
    
    pe1->calculate_salary();
    pe1->print_salary();

    pe2->calculate_salary();
    pe2->print_salary();

    pe3->calculate_salary();
    pe3->print_salary();

    pe4->calculate_salary();
    pe4->print_salary();

    pe5->calculate_salary();
    pe5->print_salary();

    delete pe1;
    return 0;
}