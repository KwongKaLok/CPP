#include "ParkingLot.h"
#include "Vehicle.h"
#include <string>
#include <iostream>
using namespace std;

// TODO: complete declaration of PrivateCar
class PrivateCar : public Vehicle
{
public:
    PrivateCar(const string &plate_no, const string &brand);
    void print() const;
    void leave(ParkingLot *parking_lot);

private:
    string brand;
};