#include "bstmap.h"
#include <iostream>

using namespace std;

int main() 
{
    cout << "Create resume container for position: C++ developer." << endl;

    BSTMap<string, string> cppResume;

    cppResume.insert("James", "HKUST");
    cppResume.insert("Yang", "HKUST");
    cppResume.insert("Amelia", "CUHK");
    cppResume.insert("David", "HKU");
    cout << endl;
    cout << "Applicants of C++ developer: " <<  endl << cppResume << endl;

    cout << endl;
    cout << "Merge with C developers applications." << endl;
    cppResume.insert("Tony", "HKUST");
    cppResume.insert("Oliver", "PolyU");
    cppResume.insert("Wang", "CUHK");
    cout << "Applicants of C & C++ developer: " << endl << cppResume << endl;
    cout << "We have " << cppResume.size() << " candidates." << endl;

    cout << endl;
    cout << "Some candidates fail in the interview" << endl;
    cppResume.remove("Wang");
    cppResume.remove("David");
    cout << "The remaining C & C++ developer candidates: " << endl << cppResume << endl;
    cout << "We have " << cppResume.size() << " candidates." << endl;

    cout << endl;
    cout << "Create a backup of applications." << endl;
    BSTMap<string, string> cppResumeBackup;
    cppResumeBackup = cppResume;
    cout << "Backup applications: " << endl << cppResumeBackup << endl;


    const BSTMap<string, string>& constCppResume = cppResume;
    cout << endl;
    cout << "HR wants to search candidates' information" << endl;
    cout << "Oliver is graduated from " << constCppResume["Oliver"] << endl;
    cout << "Yang is graduated from " << constCppResume["Yang"] << endl;
    cout << "Amelia is graduated from " << constCppResume["Amelia"] << endl;

    cout << endl;
    cout << "Oh! HR accidentaly delete all the application forms" << endl;    
    cppResume.clear();
    cout << "We have " << cppResume.size() << " candidates." << endl;

    cout << endl;
    cout << "Don't worry, we have a backup. Let's see whether the information is correct." << endl;
    cout << "Amelia is still a candidate? " << (cppResumeBackup.contains("Amelia") ? "[Yes]" : "[No]") << endl;
    cout << "James is still a candidate? " << (cppResumeBackup.contains("James") ? "[Yes]" : "[No]") << endl;
    cout << "Wang is still a candidate? " << (cppResumeBackup.contains("Wang") ? "[Yes]" : "[No]") << endl;
    cout << "Tony is still a candidate? " << (cppResumeBackup.contains("Tony") ? "[Yes]" : "[No]") << endl;
    cout << "David is still a candidate? " << (cppResumeBackup.contains("David") ? "[Yes]" : "[No]") << endl;

    return 0;
}