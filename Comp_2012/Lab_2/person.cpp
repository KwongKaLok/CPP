#include <iostream>

#include "person.h"
#include <cstring>

using namespace std;

Person::Person(const char *name, Event *event, Ticket *ticket)
        : event(event), ticket(ticket)
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    // Finish constructing with printing.
    cout << "Record of " << name << " Constructed!" << endl;
}

Person::Person(const Person &other)
{
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    
    // Finish constructing with printing.
    cout << "Record of " << name << " Copied!" << endl;
}

Person::Person(const Person &other, Event *event, Ticket *ticket): Person::Person(other)
{
    this->event = event;
    this->ticket = ticket;
    // Finish constructing with printing.
    cout << "Record of " << name << " with event and ticket Copied!" << endl;
}

Person::~Person()
{
    if (event) delete event;
    if (ticket) delete ticket;
    cout << "Record of " << name << " Destructed." << endl;
    delete [] name;
}

Event* Person::DropEvent()
{   
    Event* tobeDropped = event;
    event = nullptr;

    cout << name << " dropped an event." << endl;
    return tobeDropped;
}
 
Ticket* Person::DropTicket()
{   
    Ticket* tobeDropped = ticket;
    ticket = nullptr;

    cout << name << " dropped a ticket." << endl;
    return tobeDropped;
}