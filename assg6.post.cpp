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


using namespace std;

bool checkInput(char, char, char, char);

void promptUser(char &);

//void readInFile(string, string &, int &, int &, int[][][3]);

bool checkInput(char, char, char, char, char);

bool checkInput(string, string, string, string, string);

bool checkInput(string, string, string, string, string, string);

void manipOptions(char &);

void filterImageMenu(string &);

void greyScale();

void filterOut(string &, string, int &, int &, int &, int &);

void rotateImage();

void writeHTML(string[], int);

void generateRandomImage(string);











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
    int rowTop;
    int rowBottom;

    cout << "   ***** PHOTOSHOP *****" << endl;
    cout << endl;
    cout << endl;

    promptUser(userChoice);



    while(userChoice != quit)
    {
        if(userChoice == manipulateImage)
        {
            string magicNum; //FIXME: should i make a function and pass all of these by reference
            string line;
            int rows;
            int columns;
            int range;

            cout << "   Enter name of file you want to manipulate: ";
            cin >> fileName;
            cout << endl;

            ifstream inFile;
            inFile.open(fileName);

            inFile >> magicNum;
            cout << "   " << magicNum << endl;
            inFile >> columns;
            cout << "   " << columns << endl;
            inFile >> rows;
            cout << "   " << rows << endl;
            inFile >> range;
            cout << "   " << range << endl;

            int input[rows][columns][3];

            //while(!inFile.eof()) //FIXME: why doesn't this work
            //{

                for(int i = 0; i < rows; i++)
                {
                   // cout << "first loop" << endl;
                    for(int j = 0; j < columns; j++)
                    {
                       // cout << "second loop" << endl;
                        for(int x = 0; x < 3; x++)
                        {
                           // cout << "third loop" << endl;
                            if(!inFile.eof())
                            {
                               // cout << "if" << endl;
                                inFile >> input[i][j][x];
                                // cout << input[0][0][0];
                            }

                        } //x

                    } //j

                }
                 //} //i

            inFile.close();


//            ofstream outFile;
//            outFile.open("filterTest1.ppm");
//            outFile << magicNum << endl;
//            outFile << columns << "  ";
//            outFile << rows << endl;
//            outFile << range << endl;
//
//                for(int i = 0; i < rows; i++)
//                {
//                    for(int j = 0; j < columns; j++)
//                    {
//                        for(int x = 0; x < 3; x++)
//                        {
//                            outFile << input[i][j][x];
//                            outFile << endl;
//                        }
//                    }
//                }


 //             outFile.close();

            manipOptions(userManipChoice);

        if(userManipChoice == filterImage)
        {

                filterImageMenu(filterChoice);


                if(filterChoice == greyScale)
                {
                    int red;
                    int green;
                    int blue;
                    string fileNameG = "filterGreyScale.ppm";
                    ofstream outFile2;
                    outFile2.open(fileNameG);
                    outFile2 << magicNum << endl;
                    outFile2 << columns << "  ";
                    outFile2 << rows << endl;
                    outFile2 << range << endl;

                    for(int i = 0; i < rows; i++)
                    {
                        for(int j = 0; j < columns; j++)
                        {
                            red = input[i][j][0] * 0.3;
                            green = input[i][j][1] * 0.59;
                            blue = input[i][j][2] * 0.11;

                             outFile2 << ((red) + (green) + (blue));
                             outFile2 << endl;
                             outFile2 << ((red) + (green) + (blue));
                             outFile2 << endl;
                             outFile2 << ((red) + (green) + (blue));
                             outFile2 << endl;


                        } //j

                       // outFile2 << ((red) + (green) + (blue));

                    } //i

                    outFile2.close();

                    cout << "   File was saved as filterGreyScale.ppm " << endl;
                    cout << endl;

                    manipOptions(userManipChoice);


                }

                else if(filterChoice == filterOutRed)
                {
                    string fileNameR = "filterOutRed.ppm";
                    ofstream outFile;
                    outFile.open(fileNameR);
                    outFile << magicNum << endl;
                    outFile << columns << "  ";
                    outFile << rows << endl;
                    outFile << range << endl;

                    for(int i = 0; i < rows; i++)
                    {
                        for(int j = 0; j < columns; j++)
                        {
                            for(int x = 0; x < 3; x++)
                            {
                                if(x == 0)
                                {
                                    outFile << 0;
                                    outFile << endl;
                                } //if
                                else
                                {
                                    outFile << input[i][j][x];
                                    outFile << endl;
                                } //else
                            } //x
                        } //j
                    } //i


                    outFile.close();



                    cout << "   File was saved as filterOutRed.ppm " << endl;
                    cout << endl;

                    manipOptions(userManipChoice);


                } //filter out red



            } //filter

            else if(userManipChoice == cropImage)
            {

                cout << "   Enter Dimensions: ";
                cin >> rowTop;
                cin >> rowBottom;

//                cout << rowTop << endl;
//                cout << rowBottom << endl;

                cout << endl;

                ofstream outFileC;
                outFileC.open("croppedImage.ppm");
                outFileC << magicNum << endl;
                outFileC << columns << "  ";
                outFileC << rows - (rowTop + rowBottom) << endl;
                outFileC << range << endl;

                for(int i = rowTop; i < (rows - rowBottom); i++)
                {
                    for(int j = 0; j < columns; j++)
                    {
                        for(int x = 0; x < 3; x++)
                        {
                            outFileC << input[i][j][x];
                            outFileC << endl;

                        } //x

                    } //j

                }//i

                outFileC.close();

                cout << "   File was saved as croppedImage.ppm" << endl;
                cout << endl;

                manipOptions(userManipChoice); //FIXME: menu error???


            } //crop

            else if(userManipChoice == rotateImage)
            {
                ofstream outFileR;
                outFileR.open("rotatedImage.ppm");
                outFileR << magicNum << endl;
                outFileR << rows << " ";
                outFileR << columns << endl;
                outFileR << range << endl;

                for(int i = 0; i < columns; i++)
                {
                    for(int j = rows - 1; j >= 0; j--)
                    {
                        outFileR << input[j][i][0];
                        outFileR << endl;
                        outFileR << input[j][i][1];
                        outFileR << endl;
                        outFileR << input[j][i][2];
                        outFileR << endl;
                    }
                }

                outFileR.close();

                cout << "   File was saved as rotatedImage.ppm" << endl;
                cout << endl;

                manipOptions(userManipChoice);



//                outFileR << input[rows - 1][1][0];
//                outFileR << input[rows - 1][1][1];
//                outFileR << input[rows - 1][1][2];
//                outFileR << input[rows - 2][1][0];

            }

            else if(userManipChoice == 'q')
            {
                promptUser(userChoice);

            } //back to main menu

        } //manipulate image

        else if(userChoice == generateImage)
        {
            int numImg;
            cout << "   How many images do you want to generate? ";
            cin >> numImg;
           //string genFileName;
            string fileNames[numImg];

            for(int i = 0; i < numImg; i++)
            {
                string num = to_string(i);

                string genFileName = "generatedImage" + num + ".ppm";

                fileNames[i] = "generatedImage" + num + ".jpg";

                generateRandomImage(genFileName);
            }

            writeHTML(fileNames, numImg);

            cout << endl;

            promptUser(userChoice);
        } //generate image


    } //while the user doesn't choose quit



    return 0;
}

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

//void readInFile(string fileName, string &magicNum, int &rows, int &columns, int array[][][3])
//{
////
//}

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
    while(checkInput(filterChoice, "gs", "r", "b", "gr", "q") == false);
}

void greyScale();

void filterOut(string &filterChoice, string fileName, int &magicNum, int &columns, int &rows, int &range /*int &input[][][3]*/)
{
//    ofstream outFile;
//    outFile.open(fileName);
//    outFile << magicNum << endl;
//    outFile << columns << "  ";
//    outFile << rows << endl;
//    outFile << range << endl;
//
//    if(filterChoice == "r")
//    {
//         for(int i = 0; i < rows; i++)
//        {
//            for(int j = 0; j < columns; j++)
//            {
//                for(int x = 0; x < 3; x++)
//                {
//                    if(x == 0)
//                    {
//                        input[i][j][x] = 0;
//                        outFile << input[i][j][x];
//                        outFile << endl;
//                    } //if
//                    else
//                    {
//                        outFile << input[i][j][x];
//                        outFile << endl;
//                    } //else
//                } //x
//            } //j
//        } //i
//
//        outFile.close();
//
//    } //red

}

void cropImage();

void rotateImage();

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
    outFile << "  <p>" << endl;
    outFile << "   <ul>" << endl;

    for(int i = 0; i < numOfFiles; i++)
    {
        outFile << "    <li><a href = \"" + names[i] +"\"> Random Image " << i + 1 << "</a></li>" << endl;
    }

    outFile << "   </ul>" << endl;
    outFile << "  </p>" << endl;
    outFile << " </body>" << endl;
    outFile << "</html>" << endl;

    outFile.close();

}

void generateRandomImage(string fileName)
{

    int width = 255;
    int length = 300;
    ofstream outFile;

    outFile.open(fileName) ; //, ofstream::trunc);

    int r; //red
    int g; //green
    int b; //blue

  //  srand(time(0));

    outFile << "P3" << endl;
    outFile << width << " " << length << endl;
    outFile << "300" << endl;

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            r = rand() % 300 ;
            g = rand() % 300 ;
            b = rand() % 300 ;
         //   r = ((rand() % 300) + i)% 300; //i just made these formulas up
           //  = ((rand() % 300) + j) % 300;
            //b = ((i % j) * (i * j) % 300);

            outFile << r << endl;
            outFile << g << endl;
            outFile << b << endl;

        }
    }

   outFile.close();
}

