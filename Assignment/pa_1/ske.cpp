#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX_NUM_STU 20

// TASK1: Merge two files into a new file.
void mergeFile(const string ip_filename1, const string ip_filename2, const string op_filename)
{
    ifstream ifs1(ip_filename1);
    ifstream ifs2(ip_filename2);
    ofstream ofs(op_filename);
    char c;
    ifs1.get(c);
    while (!ifs1.eof())
    {
        ofs.put(c);
        ifs1.get(c);
    }
    ifs1.close();
    ofs.put('\n');
    ifs2.get(c);
    while (!ifs2.eof())
    {
        ofs.put(c);
        ifs2.get(c);
    }
    ifs2.close();
    ofs.close();
}

// TASK2: Clean a given file and save it to a new file.
void cleanFile(const string ip_filename, const string op_filename)
{
    ifstream ifs(ip_filename);
    ofstream ofs(op_filename);
    char c;
    int j = 0;
    string unwantedchar = "_$;'^*&(`)#^%!?:%- ";
    string marks = "";
    string name = "";
    bool unwanted = false;
    bool tab = false;
    bool nextline = false;
    ifs.get(c);
    while (!ifs.eof())
    {
        if (j > 2)
        {
            j = 0;
        }
        unwanted = false;
        for (int i = 0; i < unwantedchar.length(); i++)
        {
            if (c == unwantedchar[i])
            {
                unwanted = true;
                break;
            }
        }
        if (!unwanted)
        {
            if (c >= 48 && c <= 57)
            {
                if (name.length() > 0)
                {
                    ofs.put('\t');
                    name = "";
                }
                marks += c;
                ofs.put(c);
            }
            else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
            {
                if (marks.length() > 0)
                {
                    ofs.put('\n');
                    marks = "";
                }

                name += c;
                ofs.put(c);
            }
        }
        ifs.get(c);
    }
}

// TASK3: Analyze a file, that is, to find the two students who have got the lowest and the highest grade, respectively.
// If two or more students got the same lowest/highest grade, you only need to return the first-appeared ones.
void analyzeFile(const string filename, string &low_name, string &high_name, int &low_grade, int &high_grade)
{

    ifstream ifs(filename);
    string marks = "";
    string name = "";
    char c;
    string nameArr[12];
    int markArr[12];
    int markINT;
    int j = 0;
    ifs.get(c);

    for (int i = 0; i < 12; i++)
    {
        markArr[i] = 0;
    }

    while (!ifs.eof())
    {
        if (c >= 48 && c <= 57)
        {
            if (name.length() > 0)
            {
                nameArr[j] = name;
                name = "";
            }
            marks += c;
        }
        else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            if (marks.length() > 0)
            {

                markINT = stoi(marks);
                markArr[j] = markINT;

                marks = "";
                j++;
            }
            name += c;
        }

        ifs.get(c);
    }
    markArr[11] = stoi(marks);
    high_grade = markArr[0];
    low_grade = markArr[0];
    for (int i = 1; i < 12; i++)
    {
        if (low_grade > markArr[i])
        {
            low_grade = markArr[i];
            low_name = nameArr[i];
        }
        if (high_grade < markArr[i])
        {
            high_grade = markArr[i];
            high_name = nameArr[i];
        }
    }
}

// Display a given file.
void displayFile(const string filename)
{
    string temp;
    ifstream ifs(filename);
    if (!ifs)
    {
        cerr << "Error: Cannot open " << filename << endl;
        return;
    }

    cout << filename << endl;
    while (!ifs.eof())
    {
        getline(ifs, temp);
        cout << temp << endl;
    }
    cout << endl;
    ifs.close();
    return;
}

int main()
{
    string low_name, high_name;
    int low_grade = 0, high_grade = 0;

    displayFile("record1.txt");
    displayFile("record2.txt");

    mergeFile("record1.txt", "record2.txt", "record.txt");
    displayFile("record.txt");

    cleanFile("record.txt", "record_clean.txt");
    displayFile("record_clean.txt");

    analyzeFile("record_clean.txt", low_name, high_name, low_grade, high_grade);
    cout << low_name << " got the lowest grade: " << low_grade << endl;
    cout << high_name << " got the highest grade: " << high_grade << endl;

    return 0;
}