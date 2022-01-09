#include <iostream> /* COMP2011 Lab 7: my_include.h */
#include <cstdlib>
using namespace std;

/* Constant definitions */
const int MAX_ARRAY_LENGTH = 100;

/* External function declarations */
void printArray(const double [], int );
void printArray(const char [][MAX_ARRAY_LENGTH + 1], int );

/* Task Three */
// Add the function declarations here:
void bubbleSort(double[],int,bool=true);
void bubbleSort(char[][MAX_ARRAY_LENGTH + 1],int);
void bubbleSort(char[][MAX_ARRAY_LENGTH + 1],int,bool);

