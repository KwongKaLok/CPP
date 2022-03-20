#ifndef _PARKINGLOT_H_
#define _PARKINGLOT_H_
#include <string>
using namespace std;

enum VehicleTypes {DEFAULT, PRIVATE_CAR, BUS, TRUCK};

class Vehicle;
class ParkingLot
{
    public:
        ParkingLot(const int& size);
        ~ParkingLot();
        bool assign_space(Vehicle *pv);
        double reclaim_space(Vehicle *pv, VehicleTypes type);
        void print() const;
    
    private:
        Vehicle **spaces;
        double income;
        int size;
        float fee_rate;
        int num_vehicle;
};
#endif