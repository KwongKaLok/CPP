// max number of people in lab 8
const int MAX_PERSON= 100;

struct Person {
		int id; 
		char name[10];
		int age;
		char job; // 'M' for medical staff, 'S' for service staff
		int priority;
		bool vaccined;
};

// print single user information
void printPerson( Person& p);
// Calculate the unvacinned person in sign up queue
int numUnvaccined( Person queue[], int size);
// Print the sign up queue
void printSignupQueue( Person queue[], int size);
// Init priority queue
void initPriorityQueue(Person* pointerqueue[], int size);
// Print the priority queue
void printPriorityQueue( Person* pointerqueue[], int size);

// Lab 8 tasks in lab8.cpp
void setPriority(Person& p);
void prioritySort( Person queue[], Person* pointerqueue[], int size);
void vaccinateTopPriority( Person queue[], Person* pointerqueue[], int size);
void addPerson(int id, const char name[], char job, int age, Person queue[], Person* pointerqueue[], int& size);
