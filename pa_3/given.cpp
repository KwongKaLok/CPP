//do NOT modify this file

#include "pa3.h"
#include <iostream>
using namespace std;

void printTrain(const TrainCar* head) 
{
    const char enumToStringMapping[6][8] = {"HEAD", "OIL", "COAL", "WOOD", "STEEL", "SUGAR"};

    if(head == nullptr)
    {
        cout << "No train! :(" << endl;
        return;
    }

    while(true)
    {
        cout << "[";
        cout << enumToStringMapping[head->type];
        if(head->type!=HEAD)
            cout << ":" << head->load << "/" << head->maxLoad;
        cout << "]";
        if(head->next)
            cout << " -> ";
        else
            break;
        head = head->next;
    } 
    cout << endl;

    //head now actually points to the last/tail node after the previous loop
    cout << "In reverse: ";
    while(head) 
    {
        cout << "[";
        cout << enumToStringMapping[head->type];
        if(head->type!=HEAD)
            cout << ":" << head->load << "/" << head->maxLoad;
        cout << "]";
        if(head->prev)
            cout << " <- ";
        else
            break;
        head = head->prev;
    } 
    cout << endl;
}