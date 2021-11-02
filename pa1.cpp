/*
 * COMP2011 (Fall 2021) Programming Assignment 1
 *
 * Student name: FILL YOUR NAME HERE
 * Student ID: FILL YOUR STUDENT ID NUMBER HERE
 * Student email: FILL YOUR EMAIL HERE
 *
 */

#include <iostream>
#include <limits>
using namespace std;

// Global Constants
// You cannot modify these global constants
// You cannot use your own global variables
const int MAX_ARR_LEN = 16;
const int MAX_ROTATIONS = 1024;
// End of Global Constants

// Helper Functions
// Declare additional helper functions below when necessary
// int myHelperFunction(int argc, char *argv[])


// // Task 1
// int rotate(int arr[], int arrLen, int k);
// // Task 2
// int swapAndRecord(int arr[], int arrLen, int indexA, int indexB, int rotations[], int &rotationLen);
// // Task 3
// void sortAndRecord(int arr[], int arrLen, int rotations[], int &rotationLen);
// // Task 4
// int transformAndRecord(int src[], int tgt[], int arrLen, int rotations[], int &rotationLen);

// // Please copy and paste your implementation of the tasks under this line.
// // If you have defined your own helper functions please also copy and paste them here.

// // End of your implementation

// int batchRotate(int arr[], int arrLen, int rotations[], int rotationLen)
// {
//     int tmp = 0;
//     if (rotationLen < 0 || rotationLen >= MAX_ROTATIONS)
//     {
//         cout << "Testing Error: rotationLen = ";
//         cout << rotationLen;
//         cout << ", which is not in [0,MAX_ROTATIONS]." << endl;
//         return -1;
//     }
//     for (int j = 0; j < rotationLen; j++)
//     {
//         if (rotations[j] >= arrLen || rotations[j] < 0)
//         {
//             cout << "Testing Error: rotations[";
//             cout << j;
//             cout << "] = ";
//             cout << rotations[j];
//             cout << ", which is not in [0,arrLen]." << endl;
//             return -1;
//         }
//         for (int i = 0; i <= rotations[j] / 2; i++)
//         {
//             tmp = arr[i];
//             arr[i] = arr[rotations[j] - i];
//             arr[rotations[j] - i] = tmp;
//         }
//     }
//     return 0;
// }

// void printArr(int arr[], int arrLen)
// {
//     for (int i = 0; i < arrLen; i++)
//     {
//         cout << arr[i];
//         if (i < arrLen - 1)
//         {
//             cout << ',';
//         }
//     }
//     cout << endl;
// }

// void copyArr(int src[], int tgt[], int arrLen)
// {
//     for (int i = 0; i < arrLen; i++)
//     {
//         tgt[i] = src[i];
//     }
// }

// void testTask1(int arr[], int arrLen, int k)
// {
//     int returnVal;
//     cout << "************************ Task 1 test settings ************************" << endl;
//     cout << "arr=" << endl;
//     printArr(arr, arrLen);
//     cout << "arrLen=" << endl;
//     cout << arrLen << endl;
//     cout << "k=" << endl;
//     cout << k << endl;
//     cout << "********************** Calling Task 1 function ***********************" << endl;
//     returnVal = rotate(arr, arrLen, k);
//     cout << "After function call:" << endl;
//     cout << "return=" << endl;
//     cout << returnVal << endl;
//     if (returnVal > -1)
//     {
//         cout << "arr=" << endl;
//         printArr(arr, arrLen);
//     }
// }

// void testTask2(int arr[], int arrLen, int indexA, int indexB)
// {
//     int arrCopy[MAX_ARR_LEN], rotations[MAX_ROTATIONS], rotationLen = 0, returnVal, testResult;
//     copyArr(arr, arrCopy, arrLen);
//     cout << "************************ Task 2 test settings ************************" << endl;
//     cout << "arr=" << endl;
//     printArr(arr, arrLen);
//     cout << "arrLen=" << endl;
//     cout << arrLen << endl;
//     cout << "indexA=" << endl;
//     cout << indexA << endl;
//     cout << "indexB=" << endl;
//     cout << indexB << endl;
//     cout << "********************** Calling Task 2 function ***********************" << endl;
//     returnVal = swapAndRecord(arr, arrLen, indexA, indexB, rotations, rotationLen);
//     cout << "After function call:" << endl;
//     cout << "return=" << endl;
//     cout << returnVal << endl;
//     if (returnVal > -1)
//     {
//         cout << "arr=" << endl;
//         printArr(arr, arrLen);
//         cout << "*** Checking the rotations by applying them on the original array ****" << endl;
//         testResult = batchRotate(arrCopy, arrLen, rotations, rotationLen);
//         if (testResult > -1)
//         {
//             cout << "arr'=" << endl;
//             printArr(arrCopy, arrLen);
//         }
//     }
// }

// void testTask3(int arr[], int arrLen)
// {
//     int arrCopy[MAX_ARR_LEN], rotations[MAX_ROTATIONS], rotationLen = 0, returnVal, testResult;
//     copyArr(arr, arrCopy, arrLen);
//     cout << "************************ Task 3 test settings ************************" << endl;
//     cout << "arr=" << endl;
//     printArr(arr, arrLen);
//     cout << "arrLen=" << endl;
//     cout << arrLen << endl;
//     cout << "********************** Calling Task 3 function ***********************" << endl;
//     sortAndRecord(arr, arrLen, rotations, rotationLen);
//     cout << "After function call:" << endl;
//     cout << "arr=" << endl;
//     printArr(arr, arrLen);
//     cout << "*** Checking the rotations by applying them on the original array ****" << endl;
//     testResult = batchRotate(arrCopy, arrLen, rotations, rotationLen);
//     if (testResult > -1)
//     {
//         cout << "arr'=" << endl;
//         printArr(arrCopy, arrLen);
//     }
// }

// void testTask4(int src[], int tgt[], int arrLen)
// {
//     int arrCopy[MAX_ARR_LEN], rotations[MAX_ROTATIONS], rotationLen = 0, returnVal, testResult;
//     copyArr(src, arrCopy, arrLen);
//     cout << "************************ Task 4 test settings ************************" << endl;
//     cout << "src=" << endl;
//     printArr(src, arrLen);
//     cout << "tgt=" << endl;
//     printArr(tgt, arrLen);
//     cout << "arrLen=" << endl;
//     cout << arrLen << endl;
//     cout << "********************** Calling Task 4 function ***********************" << endl;
//     returnVal = transformAndRecord(src, tgt, arrLen, rotations, rotationLen);
//     cout << "After function call:" << endl;
//     cout << "return=" << endl;
//     cout << returnVal << endl;
//     if (returnVal > -1)
//     {
//         cout << "src=" << endl;
//         printArr(src, arrLen);
//         cout << "*** Checking the rotations by applying them on the original array ****" << endl;
//         testResult = batchRotate(arrCopy, arrLen, rotations, rotationLen);
//         if (testResult > -1)
//         {
//             cout << "src'=" << endl;
//             printArr(arrCopy, arrLen);
//         }
//     }
// }

// void test01()
// {
//     int arr[] = {9, 1, 3, 5, 4}, arrLen = 5, k = 3;
//     testTask1(arr, arrLen, k);
// }

// void test02()
// {
//     int arr[] = {9, 1, 3, 5, 4}, arrLen = 5, k = 6;
//     testTask1(arr, arrLen, k);
// }

// void test03()
// {
//     int arr[] = {1, 3, 5, 7, 2, 4, 6}, arrLen = 7, indexA = 5, indexB = 2;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test04()
// {
//     int arr[] = {1, 3, 5, 7, 2, 4, 6}, arrLen = 7, indexA = 5, indexB = 10;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test05()
// {
//     int arr[] = {1, 3, 5, 7, 2, 4, 6}, arrLen = 7;
//     testTask3(arr, arrLen);
// }

// void test06()
// {
//     int src[] = {1, 3, 5, 7, 2, 4, 6}, tgt[] = {1, 5, 3, 7, 2, 4, 6}, arrLen = 7;
//     testTask4(src, tgt, arrLen);
// }

// void test07()
// {
//     int src[] = {1, 3, 5, 7, 2, 4, 6}, tgt[] = {1, 5, 3, 7, 2, 4, 7}, arrLen = 7;
//     testTask4(src, tgt, arrLen);
// }

// void test08()
// {
//     int arr[] = {1}, arrLen = 1, k = 0;
//     testTask1(arr, arrLen, k);
// }

// void test09()
// {
//     int arr[] = {1, 2}, arrLen = 2, k = 1;
//     testTask1(arr, arrLen, k);
// }

// void test10()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 1;
//     testTask1(arr, arrLen, k);
// }

// void test11()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 2;
//     testTask1(arr, arrLen, k);
// }

// void test12()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 15;
//     testTask1(arr, arrLen, k);
// }

// void test13()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 16;
//     testTask1(arr, arrLen, k);
// }

// void test14()
// {
//     int arr[] = {1, 2}, arrLen = 2, indexA = 0, indexB = 1;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test15()
// {
//     int arr[] = {1, 2, 3}, arrLen = 3, indexA = 0, indexB = 2;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test16()
// {
//     int arr[] = {1, 2, 3}, arrLen = 3, indexA = 1, indexB = 2;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test17()
// {
//     int arr[] = {1, 2, 3, 4}, arrLen = 4, indexA = 0, indexB = 3;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test18()
// {
//     int arr[] = {1, 2, 3, 4}, arrLen = 4, indexA = 1, indexB = 3;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test19()
// {
//     int arr[] = {1, 2, 3, 4, 5}, arrLen = 5, indexA = 0, indexB = 4;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test20()
// {
//     int arr[] = {1, 2, 3, 4, 5}, arrLen = 5, indexA = 1, indexB = 4;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test21()
// {
//     int arr[] = {1, 2, 3, 4, 5}, arrLen = 5, indexA = 2, indexB = 4;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test22()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6}, arrLen = 6, indexA = 2, indexB = 5;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test23()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, indexA = 6, indexB = 15;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test24()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, indexA = 15, indexB = 6;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test25()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, indexA = 15, indexB = 16;
//     testTask2(arr, arrLen, indexA, indexB);
// }

// void test26()
// {
//     int arr[] = {1}, arrLen = 1;
//     testTask3(arr, arrLen);
// }

// void test27()
// {
//     int arr[] = {9, 8}, arrLen = 2;
//     testTask3(arr, arrLen);
// }

// void test28()
// {
//     int arr[] = {9, 8, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0}, arrLen = 16;
//     testTask3(arr, arrLen);
// }

// void test29()
// {
//     int arr[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9}, arrLen = 16;
//     testTask3(arr, arrLen);
// }

// void test30()
// {
//     int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, arrLen = 16;
//     testTask3(arr, arrLen);
// }

// void test31()
// {
//     int arr[] = {4, 3, 7, 5, 8, 1, 5, 0, 8, 0, 5, 6, 3, 7, 6}, arrLen = 15;
//     testTask3(arr, arrLen);
// }

// void test32()
// {
//     int arr[] = {5, 0, 8, 7, 4, 6}, arrLen = 6;
//     testTask3(arr, arrLen);
// }

// void test33()
// {
//     int arr[] = {2, 6, 6, 2, 7, 9, 7, 7}, arrLen = 8;
//     testTask3(arr, arrLen);
// }

// void test34()
// {
//     int arr[] = {8, 8, 9, 5, 0, 0, 5, 8, 1, 5, 0, 9, 4}, arrLen = 13;
//     testTask3(arr, arrLen);
// }

// void test35()
// {
//     int arr[] = {8, 5, 8, 6, 2, 0, 6}, arrLen = 7;
//     testTask3(arr, arrLen);
// }

// void test36()
// {
//     int src[] = {1}, tgt[] = {1}, arrLen = 1;
//     testTask4(src, tgt, arrLen);
// }

// void test37()
// {
//     int src[] = {1, 2}, tgt[] = {2, 1}, arrLen = 2;
//     testTask4(src, tgt, arrLen);
// }

// void test38()
// {
//     int src[] = {1, 2}, tgt[] = {2, 3}, arrLen = 2;
//     testTask4(src, tgt, arrLen);
// }

// void test39()
// {
//     int src[] = {1, 1}, tgt[] = {1, 1}, arrLen = 2;
//     testTask4(src, tgt, arrLen);
// }

// void test40()
// {
//     int src[] = {0, 6, 3, 4, 4, 5, 6, 1, 2, 8}, tgt[] = {4, 6, 0, 1, 8, 2, 3, 5, 4, 6}, arrLen = 10;
//     testTask4(src, tgt, arrLen);
// }

// void test41()
// {
//     int src[] = {5, 0, 8, 9, 3, 7, 3, 1, 3, 0, 0, 0, 5, 1}, tgt[] = {9, 8, 5, 0, 0, 1, 3, 3, 7, 0, 5, 0, 3, 1}, arrLen = 14;
//     testTask4(src, tgt, arrLen);
// }

// void test42()
// {
//     int src[] = {2, 0, 6, 5, 1, 5, 5, 8, 9, 3, 8, 7, 0, 2, 0, 0}, tgt[] = {2, 0, 9, 0, 6, 8, 7, 3, 0, 5, 2, 0, 8, 5, 5, 1}, arrLen = 16;
//     testTask4(src, tgt, arrLen);
// }

// void test43()
// {
//     int src[] = {1, 0, 4, 5, 9, 7, 5, 9, 1, 8}, tgt[] = {8, 1, 5, 9, 5, 4, 0, 1, 7, 9}, arrLen = 10;
//     testTask4(src, tgt, arrLen);
// }

// void test44()
// {
//     int src[] = {3, 5}, tgt[] = {5, 3}, arrLen = 2;
//     testTask4(src, tgt, arrLen);
// }

// void test45()
// {
//     int src[] = {9, 6, 9}, tgt[] = {9, 9, 6}, arrLen = 3;
//     testTask4(src, tgt, arrLen);
// }

// void test46()
// {
//     int src[] = {9, 9, 7, 3, 7, 6, 3}, tgt[] = {3, 9, 7, 9, 6, 7, 3}, arrLen = 7;
//     testTask4(src, tgt, arrLen);
// }

// void test47()
// {
//     int src[] = {0, 2, 7, 2, 0, 2, 7}, tgt[] = {2, 7, 0, 2, 7, 2, 0}, arrLen = 7;
//     testTask4(src, tgt, arrLen);
// }


// End of Helper Functions

// Tasks
// Please write your code under the TODO tag
// You cannot change the function declarations

// Task 1
int rotate(int arr[], int arrLen, int k)
{
    // Task 1 TODO
    int temp;
    if (k >= 0 && k < arrLen)
    {
        for (int i = 0; i <= k / 2; i++)
        {
            temp = arr[k - i];
            arr[k - i] = arr[i];
            arr[i] = temp;
        }
        return 0;
    }
    else
    {
        cout << "Error: Index k is out of range." << endl;
        return -1;
    }

    // End of Task 1 TODO
}

//Task 2
int swapAndRecord(int arr[], int arrLen, int indexA, int indexB, int rotations[], int &rotationLen)
{
    // Task 2 TODO
    int i = 0;
    int temp;
    if ((indexA >= 0 && indexA < arrLen) && (indexB >= 0 && indexB < arrLen))
    {
        if (indexB < indexA)
        {
            temp = indexA;
            indexA = indexB;
            indexB = temp;
        }

        if (indexA != 0)
        {
            if (indexA - 1 > 0)
            {
                rotate(arr, arrLen, indexA - 1);
                rotations[i] = indexA - 1;
                i++;
            }

            rotate(arr, arrLen, indexA);
            rotations[i] = indexA;
            i++;

            rotate(arr, arrLen, indexB);
            rotations[i] = indexB;
            i++;

            if (indexB - indexA - 1 > 0)
            {
                rotate(arr, arrLen, indexB - indexA - 1);
                rotations[i] = indexB - indexA - 1;
                i++;
            }

            if (indexB - indexA - 2 > 0)
            {
                rotate(arr, arrLen, indexB - indexA - 2);
                rotations[i] = indexB - indexA - 2;
                i++;
            }

            if (indexB - 1 > 0)
            {
                rotate(arr, arrLen, indexB - 1);
                rotations[i] = indexB - 1;
                i++;
            }

            rotationLen = i;
        }
        else //boundary cases
        {
            rotate(arr, arrLen, indexB);
            rotations[i] = indexB;
            i++;

            if (indexB - indexA - 1 > 0)
            {
                rotate(arr, arrLen, indexB - indexA - 1);
                rotations[i] = indexB - indexA - 1;
                i++;
            }

            if (indexB - indexA - 2 > 0)
            {
                rotate(arr, arrLen, indexB - indexA - 2);
                rotations[i] = indexB - indexA - 2;
                i++;
            }

            if (indexB - 1 > 0)
            {
                rotate(arr, arrLen, indexB - 1);
                rotations[i] = indexB - 1;
                i++;
            }

            rotationLen = i;
        }

        return 0;
    }
    else
    {
        cout << "Error: Index out of range." << endl;
        return -1;
    }
    // End of Task 2 TODO
}

//Task 3
void sortAndRecord(int arr[], int arrLen, int rotations[], int &rotationLen)
{
    // Task 3 TODO
    bool swapped;
    int temp_rotationLen = 0;
    int temp_rotations[MAX_ROTATIONS];
    rotationLen = 0;
    for (int i = 0; i < MAX_ROTATIONS; i++)
    {
        rotations[i] = 0;
        temp_rotations[i] = 0;
    }

    do
    {
        swapped = false;
        for (int i = 1; i < arrLen; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swapAndRecord(arr, arrLen, i - 1, i, rotations, rotationLen);
                swapped = true;

                for (int i = 0; i < rotationLen; i++)
                {
                    temp_rotations[temp_rotationLen + i] = rotations[i];
                }
                temp_rotationLen += rotationLen;
            }
        }

    } while (swapped);
    for (int i = 0; i < temp_rotationLen; i++)
    {
        rotations[i] = temp_rotations[i];
    }
    rotationLen = temp_rotationLen;
    // End of Task 3 TODO
}

//Task 4
int transformAndRecord(int src[], int tgt[], int arrLen, int rotations[], int &rotationLen)
{
    // Task 4 TODO
    bool same;
    int temp_src[arrLen];
    int temp_tgt[arrLen];
    int temp_rotationLen = 0;
    int temp_rotations[MAX_ROTATIONS];
    for (int i = 0; i < arrLen; i++)
    {
        temp_src[i] = src[i];
        temp_tgt[i] = tgt[i];
    }
    sortAndRecord(temp_src, arrLen, rotations, rotationLen);
    sortAndRecord(temp_tgt, arrLen, rotations, rotationLen);
    for (int i = 0; i < arrLen; i++)
    {
        if (temp_src[i] != temp_tgt[i])
        {
            return -1;
        }
    }
    for (int i = 0; i < arrLen; i++)
    {
        if (src[i] != tgt[i])
        {
            for (int j = 0; j < arrLen; j++)
            {
                if (src[i] == tgt[j])
                {
                    swapAndRecord(src, arrLen, i, j, rotations, rotationLen);
                    for (int i = 0; i < rotationLen; i++)
                    {
                        temp_rotations[temp_rotationLen + i] = rotations[i];
                    }
                    temp_rotationLen += rotationLen;
                }
            }
        }
    }
    for (int i = 0; i < temp_rotationLen; i++)
    {
        rotations[i] = temp_rotations[i];
    }
    rotationLen = temp_rotationLen;
    return 0;
    // End of Task 4 TODO
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED

int init(int arr[], int arrLen)
{
    char buffer;
    cout << "? Please enter one digit at a time and press return:" << endl;
    for (int i = 0; i < arrLen; i++)
    {
        cin >> buffer;
        if (buffer > '9' || buffer < '0')
        {
            cout << "Error: Illegal digit input." << endl;
            return -1;
        }
        else
        {
            arr[i] = (int)buffer - 48;
        }
    }
    return 0;
}

void printArr(int arr[], int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i];
        if (i < arrLen - 1)
        {
            cout << ',';
        }
    }
    cout << endl;
}

void runInit(int arr[], int &arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Initializing" << endl;
    cout << endl;

    int initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter the length of your array:" << endl;
        cin >> arrLen;
        if (arrLen < 1)
        {
            cout << "! Error: Length should be larger than 0." << endl;
            continue;
        }
        else if (arrLen > MAX_ARR_LEN)
        {
            cout << "Error: arrLen of should be less than or equal to " << MAX_ARR_LEN << endl;
            continue;
        }
        cout << "? Enter " << arrLen << " elements of your array." << endl;
        initResult = init(arr, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! Initialization succeeded!" << endl;
    cout << "! Printing the array:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runPrint(int arr[], int arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Printing the array" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runRotate(int arr[], int arrLen)
{
    int k, output;
    cout << "##################################################" << endl;
    cout << "# Rotating the array:" << endl;
    cout << "? Enter the index k:";
    cin >> k;
    output = rotate(arr, arrLen, k);
    if (output < 0)
    {
        cout << "! Error: Rotation failed." << endl;
    }
    else
    {
        cout << "! Rotated." << endl;
        cout << "! Array after rotation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
    }
}

void runSwap(int arr[], int arrLen)
{
    int indexA, indexB, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Swapping elements:" << endl;
    cout << "? Enter the 1st index:";
    cin >> indexA;
    cout << "? Enter the 2nd index:";
    cin >> indexB;
    output = swapAndRecord(arr, arrLen, indexA, indexB, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Swap failed." << endl;
    }
    else
    {
        cout << "! Swapped." << endl;
        cout << "! Array after swap:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runSort(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Sorting the array:" << endl;
    sortAndRecord(arr, arrLen, rotations, rotationLen);
    cout << "! Sorted." << endl;
    cout << "! Array after sorting:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
    cout << "! Rotations:" << endl;
    cout << endl;
    printArr(rotations, rotationLen);
    cout << endl;
}

void runTransform(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Transforming src array to the tgt:" << endl;
    int tgt[MAX_ARR_LEN], initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter " << arrLen << " elements of the tgt array." << endl;
        initResult = init(tgt, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! The target array:" << endl;
    cout << endl;
    printArr(tgt, arrLen);
    cout << endl;
    output = transformAndRecord(arr, tgt, arrLen, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Cannot transform array to target." << endl;
    }
    else
    {
        cout << "! Transformed." << endl;
        cout << "! Array after transformation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runOption()
{
    int arrLen = 0;
    bool is_initialized = false;
    int src[MAX_ARR_LEN];
    int tgt[MAX_ARR_LEN];
    int option;
    cout << "===========================================" << endl;
    cout << "= Welcome to COMP2011 PA1 1D Rubik's Cube =" << endl;
    cout << "===========================================" << endl;

    while (true)
    {
        if (!is_initialized)
        {
            runInit(src, arrLen);
            is_initialized = true;
        }
        else
        {
            cout << "##################################################" << endl;
            cout << "# Main Menu" << endl;
            cout << endl;
            cout << "1 Initialize" << endl;
            cout << "2 Print" << endl;
            cout << "3 Rotate" << endl;
            cout << "4 Swap" << endl;
            cout << "5 Sort" << endl;
            cout << "6 Transform" << endl;
            cout << "0 Exit" << endl;
            cout << endl;
            cout << "? Please enter an option (0-6): ";
            cin >> option;
            switch (option)
            {
            case 0:
                cout << "! Bye Bye." << endl;
                return;
            case 1:
                runInit(src, arrLen);
                break;
            case 2:
                runPrint(src, arrLen);
                break;
            case 3:
                runRotate(src, arrLen);
                break;
            case 4:
                runSwap(src, arrLen);
                break;
            case 5:
                runSort(src, arrLen);
                break;
            case 6:
                runTransform(src, arrLen);
                break;
            default:
                cout << "Illegal Choice, please try again." << endl;
                break;
            }
            cout << "! Returning to main menu." << endl;
        }
    }
}

// int main(int argc, char **argv)
// {
//     test10(); //run test case 10
//     test20(); //run test case 20
//     test30(); //run test case 30
//     return 0;
// }
int main()
{
    runOption();
    return 0;
}