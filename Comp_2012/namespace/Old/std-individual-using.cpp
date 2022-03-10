#include <iostream>     /* File: std-individual-using.cpp */
#include <vector>
#include <algorithm>

using std::vector;
using std::find;
using std::cout; 
using std::endl;

int main() 
{
    vector<int> v;
    vector<int>::iterator it;
    v.push_back(63);    // ... push_back some more int's

    it = find( v.begin(), v.end(), 42 );
    if ( it != v.end() )
        cout << "found 42!" << endl;
    return 0;
}
