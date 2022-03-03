#include <iostream>

#include "bookingsystem.h"

using namespace std;

int main()
{
    cout << "\n1. Initialize booking system!" << endl;
    BookingSystem* bookingsystem = new BookingSystem(0,3,3);
    bookingsystem->log();

    cout << "\n2. Two people come and reserve tickets for two events." << endl;
    bookingsystem->makeBooking("John");
    bookingsystem->makeBooking("Emma");
    bookingsystem->log();

    cout << "\n3. One person unregister an event but hold the ticket, and someone else make a booking again." << endl;
    bookingsystem->releaseEvent("Emma");
    bookingsystem->makeBooking("Peter");
    bookingsystem->log();

    cout << "\n4. One person unregister an event and return the ticket." << endl;
    bookingsystem->releaseEvent("Peter");
    bookingsystem->releaseTicket("Peter");
    bookingsystem->log();

    cout << "\n5. It is a good behavior to back up your data." << endl;
    BookingSystem* backupBookingSystem = new BookingSystem(1,*bookingsystem);
    backupBookingSystem->log();
    
    cout << "\n6. End of the registration. Destroy the booking system." << endl;
    delete backupBookingSystem;
    delete bookingsystem;

    cout << "\n7. Find a ticket left. Create a new booking system for one person with one ticket of one event." << endl;
    BookingSystem bookingsystem2(2,1);
    bookingsystem2.log();
    bookingsystem2.makeBooking("Mary");
    bookingsystem2.log();

    cout << "\n8. End of all events. Clear all existing data." << endl;
    return 0;
} // only "bookingsystem2" is destructed once the program runs out of this scope.