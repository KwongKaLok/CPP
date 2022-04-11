#include <iostream> /* File: vector.h */

class Vector
{
  public:
    Vector(double a = 0, double b = 0) : x(a), y(b) { }
    const Vector& operator=(const Vector& b);
    Vector operator+(const Vector& b) const;
    const Vector& operator+=(const Vector& b);
    Vector& operator++( ); // Pre-increment
    Vector operator++(int); // Post-increment
    double operator[ ](int) const;
    double& operator[ ](int);
    
  private:
    double x, y;
};

std::ostream& operator<<(std::ostream& os, const Vector& a);

