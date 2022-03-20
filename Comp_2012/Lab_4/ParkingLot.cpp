#include "ParkingLot.h"
#include "Vehicle.h"

ParkingLot::ParkingLot(const int& size):size(size)
{
    spaces = new Vehicle*[size];
    for (int i = 0; i < size; i++)
    {
        spaces[i] = nullptr;
    }
    income = 0;
    fee_rate = 2.4;
    num_vehicle = 0;
}

ParkingLot::~ParkingLot()
{
    delete[] spaces;
}

void ParkingLot::print() const
{
    if (num_vehicle == 0)
    {
        cout << "Currently " << num_vehicle << " vehicles in this parking lot, the total income is " << income << "." << endl;
    }
    else
    {
        cout << "Currently " << num_vehicle << " vehicles in this parking lot: " ;
        for (int i = 0; i < size; i++)
        {
            if (spaces[i] != nullptr)
            {
                cout << spaces[i] -> get_plate_no() << ", ";
            }
        }
        
        cout << "the total income is " << income << "." << endl;
    }
}


bool ParkingLot::assign_space(Vehicle *pv)
{    
    for (int i = 0; i < size; i++)
    {
        if (spaces[i] == nullptr)
        {
            spaces[i] = pv;
            num_vehicle ++;
            cout << pv->get_plate_no() << " enter the parking lot and get a parking spot." << endl;
            return true;
        }
    }
    cout << "Failed to assign space for " << pv->get_plate_no() << "." << endl;
    return false;
}

//TODO: complete reclaim_space()
double ParkingLot::reclaim_space(Vehicle *pv, VehicleTypes type)
{}

