#include "pa3.h"
#include <iostream>

using namespace std;

TrainCar *createSampleTrain() //this function manually creates a pre-defined train for some of the test cases, because some students may not be able to complete addCar correctly
{
    TrainCar *head = new TrainCar;
    head->type = HEAD;
    head->load = 0;
    head->maxLoad = 0;
    head->prev = head->next = nullptr;
    TrainCar *cars[5];
    cars[0] = new TrainCar;
    cars[1] = new TrainCar;
    cars[2] = new TrainCar;
    cars[3] = new TrainCar;
    cars[4] = new TrainCar;
    cars[0]->type = SUGAR;
    cars[0]->load = 30;
    cars[0]->maxLoad = 400;
    cars[0]->prev = cars[0]->next = nullptr;
    cars[1]->type = OIL;
    cars[1]->load = 10;
    cars[1]->maxLoad = 100;
    cars[1]->prev = cars[1]->next = nullptr;
    cars[2]->type = COAL;
    cars[2]->load = 40;
    cars[2]->maxLoad = 200;
    cars[2]->prev = cars[2]->next = nullptr;
    cars[3]->type = STEEL;
    cars[3]->load = 20;
    cars[3]->maxLoad = 300;
    cars[3]->prev = cars[3]->next = nullptr;
    cars[4]->type = COAL;
    cars[4]->load = 5;
    cars[4]->maxLoad = 500;
    cars[4]->prev = cars[4]->next = nullptr;
    head->next = cars[0];
    cars[0]->next = cars[1];
    cars[1]->next = cars[2];
    cars[2]->next = cars[3];
    cars[3]->next = cars[4];
    cars[0]->prev = head;
    cars[1]->prev = cars[0];
    cars[2]->prev = cars[1];
    cars[3]->prev = cars[2];
    cars[4]->prev = cars[3];
    return head;
}

TrainCar *createSampleTrain2() //this function manually creates a pre-defined train for some of the test cases, because some students may not be able to complete addCar correctly
{
    TrainCar *head = new TrainCar;
    head->type = HEAD;
    head->load = 0;
    head->maxLoad = 0;
    head->prev = head->next = nullptr;
    TrainCar *cars[4];
    cars[0] = new TrainCar;
    cars[1] = new TrainCar;
    cars[2] = new TrainCar;
    cars[3] = new TrainCar;
    cars[0]->type = COAL;
    cars[0]->load = 17;
    cars[0]->maxLoad = 440;
    cars[0]->prev = cars[0]->next = nullptr;
    cars[1]->type = WOOD;
    cars[1]->load = 23;
    cars[1]->maxLoad = 110;
    cars[1]->prev = cars[1]->next = nullptr;
    cars[2]->type = SUGAR;
    cars[2]->load = 67;
    cars[2]->maxLoad = 220;
    cars[2]->prev = cars[2]->next = nullptr;
    cars[3]->type = WOOD;
    cars[3]->load = 11;
    cars[3]->maxLoad = 330;
    cars[3]->prev = cars[3]->next = nullptr;
    head->next = cars[0];
    cars[0]->next = cars[1];
    cars[1]->next = cars[2];
    cars[2]->next = cars[3];
    cars[0]->prev = head;
    cars[1]->prev = cars[0];
    cars[2]->prev = cars[1];
    cars[3]->prev = cars[2];
    return head;
}

int main()
{
    cout << boolalpha; //to show true/false instead of 1/0

    int testCase;
    cout << "Choo-choo! All aboard! Which test case would you like to run today, captain? " << endl;
    cin >> testCase;

    cout << "Output for test case " << testCase << ":" << endl;
    cout << "==========================================" << endl;

    if (testCase == 1)
    {
        cout << "Creating a new train head..." << endl;
        TrainCar *train = createTrainHead();
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 2)
    {
        cout << "Creating a new train head..." << endl;
        TrainCar *train = createTrainHead();
        printTrain(train);
        cout << endl;
        cout << "addCar(train, 1, OIL, 100): " << addCar(train, 1, OIL, 100) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 3)
    {
        cout << "Creating a new train head..." << endl;
        TrainCar *train = createTrainHead();
        printTrain(train);
        cout << endl;
        cout << "addCar(train, 1, OIL, 100): " << addCar(train, 1, OIL, 100) << endl;
        printTrain(train);
        cout << endl;
        cout << "addCar(train, 2, WOOD, 200): " << addCar(train, 2, WOOD, 200) << endl;
        printTrain(train);
        cout << endl;
        cout << "addCar(train, 3, STEEL, 300): " << addCar(train, 3, STEEL, 300) << endl;
        printTrain(train);
        cout << endl;
        cout << "addCar(train, 1, SUGAR, 400): " << addCar(train, 1, SUGAR, 400) << endl;
        printTrain(train);
        cout << endl;
        cout << "addCar(train, 0, COAL, 500): " << addCar(train, 0, COAL, 500) << endl;
        printTrain(train);
        cout << endl;
        cout << "addCar(train, 5, COAL, 500): " << addCar(train, 5, COAL, 500) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 4)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "deleteCar(train, 1): " << deleteCar(train, 1) << endl;
        printTrain(train);
        cout << endl;
        cout << "deleteCar(train, 10): " << deleteCar(train, 10) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 5)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "deleteCar(train, 1): " << deleteCar(train, 1) << endl;
        printTrain(train);
        cout << endl;
        cout << "deleteCar(train, 4): " << deleteCar(train, 4) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 6)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "swapCar(train, 1, 3): " << swapCar(train, 4, 5) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 7)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "swapCar(train, 1, 2): " << swapCar(train, 1, 2) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 8)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling sortTrain(train, false)..." << endl;
        sortTrain(train, false);
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 9)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling sortTrain(train, true)..." << endl;
        sortTrain(train, true);
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 10)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling load(train, OIL, 200): " << load(train, OIL, 200) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling load(train, OIL, 80): " << load(train, OIL, 80) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 11)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling load(train, COAL, 260): " << load(train, COAL, 260) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 12)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling unload(train, OIL, 200): " << unload(train, OIL, 200) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling unload(train, STEEL, 20): " << unload(train, STEEL, 20) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 13)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling unload(train, COAL, 35): " << unload(train, COAL, 35) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling unload(train, COAL, 10): " << unload(train, COAL, 10) << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 14)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << "The following one line contains the cargo stats in the required order:" << endl;
        printCargoStats(train);
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 15)
    {
        TrainCar *train = createSampleTrain2();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << "The following one line contains the cargo stats in the required order:" << endl;
        printCargoStats(train);
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 16)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling divide(train, results)..." << endl;
        TrainCar *results[CARGO_TYPE_COUNT];
        divide(train, results);
        cout << "Train should remain unchanged:" << endl;
        printTrain(train);
        cout << "Divide results:" << endl;
        for (int i = 0; i < CARGO_TYPE_COUNT; i++)
        {
            cout << "results[" << i << "]:" << endl;
            if (results[i] == nullptr)
                cout << "nullptr" << endl;
            else
                printTrain(results[i]);
        }
        cout << endl;
        for (int i = 0; i < CARGO_TYPE_COUNT; i++)
        {
            if (results[i])
            {
                cout << "Calling deallocateTrain on result[" << i << "]..." << endl;
                deallocateTrain(results[i]);
            }
        }
        cout << "Calling deallocateTrain on train..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 17)
    {
        TrainCar *train = createSampleTrain2();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;
        cout << "Calling divide(train, results)..." << endl;
        TrainCar *results[CARGO_TYPE_COUNT];
        divide(train, results);
        cout << "Train should remain unchanged:" << endl;
        printTrain(train);
        cout << "Divide results:" << endl;
        for (int i = 0; i < CARGO_TYPE_COUNT; i++)
        {
            cout << "results[" << i << "]:" << endl;
            if (results[i] == nullptr)
                cout << "nullptr" << endl;
            else
                printTrain(results[i]);
        }
        cout << endl;
        for (int i = 0; i < CARGO_TYPE_COUNT; i++)
        {
            if (results[i])
            {
                cout << "Calling deallocateTrain on result[" << i << "]..." << endl;
                deallocateTrain(results[i]);
            }
        }
        cout << "Calling deallocateTrain on train..." << endl;
        deallocateTrain(train);
    }

    else if (testCase == 18)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;

        cout << "Calling optimizeForMaximumPossibleCargos(train, 500)..." << endl;
        TrainCar *result = optimizeForMaximumPossibleCargos(train, 500);
        printTrain(result);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(result);

        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 19)
    {
        TrainCar *train = createSampleTrain();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;

        cout << "Calling optimizeForMaximumPossibleCargos(train, 95)..." << endl;
        TrainCar *result = optimizeForMaximumPossibleCargos(train, 95);
        printTrain(result);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(result);

        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 20)
    {
        TrainCar *train = createSampleTrain2();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;

        cout << "Calling optimizeForMaximumPossibleCargos(train, 999)..." << endl;
        TrainCar *result = optimizeForMaximumPossibleCargos(train, 999);
        printTrain(result);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(result);

        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 21)
    {
        TrainCar *train = createSampleTrain2();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;

        cout << "Calling optimizeForMaximumPossibleCargos(train, 87)..." << endl;
        TrainCar *result = optimizeForMaximumPossibleCargos(train, 87);
        printTrain(result);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(result);

        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }
    else if (testCase == 22)
    {
        TrainCar *train = createSampleTrain2();
        cout << "Original train:" << endl;
        printTrain(train);
        cout << endl;

        cout << "Calling optimizeForMaximumPossibleCargos(train, 68)..." << endl;
        TrainCar *result = optimizeForMaximumPossibleCargos(train, 68);
        printTrain(result);
        cout << endl;
        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(result);

        cout << "Calling deallocateTrain..." << endl;
        deallocateTrain(train);
    }

    cout << "==========================================" << endl;

    return 0;
};