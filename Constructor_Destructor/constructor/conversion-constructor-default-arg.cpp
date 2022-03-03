#include <cstring>      /* File: conversion-constructor-default-arg.cpp */
#include <iostream>
using namespace std;
class Word
{
    int frequency; char* str;
  public:
    Word(const char* s, int k = 1)   // Still conversion constructor!
    {
    	frequency = k;
        str = new char [strlen(s)+1]; strcpy(str, s);
        cout<< "str: "<<str<<endl;
        cout<<"frequency: "<<frequency<<endl;
    }
};

int main()
{
    Word *p = new Word {"action",100};   // Explicit conversion
    Word movie("Titanic",10);           // Explicit conversion
    // Word origin;                     //Error, do not have default constructor
    Word director = "James Cameron"; // Implicit conversion
}
