#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>


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

bool checkInput(string choice, string option1, string option2, string option3, string option4, string option5)
{
    if(choice != option1 && choice != option2 && choice != option3 && choice != option4 && choice != option5)
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
        cout << "   Red [ r ]" << endl;
        cout << "   Blue [ b ]" << endl;
        cout << "   Green [ gr ]" << endl;
        cout << "   Quit [ q ]" << endl;
        cout << endl;

        cout << "   Pick one: ";
        cin >> filterChoice;
        cout << endl;
    }
    while(checkInput(filterChoice, "gs", "r", "b", "gr", "q"));
}

void greyScale();

void red();

void blue();

void green();

void cropImage();

void rotateImage();

void generateRandomImage(string fileName)
{
    int width = 255;
    int length = 300;
    ofstream outFile;
   outFile.open(fileName.c_str());

    int r; //red
    int g; //green
    int b; //blue

    srand(time(0));

    outFile << "P3" << endl;
    outFile << width << " " << length << endl;
    outFile << "300" << endl;

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            r = ((rand() % 300) + i) % 300; //i just made these formulas up
            g = ((rand() % 300) + j) % 300;
            b = ((i % j) * (i * j) % 300);

            outFile << r << endl;
            outFile << g << endl;
            outFile << b << endl;

        }
    }

   outFile.close();
}


int main()
{
    char userChoice;
    char userManipChoice;
    char quit = 'q';
    string quitS = "q";
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
    string fileName;
    string generatedImage1 = "generatedImage1.ppm";
    string generatedImage2 = "generatedImage2.ppm";
    string generatedImage3 = "generatedImage3.ppm";
    string generatedImage4 = "generatedImage4.ppm";
    string generatedImage5 = "generatedImage5.ppm";

    cout << "   ***** PHOTOSHOP *****" << endl;
    cout << endl;
    cout << endl;

    promptUser(userChoice);



    while(userChoice != quit || userManipChoice != quit || filterChoice != quitS)
    {
        if(userChoice == manipulateImage)
        {
            string magicNum; //should i make a function and pass all of these by reference
            string line;
            int rows;
            int columns;
            int range;

            cout << "   Enter name of file you want to manipulate: ";
            cin >> fileName;

            ifstream inFile; //why isn't it reading in the right thing for rows/columns
            inFile.open(fileName.c_str());
            inFile >> magicNum;
            inFile >> rows;
            inFile >> columns;
            inFile >> range;

            int input[rows][columns];

//            while(!inFile.eof) //why doesn't this work
//            {
//                for(int i = 4; i < rows; i++)
//                {
//                    for(int j = 4; j < columns; j++)
//                    {
//                        inFile >> input[i][j];
//                        cout << input[i][j];
//                    }
//                }
//            }


            manipOptions(userManipChoice);


            if(userManipChoice == filterImage)
            {

                filterImageMenu(filterChoice);

                if(filterChoice == greyScale)
                {

                }

            }

        } //manipulate image

        if(userChoice == generateImage)
        {
            cout << "   The HTML file name for these images is: post.html" << endl;
            cout << endl;
            cout << endl;

            generateRandomImage(generatedImage1); //why doesn't this work
            generateRandomImage(generatedImage2);
            generateRandomImage(generatedImage3);
            generateRandomImage(generatedImage4);
            generateRandomImage(generatedImage5);


            return 0;
        } //generate image

    } //while the user doesn't choose quit



    return 0;
}

