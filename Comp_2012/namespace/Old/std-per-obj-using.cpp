#include <iostream>     /* File: std-per-obj-using.cpp */
#include <vector>
#include <algorithm>

int main() 
{
    std::vector<int> v;
    std::vector<int>::iterator it;
    v.push_back(42);    // ... push_back some more int's
    v.push_back(63);

    it = std::find( v.begin(), v.end(), 42 );

    if ( it != v.end() )
        std::cout << "found 42!" << std::endl;

    return 0;
}
