#include <iostream>
#include <string>

using namespace std;

int QA() {
    cout << "What do you want to check (1: Today's event, 2: History of HKUST, 3: Quit)? ";
    string reply;
    while (cin >> reply) {
        if (reply == "1") {
            cout << "Today's event" << endl;
        } else if (reply == "2") {
            cout << "History of HKUST" << endl;
        } else if (reply == "3") {
            break;
        } else {
            cout << "Please enter the number 1, 2 or 3 (1: Today's event, 2: History of HKUST, 3: Quit)" << endl;
        }

        // repeat the message
        cout << "What do you want to check (1: Today's event, 2: History of HKUST, 3: Quit)? ";
    }

    cout << "Have a nice day in HKUST!!!" << endl;

    return 0;
}