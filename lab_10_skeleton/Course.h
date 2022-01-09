class Course
{
  private:
    char *course_ID; //Course ID, e.g., COMP2011
    char *course_name; //Course name, e.g., Programming_with_C++
    int start_time; //Start timestamp of the exam
    int end_time; //End timestamp of the exam
    int num_students; //Number of students that will attend the final exam
    
  public:
    //====================
    //Constructors
    Course();
    //==========
    //ID: course ID
    //name: course name
    //s: exam start timestamp
    //e: exam end timestep
    //num_stu: number of students
    Course(char *ID, char *name, int s, int e, int num_stu);

    //====================
    //Accessor member functions
    char* get_course_ID();
    char* get_course_name();
    int get_start_time() const;
    int get_end_time() const;
    int get_num_stu() const;
    
    //====================
    //Mutator member functions
    //With the same parameter difinitions as the constructor
    void set(char *ID, char *name, int s, int e, int num_stu);
};
