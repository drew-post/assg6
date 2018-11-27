#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool checkInput(char choice, char option1, char option2, char option3)
{
    if(choice != option1 && choice != option2 && choice != option3)
    {
        cout << "   * Invalid Input * " << endl;
        cout << endl;
        return false;
    }
    else
    {
        return true;
    }
}

void promptUser(char &userChoice)
{
    do
    {
        cout << "   Manipulate Image [ m ]" << endl;
        cout << "   Generate Image [ g ]" << endl;
        cout << "   Quit [ q ]" << endl;
        cout << endl;
        cout << "   Pick One: ";
        cin >> userChoice;
        cout << endl;
    }
    while(checkInput(userChoice, 'm', 'g', 'q') == false);



}

bool checkInput(char choice, char option1, char option2, char option3, char option4)
{
    if(choice != option1 && choice != option2 && choice != option3 && choice != option4)
    {
        cout << "   * Invalid Input * " << endl;
        cout << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool checkInput(string choice, string option1, string option2, string option3, string option4)
{
    if(choice != option1 && choice != option2 && choice != option3 && choice != option4)
    {
        cout << "   * Invalid Input * " << endl;
        cout << endl;
        return false;
    }
    else
    {
        return true;
    }
}

//void readInImage(string fileName, ifstream inFileofstream outFile, )
//{
    //ofstream outFile
    //cout << "Enter image file name: ";
    //cin >> fileName;
    //inFile.open(fileName);
    //outFile.open("result.ppm");
//}

void manipOptions(char &userManipChoice)
{
    do
    {
        cout << "   Filter [ f ]" << endl;
        cout << "   Crop [ c ]" << endl;
        cout << "   Rotate [ r ]" << endl;
        cout << "   Quit [ q ]" << endl;
        cout << endl;
        cout << "   Pick One: ";
        cin >> userManipChoice;
        cout << endl;

    }
    while(checkInput(userManipChoice, 'f', 'c', 'r', 'q') == false);
}

void filterImageMenu(string &filterChoice)
{
    do
    {
        cout << "   Grey-scale [ gs ]" << endl;
        cout << "   Filter out red [ r ]" << endl;
        cout << "   Filter out blue [ b ]" << endl;
        cout << "   Filter out green [ gr ]" << endl;
        cout << endl;

        cout << "   Pick one: ";
        cin >> filterChoice;
        cout << endl;
    }
    while(checkInput(filterChoice, "gs", "r", "b", "gr"));
}

void filterImage();

void cropImage();

void rotateImage();


int main()
{
    char userChoice;
    char userManipChoice;
    char quit = 'q';
    char manipulateImage = 'm';
    char generateImage = 'g';
    char filterImage = 'f';
    char cropImage = 'c';
    char rotateImage = 'r';
    string greyScale = "gs";
    string filterOutRed = "r";
    string filterOutGreen = "gr";
    string filterOutBlue = "b";
    string filterChoice;

    cout << "***** PHOTOSHOP *****" << endl;
    cout << endl;
    cout << endl;

    promptUser(userChoice);

    while(userChoice != quit)
    {
        if(userChoice == manipulateImage)
        {
            manipOptions(userManipChoice);

            if(userManipChoice == filterImage)
            {
                filterImageMenu(filterChoice);
               // readInImage();
            }

            if(userManipChoice == quit)
            {
                return 0;
            }
        }

    }



    return 0;
}
