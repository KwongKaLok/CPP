#include "ParkingLot.h"
#include "Vehicle.h"
#include <string>
#include <iostream>
using namespace std;

// TODO: complete declaration of Bus
class Bus : public Vehicle
{
public:
    Bus(const string &plate_no, const int &num_passengers);
    void print() const;
    void leave(ParkingLot *parking_lot);

private:
    int num_passengers;
};