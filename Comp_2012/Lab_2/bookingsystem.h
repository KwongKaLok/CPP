#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include "event-ticket.h"
#include "person.h"


const int maxNumEvent = 3;   // Maximum number of Event.
const int maxNumTicket = 3;  // Maximum number of Ticket.
const int maxNumPerson = 3;  // Maximum number of Person.

class BookingSystem
{
private:
    Event *events[maxNumEvent];
    Ticket *tickets[maxNumTicket];
    Person *persons[maxNumPerson];
    
    int numEvent;      // Current number of Event.
    int numTicket;     // Current number of Ticket.
    int numPerson;     // Current number of Person.
    int SN;            // Serial number

    int findIndexByName(const char* name); 

public:
    // TODO: General constructor
    BookingSystem(int id, int nEvent, int nTicket); 
    // TODO: Copy constructor
    BookingSystem(const BookingSystem &other);
    // TODO: Delegating constructor
    BookingSystem(int id, int capacity);
    // TODO: Delegating constructor
    BookingSystem(int id, const BookingSystem &other);
    // TODO: Destructor
    ~BookingSystem();

    void releaseEvent(const char* name);
    void releaseTicket(const char* name);
    
    // TODO: accept person's booking by allocating a Person object. 
    // The person would like to reserve an event with a ticket.
    void makeBooking(const char* name); 

    // print the log
    void log() const; 
};

#endif