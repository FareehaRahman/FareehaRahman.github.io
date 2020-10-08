//  program1.cpp
//
//  Created 1/13/2020 
//  by Fareeha Rahman for CS 141 program 1.
//  Lab 9am Tues

#include <iostream>   // for cin and cout
#include <iomanip>    // for setw() and setfill()
using namespace std;  // so that we don't need to preface every cin and cout with std::

int main()
{
    int menuOption = 0;
    
    cout << "Choose from among the following options:  \n"
         << "1. Display original graphic  \n"
         << "2. Display building          \n"
         << "3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menuOption;
    cout << endl;   // Leave a blank line after getting the user input for the menu option.
    
    if( menuOption == 1) {
       // this portion makes the lines on top the sears tower building, not very accurate but similar lines to it
       //-----------------------------------------------------------------------------
        cout << setw(10) << "||" << endl;
        cout << setw(10) << "||" << endl;
        cout << setw(10) << "||"  << endl;
        cout << setw(10) << "||" << endl;
        cout << setw(10) << "||" << endl;
        cout << setw(10) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" <<setw(7) << "||" << endl;
        cout << setw(3) << "||" << setw(7) << "||" << setw(7) << "||" << endl;
        cout << "--------------------";
        //------------------------------------------------------------------------------
        
        //Create varibales to make the walls of the sears tower building
        //-------------------------------
        int squareHeight, squareWidth;
        squareWidth = 20;
        squareHeight = 20;
        for(int i=0; i<6;i++) {
        for(int width=1; width<=squareHeight; width++) { 
            if(width<squareHeight) {
               cout<< endl;
               for(int width2=1; width2<=squareWidth; width2++) {// for vairble width2{
                 if(width2==1 || width2==squareWidth) {
                   cout  << "0"; }
                 else {
                    cout<< "."; }
           } // end of for loop for variable width2
       }     // end the if stament

            else {
            	cout<< endl;
				for(int width3=1; width3<=squareWidth; width3++) {
                cout<<"#";
            	}//end of for having variable width3
        	}// end of else
    	} // end of the for loop for variable width 
    } // end of first for loop
    } //end if( menuOption == 1)  // menu option to display custom graphic
    
     else if( menuOption == 2) {
        cout << "Number of building sections -> " << endl;
        int numberSelected;   // this variable represents what the userInputted
        cin >> numberSelected;
        // this presents out the top of the building without the sections if user choses to make 0 building sections
        //--------------------------
        if (numberSelected == 0) {
            cout << setfill(' ');
            cout << "  /\\" << endl;
	         cout << "  ||" << endl;
	         cout << "  ||" << endl;
	         cout << "  --" << endl;
	         cout << " |++|" << endl;
	         cout << " ====" <<endl;
	         cout << " ...."  << endl;
	         cout << "++++++" << endl;
	         cout << endl;
        }
        //--------------------------
        
        // this if deals with if userInputs in a number then build those amount of building sections
        //-----------------------
        if(numberSelected != 0) {
           // varibales created for the outside space, the in between the bar space, then the middle space, and then again
           // the in between bar space
           
           int space = numberSelected +3; // represents outside space
           int space2;                    // in between space
           int space3;                    // middle space
           int space4;                    // in between space
           
           // prints out the top of the building everytime when number gets selected
           //---------------------------------------
           cout << setw(space+1) << "   /\\" << endl;
	       cout << setw(space+1) << " ||" << endl;
	       cout << setw(space+1) << " ||" << endl;
	       cout << setw(space+1) << " --" << endl;
	       cout << setw(space+2) << "  |++|" << endl;
	       cout << setw(space+2) << "  ====" <<endl;
	       //---------------------------------------
	       
	       // this prints out the amount of sections the user wants using a for loop
	       //-------------------------------------
           for(int i=1; i <= numberSelected; i++) {
            space2 = 1;
            space3 = ((2*i) - (2*space2) + 1);
            space--;
            space4 = space2;
            for(int j=1;j<=2*i; j++) {
               //prints out the first half of the section and sets the width with the spaces
               //and fills in the semicolons in the middle
               if(j<=i) {
                  cout  << setfill(' ') << setw(space)  << "|"; 
                  cout << setfill(':') << setw(space2) <<  "\\";
                  cout << setfill(':') << setw(space3)<<  "/";               
                  cout << setfill(':') << setw(space4) <<  "|";
                  cout << endl;
               }
               
               // prints out the second half of the section and sets the width with the spaces
               // and fill in the semicolons in the middle
               else {
                  cout  << setfill(' ') << setw(space) << "|"; 
                  cout  << setfill(':') << setw(space2)<< "/";
                  cout  << setfill(':') << setw(space3) << "\\"; 
                  cout  << setfill(':') << setw(space4) <<"|";
                  cout << endl;    
               }
               
               // two if staments to increment/ decrement the amount of space so that it could print out 
               // a smoth x
               if(j<i) {
                  space2++;
               }
               else if (j>i) { 
			      space2--;
               }
               
               // intialize the values again, so that the values don't change 
               space4 = space2;
               space3 = ((2*i) - (2*space2) + 1);
               }// ends the for loop for making the lines
               
               
               // these for loops creates the seperation from each section at
               //------------------------------------------
               cout << setfill(' ')<< setw(space) << "/";
               for(int e=i; e>0; e--) {
                  cout << "--";       }
               cout << "\\" << endl;
               //-----------------------------------------
               
           } // closes the for loop of building the section
            
           // for loops aand cout statements to create the base of the building at the bottom 
            cout << setw(3) << "..";
            for (int d=1; d < numberSelected+1; d++) {
           		cout << ".."; }
           	cout << ".." << endl;
           	cout << "+++";
         	for(int p=0; p<numberSelected; p++) {
            	cout << "++"; }
            cout << "+++";
            cout << endl;
            cout << endl;
        }// end of the if statment when userInputs in something besides 0-----------------------------------------------
     } // end of if statmenet dealing with menuOption
     
     }

               
               
               
                
               
               
                        
                




