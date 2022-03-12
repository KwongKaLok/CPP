#include <iostream>
#include <string>
#include "school-namespaces.h"

// TODO 1: Finish the definitions of variables and functions in different namespaces
// with the 'using' statement, the '::' operator, and namespace alias.
using namespace std;
namespace eng = engineering;
namespace sc = science;
// TODO 1.1: Complete the definition of events in CSE department.
string eng::cse::events[]{
    "9:00 Making Machine Learning Automated and Trustworthy.",
    "11:00 The Next Frontier in Type Inference.",
    "14:00 AI-Human Teaming for Decision Making."};

// TODO 1.2: Complete the definition of events in ECE department.
string eng::ece::events[]{
    "15:00 2D Materials, from Academia to Industry.",
    "16:00 Bridging Vision and Language for Cross-Modal Understanding and Generation."};

// TODO 1.3: Complete the definition of events in MATH department.
string sc::math::events[]{
    "16:00 Rate of blow up in the thin obstacle problem."};

// TODO 1.4: Complete the definition of events in Physics department.
string sc::physics::events[]{
    "11:00 Interfacial Dynamics between a Hydrogel and a Fluid: Modeling and Simulation.",
    "14:00 Application of Flow Model to Theoretical Physics."};

// Define events in School of Science. (No modification to this part.)
string sc::events[]{
    "10:00 A variational approach to describe the moduli space of minimal immersions in hyperbolic."};

// Define show_events function for CSE department.
void eng::cse::show_events()
{
    cout << "Welcome to Department of CSE!" << endl;
    for (string s : events)
    {
        cout << s << endl;
    }
}

// Define show_events function for ECE department.
void eng::ece::show_events()
{
    cout << "Welcome to Department of ECE!" << endl;
    for (string s : events)
    {
        cout << s << endl;
    }
}

// Define show_events function for School of Engineering.
void eng::show_events()
{
    cout << "Welcome to School of Engineering!" << endl;
    // TODO 2: print events in both CSE and ECE departments (CSE first, ECE second).
    for (string s : cse::events)
    {
        cout << s << endl;
    }
    for (string s : ece::events)
    {
        cout << s << endl;
    }
}

// Define show_events function for MATH department.
void sc::math::show_events()
{
    cout << "Welcome to Department of Mathematics!" << endl;
    for (string s : events)
    {
        cout << s << endl;
    }
}

// Define show_events function for Physics department.
void sc::physics::show_events()
{
    cout << "Welcome to Department of Physics!" << endl;
    for (string s : events)
    {
        cout << s << endl;
    }
}

// Define show_events function for School of Science.
void sc::show_events()
{
    cout << "Welcome to School of Science!" << endl;
    // TODO 3: print events in School of Science, MATH department, and Physics department
    // (School of Science first, MATH department second, Physics department third).
    for (string s : events)
    {
        cout << s << endl;
    }
    for (string s :math::events)
    {
        cout << s << endl;
    }
    for (string s : physics::events)
    {
        cout << s << endl;
    }
}