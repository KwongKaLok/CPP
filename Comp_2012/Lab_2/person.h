#ifndef PERSON_H
#define PERSON_H

#include "event-ticket.h"

class Person
{
public:
    char *name;
    Event *event;
    Ticket *ticket;

    // General constructor.
    Person(const char *name, Event *event, Ticket *ticket);      
    // Copy constructor. Deep copy for name only and shallow copy for event and ticket.
    Person(const Person &other);                                 
    // Delegating constructor
    Person(const Person &other, Event *event, Ticket *ticket);   

    // Destructor
    ~Person();                                                   

    Event* DropEvent();
    Ticket* DropTicket();
};
#endif