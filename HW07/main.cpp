#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void startMenu();
void userInput (int& choice);
void cinFail (int& choice);

int main()
{
    int choice;

    startMenu();
    userInput(choice);

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
         <<"   |   /|\ "<< endl
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
         <<"   |   /|\ "<< endl
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
         <<"   |   /|\ "<< endl
         <<"   |   / \ "<< endl
         <<"   | You are Dead"<< endl
         <<"  ===============\n"
         << endl;
}
