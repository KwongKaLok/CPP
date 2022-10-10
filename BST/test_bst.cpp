#include <iostream> /* File: test-bst.cpp */
using namespace std;
#include "bst.h"
#include "print.cpp"
#include "insert.cpp"

int main()
{
    BST<int> bst;
    while (true)
    {
        char choice;
        int value;
        cout << "Action: d/f/i/m/M/p/q/r/s "
             << "(deep-cp/find/insert/min/Max/print/quit/remove/shallow-cp): ";
        cin >> choice;

        switch (choice)
        {
        case 'd': // Deep copy
        {
            BST<int> *bst2 = new BST<int>(bst);
            bst2->print();
            delete bst2;
        }
        break;

        case 'i': // Insert a value
            cout << "Value to insert: ";
            cin >> value;
            bst.insert(value);
            break;

        case 'p': // Print the whole tree
        default:
            cout << endl;
            bst.print();
            break;
        case 'q': // Quit
            return 0;

        case 's': // Shallow copy
        {
            BST<int> bst3{std::move(bst)};
            bst3.print();
            bst.print();
        }
        break;
        }
    }
}
