#include "Technician.h"
#include <iostream>
using namespace std;

class TechnicianLeader : public Technician
{
    public:
        TechnicianLeader();
        TechnicianLeader(int id, const string& name, char gender, const Date& entry_date, int num_projects, Department dept);
        ~TechnicianLeader();
        
        void calculate_salary();
        void print_description() const;
};