class ll_int_node {
  private: int data; ll_int_node* next;
  public: ll_int_node(const int&); ~ll_int_node(); 
    void ll_print() const; void ll_insert(const int&); 
};

class ll_char_node {
  private: char data; ll_char_node* next;
  public: ll_char_node(const char&); ~ll_char_node(); 
    void ll_print() const; void ll_insert(const char&); 
};

#include "student.h"
class ll_student_node {
  private: Student data; ll_student_node* next;
  public: ll_student_node(const Student&); ~ll_student_node(); 
    void ll_print() const; void ll_insert(const Student&); 
};



