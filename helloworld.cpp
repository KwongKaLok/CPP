#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

void displayIntro();
void prompt(char guess[], int n);
bool gaveOver(char guess[], char right[]);
char convertToColor(int num);

// #######################################################
int main(void)
{
    char symbol;
    char guess[4];
    char right[4];
    bool playAgain = true;
    bool won;
    int numGuesses;
    
    displayIntro();
    
    while (playAgain) {
          won = false;
          numGuesses = 10;
          
          cout << endl;
          // generate the correct random sequence
          srand(time(0));
          for (int i = 0; i < 4; i++)
          {
              int temp = (rand() % 6) + 1;
              right[i] = convertToColor(temp);
              cout << right[i] << " ";
        }
        cout << endl;

        // loop until the user gets the right value    
        while (!won && numGuesses > 0)
        {
              prompt(guess, numGuesses);
              won = gaveOver(guess, right);
              numGuesses--;
        }
                          
        if (won)
        {
           cout << "You win! The correct sequence was " << right[0] << " "
                << right[1] << " " << right[2] << " " << right[3] << endl;
        }
        else
        {
            cout << "You lost! The correct sequence was " << right[0] << " "
                 << right[1] << " " << right[2] << " " << right[3] << endl;
        }
           
        cout << "Would you like to play again (Y or N): ";    
    
        cin >> symbol;
           
        playAgain = (symbol == 'Y' || symbol == 'y') ? true : false;
    }
    
    return 0;
} // end main

// #######################################################
bool gaveOver(char guess[], char right[])
{
     int totalRight = 0;
     int rightColor = 0;
     int grab;
     bool exclude[4];
     bool excludeColor[4];
     bool inList = false;
     
     for (int i = 0; i < 4; i++)
     {
         exclude[i] = false;
         excludeColor[i] = false;
     }
     
     // loops to determine which have both the correct color and position
     for (int i = 0; i < 4; i++)
     {
         if (guess[i] == right[i])
         {
            totalRight++;
            exclude[i] = true;
         }
     }
     
     // loops to determine if any colors are correct, just in the wrong position
     for (int i = 0; i < 4; i++)
     {
         if (!exclude[i])
         {
            for (int j = 0; j < 4; j++)
            {
                if (!exclude[j] && i != j)
                {
                   if ((guess[i] == right[j]) && !excludeColor[j]) 
                   {
                      inList = true;
                      grab = j;
                   }
                }
            }
            
            if (inList)
            {
                cout<<grab<<endl;
               rightColor++;
               inList = false;
               excludeColor[grab] = true;
            }
         }
         
         
         
     }
     
     if (totalRight == 4)
        return true;
     else 
     {
        cout << totalRight << ", " << rightColor << endl;
        return false;
     }
          
} // end gameOver


// #######################################################
void prompt(char guess[], int n)
{
    
    
     cout << "Enter your guess (" << n << "): ";
     
     cin >> guess[0] >> guess[1] >> guess[2] >> guess[3];
     
     
     for (int i = 0; i < 4; i++)
     {
         if (guess[i] > 91) // lower case level
            guess[i] = guess[i] - 32;
     }
     
} // end prompt

// #######################################################
char convertToColor(int num) 
{
     switch (num)
     {
            case 1:
                 return static_cast<char>(66);
            case 2:
                 return static_cast<char>(71);
            case 3:
                 return static_cast<char>(79);
            case 4:
                 return static_cast<char>(80);
            case 5:
                 return static_cast<char>(82);
            case 6:
                 return static_cast<char>(89);
     }
} // end convertToColor

// #######################################################
void displayIntro()
{    
    cout << "======================= Welcome to Mastermind =======================" << endl;
    cout << "Mastermind is a game of logic." << endl;
    cout << "The goal is to use logic to guess the correct four color combination" << endl;
    cout << "by using your previous guesses as clues." << endl;
    cout << "Everytime you guess, you will be told how close to the goal you are." << endl;
    cout << "The first number says how many were in the right place. " << endl;
    cout << "The second number says how many of the right colors you have in the wrong place.";
    cout << "To guess, enter the first letter of each color." << endl;
    cout << "Available colors are Blue, Green, Orange, Purple, Red and Yellow." << endl;
    cout << "An sample guess would be look like this: R R G B" << endl;        
    cout << "====================================================================="; 
}