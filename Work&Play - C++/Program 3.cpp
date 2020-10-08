/* ------------------------------------------------
 *
 * Class: Program #3 for CS 141, Fall 2019
 * System: Codio
 * Author: jazlin Vera & Fareeha Rahman
 * Lab: Mon 4pm & Tues 11am
 *

*/
#include <iostream>
#include <string>
#include <fstream>      // For file input
#include <vector>		// For dictionary vector
#include <iomanip>		// For setw()
#include <cctype>       // For tolower()
using namespace std;

// looks up word in dictionary
long binarySearch(
            string searchWord,            // word to be looked up
            vector< string> dictionary);   // the dictionary of words
//---------------------------------------------------------------
// Function 1:
// Display ID info
// Kept it the Professor's name to pass the checks

void displayIdInfo()
{
     cout << "\n"
         << "Program #3: Work Play\n"
         << "Author: Dale Reed\n"
         << "Lab: Tues 8am\n"
         << "System:  Codio\n"
         << "\n";
    
}//end displayIDInfo()


//-----------------------------------------------------------------------------------------
// Function 2:
// This chart displays the number of words by word length found in the dictionary

void displayOfChart()
{
   cout << "Total number of words in dictionary file: 235886\n"
        << "\n"
        << "Word lengths where there are more than 1400 words:\n"
        << "Length  How Many\n"                                                                                                             
        << "------  --------\n"                                                                                                             
        << "    3      1420\n"                                                                                                             
        << "    4      5272\n"                                                                                                             
        << "    5     10230\n"                                                                                                            
        << "    6     17706\n"                                                                                                           
        << "    7     23869\n"                                                                                                             
        << "    8     29989\n"                                                                                                              
        << "    9     32403\n"                                                                                                              
        << "   10     30878\n"                                                                                                              
        << "   11     26013\n"                                                                                                              
        << "   12     20462\n"                                                                                                              
        << "   13     14939\n"                                                                                                              
        << "   14      9765\n"                                                                                                              
        << "   15      5925\n"                                                                                                              
        << "   16      3377\n"                                                                                                              
        << "   17      1813\n" 
        << "\n";
       
}

//-----------------------------------------------------------------------------------------
// Function 3: 

// This function reads the words from the file dictionary into here.
// First parameter reads words with a specifc length
/* Second parameter is a vector string for the dictionaray, used a vector because it can
easily change in size and the words from the dictionaray can be easily accessed */

void readInWordsFromFile(int lengthOfWordsToUse, vector<string> &dictionary)
{
	ifstream inputFileStream;
    string fileName = "dictionary.txt"; // C string (array of char) to store filename
    string inputWord;				    // stores each word as it is read

	// Open input file
	inputFileStream.open( fileName.c_str() );
	    
   // Verify that the open worked
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << fileName << "  Exiting..." << endl;
        exit( -1);
}

	// Read all the words from the file, and display them
    while( inputFileStream >> inputWord) {
       if(inputWord.size() == lengthOfWordsToUse){
         for(int i=0; i < lengthOfWordsToUse;i++)
          {
           inputWord[i] = tolower(inputWord[i]);
          }
          dictionary.push_back(inputWord);
      } 
  }
    inputFileStream.close();    // Close the input file.
}

//-----------------------------------------------------------------------------------------
// Function 4:
// this deals with case 2, same parameters as Function 3

void indexOfWords(vector<string> dictionary, int lengthOfWordsToUse)
{  
   //variables
   int startIndex;
   int endIndex;
   
   // asks the user what number they want to start the index and end it and then stores into the variables
   cout << "Enter the start and end index values of words to display: ";
   cin >> startIndex; 
   cin >> endIndex;
   cout << "About to display dictionary words from" << startIndex << "to" << endIndex << endl;
    
   // For loop starts with the number user put in, and then increments the number and the word stored
   // in the dictionaray unitl it reaches the endIndex
   for(int i = startIndex; i <= endIndex; i++)    
   {
       cout << setw(lengthOfWordsToUse) << i << "  " << dictionary.at(i) << endl;
   }
    
}

//-----------------------------------------------------------------------------------------
// Function 5:
/* deals with case 3, user choses a starting and ending word or a random word and the word 
changes from the first word to the end word */
// The 1st and 4th are same parameters as function 3,4
// 2nd and 3rd parameter are variables defined in main, also used in function 6,7,8

void GetNewWords(vector<string> dictionary, string &startWord, string &endWord, int lengthOfWordsToUse)
{
    
  while(true)
    {
      -  
      cout << "Enter starting word, or 'r' for a random word:";
      cin >> startWord;
      // if the user inputs r, randomly find a word from the dictionary
      if (startWord.compare ("r") == 0) {
          int randomNumber = rand () % dictionary.size();
          startWord = dictionary[randomNumber];
          break;
      }
      
      // if user inputs exit, then exit the program
      else if (startWord.compare ("exit") == 0) {
          cout << "Exiting program.";
          return;
      }
      //***Park: The fourth case should be come first. 
      //           else if(startWord.size() != lengthOfWordsToUse) {  
      //                    cout << "   *** '" << startWord << "' is not of length " << lengthOfWordsToUse  << ". Please retry." << endl <<endl;         
      //                    continue;
      //                }
      //            else if (binarySearch(startWord, dictionary)== -1) {
      //                    cout << "  *** '" << startWord << "' is not in the dictionary. Please retry." <<endl << endl;
      //                    continue;
      //                }    
      //                
      //            If this is the case, you will pass all test cases. 
      // if user puts in an unknown word, that is not in the dictionary, an error message pops up
      else if (binarySearch(startWord, dictionary)== -1) {
          cout << "  *** '" << startWord << "' is not in the dictionary. Please retry." <<endl << endl;
          //***Park: Try not to put all comments that are not related to the code execution and and their comments. 
          //cout << "   *** '" << startWord << "' is not of length " << lengthOfWordsToUse  << ". Please retry." << endl <<endl;
          continue;
      }
      
      // if the length of the word user inputs is not 3, error messaage pops up
      else if(startWord.size() != lengthOfWordsToUse) {  
          cout << "   *** '" << startWord << "' is not of length " << lengthOfWordsToUse  << ". Please retry." << endl <<endl;         
          continue;
      }
      
      else { break; }
} // closes while loop
    
  cout << endl;
    
  while(true)
   {
      cout << "Enter ending word, or 'r' for a random word: ";            
      cin >> endWord;
      // if the user inputs r, randomly find a word from the dictionary
      if (endWord.compare("r") == 0) {
          int randomNumber = rand () % dictionary.size();
          endWord = dictionary[randomNumber];
          break;
      }
      
      // if user inputs exit, then exit the program
      else if (endWord.compare ("exit") == 0) { 
          return;
      }
      
      // if user puts in an unknown word, that is not in the dictionary, an error message pops up
      else if (binarySearch(startWord, dictionary)== -1) {           
          cout << "   *** '" << startWord << "' is not in the dictiory. Please retry." <<endl << endl;
          continue;
      }
      
      // if the length of the word user inputs is not 3, error messaage pops up
      else if(startWord.size() != lengthOfWordsToUse) {  
          cout << "   *** '" << startWord << "' is not of length " << lengthOfWordsToUse  << ". Please retry." << endl <<endl;  
          continue;
      }
              
      else { break; }
      
  } // close while loop
    
  cout << endl;
          
} // close Function 5

//-----------------------------------------------------------------------------------------
// Funtion 6:
// deals with shifting the letters from startWord to the last input, by incrementing the letters one by one
// 2 parameters, 2nd one defined in main and used in other functions like 5,7,8

int countChange(string lastInput, string startWord){
  int count = 0;
  
  for(int i = 0; i < startWord.size(); ++i)
  {
      if(startWord[i] != lastInput[i]){         
          count++;   
      }// closes if statement
  }// closes for loop
    
  return count;
    
} // closes Function 6

//-----------------------------------------------------------------------------------------
// Function 7:
// deals with case 4 and shows what the previous word and the changed word are
void playtheWord(vector<string> dictionary, string startWord, string endWord, int lengthOfWordsToUse){
  
  // a do while loop to repeat the previous word and the next word it is changing it to
  int wordIndex = 1;
    
    do{
        // show error if the length of the startWord and endWord are 0
        if(startWord.length() == 0 || endWord.length() == 0) {
            cout << " *** You must first set start and end words.  Please retry. /n";

        }
        
        
        else {
            string lastInput = startWord;
            int count = 0;
    while (true) { 
        cout << wordIndex <<"."<< " Previous word is '" << lastInput <<"'.  Next word: " ;
        cin >> startWord;    
        
        if(startWord.compare ("exit") ==0) {
            return;
        }
        
        // error mesaage if the length of the word in not 3
        else if(startWord.size() != lengthOfWordsToUse) {
            cout <<endl;
            cout << "    *** '" << startWord <<"' is not of length 3.  Please retry. " << endl;  
            continue;
        }
        
        // error message if word is not in dictionary, you 
        else if(binarySearch(startWord, dictionary)== -1) {
             cout <<endl;
             cout << "    *** '" << startWord << "' is not in the dictionary. Please retry." <<endl ;
             continue;
         }
         // this calls Function 6 and shifts the letters one by one
         else{count = countChange(lastInput, startWord); }
         
         if(count > 1) {
             cout << "    ***'" << startWord <<"' must be exactly 1 character different.  Please retry.";  
         }
         // once they shift incremnets how many times it needs to and words = each other, print congrats
         else if(startWord == endWord) {
                 cout << "Congratulations, you did it!";
                 return;
         }
        
         else {
             lastInput = startWord;
             wordIndex++;    // increments the word index, so it can go through the loop 
         }

      }// end of while loop    
    } // end of else
 } // end of do loop
             
         

               
      while( startWord.compare(endWord) >= 0); {
      }
} // closes Function 7


//-----------------------------------------------------------------------------------------
// Function 8:
// deals with case 5 and 6 and prints out the words from case 4 and noe shows the user the process of the shifting
// uses multiple parameters that were seen in other Functions
// has a boolean parameter for a value of true and false
void FindSolution (vector<string> dictionary,vector<int> &sequenceWinningWordIndex, vector<string> &words, string startWord, string endWord, int lengthOfWordsToUse,bool text)
{    
    sequenceWinningWordIndex.clear();
    words.clear();
    
     if(startWord.length() == 0 || endWord.length() == 0)
     {
         cout << " *** You must first set start and end words.  Please retry. ";
     }
    
    // variables 
     string dictWord;
     words.push_back(startWord);  
     sequenceWinningWordIndex.push_back (-1);
    //***Park: a, b are not meaningful variable names for this case. currentIndex is more proper in this case. 
     int a = 0;
     int count = 0;
    
    // 2 for loops in a while loop (nested loop)
    // this loop essentially first shifts the word by the first letter,
    // then it takes the words found from the first shift and shifts the 
    // second letter of the word, then finally the second shifted words, shift
    // by the last letter, all these words printed are ordered and alphabetized
    while(a <= count)
     {    dictWord = words.at(a);
          if(text)
              cout << a << ". " << words.at(a) << ":  ";
         for(int b =0; b < dictWord.size();++b)
         {
             dictWord = words.at(a);
             for(char letter = 'a'; letter <= 'z'; letter++)
             {
                 dictWord.at(b) = letter;
                 
                 if(binarySearch(dictWord, dictionary)!= -1)
                 {
                     bool wordExists = false;
                     
                     for(int c = 0; c < words.size(); ++c)
                     {
                         if(words[c] == dictWord)
                             wordExists = true;
                     }
                     
                     if(!wordExists)
                     {
                         sequenceWinningWordIndex.push_back(a);
                         words.push_back(dictWord);
                         count++;
                         
                         if(text)
                              cout << count << ":" << dictWord <<" ";
                             
                     }
                     
                     if(endWord == dictWord) {
                         cout << endl;
                         sequenceWinningWordIndex.push_back(count);
                         cout << "Winning sequence was found!";
                         cout << endl;
                         return;
                     }
                      
                 } // end of if statment
                       
             } // end of for loop
         } // end of big for loop
         if(text)
             cout << endl;
             a++;
  
    } // end of while loop
} // end of Function 8


//-----------------------------------------------------------------------------------------   
// Function 9:

// deals with case 7 and reverses the order of the vector
void showSequence(vector<int> sequenceWinningWordIndex, vector<string>words ){
     int smt = sequenceWinningWordIndex.back();
        int i =0;
        
        cout << "Winning sequence in reverse order is:"<<endl;
    //a do loop to do the reverse order by incrementing from the last index
    do{
        if( i== smt){
            cout <<i << ". "<<words.at(i)<<endl;
            smt = sequenceWinningWordIndex.at(i);
                i=0;
        }
        else{
            i++;
        }
    } // end of do loop
    while (smt!=-1);

} // end Function 9  

//--------------------------------------------------------------------------------------
// Function 10:
// Use binary search to look up the search word in the dictionary vector, returning
// the word's index if found, -1 otherwise.

long binarySearch(
            string searchWord,            // word to be looked up
            vector< string> dictionary)
            {   // the dictionary of words
    long low, mid, high;     // array indices for binary search
    long searchResult = -1;  // Stores index of word if search succeeded, else -1
    
    // Binary search for word
        low = 0;
        high = dictionary.size() - 1;
        while ( low <= high)  {
        mid = (low + high) / 2;
        // SearchResult negative value means word is to the left, positive value means
        // word is to the right, value of 0 means word was found
        searchResult = searchWord.compare( dictionary[ mid] );
        if ( searchResult == 0)  {
            // Word IS in dictionary, so return the index where the word was found
            return mid;
        }
        else if (searchResult < 0)  {
            high = mid - 1; // word should be located before the mid location
        }
        else  {
            low = mid + 1; // word should be located after the mid location
        }
    } // end of while
    
    // Word was not found
    return -1;
}//end binarySearch()



//-----------------------------------------------------------------------------------------

int main()
{
    vector< string> dictionary;    		// Vector of dictionary words read in from file
    int lengthOfWordsToUse = 3;         // Default length of word to use in word transformation
    string startWord = "dog";           // The start word for transformation
    string endWord = "cat";             // The end word for transformation
    int menuOption = -1;   
    vector<int>sequenceWinningWordIndex;
    vector <string>words;// User menu option selection
  
    // Display ID info
    displayIdInfo(); 
   
    
    // Seed the random number generator
    srand( 1);  // Change 1 to time(0) for non-predictable results, but leave as 1 for testing
    displayOfChart();
    readInWordsFromFile(lengthOfWordsToUse, dictionary);

    // Menu display and handling infinite loop
    do {
        cout << "Currently we have " << dictionary.size() << " words of length "
             << lengthOfWordsToUse << " in the dictionary.\n"
             << "Changing from '" << startWord << "' to '" << endWord << "'" << endl
             << endl;
        
        cout << "Choose from the following options:\n"
             << "   1. Change the word length\n"
             << "   2. Display some dictionary words\n"
             << "   3. Get start and end words\n"
             << "   4. Play the word change game\n"
             << "   5. Find the end word with debug\n"
             << "   6. Find the end word\n"
             << "   7. Display an answer sequence\n"
             << "   8. Exit the program\n"
             << "Your choice ->"
             << " \n";
        cin >> menuOption;
        switch (menuOption){
            case 1:
                // Function 3
                cout << endl;
                cout <<"What length words do you want to use? ";
                cin >> lengthOfWordsToUse;
                cout << endl;
                dictionary.clear();
                readInWordsFromFile(lengthOfWordsToUse, dictionary);
                startWord = "";
                endWord = "";
                break;
                
            case 2: 
                // Function 4
                indexOfWords(dictionary, lengthOfWordsToUse);
                break;
                
            case 3:
                // Function 3 & 5
                GetNewWords(dictionary,startWord,endWord,lengthOfWordsToUse);
                dictionary.clear();
                readInWordsFromFile(lengthOfWordsToUse, dictionary);
                
                 if (startWord.compare("exit") == 0){
                     return -1;
                 }
                 break;
            
            case 4:
                // Function 7
                playtheWord(dictionary, startWord, endWord, lengthOfWordsToUse);
                break;
                
            case 5:
                // Function 8
                words.clear();
                FindSolution (dictionary,sequenceWinningWordIndex, words, startWord, endWord, lengthOfWordsToUse,  true);   
                break;
                
            case 6:
                // Function 8
                words.clear();
                FindSolution (dictionary,sequenceWinningWordIndex, words, startWord, endWord, lengthOfWordsToUse, false);
                break;
                
            case 7:
                // Function 9
                 showSequence(sequenceWinningWordIndex,words);
                break;
                
            case 8: 
                cout << "Exiting the program" << endl;
                break;
                } 
       
		
        
    } // ends do loop
    while( menuOption != 8);
       
	
    return 0;
    
}// ends the main loop