#include <iostream>
#include <cstdlib>

using namespace std;

const int MIN_HEIGHT = 120;
const int MAX_HEIGHT = 160;

struct kidNode
{
    int height;
    kidNode *next;
};

int getRandomHeight(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void printLinkedList(kidNode *head)
{
    for (kidNode *p = head; p != nullptr; p = p->next)
    {
        cout << p->height;
        cout << " ";
    }
    cout << endl;
} 

/** Task 1:  create an initial linked list with kid_num nodes with random heights, each presenting a kid. **/
kidNode *createKidList(int kid_num, int min_height, int max_height)
{
    // Please implement task 1 here.

    kidNode *head = new kidNode;
    head->height = getRandomHeight(min_height, max_height);
    kidNode *p = head;
    for (int j = 1; j < kid_num; ++j)
    {
        kidNode *height = new kidNode;
        height->height = getRandomHeight(min_height, max_height);
        height->next = nullptr;
        p->next = height;
        p = p->next;
    }
    return head;
}
/**Task 2: reverse the initial linked list.**/
kidNode *reverseKidList(kidNode *head)
{
    // Please implement task 2 here.

    kidNode *current = head;
    kidNode *prev = nullptr, *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

/**Task 3: line up the kids according to their heights in an ascending order.**/
kidNode *sortKidList(kidNode *head)
{
    int swapped;
    kidNode *lPtr;           // left pointer will always point to the start of the list
    kidNode *rPrt = nullptr; // right pointer will always point to the end of the list
    do
    {
        swapped = 0;
        lPtr = head;
        while (lPtr->next != rPrt)
        {
            if (lPtr->height > lPtr->next->height)
            {
                int temp = lPtr->height;
                lPtr->height = lPtr->next->height;
                lPtr->next->height = temp;
                swapped = 1;
            }
            lPtr = lPtr->next;
        }

    rPrt = lPtr;

    } while (swapped);
    return head;
}

int main()
{
    int kid_num;

    do
    {
        cout << "===========================================" << endl;
        cout << "Please input the number of kids in the class (no more than 20) or enter an alphabet to exit:" << endl;
        cin >> kid_num;
        if (cin.fail())
            return 0;

        if (kid_num <= 0 || kid_num > 20)
        {
            cout << "Invalid number! Please input a number again." << endl;
            continue;
        }

        kidNode *initial_line_head = createKidList(kid_num, MIN_HEIGHT, MAX_HEIGHT);

        cout << endl;
        cout << "Output:" << endl;
        cout << "The initial list of kids' heights is:" << endl;
        printLinkedList(initial_line_head);

        kidNode *reversed_line_head = reverseKidList(initial_line_head);
        cout << "The reversed list of kids' heights is:" << endl;
        printLinkedList(reversed_line_head);

        kidNode *sorted_line_head = sortKidList(reversed_line_head);
        cout << "The ascending list of kids' heights is:" << endl;
        printLinkedList(sorted_line_head);
    } while (true);

    return 0;
}