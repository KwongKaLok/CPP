#include <iostream>

using namespace std;

int main()
{
    int x [][2]{{3,6},{4,8},{5,10}};
    cout<< sizeof(x)<<endl;
    cout<< sizeof(x[0])<<endl;
    cout<< sizeof(x)/sizeof(x[0])<<endl;

}