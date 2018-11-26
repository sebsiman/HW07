#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

void ReadAnimals();
void ReadSports();
void ReadCars();
void ReadFruitsNVeggies();
void ReadCountries();

int main()
{



}

void ReadAnimals()
{
    int num = 0;
    ifstream iFile;
    string Animals;

     iFile.open("C:\\Users\\glorimar.alfonso001\\Desktop\\Ref Text Filea\\Animals.txt");

    // 1a. Defensive programming
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
    {
        for (int i = 0 ; i < 11 ; ++i)
        {
            while (!iFile.eof())
            {
                getline(iFile, Animals);
                cout << Animals << endl;
                num++;
            }
    }
}
cout << "There are this many animals: " << num << endl;
}

void ReadSports()
{
    int num = 0;
    ifstream iFile;
    string Sports;

     iFile.open("C:\\Users\\glorimar.alfonso001\\Desktop\\Ref Text Filea\\Sports.txt");

    // 1a. Defensive programming
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
    {
        for (int i = 0 ; i < 11 ; ++i)
        {
            while (!iFile.eof())
            {
                getline(iFile, Sports);
                cout << Sports << endl;
                num++;
            }
    }
}
cout << "There are this many Sports: " << num << endl;
}

void ReadCars()
{
    int num = 0;
    ifstream iFile;
    string Cars;

     iFile.open("C:\\Users\\glorimar.alfonso001\\Desktop\\Ref Text Filea\\Cars.txt");

    // 1a. Defensive programming
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
    {
        for (int i = 0 ; i < 11 ; ++i)
        {
            while (!iFile.eof())
            {
                getline(iFile, Cars);
                cout << Cars << endl;
                num++;
            }
    }
}
cout << "There are this many Cars: " << num << endl;
}

void ReadFruitsNVeggies()
{
 int num = 0;
    ifstream iFile;
    string FruitsAndVegetables;

     iFile.open("C:\\Users\\glorimar.alfonso001\\Desktop\\Ref Text Filea\\FruitsAndVegetables.txt");

    // 1a. Defensive programming
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
    {
        for (int i = 0 ; i < 11 ; ++i)
        {
            while (!iFile.eof())
            {
                getline(iFile, FruitsAndVegetables);
                cout << FruitsAndVegetables << endl;
                num++;
            }
        }
    }
    cout << "There are this many Fruits and Vegetables: " << num << endl;
}

void ReadCountries()
{
    int num = 0;
    ifstream iFile;
    string Countries;

     iFile.open("C:\\Users\\glorimar.alfonso001\\Desktop\\Ref Text Filea\\Countries.txt");

    // 1a. Defensive programming
    if (!iFile)
    {
        cout << "Trouble locating the file." << endl;
        cout << "Exiting..." << endl;
    }
    else
    {
        for (int i = 0 ; i < 11 ; ++i)
        {
            while (!iFile.eof())
            {
                getline(iFile, Countries);
                cout << Countries << endl;
                num++;
            }
        }
    }
cout << "There are this many Countries: " << num << endl;
}
