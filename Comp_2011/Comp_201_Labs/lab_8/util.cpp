#include <iostream>
#include "lab8.h"
using namespace std;

// Helper functions available to use

// print single user information
void printPerson(Person& p) {
	cout << "ID:" << p.id << '\t'
	<< "Name:" << p.name << '\t'
	<< "Jobtype:" << p.job  << '\t'
	<< "Age:" << p.age << '\t'
	<< "Priority:" << p.priority << '\t';
	cout << boolalpha << " Vaccined: " << p.vaccined << endl;
}

// Print the sign up queue
void printSignupQueue( Person queue[], int size) {
    for (int i = 0; i < size; i++)
		printPerson(queue[i]);
}

// Calculate the unvacinned person in sign up queue
int numUnvaccined( Person queue[], int size)
{
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (queue[i].vaccined == false)
			num++;
	}
	return num;
}

// Init priority queue
void initPriorityQueue(Person* pointerqueue[], int size) {
	for (int i = 0; i < size; i++)
		pointerqueue[i] = 0;
}

// Print the priority queue
void printPriorityQueue(Person* pointerqueue[], int size) {
    for (int i = 0; i < size; i++)
		printPerson(*pointerqueue[i]);
}
