#include <iostream>
using namespace std;

class Friend
{
private:
    char *_name;
    int _age;
    Friend *_best, *_good, *_fake;

public:
    //Constructor (function prototype only)
    Friend(char const *my_name, int my_age, Friend *best_friend = nullptr, Friend *good_friend = nullptr, Friend *fake_friend = nullptr);
    //Destructor (function prototype only)
    ~Friend();
    //Member function declaration
    //Accessor
    Friend *B_Friend() const;
    Friend *G_Friend() const;
    Friend *F_Friend() const;
    void print_name() const;
    void print_age() const;
    void print_family() const;
    //Mutator
    void make_friend(Friend *new_friend);
};