#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <iostream>
#include "ParkingLot.h"
using namespace std;

class Vehicle
{
    public:
        Vehicle(const string& plate_no);
        void enter(ParkingLot *parking_lot);
        void leave(ParkingLot *parking_lot);
        string get_plate_no() const;
        void print() const;

    protected: 
        bool is_parking;
        double total_fee;
        string plate_no;
};
#endif