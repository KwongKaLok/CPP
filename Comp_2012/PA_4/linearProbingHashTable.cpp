#include "linearProbingHashTable.h"
LinearProbingHashTable::LinearProbingHashTable(int m, int (*hash)(string, int))
{}
int LinearProbingHashTable::hi(string k, int i) const
{
    return ((hash(k,m)+i)%m);
}