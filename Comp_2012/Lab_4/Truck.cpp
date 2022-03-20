#include "Truck.h"

// TODO: complete the constructor and all member functions of Truck
Truck::Truck(const string &plate_no, const int &capacity) : Vehicle(plate_no), capacity(capacity) {}
void Truck::leave(ParkingLot *parking_lot)
{
    if (is_parking == false)
    {
        cout << get_plate_no() << " is not parking so it cannot leave!" << endl;
    }
    else
    {
        double fee = 0;
        fee = parking_lot->reclaim_space(this, TRUCK);
        is_parking = false;
        total_fee += fee;
    }
}
void Truck::print() const
{
    cout << "The truck is " << get_plate_no() << " with the capacity of " << capacity << ". "
         << "It has paid totally " << total_fee << "." << endl;
}
