#include "Vehicle.h"

Vehicle::Vehicle(const string &plate_no) : plate_no(plate_no)
{
    is_parking = false;
    total_fee = 0;
}

void Vehicle::enter(ParkingLot *parking_lot)
{
    if (is_parking == true)
    {
        cout << get_plate_no() << " has been parking so it cannot leave!" << endl;
        return;
    }
    this->is_parking = true;
    parking_lot->assign_space(this);
}

void Vehicle::leave(ParkingLot *parking_lot)
{
    if (is_parking == false)
    {
        cout << "This car is not parking!" << endl;
    }
    double fee = 0;
    fee = parking_lot->reclaim_space(this, DEFAULT);
    is_parking = false;
    total_fee += fee;
}

string Vehicle::get_plate_no() const
{
    return plate_no;
}

void Vehicle::print() const
{
    cout << "The vehicle is " << get_plate_no() << ". It has paid totally " << total_fee << "." << endl;
}