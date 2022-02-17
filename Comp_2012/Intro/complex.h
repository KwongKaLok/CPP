class Complex /* File: complex.h */
{
private:
  float real;
  float imag;

public:
  //Here is function defination (Constructor), not function declaration like seperating the header file and main file
  // Complex(float r, float i) { real = r; imag = i; }   //1st method to initialize 
  // Complex(float r, float i){set(r,i);}                //2nd method to initialize
  // void set(float r, float i)
  // {
  //   real = r;
  //   imag = i;
  // }
  Complex():real(9.9),imag(8.8){}                       //3rd method to initialize //Constructor : default value 
  Complex(float r, float i):real(r),imag(i){}                                      //Constructor : have value
  void print() const { cout << "(" << real << " , " << imag << ")" << endl; }

  Complex add1(const Complex &x) // Return by value
  {
    real += x.real;
    imag += x.imag;
    return (*this);
  }
  Complex *add2(const Complex &x) // Return by value using pointer
  {
    real += x.real;
    imag += x.imag;
    return this;
  }
  Complex &add3(const Complex &x) // Return by reference
  {
    real += x.real;
    imag += x.imag;
    return (*this);
  }
};
