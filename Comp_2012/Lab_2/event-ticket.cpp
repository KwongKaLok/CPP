#include <iostream>

#include "event-ticket.h"

using namespace std;

// Event
Event::Event(int id): eventID(id)
{
    cout << "Event with ID " << eventID << " Constructed!" << endl; 
}

Event::Event(const Event & other)
{
    eventID = other.eventID;
    cout << "Event with ID " << eventID << " Copied!" << endl;
}

Event::~Event()
{
    cout << "Event with ID " << eventID << " Destructed!" << endl;
}

// Ticket
Ticket::Ticket(int id): ticketID(id)
{
    cout << "Ticket with ID " << ticketID << " Constructed!" << endl; 
}

Ticket::Ticket(const Ticket & other)
{
    ticketID = other.ticketID;
    cout << "Ticket with ID " << ticketID << " Copied!" << endl;
}

Ticket::~Ticket()
{
    cout << "Ticket with ID " << ticketID << " Destructed!" << endl;
}