#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, pair<string, string>& value) {
	return (os << "(" << value.first << ", " << value.second << ")");
}

#include "deque.h"


int main() {

    cout << "Create resume container for position: C++ developer." << endl;

    Deque<pair<string, string>> cppResume;
    pair<string, string> cppApplicant1 {"James", "HKUST"};
    pair<string, string> cppApplicant2 {"Yang", "HKUST"};
    pair<string, string> cppApplicant3 {"Amelia", "CUHK"};
    pair<string, string> cppApplicant4 {"David", "HKU"};

    cppResume.push_back(cppApplicant1);
    cppResume.push_back(cppApplicant2);
    cppResume.push_back(cppApplicant3);
    cppResume.push_back(cppApplicant4);
    cout << "Applicants of C++ developer: " <<  endl << cppResume << endl;


    cout << "Create resume container for position: C developer." << endl;

    Deque<pair<string, string>> cResume;
    pair<string, string> cApplicant1 {"Tony", "HKUST"};
    pair<string, string> cApplicant2 {"Oliver", "PolyU"};
    pair<string, string> cApplicant3 {"Wang", "CUHK"};

    cResume.push_back(cApplicant1);
    cResume.push_back(cApplicant2);
    cResume.push_back(cApplicant3);
    cout << "Applicants of C developer: " << endl << cResume << endl;

    cout << "Create resume container for position: AI researcher (experienced)" << endl;
    Deque<string> rResume;
    rResume.push_back("Michael");
    rResume.push_back("Noah");
    rResume.push_back("Isabella");

    cout << "Applicants of AI researcher (experienced): " << endl << rResume << endl;

    cout << "Reviewing resumes for C++ developer." << endl;
    cppResume.pop_front();
    cppResume.pop_front();
    cout << "Remaining resumes for C++ developer: " << endl << cppResume << endl;


    cout << "C++ developer position is closed, add resumes to C developer container." << endl;
    cout << "Applicants of C developer before adding: " << endl << cResume << endl;
    cResume = cResume + cppResume;
    cout << "Applicants of C developer after adding: " << endl << cResume << endl;

    cout << "Make a copy of AI researcher resumes." << endl;
    Deque<string> rResumeCopy;
    rResumeCopy = rResume;
    cout << "Copy of AI researcher resumes: " << endl << rResumeCopy << endl;

    cout << "Is the copy equivalent to the orign? " << endl << ((rResumeCopy == rResume)?"Yes":"No") << endl;
    rResume.pop_front();
    cout << "Is the copy still equivalent to the orign? " << endl << ((rResumeCopy == rResume)?"Yes":"No") << endl;

    return 0;
}