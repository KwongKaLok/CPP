inline const int& larger(const int& a, const int& b) 
    { return (a < b) ? b : a; }

inline const char& larger(const char& a, const char& b)
    { return (a < b) ? b : a; }

inline const double& larger(const double& a, const double& b)
    { return (a < b) ? b : a; }

#include <string>
inline const string& larger(const string& a, const string& b)
    { return (a < b) ? b : a; }

#include "teacher.h"
inline const Teacher& larger(const Teacher& a, const Teacher& b)
    { return (a < b) ? b : a; }
