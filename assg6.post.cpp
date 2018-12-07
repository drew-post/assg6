//Drew Post
//A04842758
//CS1428 Fall 2018
//Assg 6


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <cstdlib>


using namespace std;


const int MAXCOLUMNS = 500; //global variable to help pass arrays into functions


bool checkInput(char, char, char, char); //checks the input of the promptUser function to make sure it's valid (used in main menu)

void promptUser(char &); //prompts user with main menu

string getFileName(); //gets file name from user

bool readinSize(string &, string &, int &, int &, int &); //reads in the size of the file in order to create the appropriate sized array for readInFile

void readInFile(const string &, int &, int &, short input[][MAXCOLUMNS][3]); //reads in file to manipulate

bool checkInput(char, char, char, char, char); //checks input to make sure its valid, overloaded to account for the various numbers of input (used in manip menu)

bool checkInput(string, string, string, string, string, string); //checks input to make sure its valid, overloaded to account for the various numbers of input (used in filter menu)

void manipOptions(char &); //prompts user with manipulation options menu

void filterImageMenu(string &); //prompts user with filter image menu

void filterOut(string &, string, string &, int &, int &, int &, short input[][MAXCOLUMNS][3]); //filters out RGB and filters greyscale

void rotateImage(string &, int &, int &, int &, short input[][MAXCOLUMNS][3]); //rotates image clockwise

void getCropDimensions(int &, int &, int &, int &); //gets dimensions the user wants to crop off of the picture

void cropImageByRow(string &, int &, int &, int &, int &, int &, short input[][MAXCOLUMNS][3]); //crops image by rows on the top and bottom

void writeHTML(string[], int); //writes the HTML file for generating random images

void generateRandomImage(string); //generates random images


//FIXME: memory issue






int main()
{
    srand(time(0));
    char userChoice;
    char userManipChoice;
    char quit = 'q';
    string quitS = "q";
    char manipulateImage = 'm';
    char generateImage = 'g';
    char filterImage = 'f';
    char cropImage = 'c';
    char rotateI = 'r';
    string greyScale = "gs";
    string filterOutRed = "r";
    string filterOutGreen = "gr";
    string filterOutBlue = "b";
    string filterChoice;
    string fileName;
    int rowTop;
    int rowBottom;

    cout << endl;
    cout << "   ***** PHOTOSHOP *****" << endl;
    cout << endl;
    cout << endl;

    promptUser(userChoice); //main menu



    while(userChoice != quit) //while the user doesn't want to quit the program
    {
        if(userChoice == manipulateImage) //if the user wants to manipulate image
        {
            fileName = getFileName(); //sets fileName to what the user inputs

            string magicNum; //magicNum, rows, columns, and range all need to be passed by reference in almost all the functions, so they needed to be declared in main
            int rows;
            int columns;
            int range;

            readinSize(fileName, magicNum, rows, columns, range); //read in the size of the image

            short input[rows][MAXCOLUMNS][3]; //create an array that will hold the values, used short to save memory

            readInFile(fileName, rows, columns, input); //assign values to array

            manipOptions(userManipChoice); //display manipulation menu options

            while(userManipChoice != quit) //while the user doesn't want to quit the manipulation menu
            {
                if(userManipChoice == filterImage) //if the user wants to filter the image
                {

                    filterImageMenu(filterChoice); //displays filter menu options


                    if(filterChoice == greyScale) //if the user wants greyscale
                    {
                        filterOut(filterChoice, "filterGreyScale.ppm", magicNum, columns, rows, range, input); //make image greyscale

                    } //greyscale

                    else if(filterChoice == filterOutRed)
                    {
                        filterOut(filterChoice, "filterOutRed.ppm", magicNum, columns, rows, range, input); //filter out red in image

                    } //filter out red

                    else if(filterChoice == filterOutGreen)
                    {
                        filterOut(filterChoice, "filterOutGreen.ppm", magicNum, columns, rows, range, input); //filter out green in image

                    } //filter out green

                    else if(filterChoice == filterOutBlue) //filter out blue in image
                    {
                        filterOut(filterChoice, "filterOutBlue.ppm", magicNum, columns, rows, range, input); //filter out blue in image

                    } //filter out blue

                    else if(filterChoice == "s")
                    {
                        filterOut(filterChoice, "filterSepia.ppm", magicNum, columns, rows, range, input);
                    }


                } //filter

                else if(userManipChoice == cropImage) //if the user wants to crop the image
                {
                    getCropDimensions(rowTop, rowBottom, rows, columns); //get dimensions for cropping

                    cropImageByRow(magicNum, rows, columns, range, rowTop, rowBottom, input); //crop image by row


                } //crop

                else if(userManipChoice == rotateI) //if the user wants to rotate the image
                {

                    rotateImage(magicNum, rows, columns, range, input); //rotate image clockwise

                } //rotate

               manipOptions(userManipChoice); //keeps the menu running until the user wants to exit to the previous menu

            } //while

        } //manipulate image

        else if(userChoice == generateImage) //if the user wants to generate random images
        {
            int numImg;
            cout << "   How many images do you want to generate? ";
            cin >> numImg; //get how many images the use wants to generate
            string fileNames[numImg]; //array of file names in jpg to prepare for the .html file

            for(int i = 0; i < numImg; i++)
            {
                string num = to_string(i + 1); //convert i value to string

                string genFileName = "generatedImage" + num + ".ppm"; //use num value to create appropriate picture names

                fileNames[i] = "generatedImage" + num + ".jpg"; //assign .jpg versions of images to array

                generateRandomImage(genFileName); //generate images
            }

            writeHTML(fileNames, numImg); //write the .html file using the fileNames array
            /*the html file has an example image to demonstrate an example of what the image could look like after someone
            manually changes the random .ppm images to .jpg images */

            cout << endl;

        } //generate image

        promptUser(userChoice); //keeps the main menu running until the user says to quit

    } //while the user doesn't choose quit



    return 0;
}

bool checkInput(char choice, char option1, char option2, char option3) //used in promptUser
{
    if(choice != option1 && choice != option2 && choice != option3) //if the user doesn't pick any of the options
    {
        cout << "   * Invalid Input * " << endl;
        cout << endl;
        return false;
    }
    else //if it's right return true
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
        cin.clear();
        cin.ignore(1024, '\n'); //makes sure that if someone enters random stuff the program won't crash
        cout << endl;
    }
    while(checkInput(userChoice, 'm', 'g', 'q') == false); //keep prompting the user until they enter something valid



}

string getFileName()
{
    string tempFile;
    cout << "   Enter name of file you want to manipulate: ";
    cin >> tempFile; //puts it in a temporary variable before assigning it to the real one in main
    cout << endl;

    ifstream inFile;
    inFile.open(tempFile);

    while(!inFile) //while the file doesn't exist
    {
        inFile.close(); //close invalid file stream

        cout << "   ** File not there **" << endl;
        cout << endl;
        cout << "   Enter new file: ";
        cin >> tempFile;
        inFile.open(tempFile); //open the user's replacement file
        cout << endl;
    }

    inFile.close(); //if it exists, close file

   return  tempFile; //return file name that's valid
}

bool readinSize(string &fileName, string &magicNum, int &rows, int &columns, int &range)
{
    ifstream inFile;
    inFile.open(fileName); //opened with constructor

    inFile >> magicNum; //read in standard info
    inFile >> columns;
    inFile >> rows;
    inFile >> range;

    inFile.close();

    while(columns > MAXCOLUMNS || magicNum != "P3" || !inFile) //error checking: if the image is too large, it's not a .ppm file, or the file doesn't exist
    {
        inFile.close();
        if(columns > MAXCOLUMNS)
        {
            cout << "   ** Image too large **" << endl;
        }
        else if(magicNum != "P3")
        {
            cout << "   ** Invalid Image **" << endl;
        }
        else if(!inFile)
        {
            cout << "   ** File not there **" << endl;
        }

        cout << endl;

        fileName = getFileName(); //change file name
        inFile.open(fileName);

        inFile >> magicNum; //read in standard info
        inFile >> columns;
        inFile >> rows;
        inFile >> range;
    }

    inFile.close();

    return true;
}

void readInFile(const string &fileName, int &rows, int &columns, short input[][MAXCOLUMNS][3])
{
    ifstream inFile;
    inFile.open(fileName); //opened file

    string filler;
    getline(inFile, filler);
    getline(inFile, filler);
    getline(inFile, filler); //skip standard information since we're reopening the file from the beginning


     for(int i = 0; i < rows; i++) //put image information into 3D array
    {
        for(int j = 0; j < columns; j++)
        {
            for(int x = 0; x < 3; x++)
            {
                if(!inFile.eof()) //if the file is still open
                {
                    inFile >> input[i][j][x]; //put number into array
                }

             } //x

        } //j

    }//i

    inFile.close();

}

bool checkInput(char choice, char option1, char option2, char option3, char option4) //used for manipulation menu
{
    if((choice != option1) && (choice != option2) && (choice != option3) && (choice != option4)) //if the user input doesn't match given options
    {
        cout << "   * Invalid Input * " << endl;
        cout << endl;
        return false;
    }
    else //if the user enters a valid option
    {
        return true;
    }
}

bool checkInput(string choice, string option1, string option2, string option3, string option4, string option5, string option6) //used for filter menu
{
    if((choice != option1) && (choice != option2) && (choice != option3) && (choice != option4) && (choice != option5) &&(choice != option6)) //if the user input doesn't match given options
    {
        cout << "   * Invalid Input * " << endl;
        cout << endl;
        return false;
    }
    else
    {
        return true; //if the user enters a valid option
    }
}

void manipOptions(char &userManipChoice)
{
    char tempChoice; //using temporary array to be validated before changing anything in main
    do //prompt the user until the user enters a valid option
    {
        cout << "   Filter [ f ]" << endl;
        cout << "   Crop [ c ]" << endl;
        cout << "   Rotate [ r ]" << endl;
        cout << "   Quit [ q ]" << endl;
        cout << endl;
        cout << "   Pick One: ";
        cin >> tempChoice;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << endl;

    }
    while(checkInput(tempChoice, 'f', 'c', 'r', 'q') == false);

    userManipChoice = tempChoice ;
}

void filterImageMenu(string &filterChoice)
{
    string tempChoice; //using temporary array to be validated before changing anything in main
    do //prompt the user until the user enters a valid option
    {
        cout << "   Grey-scale [ gs ]" << endl;
        cout << "   Red [ r ]" << endl;
        cout << "   Blue [ b ]" << endl;
        cout << "   Green [ gr ]" << endl;
        cout << "   Sepia [ s ]" << endl;
        cout << "   Quit [ q ]" << endl;
        cout << endl;

        cout << "   Pick one: ";
        cin >> tempChoice;
        cin.clear(); //makes sure to only get what i want it to get vs. a bunch of other unwanted characters
        cin.ignore(1024, '\n');
        cout << endl;
    }
    while(checkInput(tempChoice, "gs", "r", "b", "gr", "s", "q") == false);

    filterChoice = tempChoice;
}

void filterOut(string &filterChoice, string fileName, string &magicNum, int &columns, int &rows, int &range, short input[][MAXCOLUMNS][3])
{
    ofstream outFile;
    outFile.open(fileName);
    outFile << magicNum << endl; //put all standard info into output file
    outFile << columns << "  ";
    outFile << rows << endl;
    outFile << range << endl;

    if(filterChoice == "r") //if the user chooses red, make all the red codes 0
    {
         for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                for(int x = 0; x < 3; x++)
                {
                    if(x == 0) //if the code is a red code, make it black
                    {
                        outFile << 0; //writing straight to the file so the array doesn't get passed differently after each manipulation
                        outFile << endl;
                    } //if
                    else
                    {
                        outFile << input[i][j][x]; //if it's blue or green, write out as is
                        outFile << endl;
                    } //else
                } //x
            } //j
        } //i

        outFile.close();

         cout << "   File was saved as filterOutRed.ppm " << endl;
         cout << endl;

    } //red


    if(filterChoice == "gr") //if the user chooses green, make all the green codes 0
    {
         for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                for(int x = 0; x < 3; x++)
                {
                    if(x == 1) //if the code is green make it black
                    {
                        outFile << 0;
                        outFile << endl;
                    } //if
                    else
                    {
                        outFile << input[i][j][x]; //if it's red or blue write as is
                        outFile << endl;
                    } //else
                } //x
            } //j
        } //i

        outFile.close();

        cout << "   File was saved as filterOutGreen.ppm " << endl;
        cout << endl;

    } //green


      if(filterChoice == "b") //if the user chooses blue, make all the blue codes 0
    {
         for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                for(int x = 0; x < 3; x++)
                {
                    if(x == 2) //if the color code is blue make it black
                    {
                        outFile << 0;
                        outFile << endl;
                    } //if
                    else //if it's red or green write as is
                    {
                        outFile << input[i][j][x];
                        outFile << endl;
                    } //else
                } //x
            } //j
        } //i

        outFile.close();

        cout << "   File was saved as filterOutBlue.ppm " << endl;
        cout << endl;

    } //blue

    if(filterChoice == "gs") //if the user picks greyscale
    {
        int red; //stores colors after they've been modified for gs
        int green;
        int blue;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++) //use formula to make all greyscale
            {
                red = input[i][j][0] * 0.3;
                green = input[i][j][1] * 0.59;
                blue = input[i][j][2] * 0.11;

                outFile << ((red) + (green) + (blue)); //since it's taking 3 elements and making them one element, the function prints 3 times in order to adjust
                outFile << endl;
                outFile << ((red) + (green) + (blue));
                outFile << endl;
                outFile << ((red) + (green) + (blue));
                outFile << endl;


            } //j

        } //i

        outFile.close();

        cout << "   File was saved as filterGreyScale.ppm " << endl;
        cout << endl;

    } //greyscale

        if(filterChoice == "s") //if the user picks sepia
    {
        int red; //stores colors after they've been modified for sepia
        int green;
        int blue;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++) //use formula to make sepia
            {
                red = input[i][j][0];
                green = input[i][j][1];
                blue = input[i][j][2];

                outFile << ((red * 0.393) + (green * 0.769) + (blue * 0.189));
                outFile << endl;
                outFile << ((red * 0.349) + (green * 0.686) + (blue * 0.168));
                outFile << endl;
                outFile << ((red) * 0.272 + (green * 0.534) + (blue * 0.131));
                outFile << endl;


            } //j

        } //i

        outFile.close();

        cout << "   File was saved as filterSepia.ppm " << endl;
        cout << endl;

    }



}

void getCropDimensions(int &rowTop, int &rowBottom, int &rows, int &columns)
{
    int tempTop; //using temp variables to check input before making changes to variables used in main
    int tempBottom;

    cout << "   Enter Dimensions: ";
    cin >> tempTop; //first num entered represents rows off the top
    cin.ignore();
    cin >> tempBottom; //second num entered represents rows off the bottom
    cin.ignore();
    cout << endl;

     if(tempTop > rows || tempBottom > rows) //checking if user input is within bounds of picture
    {
        do
        {
            cout << "   Rows cropped can't be bigger than rows in picture. Try again" << endl;
            cout << endl;
            cout << "   Enter Dimensions: ";
            cin >> tempTop; //first num entered represents rows off the top
            cin.ignore();
            cin >> tempBottom; //second num entered represents rows off the bottom
            cin.ignore();
            cout << endl;
        }
        while(tempTop > rows || tempBottom > rows);

    }

    rowTop = tempTop;
    rowBottom = tempBottom;


}

void cropImageByRow(string &magicNum, int &rows, int &columns, int &range, int &rowTop, int &rowBottom, short input[][MAXCOLUMNS][3])
{
    ofstream outFile;
    outFile.open("croppedImage.ppm");
    outFile << magicNum << endl; //print standard info
    outFile << columns << "  ";
    outFile << rows - (rowTop + rowBottom) << endl; //rows adjusted to fit crop
    outFile << range << endl;

    for(int i = rowTop; i < (rows - rowBottom); i++)
    {
        for(int j = 0; j < columns; j++)
        {
            for(int x = 0; x < 3; x++)
            {
                outFile << input[i][j][x]; //print only desired dimensions
                outFile << endl;

            } //x

        } //j

    }//i

    outFile.close();

    cout << "   File was saved as croppedImage.ppm" << endl;
    cout << endl;

}

void rotateImage(string &magicNum, int &rows, int &columns, int &range, short input[][MAXCOLUMNS][3])
{
    ofstream outFile;
    outFile.open("rotatedImage.ppm");
    outFile << magicNum << endl; //print standard info
    outFile << rows << " ";
    outFile << columns << endl;
    outFile << range << endl;


    for(int i = 0; i < columns; i++) //start with columns in outer loop
    {
        for(int j = rows - 1; j >= 0; j--) //print rows in reverse to rotate image
        {
            outFile << input[j][i][0];
            outFile << endl;
            outFile << input[j][i][1];
            outFile << endl;
            outFile << input[j][i][2];
            outFile << endl;
        }
    }

    outFile.close();

    cout << "   File was saved as rotatedImage.ppm" << endl;
    cout << endl;
}

void writeHTML(string names[], int numOfFiles)
{
    ofstream outFile;
    outFile.open("DrewPost.html");
    outFile << "<!DOCTYPE html>" << endl;
    outFile << "<html>" << endl;
    outFile << " <head>" << endl;
    outFile << "   <title> DrewPost.html </title>" << endl;
    outFile << " </head>" << endl;
    outFile << endl;
    outFile << " <body>" << endl;
    outFile << "  <h2 style=\"font-size:20px;\"> Random Images </h2>" << endl;
    outFile << "  <p>" << endl;
    outFile << "   <ul>" << endl;

    for(int i = 0; i < numOfFiles; i++)
    {
        outFile << "    <li><a href = \"" + names[i] +"\"> Random Image " << i + 1 << "</a></li>" << endl;
    }

    outFile << "   </ul>" << endl;
    outFile << "  </p>" << endl;
    outFile << "  <h3 style=\"font-size:20px;\"> Example Image </h3>" << endl;
    outFile << "   <p>" << endl;
    outFile << "   <ul>" << endl;
    outFile << "    <li><a href = \"generatedExample.jpg\"> Example Image </a></li>" << endl;
    outFile << "   </ul>" << endl;
    outFile << "   </p>" << endl;
    outFile << " </body>" << endl;
    outFile << "</html>" << endl;

    outFile.close();

    cout << endl;
    cout << "   HTML file called: DrewPost.html" << endl;

}

void generateRandomImage(string fileName)
{

    int width = 255;
    int length = 300;
    ofstream outFile;

    outFile.open(fileName);

    int r; //red
    int g; //green
    int b; //blue

    outFile << "P3" << endl; //writing out standard info
    outFile << width << " " << length << endl;
    outFile << "300" << endl;

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            r = rand() % 300; //randomly assigning colors to pixels
            g = rand() % 300;
            b = rand() % 300;

            outFile << r << endl;
            outFile << g << endl;
            outFile << b << endl;

        }
    }

   outFile.close();
}

