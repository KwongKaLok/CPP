#include <string>
#include <iostream>
#include "Vehicle.h"
#include "ParkingLot.h"
using namespace std;

// TODO: complete declaration of Truck
class Truck : public Vehicle
{
public:
    Truck(const string &plate_no, const int &capacity);
    void print() const;
    void leave(ParkingLot *parking_lot);

private:
    int capacity;
};