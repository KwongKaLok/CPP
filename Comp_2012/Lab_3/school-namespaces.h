#ifndef SCHOOL_NS_H
#define SCHOOL_NS_H

#include <string>

namespace engineering
{
    void show_events();
    namespace cse {
        extern std::string events[];
        void show_events();
    }
    namespace ece {
        extern std::string events[];
        void show_events();
    }
}

namespace science
{
    void show_events();
    extern std::string events[];
    namespace math {
        extern std::string events[];
        void show_events();
    }
    namespace physics {
        extern std::string events[];
        void show_events();
    }
}

#endif