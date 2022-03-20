#include "PrivateCar.h"

// TODO: complete the constructor and all member functions of PrivateCar
PrivateCar::PrivateCar(const string &plate_no, const string &brand) : Vehicle(plate_no), brand(brand) {}
void PrivateCar::leave(ParkingLot *parking_lot)
{
    if (is_parking == false)
    {
        cout << get_plate_no() << " is not parking so it cannot leave!" << endl;
    }
    else
    {
        double fee = 0;
        fee = parking_lot->reclaim_space(this, PRIVATE_CAR);
        is_parking = false;
        total_fee += fee;
    }
}
void PrivateCar::print() const
{
    cout << "The private car is " << get_plate_no() << " with the brand of " << brand << ". "
         << "It has paid totally " << total_fee << "." << endl;
}
