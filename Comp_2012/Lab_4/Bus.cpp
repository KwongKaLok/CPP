#include "Bus.h"

// TODO: complete the constructor and all member functions of Bus
Bus::Bus(const string &plate_no, const int &num_passengers) : Vehicle(plate_no), num_passengers(num_passengers) {}
void Bus::leave(ParkingLot *parking_lot)
{
    if (is_parking == false)
    {
        cout << get_plate_no() << " is not parking so it cannot leave!" << endl;
    }
    else
    {
        double fee = 0;
        fee = parking_lot->reclaim_space(this, BUS);
        is_parking = false;
        total_fee += fee;
    }
}
void Bus::print() const
{
    cout << "The bus is " << get_plate_no() << " with " << num_passengers << " passengers. "
         << "It has paid totally " << total_fee << "." << endl;
}
