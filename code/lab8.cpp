#include <iostream>
#include <cstring>
#include "lab8.h"
using namespace std;

/* Task 0: calculate and set the priority for one person

    1. Priority associated with different job types
        1. Use M represent Medical staffs, they have highest priority of 3
        2. Use S represent Service workers, they have a priority value of 2
        3. Use O represent Other people, they have a priority value of 1
    2. Priority value with ages
        1. age >= 60 priority is 4
        2. age < 60 and age >= 40 priority is 3
        3. age < 40 and age >= 20 priority is 2
        4. age < 20 priority value is 1
    
    A person's priority = job priority + age priority
    For exmaple, a medical staff with age >=60 has priority 3 + 4 = 7
*/
void setPriority(Person &p)
{

    int job_p;
    int age_p;
    switch (p.job)
    {
    case 'M':
        p.priority = 3;
        break;
    case 'S':
        p.priority = 2;
        break;
    case 'O':
        p.priority = 1;
        break;
    default:
        break;
    }

    if (p.age >= 60)
    {
        p.priority += 4;
    }

    else if (p.age >= 40 && p.age < 60)
    {
        p.priority += 3;
    }
    else if (p.age >= 20 && p.age < 40)
    {
        p.priority += 2;
    }
    else if (p.age < 20)
    {
        p.priority += 1;
    }
}

/*
    Task 1. Sort the sign up queue via pointers and print the priority queue
    1a. Set the priority of everyone in the sign up queue 
    1b. Figure out the vaccine sequence by properly set up the pointer
    1c. Print the priority queue

    queue is the sign up queue, struct array
    pointerqueue is the priority queue, a pointer array pointing to elements of queue
    when do sorting, sign up queue remain unchanged!!! 
    the sorting is done by setup pointer array. 
    For example, pointerqueue[0] now points to the person with highest priority. 
*/
void prioritySort(Person queue[], Person *pointerqueue[], int size)
{
    int highest;
    bool isMax;
    int position;
    for (int i = 0; i < size; i++)
    {
        highest = 0;
        isMax = true;

        for (int j = 0; j < size; j++)
        {
            if (queue[j].priority > highest && !queue[j].vaccined)
            {
                for (int k = 0; k < i; k++)
                {
                    if (pointerqueue[k] == &queue[j])
                    {
                        isMax = false;
                        break;
                    }
                    else
                    {
                        isMax = true;
                    }
                }
                if (isMax)
                {
                    highest = queue[j].priority;
                    position = j;
                }
            }
        }
        if (highest != -1)
        {
            pointerqueue[i] = &queue[position];
        }
        else
        {
            pointerqueue[i] = 0;
        }
    }
    
    
}

/* 
    Task 2. Assume that the the highest priority person is vaccinated 
    Remove him from the priority queue and print the updated priority queue
    Important: 
    DO NOT remove him from the sign up queue
*/
void vaccinateTopPriority(Person queue[], Person *pointerqueue[], int size)
{
    pointerqueue[0]->priority = true;
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
            pointerqueue[i] = pointerqueue[i + 1];
        else
            pointerqueue[i] = 0;
    }
}

/* 
    Task 3. Add a new person to the END of current sign up queue 
            Since the newly-added person can cut in line with his priority,
            most likely you need to update the priority queue 

    This function is used when setup the initial queues from file
*/
void addPerson(int id, const char name[], char job, int age, Person queue[], Person *pointerqueue[], int &size)
{
    for (int i = 0; i < 10; i++)
    {
        queue[size].name[i] = name[i];
    }
    queue[size].id = id;
    queue[size].job = job;
    queue[size].age = age;
    queue[size].vaccined = false;
    pointerqueue[size] = &queue[size];
    setPriority(queue[size]);
}
