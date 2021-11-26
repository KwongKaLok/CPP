//modify and submit this file only
#include "pa3.h"
#include <iostream>
using namespace std;
//you are NOT allowed to include any additional library; see FAQ

int findlastone(int arr[], int one, int length)
{
    int position = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == one)
            position++;
    }
    return position;
}
int countLength(TrainCar *head)
{
    int count = 0;            
    TrainCar *current = head; 
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int findCarPosition(TrainCar *head, TrainCar *position)
{
    int count = 0;            
    TrainCar *current = head; 
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
    int swapped;
    TrainCar *left_ptr;
    TrainCar *right_ptr = nullptr;
    int length = countLength(head) - 1;

    do
    {
        swapped = 0;
        left_ptr = head->next;
        while (left_ptr->next != right_ptr)
        {
            if (ascending)
            {
                if (left_ptr->load > left_ptr->next->load)
                {
                    int left_ptr_position = findCarPosition(head, left_ptr);
                    int right_ptr_position = findCarPosition(head, left_ptr->next);
                    swapCar(head, left_ptr_position, right_ptr_position);
                    left_ptr = left_ptr->prev;
                    swapped = 1;
                }
                left_ptr = left_ptr->next;
            }
            else
            {
                if (left_ptr->load < left_ptr->next->load)
                {
                    int left_ptr_position = findCarPosition(head, left_ptr);
                    int right_ptr_position = findCarPosition(head, left_ptr->next);
                    swapCar(head, left_ptr_position, right_ptr_position);
                    left_ptr = left_ptr->prev;
                    swapped = 1;
                }
                left_ptr = left_ptr->next;
            }
        }
        right_ptr = left_ptr;
    } while (swapped);
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
        do
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
            current = current->prev;
        }

        return false;
    }
}

void printCargoStats(const TrainCar *head)
{
    const char enumToStringMapping[6][8] = {"HEAD", "OIL", "COAL", "WOOD", "STEEL", "SUGAR"};
    TrainCar *type_train[CARGO_TYPE_COUNT];
    TrainCar *checkCar;
    bool repeated = false;
    checkCar = head->next;
    int k = 0;

    for (int i = 0; i < 5; i++)
    {
        type_train[i] = nullptr;
    }

    type_train[0] = head->next;
    checkCar = type_train[0]->next;
    while (checkCar != nullptr)
    {
        k = 0;
        repeated = false;
        while (type_train[k] != nullptr)
        {

            if (type_train[k]->type == checkCar->type)
            {
                type_train[k]->load = type_train[k]->load + checkCar->load;
                type_train[k]->maxLoad = type_train[k]->maxLoad + checkCar->maxLoad;
                repeated = true;
            }
            k++;
        }
        if (!repeated)
        {
            type_train[k] = checkCar;
        }
        checkCar = checkCar->next;
    }

    k = 0;

    while (type_train[k] != nullptr)
    {

        cout << enumToStringMapping[type_train[k]->type] << ":" << type_train[k]->load << "/" << type_train[k]->maxLoad;

        if (type_train[k + 1] != nullptr)
        {
            cout << ",";
        }

        k++;
    }

    cout << endl;
}

void divide(const TrainCar *head, TrainCar *results[CARGO_TYPE_COUNT])
{
    TrainCar *type_train[CARGO_TYPE_COUNT];
    TrainCar *checkCar;
    bool repeated = false;
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        type_train[i] = nullptr;
        results[i] = nullptr;
    }
    checkCar = head->next;
    type_train[0] = checkCar;
    while (checkCar != nullptr)
    {
        k = 0;
        repeated = false;
        while (type_train[k] != nullptr)
        {

            if (type_train[k]->type == checkCar->type)
            {
                repeated = true;
            }
            k++;
        }

        if (!repeated)
        {
            type_train[k] = checkCar;
        }
        checkCar = checkCar->next;
    }
    k = 0;
    while (type_train[k] != nullptr)
    {
        TrainCar *current;
        results[k] = createTrainHead();
        current = results[k];
        checkCar = head->next;
        int j = 1;
        while (checkCar != nullptr)
        {
            if (checkCar->type == type_train[k]->type)
            {
                addCar(results[k], j, checkCar->type, checkCar->maxLoad);
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->load = checkCar->load;
                j++;
            }

            checkCar = checkCar->next;
        }
        k++;
    }
}
TrainCar *optimizeForMaximumPossibleCargos(const TrainCar *head, int upperBound)
{
    int diff = upperBound;
    int position = 0;
    TrainCar *tempCar = head->next;
    while (tempCar != nullptr)
    {
        position += 1;
        tempCar = tempCar->next;
    }
    int car_loading[position];
    int final_car_using[position];
    int used_car_arr[position];
    TrainCar *viewer = head->next;

    for (int k = 0; k < position; k++)
    {
        car_loading[k] = viewer->load;
        viewer = viewer->next;
    }

    for (int i = 0; i < position; i++)
    {
        used_car_arr[i] = 0;
    }

    while (findlastone(used_car_arr, 1, position) != position)

    {

        used_car_arr[0]++;

        for (int j = 0; j < countLength(head->next); j++)
        {
            if (used_car_arr[j] == 2)
            {
                used_car_arr[j] = 0;
                used_car_arr[j + 1]++;
            }
        }

        int total = 0;
        for (int i = 0; i < countLength(head->next); i++)
        {
            if (used_car_arr[i] == 1)
            {
                total += car_loading[i];
            }
        }

        if (abs(total - upperBound) < diff)
        {
            diff = abs(total - upperBound);
            for (int m = 0; m < position; m++)
            {
                final_car_using[m] = used_car_arr[m];
            }
        }
    }

    TrainCar *new_head = createTrainHead();
    TrainCar *current = new_head;
    TrainCar *checkCar = head->next;
    int location = 0;
    int w = 1;
    while (checkCar != nullptr)
    {
        if (final_car_using[location++] == 1)
        {
            addCar(new_head, w, checkCar->type, checkCar->maxLoad);
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->load = checkCar->load;
            w++;
        }
        checkCar = checkCar->next;
    }
    return new_head;
}

void deallocateTrain(TrainCar *head)
{
    if (head == nullptr)
        return;
    deallocateTrain(head->next);
    delete head;
    head = nullptr;
}
