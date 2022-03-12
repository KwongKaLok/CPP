#include <iostream>
#include "school-namespaces.h"

// Note: You are supposed to insert new lines in this file, but not modify/delete existing lines!
// TODO 1: Specify namespaces to be used in this file.
using namespace std;
namespace sc = science;
namespace eng = engineering;

void QueryEvents()
{
    cout << "Select the school: 1. School of Engineering; 2. School of Science:";
    char choice;
    while (cin >> choice)
    {
        if (choice == '1' || choice == '2')
            break;
        else
            cout << "Select from 1 or 2." << endl;
    }

    if (choice == '1')
    {
        cout << "Select the department: 1. Department of CSE; 2. Department of ECE; 3. All Departments:";
        // TODO 2: Call the corresponding print_events function according to input.
        char choice1;
        cin >> choice1;
        switch (choice1)
        {
        case '1':
            eng::cse::show_events();
            break;
        case '2':
            eng::ece::show_events();
            break;
        case '3':
            eng::show_events();
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    }
    else
    {
        cout << "Select the department: 1. Department of Mathematics; 2. Department of Physics; 3. All Departments:";
        // TODO 3: Call the corresponding print_events function according to input.
        char choice2;
        cin >> choice2;
        switch (choice2)
        {
        case '1':
            sc::math::show_events();
            break;
        case '2':
            sc::physics::show_events();
            break;
        case '3':
            sc::show_events();
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    }
}