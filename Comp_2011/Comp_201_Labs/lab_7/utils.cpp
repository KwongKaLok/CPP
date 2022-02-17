#include <iostream> /* COMP2011 Lab 7: utils.cpp */
#include <cstring>
#include "my_include.h"

/* Task One */
void bubbleSort(double arr[], int n, bool ascending)
{

   if (ascending)
   {
      for (int i = 0; i < (n - 1); ++i)
      {
         int swapped = 0;

         for (int i = 0; i < (n - 1); ++i)
         {
            if (arr[i] > arr[i + 1])
            {
               double temp = arr[i];
               arr[i] = arr[i + 1];
               arr[i + 1] = temp;
               swapped = 1;
            }
         }
         if (swapped == 0)
            break;
      }
   }
   else
   {
      for (int i = 0; i < (n - 1); ++i)
      {
         int swapped = 0;

         for (int i = 0; i < (n - 1); ++i)
         {
            if (arr[i] < arr[i + 1])
            {
               double temp = arr[i];
               arr[i] = arr[i + 1];
               arr[i + 1] = temp;
               swapped = 1;
            }
         }
         if (swapped == 0)
            break;
      }
   }
}

/* Task Two */
void bubbleSort(char arr[][MAX_ARRAY_LENGTH + 1], int n)
{
   char temp[MAX_ARRAY_LENGTH + 1];

   for (int i = 0; i < n; i++)
   {
      for (int j = 1; j < n; j++)
      {
         if (strcmp(arr[j - 1], arr[j]) > 0)
         {
            strcpy(temp, arr[j - 1]);
            strcpy(arr[j - 1], arr[j]);
            strcpy(arr[j], temp);
         }
      }
   }
}
void bubbleSort(char arr[][MAX_ARRAY_LENGTH + 1], int n, bool ascending)
{
   char temp[MAX_ARRAY_LENGTH + 1];
   if (ascending == false)
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 1; j < n; j++)
         {
            if (strcmp(arr[j - 1], arr[j]) < 0)
            {
               strcpy(temp, arr[j - 1]);
               strcpy(arr[j - 1], arr[j]);
               strcpy(arr[j], temp);
            }
         }
      }
   }
}
/* Given Functions */
void printArray(const double arr[], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
   cout << endl;
}

void printArray(const char arr[][MAX_ARRAY_LENGTH + 1], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << endl;
   cout << endl;
}
