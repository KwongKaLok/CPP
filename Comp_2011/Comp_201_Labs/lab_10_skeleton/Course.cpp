#include "Course.h"
#include <cstring>

//===================
//Implementation of the constructor
Course::Course()
{
    course_ID = NULL;
    course_name = NULL;
    start_time = 0;
    end_time = 0;
    num_students = 0;
}
//==========
Course::Course(char *ID, char *name, int s, int e, int num_stu)
{
    set(ID, name, s, e, num_stu);
}

//===================
//Impelmentation of the accessor member funcstions
char *Course::get_course_ID()
{
    return course_ID;
}

char *Course::get_course_name()
{
    return course_name;
}

int Course::get_start_time() const
{
    return start_time;
}

int Course::get_end_time() const
{
    return end_time;
}

int Course::get_num_stu() const
{
    return num_students;
}

//====================
//Task 1: Implement the mutator member function
void Course::set(char *ID, char *name, int s, int e, int num_stu)
{
    course_ID = ID;
    course_name = name;
    start_time = s;
    end_time = e;
    num_students = num_stu;
}
