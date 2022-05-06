#include "shop.h"
#include <iostream>
#include <cctype> //hint: you may use the isupper function in it
using std::cout;
using std::endl;

Shop::Shop(HashTable *fireTable, HashTable *iceTable, HashTable *lightningTable)
{
    profit = 0;
    Shop::fireTable = fireTable;
    Shop::iceTable = iceTable;
    Shop::lightningTable = lightningTable;
}
Shop::~Shop()
{
    delete fireTable;
    delete iceTable;
    delete lightningTable;
}
HashTable *Shop::getTable(string prefix) const
{
    if (prefix == "Fire")
        return fireTable;
    else if (prefix == "Ice")
        return iceTable;
    else if (prefix == "Lightning")
        return lightningTable;
    else
        return nullptr;
}

bool Shop::stockUp(string name, int quantity, int price) const
{

    char c;
    bool start_surffix = false;
    Magic *adding_magic = new Magic{"", "", 0, 0};
    adding_magic->price = price;
    adding_magic->quantity = quantity;
    for (int i = 0; i < name.size(); i++)
    {
        c = name[i];
        if (i == 0)
        {

            adding_magic->prefix += c;
            continue;
        }
        if (!isupper(c) && !start_surffix)
        {
            adding_magic->prefix += c;
        }
        else
        {
            start_surffix = true;
            adding_magic->suffix += c;
        }
    }

    HashTable *that_table = getTable(adding_magic->prefix);
    Magic *temp_magic = that_table->get(adding_magic->suffix);
    if (temp_magic)
    {
        temp_magic->quantity += adding_magic->quantity;
        temp_magic->price = adding_magic->price;
    }
    else
    {
        if (that_table->add(adding_magic))
            return true;
        else
            return false;
    }
    return true;
}
bool Shop::sell(string name, int quantity)
{
    char c;
    bool start_surffix = false;
    Magic *removing_magic = new Magic{"", "", 0, 0};
    removing_magic->quantity = quantity;
    for (int i = 0; i < name.size(); i++)
    {
        c = name[i];
        if (i == 0)
        {
            removing_magic->prefix += c;
            continue;
        }
        if (!isupper(c) && !start_surffix)
        {
            removing_magic->prefix += c;
        }
        else
        {
            start_surffix = true;
            removing_magic->suffix += c;
        }
    }
    HashTable *that_table = getTable(removing_magic->prefix);
    Magic *temp_magic = that_table->get(removing_magic->suffix);
    if (temp_magic)
    {
        if (temp_magic->quantity > removing_magic->quantity)
        {
            temp_magic->quantity -= removing_magic->quantity;
        }
        else if (temp_magic->quantity == removing_magic->quantity)
        {
            that_table->remove(temp_magic->suffix);
        }
        else
        {
            delete removing_magic;
            return false;
        }
        profit = (removing_magic->quantity) * (temp_magic->price);
        delete removing_magic;
        return true;
    }
    else
    {
        delete removing_magic;
        return false;
    }
}
