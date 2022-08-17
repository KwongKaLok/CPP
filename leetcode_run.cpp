#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    cout << typeid('7' - '0').name() << endl;
    cout << typeid('7').name() << endl;
}