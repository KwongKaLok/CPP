//do NOT modify this file

enum CarType {HEAD, OIL, COAL, WOOD, STEEL, SUGAR}; //either HEAD for the train head or the type of the cargo the train car can carry

struct TrainCar //a node in the doubly-linked list that represents the train - it is therefore a car in the train
{
    CarType type; 
    int maxLoad; //maximum possible load of cargo for this car; always 0 for HEAD
    int load; //current load of cargo for this car; always 0 for HEAD
    TrainCar* prev; //previous pointer
    TrainCar* next; //next pointer
};

const int CARGO_TYPE_COUNT = 5; //there are 5 types of cargos


//the following function's implementation is given to you (in given.cpp)
void printTrain(const TrainCar* head);

//you need to implement the following in todo.cpp
TrainCar* createTrainHead();
bool addCar(TrainCar* head, int position, CarType cargoType, int maxLoad);
bool deleteCar(TrainCar* head, int position);
bool swapCar(TrainCar* head, int a, int b);
void sortTrain(TrainCar* head, bool ascending); 
bool load(TrainCar* head, CarType type, int amount);
bool unload(TrainCar* head, CarType type, int amount);
void printCargoStats(const TrainCar* head);
void divide(const TrainCar* head,  TrainCar* results[CARGO_TYPE_COUNT]);
TrainCar* optimizeForMaximumPossibleCargos(const TrainCar* head, int upperBound);
void deallocateTrain(TrainCar* head);