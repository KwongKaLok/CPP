#include <cstring>
#include "friend.h"
// #include <iostream>
// using namespace std;

//Constructor (function defination)
Friend::Friend(char const *my_name, int my_age, Friend *best_friend, Friend *good_friend, Friend *fake_friend)
{
    _name = new char[strlen(my_name) + 1]; //the "+1" is for null character
    strcpy(_name, my_name);
    _age = my_age;
    _best = best_friend;
    _good = good_friend;
    _fake = fake_friend;
};
//Destructor (function defination)
Friend::~Friend() { delete[] _name; }
//Member function defination
//Accessor
//"Friend::" needed is because these Accessor functions are in class scope
Friend *Friend::B_Friend() const { return _best; }
Friend *Friend::G_Friend() const { return _good; }
Friend *Friend::F_Friend() const { return _fake; }

void Friend::print_name() const
{
    cout << (_name ? _name : "unknown");
}
void Friend::print_age() const { cout << _age; }
//Mutator
//Assign a new object "new_friend" as _fake pointer 
void Friend::make_friend(Friend *new_friend) { _fake = new_friend; }

//Global function defination, not class scope anymore
void print_parent(Friend *parent)
{
    if (parent)
        parent->print_name();
    else
        cout << "unknown";
};
//Accessor again
void Friend::print_family() const
{
    cout << "Name: ";
    print_name();
    cout << endl;
    cout << "age: ";
    print_age();
    cout << endl;
    cout << "best: ";
    print_parent(_best);
    cout << endl;
    cout << "good: ";
    print_parent(_good);
    cout << endl;
    cout << "fake: ";
    print_parent(_fake);
}