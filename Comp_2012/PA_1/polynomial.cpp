#include "polynomial.h"
#include <iostream>
using namespace std;
// note: you are not allowed to include any additional library, see also FAQ for what you can/cannot do
// write your code below and submit this file only
Polynomial::Polynomial() // default constructor
{
    head = new Term;
    head->coefficient = 0;
    head->exponent = 0;
    head->next = nullptr;
}

Polynomial::Polynomial(const Polynomial &another) // copy constructor
{
}
Polynomial::Polynomial(int array[], int arraySize) // conversion constructor
{
    int location;
    head = new Term;
    head->next = nullptr;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == 0)
            continue;
        else
        {
            head->coefficient = array[i];
            head->exponent = arraySize - i - 1;
            head->next = nullptr;
            location = i;
            break;
        }
    }
    Term *current_node = head;
    for (int i = location + 1; i < arraySize; i++)
    {
        if (array[i] == 0)
            continue;
        else
        {
            Term *n_node = new Term;
            n_node->coefficient = array[i];
            n_node->exponent = arraySize - i - 1;
            n_node->next = nullptr;
            current_node->next = n_node;
            current_node = n_node;
        }
    }
}
Polynomial::~Polynomial() // destructor
{
    //     cout<<head->coefficient<<"destructor";
}

void Polynomial::print() const
{
    for (Term *n = head; n != nullptr; n = n->next)
    {
        if (n == head)
        {
            if (n->coefficient > 1)
            {
                cout << n->coefficient;
                if (n->exponent > 1)
                    cout << "*x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << "*x";
            }
            else if (n->coefficient == 1)
            {
                if (n->exponent == 0)
                    cout << n->coefficient;
                else if (n->exponent > 1)
                    cout << "x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << "x";
            }
            else if (n->coefficient == -1)
            {
                if (n->exponent == 0)
                    cout << n->coefficient;
                else if (n->exponent > 1)
                    cout << "-x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << "-x";
            }
            else if (n->coefficient < -1)
            {
                cout << "-" << abs(n->coefficient);
                if (n->exponent > 1)
                    cout << "*x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << "*x";
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            if (n->coefficient > 1)
            {
                cout << " + " << n->coefficient;
                if (n->exponent > 1)
                    cout << "*x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << "*x";
            }
            else if (n->coefficient == 1)
            {
                if (n->exponent == 0)
                    cout << n->coefficient;
                else if (n->exponent > 1)
                    cout << " + x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << " + x";
            }
            else if (n->coefficient == -1)
            {
                if (n->exponent == 0)
                    cout << n->coefficient;
                else if (n->exponent > 1)
                    cout << " - x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << " - x";
            }
            else if (n->coefficient < -1)
            {
                cout << " - " << abs(n->coefficient);
                if (n->exponent > 1)
                    cout << "*x^" << n->exponent;
                else if (n->exponent == 1)
                    cout << "*x";
            }
        }
    }
}
