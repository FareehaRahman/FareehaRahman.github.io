/* --------------------------------------------------------
 * prog2RallySongs.cpp
 *    Read political candidate's favorite song lyrics from a file.
 *    Choose random lines and see if the reader can identify the candidate.
 *
 *    This was inspired by the New York Times article:
 *       https://www.nytimes.com/interactive/2019/08/19/us/politics/presidential-campaign-songs-playlists.html
 *    which describes the different songs played at political rallies for
 *    different 2020 presidential candidates.
 *
 * Class: Program #2 for CS 141, Fall 2019
 * Lab: Tues 11am,
 * TA: 
 * System: Windows 10
 * Author: Fareeha Rahman
 */

#include <iostream>
#include <cctype>       // For the letter checking functions
#include <fstream>      // For file input
#include <iomanip>      // For setw
#include <cstdlib>      // For exit and abs
using namespace std;

// *** Yuwei: Incorrect level of indentation
    // Created a function to randommly generate the lines and passed a parameter thorough it so that one function can be used for both files
    void printRandomLines(string candidateName) {

    // Here is some sample code to open a file, read the number on the first line, and print it.
	ifstream inputFileStream;  // Declare the input file stream
    // Open input file and verify that file was found
    //string candidateName = "Trump.txt";
    inputFileStream.open( candidateName.c_str() );
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << candidateName << "  Exiting..." << endl;
        exit( -1);
    }

    // Read the number on the first line of the input file, which indicates how many subsequent
    // lines there are in the file.
    int numberOfLinesInFile = 0;
    inputFileStream >> numberOfLinesInFile;    
    
    //-------------------------------------------------- Sample Code above -------------------------------------------------------------------   
     
    // Random generator starts here
    
   
	string line;           
    int lineCounter = 1; // created variable to count the lines and started it at one so it skips the first line    
    int random = rand() % numberOfLinesInFile; // generates the random line
       
        while( getline(inputFileStream, line)){
           if(lineCounter == random) {
                if  ((line.size() == 0) || (line.at(0) == char('#')) || (line.at(0) == char(' '))) {
               // this if statement looks for the title lines or lines with an empty string, if it finds 
               // one it will continue and eventually hit the break and increment the line to go to the 
               // next. If it doesn't find a line that meets these conditions then it couts the random line
                   continue;
// *** Yuwei: Incorrect level of indentation                    
    }  
               else{    
                   cout << line << endl;
    }
               break;
              
    }// cloaes the first if statement
           lineCounter++;
            
    }// closes the while loop
           inputFileStream.close(); // closes the file
        
    }// closes the function

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
// *** Yuwei: Incorrect level of indentation
    // created another function for the quiz part and passed in parameters so that they can be changed. These 
    //variables are defined in the main and have an amper sign in front of them so that the computer knows these 
    //variables are the same not new ones created.
    
    void quizGame(int numberDisplayed, int &totalGames, int &numberOfCorrect, int &percentCorrect) {
        
        
        int userChose;    
        int randomNumber = (rand() % 2) + 1;
        
        //created a random variable so that a computer choses between 2 options. 1 option for trump and 1 for warren. 
        //if the computer randomly decides option 1 then it'll display Trump lines using the function above and if 
        //randomly decided option 2 then it'll display Warren's line.
        
        if (randomNumber == 1) {
            int count = 1;
            cout << "\n";
            while(count <= numberDisplayed) {
                printRandomLines("Trump.txt");
                count++; 
// *** Yuwei: Incorrect level of indentation                
    }
        
    }
    
        if (randomNumber == 2) {
            int count = 1;
            cout << "\n";
            while(count <= numberDisplayed) {
                printRandomLines("Warren.txt");
                count++;          
    }
            
    }
    
        cout << "\nEnter 1 for Trump, 2 for Warren:";
        cout << endl;
        cin >> userChose;
        
    // the above part ask the user who they think the lines belong to and they enter the number 1 or 2. If they enter 1 
    // and it matches up with the randomNumber the computer generated then it is correct and prints out a point for them
    // and a percent which is calculated by the total number of games played divded by how many they got right, multiplied by 100
    // if not correct then they don't get a point
    
        if (userChose == randomNumber) {
            numberOfCorrect++;
            percentCorrect = ((numberOfCorrect*100)/totalGames);
            cout << "\nCorrect! You got " << numberOfCorrect << " out of " << totalGames << " , which is " << fixed << setprecision( 0) << percentCorrect<< "%" << endl;
       
            cout << endl;
    }
        else{
            percentCorrect = ((numberOfCorrect*100)/totalGames);
            cout << "\n\nWrong! You got " << numberOfCorrect << " out of " << totalGames << " , which is " << percentCorrect << "%";
            cout << endl;
    }
       
}// end function
    


//-----------------------------------------------------------------------------------------------------------------------------------------
int main() {
	
	//Initialize the random number generator
    srand( 1);    // You must leave it as srand( 1) for the version you turn in.
	              // Change this to srand( time(0))  if you want it to be different every time.
	//cout << "A random value is: " << rand() << endl;
	
    
    // variables 
    char userInputCharacter = '0';
    int numberDisplayed = 3;
    int numberOfCorrect = 0;
    int totalGames = 0;
    int percentCorrect;
    
    
    // put all of my code in a while loop so that it prints out the menu option after every user input as long
    // as the user doesn't press 5, 5 = exits.
    
    while (userInputCharacter != '5') {
           // Display which program this is and display menu options to select program output to be displayed
        cout << endl
             << "---- Program 2: Rally Songs ----      \n"
             << "Select from the following:                 \n"
             << "   1. Set number of lines to display       \n"
             << "   2. Get random lines from Trump.txt      \n"
             << "   3. Get random lines from Warren.txt     \n"
             << "   4. Rally song quiz                      \n"
             << "   5. Exit the program                     \n"
             << "Your choice --> "
             << endl;
        cin >> userInputCharacter;

            // displays the number of lines desired
            if (userInputCharacter == '1') {
                cout << "Enter the number of lines you want to display ->";
                cin >> numberDisplayed;

       }

            // displayes Trump lines by calling the function and using his file
            // used a while loop so that it prints out atleast 3 lines or the number of lines user desires       
            else if (userInputCharacter == '2')  {
                int count = 1;
                cout << "\n";
                while(count <= numberDisplayed) {
                    printRandomLines("Trump.txt");
                    count++;          
        }
        }

            // displayes Warren lines by calling the function and using his file
            // used a while loop so that it prints out atleast 3 lines or the number of lines user desires 
            else if (userInputCharacter == '3')  {
                int count = 1;
                cout << "\n";
                while(count <= numberDisplayed) {
                    printRandomLines("Warren.txt");
                    count++;          
        }
        }

            // user plays quiz, quiz function is called with all its references. Total games played gets incremented
            // every time user plays
            else if( userInputCharacter == '4') {
                quizGame(numberDisplayed,++totalGames, numberOfCorrect, percentCorrect);
        }

            // exits the program and displays the score 
            else if( userInputCharacter == '5') {

                cout << "\nYou got " << numberOfCorrect << " out of " << totalGames << ", which is " << percentCorrect << "%" << endl;
                exit( -1);
        }

 }//end while loop
   
    return 0;
}//end main()
