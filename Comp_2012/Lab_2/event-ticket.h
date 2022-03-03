#ifndef EVENTTICKET_H
#define EVENTTICKET_H

class Event
{
private:
    int eventID;
public:
    Event(int id);                // Conversion constructor
    Event(const Event &other);    // Copy constructor
    ~Event();                     // Destructor
};

class Ticket
{
private:
    int ticketID;
public:
    Ticket(int id);               // Conversion constructor
    Ticket(const Ticket &other);  // Copy constructor
    ~Ticket();                    // Destructor
};


#endif