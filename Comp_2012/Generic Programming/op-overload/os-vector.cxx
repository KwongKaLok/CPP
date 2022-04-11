#include <iostream> /* File: os-vector0.cxx */
#include "vector0.h"

ostream& operator<<(ostream& os, const Vector& a)
{
    return (os << '('  << a.getx( ) << " , " << a.gety( ) << ')');
}
    
