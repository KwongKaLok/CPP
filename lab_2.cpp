// https://magisterrex.files.wordpress.com/2014/07/mastermindrules.pdf
// Cindy https://www.youtube.com/watch?v=dMHxyulGrEk

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    //Codemaker's choice of a random 4-color combination among six colors
    // 1 Yellow, 2 Orange, 3 black, 4 Green, 5 Blue, 6 Purple
    int p0 = rand() % 6 + 1; // 1 to 6
    int p1 = rand() % 6 + 1; // 1 to 6
    int p2 = rand() % 6 + 1; // 1 to 6
    int p3 = rand() % 6 + 1; // 1 to 6

    // variable for code breaker's guess
    int g0;
    int g1;
    int g2;
    int g3;

    // variable for codemaker's response
    // red: correct color and correct position
    // white: correct color but wrong position
    // red overrides white
    int redpin;
    int whitepin;

    //you may declare additional variables here  to help you solve the problem:
    bool color_position_correct_array[4];
    int color_correct_array[4];
    int breaker_array[4];
    int maker_array[4];
    bool win = false;
    bool debug = true;

    cout << "==============================" << endl;
    cout << "Welcome to the Mastermind Game" << endl;
    cout << "==============================" << endl;

    if (debug)
    {
        cout << "Coder maker's colors:" << endl;
        cout << "p0=" << p0 << "\tp1=" << p1 << "\tp2=" << p2 << "\tp3=" << p3 << endl
             << endl;
    }

    cout << "Code maker has made his choice." << endl;
    cout << "Code breaker, you have 12 attempts to crack his code." << endl;
    cout << "Game starts!" << endl
         << endl;

    // Write your code below this section:
    redpin = 0;
    whitepin = 0;
    maker_array[0] = p0;
    maker_array[1] = p1;
    maker_array[2] = p2;
    maker_array[3] = p3;

    for (int attempts = 0; attempts < 12; attempts++)
    {
        for (int i = 0; i < 4; i++)
        {
            color_position_correct_array[i] = false;
        }
        cout << "Attempt " << attempts + 1 << endl;
        cout << "Please input your guess: " << endl;
        cin >> breaker_array[0] >> breaker_array[1] >> breaker_array[2] >> breaker_array[3];

        for (int i = 0; i < 4; i++)
        {
            if (breaker_array[i] == maker_array[i])
            {
                color_position_correct_array[i] = true;
                redpin++;
            }
        }
        if (redpin == 4)
        {
            cout << "Red pins: " << redpin;
            cout << ", White pins: " << whitepin << endl;
            cout << " " << endl;
            cout << "Congratulations!\n";
            cout << "Coder maker's colors:\n";
            cout << "p0=" << breaker_array[0] << "\t"
                 << "p1=" << breaker_array[1] << "\t"
                 << "p2=" << breaker_array[2] << "\t"
                 << "p3=" << breaker_array[3] << "\n";
            cout << "You cracked the code with " << attempts + 1 << " attempts" << endl;
            win = true;
            break;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (!color_position_correct_array[i])
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (breaker_array[i] == maker_array[j] && !color_position_correct_array[j])
                        {
                            for (int k = 0; k < 4; k++)
                            {
                                if (breaker_array[i] == color_correct_array[k])
                                {
                                    break;
                                }
                                else
                                {
                                    color_correct_array[k] = breaker_array[i];
                                    whitepin++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            cout << "Red pins: " << redpin;
            cout << ", White pins: " << whitepin << endl;
            cout << " " << endl;
            redpin = 0;
            whitepin = 0;
        }
    }

    // Player runs out of attempts and loses
    if (!win)
        cout << "Sorry, you ran out of turns :( " << endl;

    return 0;
}