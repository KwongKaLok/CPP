#include <iostream> /* File : range-for.cpp */
#include "friend.h"
using namespace std;
int main()
{
    Friend Tom("Tom", 18, nullptr, nullptr, nullptr);
    Friend Mike("Mike", 20, &Tom, nullptr, nullptr);
    Friend Jack("Jack", 28, &Tom, &Mike, nullptr);
    Friend Dick("Dick", 28, &Tom, &Mike, &Jack);

    Tom.print_family(); cout << endl;
    Mike.print_family();  cout << endl;
    Jack.print_family(); cout << endl;
    Dick.print_family();   cout << endl;
    return 0;
}