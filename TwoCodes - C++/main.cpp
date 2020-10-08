/* Prog4Two codes.cpp
*  Printing specific lines from the constitution by using
   different functions.
	Name: Fareeha Rahman and Nency Baxi
	Lab: Tuesdays at 9 am & Tuesdays at 8am
	Date: 3/23/20
*/

 #include <iostream>   // For Input and Output
 #include <fstream>	// For file input and output
 #include <cctype> 	// Allows using the tolower() function
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <vector>	 
 #include <ctype.h>
 #include <string>	 
 #include <cstring>
 using namespace std;
    
// This function reads every line from the constitution by looping through the file
// and storing all the lines in a vector string created called vecOfLines
void getLineFromFile(string linesFound, vector<string> &vecOfLines)
{
	// Open the Files
	ifstream inStream;
	inStream.open( "ConstitutionAndBillOfRights.txt");
    
	//  if statement opens if no text file found
	if( !inStream.is_open()) {
	// print this statement if no text from the constitution
	// is found.
 	cout << "Could not find .txt.  Exiting..." << endl;
 	exit( -1);
	}
    
	int counter = 0;
	while (getline(inStream, linesFound))
	{
	// if the linesFound length is greater than 1 then store that into a vector, intially
	//trying not to count lines that are blank
  	if(linesFound.length() > 1) {
    	vecOfLines.push_back(linesFound);
       	counter++;
  	}
	}
    
	//Close The File
	inStream.close();
 } // ends function
 
// created a function that takes userInput and converts into a lowercase by looping through
// each letter and calling the tolower option
// calls the lowercase function in the printLine function and in main
string lowerCase(string c)
{
 	int counter[26];
 	for (int i = 0; i < c.length(); i++)
 	{
     	c[i] = tolower(c[i]);
 	}
	return c;
    
} // ends function
    
// this function prints the line from the constitution that matches what the userInputted
// by looping through all the lines in the vector and uses the string function .find to find userInputtedWord
bool printLine(string linesFound, vector<string> &vecOfLines, string userInputWord, int &i) {
	for( int j=0; j<vecOfLines.size(); ++j)  {
  	string temp = lowerCase(vecOfLines[j]);
 	 
  	// if the word found is not equal to null then print out the line
   	// if the if condition is true, then return true.
  	if (temp.find(userInputWord) != string::npos) {
    	 
      	// displaying the contents of the line
     	cout << "Line " << j << ": " << endl;
     	cout << vecOfLines[j];
     	// make i=j becuase we manipulate i in the functions below
     	i=j;
    	return true;
  	}
	} // closes the for loop
    
	// If the if condition is not true, then return false.
	return false;
}// ends function

// This boolean function finds the previous line of the word that the user enters by taking the line j from above
// and drecrements it to find the appropiate output

bool readPreviousLine( vector<string> &vecOfLines, int &i )
{
	// If the line in the constitution is greater than 0, then decrement by 1.
	// It would return true as long as the below statement is true.
	if(i > 0) {
  	i--;
  	// Print out the line if it is found
  	cout << "Line " << i << ": " << endl;
  	cout << vecOfLines[i];
  	return true;
	}// ends if sttament
    
	// If there is no line found then this is what would print out.
	else {
  	cout<<"There is no previous file contents."<<endl;
  	return false;
	}
} // end function

// This boolean function finds the following line of the word that the user enters.
bool readFollowingLine(vector<string> &vecOfLines, int &i)
{
	// If the line in the constitution is less than (251)-1, then increment by 1.
	// Always returns true if the above condition is satisfied.
	if(i < vecOfLines.size()-1) {
  	i++; 	// Increment by 1
  	// Print out the line if it is found
  	cout << "Line " << i << ": " << endl;
  	cout << vecOfLines[i];
  	return true;
	}
	else {
  	// Print out this if no line is found from the constiturion.
  	cout<<"There is no following file contents."<<endl;
  	// Returns false if it's not true.
 	return false;
	}
}
// This function finds every line from the constitution that has a word or a phrase that matches what the user enters in.
void readOccurences(string linesFound, vector<string> &vecOfLines, string userInputWord, int &i )
{
	// loops through the vector just like the printLine function
	for( int j=0; j<vecOfLines.size(); ++j)  {

  	string temp = vecOfLines[j];
  	temp = lowerCase(vecOfLines[j]);      	// send the vector index to your lowerCase
 	 
  	// if the matching line is not equal to a null position then display the contents of the lines
  	if (temp.find(userInputWord) != string::npos) {
    	cout << "Line " << j << ": " << endl;
    	cout << vecOfLines[j];
    	i=j;
   } // ends if statement
 } // closes the for loops
} // ends function
int main()
{
	char menuOption;             	// Userinput for menu option
	char menuOptionNew;          	// Userinput for the second menu items
	char returnCharacter;
	string userInputWord= "";    	// the word or sentence the user enters in
	bool check = true;           	// used to exit the program
	string linesFound;           	// lines found from the file that match userIputted word
	int i;                       	// a variable tha represents the position of the line found
	vector<string> vecOfLines;   	// vector of strings  
    
	// cout the menu options
	cout << "Select from the following choices: \n"
	<< "	W  Enter word or phrase to find, and display enclosing text \n"
	<< "	X  Exit program \n"
	<< "Your choice: ";
    
   cin >> menuOption;
   returnCharacter = cin.get();
   
   // gets the line from vector
   getLineFromFile(linesFound,vecOfLines) ;
   
   // Prints out Exiting program if user inputs x or X.
   if((menuOption=='x') || (menuOption=='X'))
{
  	cout << "Exiting program." << endl;
  	exit( -1); }
 	 
   cout << endl << "Enter word or phrase: " << endl;
   // reads the userInputWord
   getline(cin, userInputWord);
   
   // make lowerCase function call here so that the userInput can be lowercased
   userInputWord = lowerCase(userInputWord);
   
   // calls print line function when user inputs in W
   if ((menuOption=='w') || (menuOption=='W')) {
  	printLine(linesFound,vecOfLines, userInputWord,i); }
 	 
	// while loop to get the menu options from below to repeat after user decided something  
   while(true){
   cout << "Select from the following choices: " << endl;
  	cout << endl << " W  Enter word or phrase to find, and display enclosing text " << endl;
  	cout << " P  Display previous text" << endl;
  	cout << " F  Display following text" << endl;
  	cout << " A  Display all occurrences of found word or phrase " << endl;
  	cout << " X  Exit program " << endl;
  	cout << "Your choice:" << endl;
  	cin >> menuOptionNew;
  	returnCharacter = cin.get();
 	 
  	// Print Exiting program if user enters x or X.
   	if((menuOptionNew=='x') || (menuOptionNew=='X')) {
     	cout << "Exiting program." << endl;
        	check = false;
        	exit( -1);
  	}
 	 
  	if((menuOptionNew=='w')|| (menuOptionNew=='W')) {
     	cout << endl << "Enter word or phrase: " << endl;
     	getline(cin, userInputWord);         	// Reads a line from the userInput
     	printLine(linesFound,vecOfLines, userInputWord, i);        	// Calling printLine function here

  	}
 	 
   	if((menuOptionNew=='p') || (menuOptionNew=='P')) {
     	// Calling PreviousLine function here
     	readPreviousLine(vecOfLines,i);
  	}
 	 
  	else if((menuOptionNew=='f') || (menuOptionNew=='F')) {
     	// Calling FollowingLine function here
     	readFollowingLine(vecOfLines, i);
  	}
 	 
  	else if((menuOptionNew=='a') || (menuOptionNew=='A')) {
     	// Calling readOccurences function here
     	readOccurences(linesFound,vecOfLines,userInputWord,i);
  	}
 	 
 	} // ends the while loop
	return 0;
	}
