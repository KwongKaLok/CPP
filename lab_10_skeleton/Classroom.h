#include "Course.h"

const int MAX_NUM_COURSE_APP = 20; //Maximum number of coures applying to use this classroom

class Classroom
{
  private:
    char *room_ID; //ID of the classroom, e.g., RM2464
    int quota; //Number of seats
    Course* app_list; //A Course array records all the course applying to use this classroom as the exam place
    Course* exam_list; //A Course array records the courses that can use this classroom as their final exam place
    int num_app; //Number of courses applying to use this classroom, i.e., length of app_list
    int num_exams; //Number of exams that will be held in this class room, i.e., length of exam_list
    
  public:
    //====================
    //Constructor
    //ID: classroom ID
    //q: quota
    Classroom(char *ID, int q);
    //Destructor
    ~Classroom();

    //====================
    //Accessor member functions
    char* get_room_ID();
    int get_quota() const;
    Course* get_app_list();
    Course* get_exam_list();
    int get_num_app();
    int get_num_exams();
    
    //==========
    //Other member functions
    //Receive the application of a couse
    void receive_app(Course course);
    //Generate the final timetable
    void gen_timetable();
    //Print the timetable
    void print_timetable();
};
