#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    int age;
    char *name;
    // char name[100];
    void set(int a, const char *n)
    {
        age = a;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

public:
    Student()
    {
        set(0, "none");
        cout << "This is default constructor" << endl;
    }

    Student(const char *n, int a)
    {
        set(a, n);
        cout << "This is explicit conversion constructor const char *n" << endl;
    }

    Student(const Student &student)
    {
        set(student.age, student.name);
        cout << "This is copy constructor" << endl;
    }
    void print() const
    {
        cout << "name: " << name << '\t' << "age: " << age << endl;
        cout << reinterpret_cast<const void *>(name) << endl;
    }

    Student to_upper_case() const
    {
        Student x(*this);
        for (char *p = x.name; *p != '\0'; p++)
        {
            *p += 'A' - 'a';
        }
        cout << "This is to_upper_case() " << endl;
        return x;
    }
};
int main()
{
    Student Peter("peter", 18);
    Student Alice = Peter;          // deep copy
    Student Dick("dick", 20);
    Dick=Peter;                     //shallow copy
    Peter.print();
    Alice.print();
    Dick.print();
}