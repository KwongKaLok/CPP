#include <iostream> /* COMP2011 Lab 7: main.cpp */
#include "my_include.h"
using namespace std;

int main()
{
   int reply;
   int array_size;

   do {
      cout << "===========================================" << endl;
      cout << "Choose which array to operate on:" << endl;
      cout << "1: Floating Point Array " << endl;
      cout << "2: Cstring Array " << endl;
      cout << "3: Quit" << endl;
      cin >> reply;
      if (cin.fail())
         return 0;

      switch(reply) {
      case 1:{
         cout<<"Task 1: sort a floating point number array" << endl;
         cout << "Input the array size less than " << MAX_ARRAY_LENGTH << endl;
         cin >> array_size;
         if (cin.fail()){
            cout << "The input is invalid. Please make sure you enter a number between 1 and "<< MAX_ARRAY_LENGTH << endl;
            return 0;
         } 
         cout << "Input the array content " << endl;
           
         double arr2[MAX_ARRAY_LENGTH];
         for (int i = 0; i < array_size; i++) {
            cin >> arr2[i];
         }

         cout << "===========================================" << endl;
         bubbleSort(arr2, array_size);  
         cout<<"Sorted Ascending: \n";
         printArray(arr2, array_size);
         cout << "===========================================" << endl;
         bubbleSort(arr2, array_size, false);  
         cout<<"Sorted Descending: \n";
         printArray(arr2, array_size);
         break;
      }     
      case 2:{
         cout<<"Task 2: sort a cstring array" << endl;
         cout << "Input the array size less than " << MAX_ARRAY_LENGTH << endl;
         cin >> array_size;
         if (cin.fail()){
            cout << "The input is invalid. Please make sure you enter a number between 1 and "<< MAX_ARRAY_LENGTH << endl;
            return 0;
         } 
         cout << "Input the array content " << endl;
         char arr2[MAX_ARRAY_LENGTH+1][MAX_ARRAY_LENGTH+1];
         cin.get();
         for (int i = 0; i < array_size; i++){
            cin.getline(arr2[i], MAX_ARRAY_LENGTH+1, '\n');       
         } 
         cout << "===========================================" << endl;
         bubbleSort(arr2, array_size);  
         cout<<"Sorted Ascending: \n";
         printArray(arr2, array_size);
         cout << "===========================================" << endl;
         bubbleSort(arr2, array_size, false);  
         cout<<"Sorted Descending: \n";
         printArray(arr2, array_size);
         break;
      }       
      default:
         break;
      }
   } while (reply != 3);

   return 0;
}


