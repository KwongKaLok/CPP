/* File: temperature_constructors_accessors.cpp */
#include "temperature.h"

// CONSTRUCTOR member functions
temperature::temperature() { degree = 0.0; }
temperature::temperature(double d, char s) { set(d, s); }

// ACCESSOR member functions
double temperature::kelvin() const { return degree; }
double temperature::celsius() const { return degree - 273.15; }
double temperature::fahrenheit() const
                    { return (degree - 273.15)*9.0/5.0 + 32.0; }

void temperature::set(double d, char s){
    switch (s)
    {
    case KELVIN: degree = d; break;
    case CELSIUS: degree = d + 273.15; break;
    case FAHRENHEIT: degree = (d - 32.0)*5.0/9.0 + 273.15; break;
    
    default: cerr << "Bad temperature scale: " << s << endl;
            exit(-1);
    }    
}