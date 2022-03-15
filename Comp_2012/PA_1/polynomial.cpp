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
    head = new Term;
    head->coefficient = another.head->coefficient;
    head->exponent = another.head->exponent;
    head->next = nullptr;
    Term *current_node = head;
    if (another.head->next != nullptr)
    {
        for (Term *n = another.head->next; n != nullptr; n = n->next)
        {
            Term *n_node = new Term;
            n_node->coefficient = n->coefficient;
            n_node->exponent = n->exponent;
            n_node->next = n->next;
            current_node->next = n_node;
            current_node = current_node->next;
        }
    }
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
    Term *current = head;
    Term *next_node = nullptr;
    while (current)
    {
        next_node = current->next;
        delete current;
        current = next_node;
    }
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

Polynomial Polynomial::add(const Polynomial &another) const
{
    Polynomial temp;
    Term *current_p1 = head;
    Term *current_p2 = another.head;
    Term *current_temp = temp.head;

    while (current_p1->next && current_p2->next)
    {
        if (current_p1->exponent > current_p2->exponent)
        {
            current_temp->coefficient = current_p1->coefficient;
            current_temp->exponent = current_p1->exponent;
            current_p1 = current_p1->next;
        }
        else if (current_p1->exponent < current_p2->exponent)
        {
            current_temp->coefficient = current_p2->coefficient;
            current_temp->exponent = current_p2->exponent;
            current_p2 = current_p2->next;
        }
        else
        {
            current_temp->exponent = current_p1->exponent;
            current_temp->coefficient = current_p1->coefficient + current_p2->coefficient;
            current_p1 = current_p1->next;
            current_p2 = current_p2->next;
        }
        current_temp->next = new Term;
        current_temp = current_temp->next;
        current_temp->next = nullptr;
    }
    while (current_p1->next || current_p2->next)
    {
        if (current_p1->next)
        {
            current_temp->exponent = current_p1->exponent;
            current_temp->coefficient = current_p1->coefficient;
            current_p1 = current_p1->next;
        }
        if (current_p2->next)
        {
            current_temp->exponent = current_p2->exponent;
            current_temp->coefficient = current_p2->coefficient;
            current_p2 = current_p2->next;
        }
        current_temp->next = new Term;
        current_temp = current_temp->next;
        current_temp->next = nullptr;
    }
    if (current_p1->exponent > current_p2->exponent)
    {
        current_temp->exponent = current_p1->exponent;
        current_temp->coefficient = current_p1->coefficient;
        current_temp->next = new Term;
        current_temp = current_temp->next;
        current_temp->exponent = current_p2->exponent;
        current_temp->coefficient = current_p2->coefficient;
        current_temp->next = nullptr;
    }
    else if (current_p1->exponent < current_p2->exponent)
    {
        current_temp->exponent = current_p2->exponent;
        current_temp->coefficient = current_p2->coefficient;
        current_temp->next = new Term;
        current_temp = current_temp->next;
        current_temp->exponent = current_p1->exponent;
        current_temp->coefficient = current_p1->coefficient;
        current_temp->next = nullptr;
    }
    else
    {
        current_temp->exponent = current_p1->exponent;
        current_temp->coefficient = current_p1->coefficient + current_p2->coefficient;
        current_temp->next = nullptr;
    }

    return temp;
}
Polynomial Polynomial::subtract(const Polynomial &another) const
{
    Polynomial temp;
    Term *current_p1 = head;
    Term *current_p2 = another.head;
    Term *current_temp = temp.head;

    while (current_p1->next && current_p2->next)
    {
        if (current_p1->exponent > current_p2->exponent)
        {
            current_temp->coefficient = current_p1->coefficient;
            current_temp->exponent = current_p1->exponent;
            current_p1 = current_p1->next;
            current_temp->next = new Term;
            current_temp = current_temp->next;
            current_temp->next = nullptr;
        }
        else if (current_p1->exponent < current_p2->exponent)
        {
            current_temp->coefficient = 0 - current_p2->coefficient;
            current_temp->exponent = current_p2->exponent;
            current_p2 = current_p2->next;
            current_temp->next = new Term;
            current_temp = current_temp->next;
            current_temp->next = nullptr;
        }
        else
        {
            int result = current_p1->coefficient - current_p2->coefficient;
            if (result == 0)
            {
                current_p1 = current_p1->next;
                current_p2 = current_p2->next;
            }
            else
            {
                current_temp->exponent = current_p1->exponent;
                current_temp->coefficient = result;
                current_p1 = current_p1->next;
                current_p2 = current_p2->next;
                current_temp->next = new Term;
                current_temp = current_temp->next;
                current_temp->next = nullptr;
            }
        }
    }
    while (current_p1->next || current_p2->next)
    {
        if (current_p1->next)
        {
            current_temp->exponent = current_p1->exponent;
            current_temp->coefficient = current_p1->coefficient;
            current_p1 = current_p1->next;
        }
        if (current_p2->next)
        {
            current_temp->exponent = current_p2->exponent;
            current_temp->coefficient = current_p2->coefficient;
            current_p2 = current_p2->next;
        }
        current_temp->next = new Term;
        current_temp = current_temp->next;
        current_temp->next = nullptr;
    }
    if (current_p1->exponent > current_p2->exponent)
    {
        current_temp->exponent = current_p1->exponent;
        current_temp->coefficient = current_p1->coefficient;
        current_temp->next = new Term;
        current_temp = current_temp->next;
        current_temp->exponent = current_p2->exponent;
        current_temp->coefficient = current_p2->coefficient;
        current_temp->next = nullptr;
    }
    else if (current_p1->exponent < current_p2->exponent)
    {
        current_temp->exponent = current_p2->exponent;
        current_temp->coefficient = 0 - current_p2->coefficient;
        current_temp->next = new Term;
        current_temp = current_temp->next;
        current_temp->exponent = current_p1->exponent;
        current_temp->coefficient = current_p1->coefficient;
        current_temp->next = nullptr;
    }
    else
    {
        int result = current_p1->coefficient - current_p2->coefficient;
        if (result == 0)
        {
            current_temp = temp.head;
            while (current_temp->next->next == nullptr)
            {
                delete current_temp->next;
                current_temp->next = nullptr;
                break;
            }
        }
        else
        {
            current_temp->exponent = current_p1->exponent;
            current_temp->coefficient = result;
            current_temp->next = nullptr;
        }
    }
    return temp;
}
Polynomial Polynomial::multiply(const Polynomial &another) const
{
    Polynomial temp;
    Term *current_p1 = head;
    Term *current_p2 = another.head;
    Term *current_temp = temp.head;

    current_temp->coefficient = current_p1->coefficient * current_p2->coefficient;
    current_temp->exponent = current_p1->exponent + current_p2->exponent;
    current_temp->next = nullptr;
    current_p2 = current_p2->next;
    while (current_p1)
    {
        while (current_p2)
        {
            current_temp->next = new Term;
            current_temp = current_temp->next;
            current_temp->coefficient = current_p1->coefficient * current_p2->coefficient;
            current_temp->exponent = current_p1->exponent + current_p2->exponent;
            current_temp->next = nullptr;
            current_p2 = current_p2->next;
        }
        current_p2 = another.head;
        current_p1 = current_p1->next;
    }

    current_p1 = temp.head;

    Term *temp_node = nullptr;
    while (current_p1 && current_p1->next)
    {
        current_p2 = current_p1;
        while (current_p2->next)
        {
            if (current_p1->exponent == current_p2->next->exponent)
            {
                current_p1->coefficient = current_p1->coefficient + current_p2->next->coefficient;
                temp_node = current_p2->next;
                current_p2->next = current_p2->next->next;
                delete temp_node;
            }
            else
                current_p2 = current_p2->next;
        }
        current_p1 = current_p1->next;
    }
    current_p1 = temp.head;
    int temp_coe, temp_exp;
    temp_node = nullptr;
    while (current_p1->next)
    {
        current_p2 = current_p1;
        while (current_p2->next)
        {
            if (current_p1->exponent < current_p2->exponent)
            {
                temp_coe = current_p1->coefficient;
                temp_exp = current_p1->exponent;
                current_p1->coefficient = current_p2->coefficient;
                current_p1->exponent = current_p2->exponent;
                current_p2->coefficient = temp_coe;
                current_p2->exponent = temp_exp;
            }
            current_p2 = current_p2->next;
        }
        current_p1 = current_p1->next;
    }

    return temp;
}
int Polynomial::evaluate(int valueOfX) const
{
    return 0;
}
int Polynomial::compare(const Polynomial &another) const
{
    return 0;
}
    