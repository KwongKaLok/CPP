#include "vector.h" /* File: test-vector.cpp */
using namespace std;

std::ostream& operator<<(std::ostream& os, Vector& a)
{
    return (os << '('  << a[0] << " , " << a[1] << ')');
}
    
int main( )
{
    Vector a(1.1, 2.2);
    Vector b(3.3, 4.4);
    Vector c;
    Vector d(5.0);

    cout << "a+b = " << a+b << endl;
    c = d;
    c += a;
    c += c;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    
    c = ++a;
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    d = a++;
    cout << "a = " << a << endl;
    cout << "d = " << d << endl;
    c[1] = d[0];
    cout << "c = " << c << endl;
}
    
