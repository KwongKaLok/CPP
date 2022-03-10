#include <iostream>     /* File: using-std.cpp */
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    vector<int> v;
    vector<int>::iterator it;

    v.push_back(63);    // ... push_back some more int's
    v.push_back(42);
    it = find( v.begin(), v.end(), 42 );

    if ( it != v.end() )
    	cout << "found 42!" << endl;

    return 0;
}
