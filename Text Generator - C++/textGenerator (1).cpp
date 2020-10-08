/*
 * File: textGenerator.cpp */
// Fareeha Rahman, 42499, Project 2 - Generating Text


#include "myrandom.h"         // included to generate random text in Function #
#include <iostream>
#include <map>                // included to use maps to search
#include <vector>             // Used vectors in program
#include <fstream>
using namespace std;

// Explained in Function #9, prints the menu
void printMenu(string &filename, int &nGram, int &totalWords);

// Function #1 builds the maps by taking in the vector words
// that holds the words in the file, two new vectors that are
// going to hold the value of the key and the value in the file
void buildMap(string &word,string &filename, int &nGram, vector<string> &words,
    map<vector<string>, vector<string>> &mappedWords) {
    string value;    
    // takes the word in file
    ifstream inFile(filename);                        // read in file once
    while (inFile >> word) {
        words.push_back(word);                        // push words into vector
    }
    for (int i = 0; i < words.size(); i++) {  // loop thorough the words in file
        vector<string> keyVec;                // create a vector for key
        vector<string> valuesVec;             // creates a vector for values
        int j = 0;  // counter created to keep track of ind
        int k = i;  // counter to keep track of ind
        // push the words one less of Ngram into the keyVec
        while (j < nGram-1) {
            keyVec.push_back(words[k]);
            // Iterate back to the first element
            k = (k+1)%words.size();
            j++;
        }
        value = words[k];
        // checks the key so it is exists, points to where
        auto it = mappedWords.find(keyVec);
        if (it != mappedWords.end()) {
            //pushes the value of the words needed in map to key
            it -> second.push_back(value);
        } else {
             // push words into the value vector
            valuesVec.push_back(value);
            // don't print after last element so make it empty
            mappedWords.insert(pair<vector<string>,
            vector<string>>(keyVec, valuesVec));
        }
    }  // end for loop
}

// Function #2 prints out all the elements in the map vector
// takes the map as a parameter only
void printMap(map<vector<string>, vector<string>> &mappedWords) {
    cout << endl;
    for (auto &e : mappedWords) {            // loops through the map
        int count1 = 0;                      // counters to check if reached end
        int count2 = 0;
        cout << "{";
        for (auto &s : e.first) {            // goes into the first vector
            count1++;
            cout << s;
            // don't print after last element so make it empty
            if (count1 != e.first.size()) {
                cout << " ";
            }
        }
        cout << "}";
        cout << " -> ";
        cout << "{";
        for (auto &v : e.second) {          // got into the second vector
            count2++;
            cout << v;
             // don't print out after last elemnt so make it empty
            if (count2 != e.second.size())
                cout << " ";
        }
        cout << "}";
        cout << endl;
    }
     cout << endl;
     cout << endl;
}

// Function #3 we take all the keys from our map and store them
// in a vector. Then by using the randomInteger() in line 82 which
// was given to use we select a key from the keys vector. Using this
// as a starting point, we build out textVec. Parameters are the map
// that holds the vectors, the new vectors and nGram
void helper(map<vector<string>, vector<string>> &mappedWords,
    vector<string> &textVec, int &nGram) {
    vector<vector<string>> keys;
    for (auto &e : mappedWords) {
        keys.push_back(e.first);
    }
    int key = randomInteger(0, (keys.size()-1));
    textVec = keys[key];
    keys.clear();
}

// Function #4 takes the helper function and randomly generates
// the text from the text vector. Moving the window, we store the
// next key to be searched in the searchVector which is a new vector created.
// We pushback the corresponding value in the textVec and then display the
// textVec. Takes the same parameters as the previous function
void generateText(int &nGram, int &totalWords, map<vector<string>,
    vector<string>> &mappedWords, vector<string> &words) {
    vector<string> textVec;
    helper(mappedWords, textVec, nGram);
    auto it = mappedWords.find(textVec);
    string value;
    if (it != mappedWords.end()) {
        // randomly find a word in textVec
        int x = randomInteger(0, (it->second.size()-1));
        value = it->second.at(x);  // holds the value of the word
        textVec.push_back(value);                            // push into vector
    }
    int countWords = nGram;  // how many words should be generated
    int start = 1;      // same thing as i=1
    // holds the amount of words the user wants in vector
    while (countWords < totalWords) {
        vector<string> searchVector;
        // pushes the specific word into the searchVector
        for (int i=start; i < textVec.size(); i++) {
            searchVector.push_back(textVec[i]);
        }
        auto it = mappedWords.find(searchVector);            // map this vector
        if (it != mappedWords.end()) {
            int x = randomInteger(0, (it->second.size()-1));
            value = it->second.at(x);
            textVec.push_back(value);   // push the next word in value
        }
        countWords++;
        start++;
    }
    // print out statements to loop through the vector and print the text
    cout << endl;
    cout << "...";
    int c = 0;
    for (auto &t : textVec) {
        c++;
        cout << t;
        if (c < textVec.size()) {
            cout << " ";
        }
    }
    cout << "...";
    cout << endl;
    textVec.clear();
}

// Function #5 is a function that startOveras the program and empys out the
// words vector and the map vectors so that it can start anew. Then it prints
// the menu again and opens the file again to store words
void startOver(string &filename, int &nGram, int &totalWords,
     map<vector<string>, vector<string>> &mappedWords,
     vector<string> &words) {
    words.clear();
    mappedWords.clear();
    cout << endl;
    printMenu(filename, nGram, totalWords);
}

// Function #6 is a function that checks if the file name is
// valid or not by taking in the filename and checking if it
// is infile, if it is, then stop the loop. if it isn't print
// error and then cin another filename until it finds a proper one
string checkValidFile(string &filename) {
    cin >> filename;
    while (1) {
        ifstream inFile(filename);
        if (inFile) {
            break;
        } else {
            cout << " Invalid file, try again: ";
            cin >> filename;
        }
    }
    return filename;
}

// Function #7 is also an error checking function that checks
// to see if the Ngram the userInputed is an proper integer
// by looping through until finding a valid nGram. If not
// valid then print error message and cin another nGram
// until that is a valid number
int checkValidNgram(int &nGram) {
    cin >> nGram;
    while (1) {
        if ( nGram <= 1 ) {
            cout << " N must be > 1, try again: ";
            cin >> nGram;
        } else {
            break;
        }
    }
    return nGram;
}

// Function #8 is also an error checking function that checks
// to see if the userInputed in a appropiate value for TotalValue.
// Loops through to find a appropiate one, if found break from
// the loop, if not print error message and cin another one until
// that one is appropiate.
int checkTotalValue(int &nGram, int &totalWords) {
    cin >> totalWords;
    while (1) {
        if (totalWords < nGram) {
            cout << " Total words must be at least N, try again: ";
            cin >> totalWords;
        } else {
            break;
        }
    }
    return totalWords;
}
// Function #9 is an function that prints out the main menu
// needed to run the program. Takes in all the userInputs
// and calls all the error checking functions.
void printMenu(string &filename, int &nGram, int &totalWords) {
    cout << "Welcome to the Text Generator." << endl;
    cout << "This program makes random text based on a document." << endl;
    cout << "Input file name? ";
    filename = checkValidFile(filename);                // call function #6
    cout << " Value of N? ";
    nGram = checkValidNgram(nGram);                     // call function #7
    cout << " Total words you'd like to generate? ";
    totalWords = checkTotalValue(nGram, totalWords);    // call function 8
}

int main() {
    string filename;
    int nGram;
    int totalWords;                                   // needed for function #4
    vector<string> words;                           // declared words vector
    map<vector<string>, vector<string>> mappedWords;  // map of vectors
    char userInput;
    string word;                                      // the word in file
    printMenu(filename, nGram, totalWords);           // call Function #9
    cout << " ";

    while (1) {
        cout << "Type b-build map, p-print map, ";
        cout << "g-generate text, s-start over, x-to exit:";
        cin >> userInput;
        // whatever the user inputs depending on the letter do that.
        switch (userInput) {
            // calls Function #1
            case 'b' :  cout << endl;
                        cout << "...Building map: " << filename << "...";
                        cout << endl;
                        cout << endl;
                        buildMap(word, filename, nGram, words, mappedWords);
                        break;
            // calls Function #2
            case 'p' :  printMap(mappedWords);
                        break;
            // calls Function #4
            case 'g' :  generateText(nGram, totalWords, mappedWords, words);
                        break;
            // calls Function #5
            case 's' :  startOver(filename, nGram,
            totalWords, mappedWords, words);
                        break;
             // exit program
            case 'x' :  exit(0);
                        break;
        }
    }
    getchar();
}
