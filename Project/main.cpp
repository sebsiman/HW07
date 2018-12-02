/*
    Programmer : Angel Saldivia
                 Sebastian Siman
                 Glorimar Alonso
                 Chabeli Castano

    Date : 12/3/2018
    Description : Hangman Game
*/

#include <iostream>
#include <iomanip>      //for cout manipulation
#include <fstream>      //for file reading
#include <ctime>        //for computer time
#include <cstdlib>      //for rand
#include <stdlib.h>     //for system("csl")

using namespace std;

//Different States of the Hangman
void stateDead();
void stateOneLeg();
void stateBothArms();
void stateOneArm();
void stateBody();
void stateHead();
void stateStart();

//Function to switch the different states
void hangmanStates(int counter);

//Function to see if the char answer is repeated or not
bool repeated(char alphabet[], char guess);

//Function to check if the user won or lost
void winOrLose(int counter, string secretWord);

//Display menu
void startMenu();

//Safe Cin for char and ints
void cinSafe(int &choice);
void cinSafe(char &choice);

//Check alphabet and letters that have been picked already
void tempString(char alphabet[], char guess);

//Check how many words each file has
int arrInitialize(string fileName);

//Fill a word array with each word from the file
void arrFiller(string fileName,string arr[],int siz);

//get a random number between 0 and maxSize
int randIndx(int maxSize);

// With the help of the previous function, pick a random word from the file
string wordPicker(string fileName);

//create a char array were each char is one letter of secretWord
void wordArrCreator(char wordArr[],string secretWord);

//create a char array to compare with our previous arr. The user will see this and it will display the correct letters that the user guesses
void guessArrCreator(char secret[], int siz);

//cout the guessArr we created before so the user can see it
void coutWord(char guessArr[],int siz);

//check the letter guess of the user and see if it is correct
void checkGuess(char originalArr[], char secretArr[], int siz, char guess, int &counter);

//bool condition to determine if the player already won or not
bool winCondition (char guessArr[], int siz, int counter);

//Actual game were all of the functions unite
void hangMan(string fileName);

//Constant string that will be use to determine the files name and location.
const string ANIMALS = "Animals.txt";
const string CARS = "Cars.txt";
const string COUNTRIES = "Countries.txt";
const string FRUITS= "FruitsAndVegetables.txt";
const string SPORTS= "Sports.txt";

int main()
{
    int choice;             //int to store the users choice
    do
    {
        startMenu();        //display menu
        cinSafe(choice);    //cin safely choice
        switch(choice)      //Switch the choice and pick the right game
        {
            case 1:
            {
                //clear console
                system("cls");
                cout << "Guess an Animal!" << endl;
                hangMan(ANIMALS);   //Play hangMan with the file attached to the const Animals
                break;
            }
        case 2:
            {
                //clear console
                system("cls");
                cout << "Guess a Car!" << endl;
                hangMan(CARS);      //same as before but with a different file
                break;
            }
        case 3:
            {
                //clear console
                system("cls");
                cout << "Guess a Country!" << endl;
                hangMan(COUNTRIES); //same as before but with a different file
                break;
            }
        case 4:
            {
                //clear console
                system("cls");
                cout << "Guess a Fruit or Vegetable!" << endl;
                hangMan(FRUITS);    //same as before but with a different file
                break;
            }
        case 5:
            {
                //clear console
                system("cls");
                cout << "Guess a Sport!" << endl;
                hangMan(SPORTS);    //same as before but with a different file
                break;
            }
        case 6:                     //case 6 the user wants to quit the game
            {
                cout << "Thanks for playing COP 1334 Hangman" << endl
                     << "Have a nice day!" << endl;
                break;
            }
        default:                    //in case of an invalid numerical answer
            {
                cout << "Invalid Choice" << endl
                     << "Please enter a number between 1 and 6." << endl;
                break;
            }
        }
    }while(choice != 6);            //repeat everything until the user wants to quit
}
/*
     Function   :   cinSafe
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   choice (int) byReference

     Returns    :   void
*/
void cinSafe(int &choice) //for int
{
    //cin with defensive programing
    while(!(cin>>choice))
    {
        cout << "Wrong data type, please enter only numbers" << endl;
        cout << "Enter your choice again: ";
        cin.clear();
        cin.sync();
    }
}
/*
     Function   :   cinSafe
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   choice (char) byReference

     Returns    :   void
*/
void cinSafe(char &choice) //for char
{
    string cinString;
    cout << "Enter your letter guess: ";
    do
    {
        cin >> cinString;
        cin.clear();
        cin.sync();
        //check if the user introduced more than one char
        if(cinString.size()>1)
        {
            cout << "Please enter only one character at a time" << endl;
            cout << "Enter your choice again: ";
            cin.clear();
            cin.sync();
        }
        //check if the input is alpha or not
        else if(!isalpha(cinString[0]))
        {
            cout << "Please enter only letters" << endl;
            cout << "Enter your choice again: ";
            cin.clear();
            cin.sync();
        }
        //if everything else is fine that means the user inputed one correct char
        else
        {
            //store that char into choice
            choice = cinString[0];
        }
    //keep on going until we get a right answer.
    }while((cinString.size()>1) || (!isalpha(cinString[0])));
}
/*
     Function   :   startMenu
     Programmer :   *PUT YOUR NAME HERE*

     Date       :   12/3/2018
     Parameters :

     Returns    :   void
*/
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
    cout << "Your Choice: ";
}
/*
     Function   :   arrInitialize
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   fileName(string) byValue

     Returns    :   void
*/
int arrInitialize(string fileName)
{
    int siz = 0;
    ifstream iFile;     //for file reading
    string variable;    //to store each word
    iFile.open(fileName.c_str());   //open file

    //Defensive programming, if the file is not found display...
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
        //until the end of file
        while (!iFile.eof())
        {
            //get one line of the text and store it into variable
            getline(iFile, variable);
            //increment siz
            siz++;
        }
    iFile.close();
    //return the amount of lines in the file
    return siz;
}
/*
     Function   :   arrFiller
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   fileName(string) byValue
                    arr[] (string) Array
                    siz (int) byValue

     Returns    :   void
*/
void arrFiller(string fileName,string arr[],int siz)
{
    //The same as the last function but in this case we fill the string arr[] with each word in the list
    ifstream iFile;
    string variable;
    iFile.open(fileName.c_str());
    //Defensive programming
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
        for(int i = 0;i<siz;i++)
        {
            getline(iFile, variable);
            arr[i]= variable;
        }
    iFile.close();
}
/*
     Function   :   randIndx
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   maxSize(int) byValue

     Returns    :   void
*/
int randIndx(int maxSize)
{
    int randNum;
    unsigned seed = time(0);  // current time
    srand(seed);
    randNum = rand() % maxSize;
    return randNum;
}
/*
     Function   :   wordPicker
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   fileName(int) byValue

     Returns    :   string Arr
*/
string wordPicker(string fileName)
{
    //this function takes in the file name and will create a random array from the word list
    int maxSize = arrInitialize(fileName);
    string arr[maxSize];
    arrFiller(fileName, arr, maxSize);
    //after that it will return one random word from the array of words.
    return arr[randIndx(maxSize)];
}
/*
     Function   :   wordArrCreator
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   wordArr[] (char) Array
                    secretWord (string)

     Returns    :   void
*/
void wordArrCreator(char wordArr[], string secretWord)
{
    //separate each char of the word into a char array
    for (int i = 0; i<secretWord.size(); i++)
        wordArr[i] = secretWord[i];
}
/*
     Function   :   guessArrCreator
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   secret[] (char) Array
                    siz (int) byValue

     Returns    :   void
*/
void guessArrCreator(char secret[], int siz)
{
    //create a "secret" array, the size of the array created in word ArrCreator
    //and fill it with '_', this is the arr that the user will see
    for (int i = 0; i < siz; i++)
        secret[i] = '_';
}
/*
     Function   :   coutWord
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   guessArr[] (char) Array
                    siz (int) byValue

     Returns    :   void
*/
void coutWord(char guessArr[],int siz)
{
    //Display the guess array with the right format
    for(int i = 0;i<siz;i++)
        cout << guessArr[i] <<" ";
    cout << endl << endl;
}
/*
     Function   :   checkGuess
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   originalArr[] (char) Array
                    secretArr[] (char) Array
                    siz (int) byValue
                    guess (char) byValue
                    counter (int) byReference

     Returns    :   void
*/
void checkGuess(char originalArr[], char secretArr[], int siz, char guess, int &counter)
{
    int success = 0;
    for(int i=0;i<siz;i++)
    {
        if(originalArr[i] == guess)
        {
            secretArr[i]=originalArr[i];
            success++;
        }
        else if(originalArr[i]== toupper(guess))
        {
            secretArr[i]= toupper(originalArr[i]);
            success++;
        }
        else if(originalArr[i]== tolower(guess))
        {
            secretArr[i] = tolower(originalArr[i]);
            success++;
        }
    }
    if(success == 0)
        counter++;
}
/*
     Function   :   winConditions
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   guessArr[] (char) Array
                    siz (int) byValue
     Returns    :   bool
*/
bool winCondition(char guessArr[], int siz, int counter)
{
    int i = 0;
    if(counter == 7)
        return false;
    for(int i=0;i<siz;i++)
    {
        if(guessArr[i]!='_')
            i++;
        else
            return true;
    }
    if(i == siz)
        return false;

}
/*
     Function   :   tempString
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   alphabet[] (char) Array
                    guess (char) byValue
     Returns    :   void
*/
void tempString(char alphabet[], char guess)
{
    //for each letter in the alphabet check
    for(int i = 0; i < 26; i++)
    {
        //if guess is equal to the letter
        if(alphabet[i] == guess)
            alphabet[i] = ' ';
        //if guess is the UpperCase of the letter
        else if(alphabet[i]== toupper(guess))
            alphabet[i] = ' ';
        //if guess is the LowerCase of the Letter
        else if(alphabet[i]== tolower(guess))
            alphabet[i] = ' ';
    }
    //display the rest of the available letters
    cout << "Available characters: ";
    for(int i = 0; i < 26; i++)
        cout << alphabet[i] << " ";
    cout << endl;
}
/*
     Function   :   repeated
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   alphabet[] (char) Array
                    guess (char) byValue
     Returns    :   bool
*/
bool repeated(char alphabet[], char guess)
{
    //check each letter of the alphabet if it is repeated or not
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] == guess)
        {
            alphabet[i] = ' ';
            return false;
        }
        else if(alphabet[i]== toupper(guess))
        {
            alphabet[i] = ' ';
            return false;
        }
    }
    return true;
}
/*
     Function   :   winOrLose
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   counter (int) byValue
                    secretWord (string) byValue
     Returns    :   void
*/
void winOrLose(int counter, string secretWord)
{
    //if the counter is ==7 then the user lost the round
    if(counter == 7)
    {
        hangmanStates(counter);
        cout << "You lost" << endl
             << "The word was \"" << secretWord << "\"" << endl;
    }
    //if its less than 7 then he won
    else
    {
        cout << "Congratulations!" << endl
             << "You guessed correctly the word \"" << secretWord << "\"" << endl;
    }
}
/*
     Function   :   hangMan
     Programmer :   Angel Saldivia

     Date       :   12/3/2018
     Parameters :   filename (string) byValue
     Returns    :   void
*/
void hangMan(string fileName)
{
    //this function has all of the logic and merge of functions of the actual game
    char guess = '0';
    //array of char displaying the alphabet
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    //initialize the counter at state 1
    int counter = 1;
    //create the secret word by using wordPicker
    string secretWord = wordPicker(fileName.c_str());
    //create a char array were we are going to store the word with size secretWord.size()
    char wordArr[secretWord.size()];
    //same as before but with the array that the user is going to use and see
    char guessArr[secretWord.size()];
    //fill word arr with wordArrCreator
    wordArrCreator(wordArr, secretWord);
    //fill word arr with guessArrCreator
    guessArrCreator(guessArr,secretWord.size());
    //do the following untill the round ends
    do
    {
        //display the correct hangman state
        hangmanStates(counter);
        //display the guess array
        coutWord(guessArr,secretWord.size());
        //display the alphabet and any missing letters
        tempString(alphabet, guess);
        //safely take in guess
        cinSafe(guess);
        //as long as the lettered entered is repeated do the following
        while(repeated(alphabet,guess))
        {
            cout << "You already entered \"" << guess << "\" before" << endl;
            cinSafe(guess);
        }
        //if its not repeated then check the guess and see if its good or not, also make any modifications needed to the array
        checkGuess(wordArr,guessArr,secretWord.size(),guess,counter);
    }while(winCondition(guessArr,secretWord.size(),counter));    //if the user wins or loses get out of the loop
    //display if the user won or lost
    winOrLose(counter, secretWord);
    string i;
    cout << "Press enter to continue...";
    getline(cin,i);
    cin.sync();
    cin.clear();
    //clear console
    system("cls");
}
/*
     Function   :   hangMan
     Programmer :   Sebastian Siman
                    Chabeli Castano
     Date       :   12/3/2018
     Parameters :   counter (int) byValue
     Returns    :   void
*/

void hangmanStates(int counter)
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
