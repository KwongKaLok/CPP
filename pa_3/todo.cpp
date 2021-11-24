//modify and submit this file only
#include "pa3.h"
#include <iostream>
using namespace std;
//you are NOT allowed to include any additional library; see FAQ

int countLength(TrainCar *head)
{
    int count = 0;            // Initialize count
    TrainCar *current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int findCarPosition(TrainCar *head, TrainCar *position)
{
    int count = 0;            // Initialize count
    TrainCar *current = head; // Initialize current
    while (current != position)
    {
        count++;
        current = current->next;
    }
    return count;
}
TrainCar *createTrainHead()
{
    TrainCar *head = new TrainCar;
    head->type = HEAD;
    head->load = 0;
    head->maxLoad = 0;
    head->prev = head->next = nullptr;
    return head;
}

bool addCar(TrainCar *head, int position, CarType type, int maxLoad)
{
    int length_of_the_train = countLength(head);
    if (length_of_the_train < position || position <= 0 || maxLoad <= 0 || type == HEAD)
    {
        return false;
    }
    else
    {
        TrainCar *current;
        current = head;
        TrainCar *newCar = new TrainCar;
        for (int i = 1; i < position; i++)
        {
            current = current->next;
        }
        newCar->load = 0;
        newCar->maxLoad = maxLoad;
        newCar->type = type;
        newCar->next = current->next;
        current->next = newCar;
        newCar->prev = current;
        if (newCar->next != nullptr)
        {
            newCar->next->prev = newCar;
        }
        return true;
    }
}

bool deleteCar(TrainCar *head, int position)
{
    int length_of_the_train = countLength(head);
    if (position >= length_of_the_train || position < 1)
    {
        return false;
    }
    else
    {
        TrainCar *current;
        current = head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        current->prev->next = current->next;
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }

        delete current;
        return true;
    }
}

bool swapCar(TrainCar *head, int a, int b)
{
    int length_of_the_train = countLength(head);
    TrainCar *a_car;
    a_car = head;
    TrainCar *b_car;
    b_car = head;

    if (a >= length_of_the_train || b >= length_of_the_train || a < 1 || b < 1)
    {
        return false;
    }
    else
    {
        if (a == b)
        {
            return true;
        }

        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        for (int i = 0; i < a; i++)
        {
            a_car = a_car->next;
        }
        for (int i = 0; i < b; i++)
        {
            b_car = b_car->next;
        }

        if (a_car->next != b_car)
        {
            a_car->prev->next = b_car;
            b_car->prev->next = a_car;
            a_car->next->prev = b_car;
            if (b_car->next != nullptr)
            {
                b_car->next->prev = a_car;
            }
            TrainCar *temp;
            temp = a_car->prev;
            a_car->prev = b_car->prev;
            b_car->prev = temp;
            temp = a_car->next;
            a_car->next = b_car->next;
            b_car->next = temp;
            return true;
        }
        else
        {
            a_car->prev->next = b_car;
            if (b_car->next != nullptr)
            {
                b_car->next->prev = a_car;
            }
            TrainCar *temp;
            temp = a_car->prev;
            a_car->prev = b_car;
            b_car->prev = temp;
            temp = b_car->next;
            b_car->next = a_car;
            a_car->next = temp;
            return true;
        }

        return true;
    }
}

void sortTrain(TrainCar *head, bool ascending)
{
    // int swapped;
    // TrainCar *left_ptr;
    // TrainCar *right_ptr = nullptr;

    // do
    // {
    //     swapped = 0;
    //     left_ptr = head;
    //     while (left_ptr->next != right_ptr)
    //     {

    //         if (left_ptr->load > left_ptr->next->load)
    //         {
    //             int left_ptr_position = findCarPosition(head, left_ptr);
    //             int right_ptr_position = findCarPosition(head, left_ptr->next);

    //             swapCar(head, left_ptr_position, right_ptr_position);
    //             printTrain(head);
    //             swapped = 1;
    //         }
    //         left_ptr = left_ptr->next;
    //     }
    //     right_ptr = left_ptr;
    // } while (swapped);
}

bool load(TrainCar *head, CarType type, int amount)
{
    int total_load = 0;
    TrainCar *current;
    current = head;
    do
    {
        current = current->next;
        if (current->type == type)
        {
            total_load = total_load + (current->maxLoad - current->load);
        }

    } while (current->next != nullptr);

    if (total_load < amount)
    {
        return false;
    }
    else
    {
        current = head;
        do
        {
            current = current->next;
            if (current->type == type)
            {
                if ((current->maxLoad - current->load) < amount)
                {
                    amount -= current->maxLoad - current->load;
                    current->load = current->maxLoad;
                }
                else
                {
                    current->load += amount;
                    return true;
                }
            }

        } while (current->next != nullptr);

        return false;
    }
}
bool unload(TrainCar *head, CarType type, int amount)
{
    int total_unload = 0;
    TrainCar *current;
    current = head;
    do
    {
        current = current->next;
        if (current->type == type)
        {
            total_unload += current->load;
        }

    } while (current->next != nullptr);

    if (total_unload < amount)
    {
        return false;
    }
    else
    {
        current = head;
        do //move the current to the tail
        {
            current = current->next;
        } while (current->next != nullptr);


        while (current->prev != nullptr)
        {
             if (current->type == type)
            {
                if (current->load < amount)
                {
                    amount -= current->load;
                    current->load = 0;
                }
                else
                {
                    current->load -= amount;
                    return true;
                }
            }
            current=current->prev;
        }
        
        return false;
    }
}

void printCargoStats(const TrainCar *head)
{
    TrainCar*print_out[5];
    TrainCar*current;
    for (int i = 0; i < 5; i++)
    {
        print_out[i]=nullptr;
    }
    current=head->next;
   while (current!=nullptr)
   {
       
       current=current->next;
   }
   
    

    
}

void divide(const TrainCar *head, TrainCar *results[CARGO_TYPE_COUNT])
{
}

TrainCar *optimizeForMaximumPossibleCargos(const TrainCar *head, int upperBound)
{
}

void deallocateTrain(TrainCar *head)
{

    if (head == nullptr)
        return;
    deallocateTrain(head->next);
    delete head;
    head = nullptr;
}
