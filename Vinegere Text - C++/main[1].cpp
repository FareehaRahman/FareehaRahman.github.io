 
/* Prog3Vigenere.cpp
*   Encode/Decode using Vigenere cipher.
    Name: Fareeha Rahman and Nency Baxi
    Lab: Tuesdays at 9 am & Tuesdays at 8am
    Date: 3/5/20
*/
#include <iostream>   // For Input and Output
#include <fstream>  // For file input and output
#include <cctype>   // Allows using the tolower() function
#include <string.h>
#include <stdlib.h>
using namespace std;

// Global constants
const int NUMWORDS = 21735;   // the amount of words in the dictionary
const int LENWORDS = 81;      // the length of any array
const int BOOKSIZE = 93297;   // the amount of words in the secret agent file



/* This Function reads all the words from the dictionary and makes sure to only
   use words that are greater than three and makes sure to lower case any word
   that is uppercase */

int readWordsInFile(int &numberOfWords, char dictionary[NUMWORDS][LENWORDS] ) {
 // this section opens a file for reading and declares an input stream
    ifstream inStream;          
    inStream.open( "dictionary.txt");
//  variable created to find all the words that belong to our dictionary
    numberOfWords = 0;          

//  if statement opens if no text file found
    if( !inStream.is_open()) {
          cout << "Could not find dictionary.txt.  Exiting..." << endl;
          exit( -1);                }
          
      /* created two variables one that reads in each words from the dictionary and makes
      sure the max length is 81 and another variable that counts all the words that are
      greater than three */             
    char theWord[LENWORDS];  
    int counter = 0;
    
    // while loop that reads all the words into the file and stores it into a 2d array called dictionary
    // before storing it though, it finds the words greater than three and then lowercases any uppercase
    // letters by using a for loop to go through each letter
    // then increments the counter everytime they find a word greater than three
    while( inStream >> theWord) {
 
          if (strlen(theWord) >= 3) {
   
           for(int i=0; i<=strlen(theWord); i++) {
              theWord[i] = tolower(theWord[i]);
   }
           strcpy(dictionary[counter],theWord);
           counter++;
 }
}

// close the file
    inStream.close();

    cout << counter << " words of size >= 3 were read in from dictionary. " << endl;
    cout << endl;
    return counter;

}

// This function deals with case 1, when we have to read to see if it is in the dictionary
// We see it is in the dictionary by finding the middle of the dictionary and comparing that
// to what the userInputed.

bool binarySearch(char dictionary[NUMWORDS][LENWORDS], char searchWord[], int numWords)
{
  int low,mid,high;  // using these variables breaks down the search for us
  int searchResult;  // a variable created to see what strcmp couts
 
  // initializing low as the lowest positions and the high to highest position of words greater than three
  low = 0;
  high = numWords - 1;
 
  // loop through until the high and low are equal or until high is greater than high
  while ( low <= high)  {
      
      // finds the middle meaning average and compares it with the word found in the dictionary
      mid = (low + high) / 2;
      searchResult = strcmp(searchWord, dictionary[mid]);
     
     // if the searchResult prints out 0 means that strchr was true and that it found a match
      if ( searchResult == 0)  {
            return true;
   }
   
   // else keep looking by shortening the high and low until found    
    else if (searchResult < 0)  {
             high = mid - 1;  }
    else  {
           low = mid + 1; }
} // end of while

   // means word was not found in dictionary
   return false;
}

// This function basically reads in the line directly from the dictionary
// and it uses char placeHolder parameter to store in the array LENWORDS.
void readInAline(char placeHolder[LENWORDS],int &placeLen ) {
    // fgets reads maximum of num - 1 from a given stream and 
// stores them into an array stream
   fgets(placeHolder,81, stdin);
   placeLen = strlen(placeHolder);
   placeHolder[placeLen-1]='\0';
   placeLen = placeLen-1;
}
 
// this generate a key with the same length of the original text the user has inputted
void generateKey(int msgLen, int keyLen, char keyWord[81],char temp[81]) {
   int i;
   for(i=0 ; i < msgLen; i++){
      if( isalpha( keyWord[i])!= 0){
         keyWord[i] = tolower(keyWord[i]);
   }
   temp[i] = keyWord[i%keyLen];
 }
}

// This function is needed for case 2 of the program and it basically 
//takes in the text that needs to be coded and takes the keyword for 
//the vigenere encryption and it returns the keyword, plaintext and ciphertext.
void encryptText(int msgLen, int keyLen, char keyWord[LENWORDS], 
   char plainText[LENWORDS], char encryptedText[LENWORDS]) {
   int i;
   
   // iterated through each letter and change to new word
   for(i=0;  i< msgLen; ++i) {
      char c = plainText[i];
      // The isalpha checks for all lower case
      if( isalpha( c)!= 0){
         c = tolower(c);
         
         // formula for the encryptedText
         encryptedText[i] = (((c - 97) + (keyWord[i] - 97)) % 26)+97;
  }
      else {
         encryptedText[i] = c;
   }
    }
    // Checks the last character of the encryptedText 
    // and sets that character to null by using 
    // null terminator.
      encryptedText[i] = '\0';
      cout << encryptedText << endl;     
}
// This function is needed for case 3 of the program, and what if does is that 
// it takes in the cipher text that needs to be decoded
// and takes vigenere keyword and it prints out the decryptedText
void decodeText(int msgLen, int keyLen, char keyWord[LENWORDS], 
   char plainText[LENWORDS], char decryptedText[LENWORDS]) {
   int i;
   
   // iterate through each letter to undo what was in the funtion about
   for(i=0; i< msgLen; ++i) {
      char c = plainText[i];
      
      // To check if all are lowercase
      if( isalpha( c)!=0 && isalpha(keyWord[i])){
         c = tolower(c);
         decryptedText[i] = (abs((c - 97) - (keyWord[i] - 97) + 26)% 26)+97;
     }
       else {
         decryptedText[i] = c;
   }
  }
  // Checks the last character of the decryptedText 
    // and sets that character to null by using 
    // null terminator.
      decryptedText[i]='\0';
}
// This function basically counts every words
// from the dictionary by using a while loop.
int countWords(char plainText[LENWORDS], char keyWord[LENWORDS], char dictionary[NUMWORDS][LENWORDS], char searchWord[], int numWords, int msgLen) {
   
   // used to increment the number of words found in the dictionary and to find them we store in userInput into a temp array
   int numberOfWords = 0;
   char tempArray[LENWORDS];

   int i=0;
   int j=0;
   while (plainText[i] != '\0')
   {
         // read in each letter
         if (plainText[i] != ' ') {
            tempArray[j] = plainText[i];
         }
         j++;
         
         // stop reading in letters once you find a space or null which represent is to be a word
         if((plainText[i] == ' ') || (plainText[i] =='\0')) {
            tempArray[j-1]='\0';
             if (binarySearch(dictionary, tempArray, numWords) == true){
               numberOfWords++;
       }
       // sets the temp back to empty, so it could move on and find another a word
         for(int s=0; s<tempArray[j]; j--) {
            tempArray[s]='\0';        } // closes the for loop
         j=0;  } // closes the id statament
         i++;           
}// closes the while loop

  // if statment dealing with the last letter
   if((plainText[i] =='\0')) {
      tempArray[j]='\0';
      if (binarySearch(dictionary, tempArray, numWords) == true){
                numberOfWords++;
            }
 }
      return numberOfWords;

}
// This function is needed to do case 4 of the project,
// and it basically reads in every character by character
// from the secretAgent file and also 
// checks the words that needs to be extracted from the dictionary.
int readBookFile(int &numberOfWords, char dictionary[NUMWORDS][LENWORDS], 
char keyWord[LENWORDS],int msgLen, int keyLen, char encryptedText[LENWORDS], 
char decryptedText[LENWORDS], char temp[LENWORDS], char searchWord[], int numWords, char plainText[LENWORDS])
{
   // Reads the file "The secretAgentJosephConrad.txt". and opend it
   int totalNumberOfWords;
   ifstream inStream;   
   inStream.open( "TheSecretAgentByJosephConrad.txt");
   if( !inStream.is_open()) {
      cout << "Could not find dictionary.txt.  Exiting..." << endl;
      exit( -1);
      } // closes if
   
   // variable that reads in the words into the fille
   char autoDecodeWord[ 81];  
   int max=0;   // finds the greatest amount of numbers
   
   // loops through all the words and calls all the functions 
   for(int i=0; i<BOOKSIZE; i++) {
      inStream >> autoDecodeWord;
      
      //lower cases
      for(int i=0; i < strlen(autoDecodeWord); i++) {
         if( isalpha( autoDecodeWord[i])== 0){
            autoDecodeWord[i] = tolower(autoDecodeWord[i]); }}
            
    // lower cases
      for(int i=0; i < strlen(keyWord); i++) {
         if( isalpha( keyWord[i])== 0){
            keyWord[i] = tolower(keyWord[i]); }}
      
      // generate the key
      keyLen = strlen(autoDecodeWord);
      generateKey(msgLen,keyLen,autoDecodeWord,keyWord);
   
     // lower cases then decode the text
      for(int i=0; i < strlen(encryptedText); i++) {
         if( isalpha( encryptedText[i])!= 0){
          encryptedText[i] = tolower(encryptedText[i]);
    
           decodeText(msgLen,keyLen,keyWord,encryptedText,decryptedText);
        }
         else {
            encryptedText[i] = decryptedText[i];
       
    }
    }
    
       totalNumberOfWords = countWords(decryptedText, keyWord, dictionary, searchWord, numWords, msgLen);

// This if condition basically is checking the
//number of words that were found using keyword
      if(totalNumberOfWords > max) {
       cout<< totalNumberOfWords << " words found using keyword: " << autoDecodeWord << " giving:" << endl;
       cout << "   " << decryptedText <<endl;
       max=totalNumberOfWords;

   }
}
     // empties it
      for(int s=0; s<msgLen; s++) {
            encryptedText[s]='\0';
   }
// close the file
inStream.close();
}
//---------------------------------------------------------------------------
int main()
{
int numberOfWords = 0;
char dictionary[NUMWORDS][LENWORDS];
char searchWord[LENWORDS];
int numWords;
string startWord;         // The start word for transformation
// Declare variables
int menuOption;                 // Userinput for menu option

// Separately store the return character so cin.getline does not consider it the next user input
char plainText[LENWORDS];
char keyWord[LENWORDS];

// variable that holds the length of the keyword and the text
int msgLen = -1;// = strlen(plainText);
int keyLen = -1; // = strlen(keyWord);

char encryptedText[LENWORDS];
char decryptedText[LENWORDS];

char temp[LENWORDS];
char carriageReturn;
numWords = readWordsInFile(numberOfWords, dictionary);
// Display menu and handle menu options
cout << "Choose from the following options: \n"
     << "    1. Lookup dictionary word \n"
     << "    2. Encode some text  \n"
     << "    3. Decode some text  \n"
     << "    4. Auto-decode the ciphertext given with the assignment  \n"
     << "    5. Exit program  \n"
     << "Your choice: ";
cin >> menuOption;
carriageReturn = cin.get();
//returnCharacter = cin.get();  // Read and discard the return character at the end of the above input line.
// This is necessary because otherwise a subsequent cin.getline() reads it as
// an empty line of input.
switch( menuOption) {
  case 1: // Do dictionary lookup of a word and indicate whether or not it was found.
     cout << "Enter a word to be looked up in dictionary: ";
     cin >> searchWord;
 //    binarySearch(dictionary, searchWord, numWords, searchResult);
     if(binarySearch(dictionary, searchWord, numWords)) {
        cout << searchWord << " IS in the dictionary." << endl;
     }
     
     else{
        
        cout << searchWord << " is NOT in the dictionary." << endl;

     }
     break;
  case 2: // Encode some text
     cout << "Enter the text to be encoded: ";
     readInAline(plainText, msgLen);
     
     cout << "Enter a keyword for Vigenere encryption: ";
     readInAline(keyWord,keyLen);
    
     cout << "Keyword, plainText and ciphertext are:  \n";
     generateKey(msgLen,keyLen, keyWord, temp);
     
     // loops through the whole userInput
     for (int k = 0; k< msgLen; k++) {
         cout << temp[k];
     }
     cout << endl;
     
     // lowers the plainText
     for (int l = 0; l<msgLen; l++){
        if( isalpha(plainText[l])!= 0){
            plainText[l] = tolower(plainText[l]);
        }
     }
     cout << plainText<<endl;
     encryptText(msgLen,keyLen,temp,plainText,encryptedText);
   
     break;
  case 3: // Decode using user-entered values
 
     // gets userInput by calling our fgets function
     cout << "Enter the cipherText to be decoded: ";
     readInAline(plainText, msgLen);
     msgLen = strlen(plainText);
     
     // gets userInput by calling our fgets function
     cout << "Enter a Vigenere keyword to be tried: ";
     readInAline(keyWord, keyLen);
     keyLen = strlen(keyWord);
    
     // calls the functions
     generateKey(msgLen,keyLen, keyWord, temp);
     decodeText(msgLen,keyLen,temp,plainText,decryptedText);
     numberOfWords = countWords(decryptedText, keyWord, dictionary, searchWord, numWords, msgLen);
     cout << numberOfWords << " words found using keyword: " << keyWord << " giving:" << endl;
     cout<< "   " << decryptedText << endl;
     
     break;
       
  case 4: // Decode ciphertext given with the assignment
  
      // gets userInput by calling our fgets function
     cout << "Enter the cipherText to be decoded: ";
     readInAline(encryptedText,msgLen);
     msgLen = strlen(encryptedText);
     
     // calls the functions
     readBookFile(numberOfWords, dictionary,keyWord,msgLen,keyLen,encryptedText,
     decryptedText,temp,searchWord,numWords, plainText);

     break;
  case 5: // exit program
     cout << "Exiting program" << endl;
     exit( 0);
     break;
  default:
     // Sanity check
     cout << "Invalid menu option.  Exiting program." << endl;
     break;
}// end switch( menuOption)
return 0;
}//end main()





