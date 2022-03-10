#include <iostream>
#include <cstring>
using namespace std;

class Word              /* File: default-initializer.cpp */
{   // Implicitly private members
    public:
    int frequency {1000};
    const char* str {nullptr};
};

int main() { Word movie;
    cout<< movie.frequency;}
