#include "vector-op-add.h" /* File: vector-op-add-test.cpp */
using namespace std;

ostream& operator<<(ostream& os, const Vector& a)
{
    return (os << '('  << a.getx() << ", " << a.gety() << ')');
}
    
int main()
{
    Vector a(1.1, 2.2);
    Vector b(3.3, 4.4);

    cout << "vector + vector: a + b + b= " << a + b + b<< endl;
    cout << "vector + scalar: b + 1.0 = " << b + 1.0 << endl;
    

    a += b+=b;
    cout << "After += : a = " << a << "  b = " << b << endl;
    return 0;
}
