#include <iostream>
#include <fstream>
#include <cstring>
#include "lab8.h"
using namespace std;

// A helper function to init both queues from file
void initQueues(Person signupqueue[], Person* priorityqueue[], int size, const char filename[]) {
    int id; 
	int age;
	char job; // 'M' for medical staff, 'S' for service staff
	char name[10];
    ifstream fin(filename);
    for (int i = 0; i < size; i++) {
        fin >> id >> name >> job >> age;
        // YOU NEED TO IMPLEMENT addPerson FUNCTION
        addPerson(id, name, job, age, signupqueue, priorityqueue, i);
    }
}

int main()
{
    int queue_length;
    int priority_queue_length;
    Person SignUpQueue[MAX_PERSON];   // array of Peron
    Person* PriorityQueue[MAX_PERSON]; // array of pointers to Person

    int id; // variables for data input
    char name[10];
    char job;	
    int age;

    initPriorityQueue(PriorityQueue, queue_length);

    cout << "================================================" << endl;
    cout << "Quickly init both sign up and priority queues from file "<< endl;
    cout << " Input a number from 1 to 40: " << endl;
    cin >> queue_length;
    priority_queue_length = queue_length;
    initQueues(SignUpQueue, PriorityQueue, queue_length, "sample.txt");
    cout << "================================================" << endl;

    cout << "The queue has been initialized, the priority queue is:" << endl;
    printPriorityQueue(PriorityQueue, priority_queue_length);

    int option;
    cout << "================================================" << endl;
    cout << "Please choose options, 1 for sign up, 2 for vaccine, 3 for print sign up queue, 4 for exit: " << endl;
    cin >> option;
    
    while (option != 4) {
        switch (option) {
        case 1:
            cout << "Please input id, name, job type: M (Medical staff), S (Sevice related), O (Others) and age: " << endl;
            /******* Input id, name, jobtype, and age *******/
            cin >> id >> name >> job >> age;
            addPerson(id, name, job, age, SignUpQueue, PriorityQueue, queue_length);
            queue_length++;
            priority_queue_length++;
            cout << "A new person has signed up, the priority queue is: " << endl;
            printPriorityQueue(PriorityQueue, priority_queue_length);
            break;
        case 2:
            if (priority_queue_length == 0) {
                cout << "No people in vaccine line." << endl;
            }else{
                vaccinateTopPriority(SignUpQueue, PriorityQueue, queue_length);
                priority_queue_length--;
                cout << "A highest priority person has vaccinated, the priority queue is: " << endl;
                printPriorityQueue(PriorityQueue, priority_queue_length);
            }
            break;
        case 3:
            cout << "The sign up queue is: " << endl;
            printSignupQueue(SignUpQueue, queue_length);
            break;
        default:
            cout << "Wrong input, you choice again: " << endl;
        }
        cout << "================================================" << endl;
        cout << "Please input options:1 for sign up, 2 for vaccine, 3 for print queue, 4 for exit: " << endl;
        cin >> option;
    }
}
