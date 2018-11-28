/* DISCLAIMER:
    If you guys have any questions about the code below just let me know, I will implement it to the code
    that you already finished by the end of this week. Also keep in mind that its filled with debug statements
    so dont worry about those
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void arrFiller(string fileName,string arr[],int siz);
int arrInitialize(string fileName);
int randIndx(int maxSize);
string wordPicker(string fileName);

int main()
{

    string secretWord = wordPicker("Animals.txt");
    string wordArr[secretWord.size()];
    for (int i = 0; i < secretWord.size(); i++)
        wordArr[i] = secretWord[i];
    for(int i = 0;i<secretWord.size();i++)
        cout << wordArr[i] <<endl;
    string guessArr[secretWord.size()];
    for(int i = 0;i<secretWord.size();i++)
        guessArr[i] = "_";
    for(int i = 0;i<secretWord.size();i++)
        cout << guessArr[i] <<" ";
}
int arrInitialize(string fileName)
{
    int siz = 0;
    ifstream iFile;
    string variable;
    iFile.open(fileName.c_str());

    // 1a. Defensive programming
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
        while (!iFile.eof())
        {
            getline(iFile, variable);
            siz++;
        }
    iFile.close();
    return siz;
}
void arrFiller(string fileName,string arr[],int siz)
{
    ifstream iFile;
    string variable;
     iFile.open(fileName.c_str());
    // 1a. Defensive programming
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
int randIndx(int maxSize)
{
    int randNum;
    unsigned seed = time(0);  // current time
    srand(seed);
    randNum = 1 + rand() % maxSize;
    return randNum;
}
string wordPicker(string fileName)
{
    //this function takes in the file name and will create a random array from the word list
    int maxSize = arrInitialize(fileName);
    string arr[maxSize];
    arrFiller(fileName, arr, maxSize);
    return arr[randIndx(maxSize)];
}
