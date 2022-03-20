#include <iostream>
#include <string>
#include "Truck.h"
#include "PrivateCar.h"
#include "Bus.h"
using namespace std;

int main()
{
    ParkingLot *parking_lot = new ParkingLot(2);
    parking_lot->print();

    PrivateCar car("AS134", "M-Benz");
    car.print();

    car.enter(parking_lot);
    parking_lot->print();

    car.enter(parking_lot);
    parking_lot->print();

    car.leave(parking_lot);
    parking_lot->print();
    car.print();

    Truck truck("XY778", 15);
    truck.print();

    Bus bus("QW907", 12);
    bus.print();

    truck.leave(parking_lot);
    truck.enter(parking_lot);
    bus.enter(parking_lot);
    parking_lot->print();

    PrivateCar car2("CY890", "Audi");
    car2.enter(parking_lot);

    bus.leave(parking_lot);
    truck.leave(parking_lot);
    bus.print();
    truck.print();
    parking_lot->print();
    
    return 0;
}