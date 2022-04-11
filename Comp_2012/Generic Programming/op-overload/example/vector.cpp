#include "vector.h" /* File: vector.cpp */


const Vector& Vector::operator=(const Vector& b)
{
    if (this != &b)
        x = b.x; y = b.y;
    return *this;
};


Vector Vector::operator+(const Vector& b) const
{
    return Vector(x + b.x, y + b.y);
};

const Vector& Vector::operator+=(const Vector& b)
{
    x += b.x; y += b.y;
    return *this;
};


Vector& Vector::operator++( )
{
    ++x; ++y;
    return *this;
}

Vector Vector::operator++(int)
{
    Vector temp(x,y);
    x++; y++;
    return temp;
}

double Vector::operator[ ](int j) const
{
    switch (j)
    {
        case 0: return x;
        case 1: return y;
        default: std::cerr << "Error (const): invalid dimension!\n";
    }
}

double& Vector::operator[ ](int j) 
{
    switch (j)
    {
        case 0: return x;
        case 1: return y;
        default: std::cerr << "Error: invalid dimension!\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& a)
{
    return (os << '('  << a[0] << " , " << a[1] << ')');
}
    
