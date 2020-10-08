//
//  Project 1 Starter Code - GerryMandering
//  TODO: Fareeha Rahman, 42499, Project 1 - GerryMandering App


#include "ourvector.h"
#include <iostream>
#include <string>
#include <fstream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <cmath>              // used for floor
#include <algorithm>          // used for transform
using namespace std;


struct eachState 
{         
    // stores state name, the district, and the eligible voters
    string stateName;
    string numOfDistricts;
    string totalVoters;
    
   // two vectors 
    ourvector<int> demPerState;
    ourvector<int> repPerState;
};

// // #1 String function created to extract the state name out of the district.txt file, takes in the lineValue which is the line getting read into by file
string getStateName(string &lineValue) 
{
    size_t pos = lineValue.find(",");
    string stateName = lineValue.substr(0,pos); // do the actual extraction 
    lineValue = lineValue.substr(pos+1, lineValue.size()-stateName.size()-1);
    return stateName;    // retrun the state name 
}

// #2 String function that extracts the district number, the demPerState, and the repPerState
// takes the parameters for the 2 vectors and the lineValue
string getDistrictVals(string &lineValue,ourvector<int>&demPerState,ourvector<int>&repPerState) 
{
  
    string numOfDistricts;
    string nextSpot;
    string lastSpot;
    
    // checks to see if the line in the file is empty, other wise it'll go one an infinite loop
    while(!lineValue.empty()) 
    {
        size_t pos = lineValue.find(","); 
        numOfDistricts = lineValue.substr(0,pos); // extracts the district number 
        lineValue = lineValue.substr(pos+1, lineValue.size()-numOfDistricts.size()-1);
        
        // done with that extraction, on to the demPerState
        //------------------- 
        pos = lineValue.find(",");
        if((int)pos == -1)     //checks to see it it found a common
        { 
           nextSpot = lineValue;
           lineValue = "";          //if it did not,line = empty
        }
        else 
        {
            nextSpot = lineValue.substr(0,pos); // extracts the district voters
            lineValue = lineValue.substr(pos+1, lineValue.size()-nextSpot.size()-1);
        }
        
        demPerState.push_back(stod(nextSpot)); // push back into vector
        //-----------------    // do the same for the lastSpot 
        size_t pos1 = lineValue.find(",");
        if((int)pos1 == -1) 
        { 
            lastSpot = lineValue;
            lineValue = "";
        }
        else 
        {
            lastSpot= lineValue.substr(0,pos1);
            lineValue = lineValue.substr(pos1+1, lineValue.size()-lastSpot.size()-1);
        }
        repPerState.push_back(stod(lastSpot));  // push back into vec
   }

 // for the states that have letters as there district numbers, check and change them to 1
   for(int i =0; i<numOfDistricts.length(); i++) {
        if(isalpha(numOfDistricts[i])){
            numOfDistricts = "1";
         }
    }
    return numOfDistricts;
}

// #3 Function to load the districts.txt file and read each line. Takes parameters to check if the word userInput is load, takes in the statesVec and the line that goes through the file. Made a boolean so it could return true or false, if userInputted in right word.
bool loadDistricts( string &checkForWord,ourvector<eachState>&statesVec,int count, string &lineValue,string fileName) 
{
    
   
    // checks to see if userInputed the right file if not, then print out error messages
    int found;
    found = checkForWord.find(fileName);
    if(found == -1)
    {
        cout << "Invalid first file, try again." << endl;
        count--;
        return false;
    }
    
    ifstream infile(fileName);    // opens file
    getline(infile,lineValue);    // reads the line
    
    if(!infile.is_open()) 
    {
        cout << "**file not found" << endl;
        return false;
    }
    
   
    //---------------------------------------------------------
    
    cout << "Reading: " << fileName<< endl;
    while(!infile.eof())
    {
        if (!infile.fail()) 
        {
         // vectors needed to be passed in properly in line 128
         ourvector<int> demPerState;
         ourvector<int> repPerState;
         
         // define the struct, make the struct.elements = to the parsed versions found using functions about.
         eachState eachState;
         eachState.stateName = getStateName(lineValue);
         eachState.numOfDistricts = getDistrictVals(lineValue,demPerState,repPerState);   // stores districts
         eachState.demPerState = demPerState;                                             // stores Democratic votes
         eachState.repPerState = repPerState;                                             // stores Republican votes
         
        // pushes all of this data into the vector
         statesVec.push_back(eachState);
         cout << "..." << eachState.stateName << "..." << eachState.numOfDistricts << " districts total" << endl;
         getline(infile,lineValue);

        }
    }
    
    return true;
}

// #4 function that searchs if the state is in the statesVec
int searchState(string tempString, ourvector<eachState> &statesVec) {
    
      for(int i=0; i<statesVec.size(); i++) 
      {
        if(statesVec[i].stateName == tempString )    // found in the vector
        {
            return i;
        }
    }
    return -1;
}

// #5 same thing as loadDistricts but for the file eligible_voters.txt
bool loadVoters(string &checkForWord,ourvector<eachState>&statesVec,int &count,string &voterValue, string fileName2) 
{
    
    // error statements that sees if the file is valid or not by finding the name the userInputed
    int found;
    found = checkForWord.find(fileName2);
    if(found == -1)
    {
        cout << "Invalid second file, try again." << endl;
        count--;
        return false;
    }
    
    ifstream infile(fileName2);   // opens file
    getline(infile,voterValue);  // reads line
    
    
    if(!infile.is_open()) 
    {
        cout << "**file not found" << endl;
        return false;
    }
    cout << endl;
    
    cout << "Reading: " << fileName2 << endl;
    while(!infile.eof()) 
    {
        if (!infile.fail()) 
        {
            
            // parses thorugh the file to find the voters 
            size_t pos = voterValue.find(",");
            string checkState = voterValue.substr(0,pos);   // extracts the state
            string checkNumber = voterValue.substr(pos+1, voterValue.size()-checkState.size()-1);  // extracts the checkState
            
            // checks to see if the states in the vector match the ones of checkState
             if(searchState(checkState,statesVec) > -1 ) 
             {
                int thisState = searchState(checkState,statesVec);         // makes the userInputed state the index
                statesVec[thisState].totalVoters = checkNumber;            
             
                cout << "..." << statesVec[thisState].stateName <<  "...";
                cout  << statesVec[thisState].totalVoters;                 // holds totalVoters value;
                cout << " eligible voters" << endl;
             }
        
             getline(infile, voterValue);

        }
    }
    cout << endl;
    return true;
}

//#6 this function finds all the statistics of the states and prints it all out. Takes in all the vectors as parameters
// because we need to the dem and rep per the state the user accquires
void stateStats(string &stateInputted,ourvector<eachState>&statesVec, ourvector<int>&demPerState, ourvector<int>&repPerState ) 
{
    // all variables are understandable by their name
    int totalDems;      
    int totalReps;
    int totalVotes; 
    int ind;
    ind = searchState(stateInputted,statesVec);   // index of the state userInputed
    int overHalfVotes = 0;
    int wastedDem = 0;
    int wastedRep=0;
    int totalWastedDem = 0;                        // all the wastedRep added together
    int totalWastedRep = 0;                        // all the wastedDem added together
    double allVotes = 0;                           // all the totalVotes added together
    string lostState;
    double efficiencyGap = 0;
    string gerryMan = "";                       // sees if the state Gerrymandered
    
    // didn't return 0 meaning the state exists, so we can find the statistics.
    if((int)ind >=0) 
    {
        for(int i=0; i < stoi(statesVec[ind].numOfDistricts); i++) // loops through the numOfDistricts per state. Used stoi to convert to int
        {    
            // see if dem are higher than Republicans because then all the votes for Republicans
            // will be wasted and all the wasted dem can be calculated by the overHalf
            if(statesVec[ind].demPerState[i] > statesVec[ind].repPerState[i]) 
            {
                totalVotes = statesVec[ind].demPerState[i] + statesVec[ind].repPerState[i];
                overHalfVotes = ((totalVotes/2)+1);
                wastedDem = abs(overHalfVotes - statesVec[ind].demPerState[i]);
                wastedRep = statesVec[ind].repPerState[i];    
                    
            }
             
            // see if Republicans are higher than Democrats because then, all the Democrats votes
            // are wasted and the republican votes can be found by calculating the over half
            else if (statesVec[ind].demPerState[i] < statesVec[ind].repPerState[i]) 
            {
                  
                
                totalVotes = statesVec[ind].demPerState[i] + statesVec[ind].repPerState[i];
                overHalfVotes = ((totalVotes/2)+1);
                wastedRep = abs(overHalfVotes - statesVec[ind].repPerState[i]);
                wastedDem = statesVec[ind].demPerState[i];

            }
                
            // totals them all per district   
            totalWastedDem +=wastedDem;
            totalWastedRep +=wastedRep;
            allVotes += totalVotes;
                
                wastedDem = 0;
                wastedRep = 0;
                 
        } // end for loop
        
        // if a district has less then three then efficiencyGap cannot be calculated
        if(stoi(statesVec[ind].numOfDistricts) < 3) 
        {
            gerryMan = "No";
        }
        else 
        {
            efficiencyGap = ((totalWastedRep - totalWastedDem) / allVotes)* 100;  // make it a decimal.
            efficiencyGap = abs(efficiencyGap);                                   // makes it always positive
            
            // finds who was Gerrymandered against if GerryMandering = "Yes" by looking at 
            //the total # of wasted votes. If dem higher, then they are Gerrymandered and vice versa
            if(totalWastedDem >= totalWastedRep) 
            {
                    lostState = "Democrats";
            }
                
            else if (totalWastedDem < totalWastedRep)
            {
                lostState = "Republicans";
            }
            
            // finds if they are Gerrymandered or not by looking at the efficiencyGap and 
            // seeing if it is greater then 7
            if(efficiencyGap > 7) {
                gerryMan = "Yes";
            }
 
            else 
            {
                gerryMan = "No";
            }

        } // end else
        
        // couts statements       
        cout << "Gerrymandered: " << gerryMan << endl;
        if (gerryMan == "Yes") 
        {
            cout << "Gerrymandered against: "<< lostState << endl;
            cout << "Efficiency Factor: " << efficiencyGap << "%" << endl;
        }
        cout << "Wasted Democratic votes: " << totalWastedDem << endl;
        cout << "Wasted Republican votes: " << totalWastedRep << endl;
        cout << "Eligible voters: "  <<  statesVec[ind].totalVoters << endl;
        cout << endl;
    }// ends if statement
        
} // end function

// #7 function that plots an historgram of how many Democratic and Republican voters there are in each district
// takes the three vectors and the user inputted state as its parameter
void statePlot(string &stateInputted,ourvector<eachState>&statesVec, ourvector<int>&demPerState, ourvector<int>&repPerState) 
{
    
 
    double demPlot;             // plots the D's
    double repPlot;             // plots the R's
    int totalVotes;             // totalVotes of dem and rep
    int ind;                     // index of searchState()
    ind = searchState(stateInputted,statesVec);
    int n=stoi(statesVec[ind].numOfDistricts);     // numOfDistricts per state
    
    for(int i=0;i<n;i++)
    {                          // loops through the Districts
    
        totalVotes = (statesVec[ind].demPerState[i] + statesVec[ind].repPerState[i]);
        demPlot = ((double)(statesVec[ind].demPerState[i])/((double)totalVotes)*100); // made it into a number to be plotted
        
        // does the actual plotting
        cout<<"District: " << i+1 <<endl;
        for(int j=0;j<floor(demPlot);j++)
        {
            cout << "D";
        }    
        for(int k=0;k<100-floor(demPlot);k++)
        {
            cout << "R";
        }
        cout<<endl;

    } // end Districts per state for loop
    cout << endl;
} // end function

// #8 This function takes care of my creative component where I basically find the maximun and minimum demPerState
// and compare that to the other Democratic and republican voters in the vectore. So the state the userInput
// they can see the maximun number of voters they were for republican and Democrats
// takes the parameters of the three vectors and the userInputted word
int maxVoters(string &stateInputted,ourvector<eachState>&statesVec, ourvector<int>&demPerState, ourvector<int>&repPerState) 
{
    
    int maxDemVotes;
    int maxRepVotes;
    int ind;
    ind = searchState(stateInputted,statesVec);
    maxDemVotes = statesVec[ind].demPerState[0];                      // intially start at 0, then compare from there
    
    for(int i=0; i<stoi(statesVec[ind].numOfDistricts); i++)          // loops through each district per state inputted
    {
        if(statesVec[ind].demPerState[i] > maxDemVotes)               // If current element is greater than the first
        {
            maxDemVotes = statesVec[ind].demPerState[i];              // make that one the max
        }
    }
    
    // repeats line 368-374 but for Republicans
    for(int i=0; i<stoi(statesVec[ind].numOfDistricts); i++) 
    {
        if(statesVec[ind].repPerState[i] > maxRepVotes)               // If current element is greater than max
        {
            maxRepVotes = statesVec[ind].repPerState[i];
        }
    }
    
    // Print it out maximum element
    cout<<"Maximum Democratic Voters are: " << maxDemVotes << endl;
    cout<<"Maximum Republican Voters are: " << maxRepVotes << endl;
    return 0;
} // end function

// #9 This function takes care of my creative component where I basically find the maximun and minimum demPerState
// and compare that to the other Democratic and republican voters in the vectore. So the state the userInput
// they can see the maximun number of voters they were for republican and Democrats
// takes the parameters of the three vectors and the userInputted word
int minVoters(string &stateInputted,ourvector<eachState>&statesVec, ourvector<int>&demPerState, ourvector<int>&repPerState) 
{
    
    int minDemVotes;
    int minRepVotes;
    int ind;
    ind = searchState(stateInputted,statesVec);
    minDemVotes = statesVec[ind].demPerState[0];                       // Assume first element as is the min
    
    for(int i=0; i<stoi(statesVec[ind].numOfDistricts); i++) 
    {
        if(statesVec[ind].demPerState[i] < minDemVotes)               // If current element is smaller than min
       {
            minDemVotes = statesVec[ind].demPerState[i];              // then make min equal to that
       }    
    }
    
    // repaeat lines 402-408 for Republicans
    for(int i=0; i<stoi(statesVec[ind].numOfDistricts); i++) 
    {
        if(statesVec[ind].repPerState[i] < minRepVotes)            // If current element is smaller than min
       {
            minRepVotes = statesVec[ind].repPerState[i];          // then make min equal to that
       }    
    }
    
    // Print it out minimum element
    cout<<"Minimum Democratic Voters are: " << minDemVotes << endl;
    
    cout<<"Minimum Republican Voters are: " << minRepVotes << endl;
    return 0;
}

// #10 function is a menu option that I made to make the main look nicer
// takes in the three variables used to hold the values of stateInputted,
// dataLoaded and userInput
void appInfo(string &dataLoaded, string &stateInputted,string &userInput) 
{
    
        cout << "Data loaded? " << dataLoaded << endl;
        cout << "State: " << stateInputted << endl;
        cout << endl;
        cout << "Enter command: ";
        cin >> userInput;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << endl;

}

// #11 function basically takes care of the edge cases and checks if the user typed 
// in the proper sequence, by first providing the gile, then searching, then typing states
// then typing plot. if it is not in the write order, return false
bool checkErrors(string userInput, string dataLoaded, string stateInputted) 
{
    if ((userInput == "search") && (dataLoaded == "No")) 
    {
        cout << "No data loaded, please load data first." << endl;
        return false;
    }
    if ((userInput == "stats") && (dataLoaded == "No")) 
    {
        cout << "No data loaded, please load data first." << endl;
        return false;
    }
    else if ((userInput == "plot") && (dataLoaded == "No")) 
    {
        cout << "No data loaded, please load data first." << endl;
        return false;
    }
    else if ((userInput == "stats") && (stateInputted == "N/A")) 
    {
        cout << "No state indicated, please search for state first." << endl;
        return false;
    }
    else if ((userInput == "plot") && (stateInputted == "N/A")) 
    {
        cout << "No state indicated, please search for state first." << endl;
        return false;
    }
    else if((userInput == "load") && (dataLoaded == "Yes")) 
    {
         cout << "Already read data in, exit and start over" << endl;
         appInfo(dataLoaded,stateInputted,userInput);
         return false;
     }
    return true;
}

int main() {
    
    // my three vectors
    ourvector<eachState> statesVec;
    ourvector<int> demPerState;
    ourvector<int> repPerState;

    string dataLoaded = "No";     // variable that tells the user if data was loaded or not
    string userInput;     
    string stateInputted = "N/A"; // variable that holds the state the user is searching for
    string tempString = "";       // used in #4 function
    string lineValue;             // reads in the districts.txt line
    string voterValue;            // reads in the eligible_voters.txt
    string fileName = "districts.txt";
    string fileName2 = "eligible_voters.txt";
    int count = 0;                // harmless counter used to increment in while loop
   
    // main menu
    cout << "Welcome to the Gerrymandering App!" << endl;
    cout << endl; 
    
    if(userInput == "exit") 
    {    
        exit(0);                    // exits the program
    }
    
    while(userInput != "exit") 
    {
        count++;                    // increment
        appInfo(dataLoaded,stateInputted,userInput);    // calls the menu
        if(checkErrors(userInput, dataLoaded,stateInputted) == true)     // check is they are errors if not continue
        {
        
            if(userInput == "load") 
            {
                string checkWord;
                getline(cin,checkWord);   // gets the file name
                if ((loadDistricts(checkWord,statesVec,count,lineValue,fileName) == true) && (loadVoters(checkWord,statesVec,count,voterValue,fileName2)== true) )                 // checks if file is proper
                {
                    dataLoaded = "Yes";                  // if proper then dataLoaded is set!
                }

            }
            else if((userInput == "search") && (dataLoaded == "Yes"))    // makes sure they are searching after data was set
            {
                string checkForState;                         // string created to check what the userinputed after search
                getline(cin,checkForState);                   
                checkForState.erase(0,1);                     // remove white space
                checkForState[0] = toupper(checkForState[0]); // uppercase the first letter when storing in stateInputted
                int index;
                index = searchState(checkForState, statesVec);  // calls function #4
                
                if(index == -1)                                 // invali state typed in            
                {
                stateInputted = "N/A";
                cout << "State does not exist, search again." << endl;
                }
                
                else 
                {
                stateInputted = statesVec[index].stateName;
                
                }
            }

            // calls function #6 
            else if(userInput == "stats") 
            {
            stateStats(stateInputted,statesVec,demPerState,repPerState);
            }
            
            // calls function #7
            else if(userInput == "plot") 
            {
            statePlot(stateInputted,statesVec,demPerState,repPerState);
            }
            
            // calls function #8
            else if(userInput == "max") 
            {
            maxVoters(stateInputted, statesVec,demPerState,repPerState);
            }
            
            // calls function #9
            else if (userInput == "min") 
            {
            minVoters(stateInputted, statesVec,demPerState,repPerState);
            }
  
      }
}
    return 0;

}