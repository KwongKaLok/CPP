#include <iostream>
using namespace std;
int main()
{
    int a =10;
    int b =5;
    int& x=a;
   
    x+=2;
    b=a;
    cout<<b<<endl;
    cout<<a<<endl;
    return 0;
}