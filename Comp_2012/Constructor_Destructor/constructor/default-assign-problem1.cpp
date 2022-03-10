#include <iostream> /* File: default-assign-problem1.cpp */
#include <cstring>
using namespace std;
class Word
{
private:
  int frequency;
  char str[100];
  void set(int f, const char *s)
  {
    frequency = f;
    strcpy(str, s);
  }

public:
  Word(const char *s, int k = 1)
  {
    set(k, s);
    cout << "\nImplicit const char* conversion\n";
  }
  Word(const Word &w)
  {
    set(w.frequency, w.str);
    cout << "\nCopy\n";
  }

  void print() const // Also prints the address of object's str array
  {
    cout << str << " : " << frequency << " ; "
         << reinterpret_cast<const void *>(str) << endl;
  }
};

int main()
{
  Word x("rat"); // Conversion constructor
  Word y = x;    // Copy constructor
  Word z("cat"); // Conversion constructor
  z = x;         // Default assignment operator

  x.print();
  y.print();
  z.print();
}
