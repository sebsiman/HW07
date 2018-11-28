#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void startMenu();
void userInput (int& choice);
void cinFail (int& choice);
void tempString(char alphabet[], char guess);
void stateStart();
void stateHead();
void stateBody();
void stateOneArm();
void stateBothArms();
void stateOneLeg();
void stateDead();
void hangmanStates();


int main()
{
    int choice; // menu selection
    char guess; // user guess at letter in word
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // bool attempt = true;

    startMenu();
    userInput(choice);
    tempString(alphabet, choice);
    hangmanStates();

}
void startMenu()
{
    cout << "Welcome to COP 1334 Hangman" << endl;
    cout << "Please choose from the following options:" << endl;
    cout << "1. Animals" << endl;
    cout << "2. Sports" << endl;
    cout << "3. Cars" << endl;
    cout << "4. Fruits and Vegetables" << endl;
    cout << "5. Countries" << endl;
    cout << "6. Exit" << endl;
    cout << "Your Choice:";
}

void userInput (int& choice)
{
    cin >> choice;
    cinFail(choice);
    while(choice < 1 || choice > 6)
    {
        cout << "Please enter a number between 1 and 6." << endl;
        cin >> choice;
        cinFail(choice);
    }
    cout << "Your choice: " << choice << endl;
}

void cinFail (int& choice)
{
    cout << "Please enter a number value." << endl;
    cin.clear();
    cin.sync();
    cin >> choice;
}

void tempString(char alphabet[], char guess)
{
    cout << "Available characters: ";
    for(int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }
    cout << endl;
    cin >> guess;
    for(int i = 0; i < 26; i++)
    {
        if(guess == alphabet[i])
        {
            alphabet[i] = ' ';
        }
    }
    cout << "Available characters: ";
    for(int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }

}

void hangmanStates()
{
    for(int counter = 1; counter < 8; counter++)
    {
        switch(counter)
        {
        case 1:
            stateStart();
            break;
        case 2:
            stateHead();
            break;
        case 3:
            stateBody();
            break;
        case 4:
            stateOneArm();
            break;
        case 5:
            stateBothArms();
            break;
        case 6:
            stateOneLeg();
            break;
        case 7:
            stateDead();
            break;
        }
    }
}

void stateStart()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateHead()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateBody()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |    |  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateOneArm()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateBothArms()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|\\ "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateOneLeg()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|\\ "<< endl
         <<"   |   /   "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateDead()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|\\ "<< endl
         <<"   |   / \\ "<< endl
         <<"   | You are Dead"<< endl
         <<"  ===============\n"
         << endl;
}
