#include "openAddressingHashTable.h"

OpenAddressingHashTable::OpenAddressingHashTable(int m, int (*hash)(string, int))
{
    HashTable::m = m;
    HashTable::hash = hash;
    table = new Cell[m];
    for (int i = 0; i < m; i++)
        table[i] = Cell(nullptr, EMPTY);
}
OpenAddressingHashTable::~OpenAddressingHashTable()
{
    for (int i = 0; i < m; i++)
        delete table[i].magic;
    delete[] table;
}
void OpenAddressingHashTable::performRehashing()
{
    m = 2 * m;
    Cell *large_table = new Cell[m];
    for (int i = 0; i < m; i++)
    {
        large_table[i] = Cell(nullptr, EMPTY);
    }
    for (int i = 0; i < m / 2; i++)
    {
        if (table[i].status == ACTIVE)
        {
            for (int j = 0; j < m; j++)
            {
                int hash_num = hi(table[i].magic->suffix, j);
                comparisonCount++;
                if (large_table[hash_num].status != ACTIVE)
                {
                    large_table[hash_num].magic = table[i].magic;
                    large_table[hash_num].status = ACTIVE;
                    break;
                }
            }
        }
    }
    delete[] table;
    table = large_table;
}

bool OpenAddressingHashTable::add(Magic *magic)
{
    if (activeCellCount > ((m) / 2))
    {
        cout << "Rehashing is needed!" << endl;
        performRehashing();
        cout << "Rehashing is done!" << endl;
    }
    for (int i = 0; i < m; i++)
    {
        comparisonCount++;
        int hash_num = hi(magic->suffix, i);
        if (table[hash_num].status != ACTIVE)
        {
            table[hash_num].magic = magic;
            table[hash_num].status = ACTIVE;
            activeCellCount += 1;
            return true;
        }
    }
    return false;
}

bool OpenAddressingHashTable::remove(string key)
{
    for (int i = 0; i < m; i++)
    {
        comparisonCount++;
        int hash_num = hi(key, i);
        if (table[hash_num].status == ACTIVE && key == table[hash_num].magic->suffix)
        {
            delete table[hash_num].magic;
            table[hash_num].status = DELETED;
            activeCellCount -= 1;
            return true;
        }
        else if (table[hash_num].status == EMPTY)
            return false;
    }
    return false;
}

Magic *OpenAddressingHashTable::get(string key)
{
    for (int i = 0; i < m; i++)
    {
        int hash_num = hi(key, i);
        comparisonCount++;
        if (table[hash_num].status == ACTIVE && key == table[hash_num].magic->suffix)
            return table[hash_num].magic;
        else if (table[hash_num].status == EMPTY)
            return nullptr;
    }
    return nullptr;
}

int OpenAddressingHashTable::getClusterCount() const
{
    int num_of_consecutive = 0;
    bool *check = new bool[m];
    for (int i = 0; i < m; i++)
        check[i] = false;
    for (int i = 0; i < m; i++)
    {
        if (check[(i + m + 1) % m] == false && check[(i + m - 1) % m] == false && table[i].status == ACTIVE)
        {
            num_of_consecutive++;
            check[i] = true;
        }
        else if (table[i].status == ACTIVE && (check[(i + m + 1) % m] == false || check[(i + m - 1) % m] == false))
            check[i] = true;
    }
    delete[] check;
    return num_of_consecutive;
}

int OpenAddressingHashTable::getLargestClusterSize() const
{
    int count{0};
    Cell temp_array[2 * m];
    int cluster_size{0};
    int j = 0, k = 0;
    while (j < 2)
    {
        for (int i = 0; i < m; i++)
            temp_array[k++] = table[i];
        j++;
    }
    k = 0;
    for (int i = 0; i < 2 * m; i++)
    {
        count = 0;
        while (temp_array[k++].status == ACTIVE)
            ++count;
        if (cluster_size < count)
            cluster_size = count;
    }
    if (cluster_size > m)
        cluster_size = cluster_size / 2;

    return cluster_size;
}

string OpenAddressingHashTable::getClusterSizeSortedList() const
{
    int start_bit = 0;
    int end_bit = m - 1;
    int cluster_size = 0;
    int number_of_cluster = 0;
    bool counting = false;
    int result_list = new int[m];
    string result_message = "";
    if (getLargestClusterSize() == 0)
        result_message = "(empty)";
    else if (getLargestClusterSize() == 1)
    {
        result_message = "1";
    }
    else if (getLargestClusterSize() == m)
    {
        result_message = std::to_string(m);
    }
    else
    {

        while (table[(start_bit + m) % m].status == ACTIVE && table[(end_bit + m) % m].status == ACTIVE)
        {
            start_bit--;
            end_bit--;
        }
        for (int i = start_bit; i <= end_bit; i++)
        {
            if (table[(i + m) % m].status == ACTIVE)
            {
                if (counting)
                {
                    cluster_size++;
                    if (i == end_bit)
                    {
                        result_list[number_of_cluster++] = cluster_size;
                    }
                }
                else
                {
                    cluster_size = 1;
                    counting = true;
                }
            }
            else if ((table[(i + m) % m].status != ACTIVE) && counting)
            {
                result_list[number_of_cluster++] = cluster_size;
                cluster_size = 0;
                counting = false;
            }
        }
        for (int i = 0; i < number_of_cluster; i++)
        {
            for (int j = i + 1; i < number_of_cluster; j++)
            {
                if (result_list[j] > result_list[i])
                {
                    int temp = result_list[i];
                    result_list[i] = result_list[j];
                    result_list[j] = temp;
                }
            }
        }

        for (int i = 0; i < number_of_cluster; i++)
        {
            result_message += std::to_string(result_list[i]);
            if (i != 0 || i != number_of_cluster - 1)
            {
                result_message += ",";
            }
        }
    }
    delete[] result_list;
    return result_message;
}