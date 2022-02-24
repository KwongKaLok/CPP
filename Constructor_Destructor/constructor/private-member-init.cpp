#include <iostream>
#include <cstring>
using namespace std;

class Word /* File: private-member-init.cpp */
{
private:
  const char *str;

public:
  int frequency;
  Word()
  {
    frequency = 0;
    str = nullptr;
  }
  Word(int feq, const char *name)
  {
    frequency = feq;
    str = name;
    cout<<"str: "<<str<<endl;
  }
};

int main()
{
  Word movie = {1, "Titanic"};
  cout<< movie.frequency<<endl;  
}
