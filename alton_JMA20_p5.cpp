/*=========================================================================*/

/*PROGRAM Cypher Decoder

AUTHOR: <John Alton>
FSU MAIL NAME: <JMA20>
RECITATION SECTION NUMBER <04>
RECITATION INSTRUCTOR NAME: <Priya>
COP 3363 - Fall 2022
PROJECT NUNBER: 5
DUE DATE: Thursday 11/12/2022
PLATFORM g++ / UNIX OS

SUMMARY
The user will be asked if they want 
to decode a message using either a 
substitution cypher or a Caeser 
Cypher. The Program will then 
decode a file using the given cypher.

INPUT 
user will input what kind of cypher
their file is in, and the name of the file. 
The user will input if they want to rerun
the program.

OUTPUT 
the program outputs standard 
introductory information, the user's
answer, and the decoded text.

ASSUMPTIONS 
the user inputs the correct cypher type
and file name. The file the user chooses
has either the shift number for the caesar 
cipher, or the substitution alphabet 
for the substiution cipher on the first line
of the file.  */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

string Lines;
typedef char alphabet [26];

void OpenFile(ifstream &);
void C_Cipher(ifstream &, const alphabet normal);    // function prototypes
void S_Cipher(ifstream &, const alphabet normal);
bool ReplayStatus();
void PrintIntro();
char TypeSelect();

/* ================================================================ */

int main()

{
ifstream inFile; // stream for opening file
char Answer;    // user answer for what kind of cypher to use 
bool PlayStatus; // status on if the program will run 

alphabet normal = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',     // standard alphabet 
                  'Q', 'R', 'S', 'T', 'U', 'V', 'W','X',
                  'Y', 'Z'};
          

  PrintIntro(); // prints intro 

PlayStatus = true; // starts as true so the program can start 

while (PlayStatus == true) // loops program while true 
{
  Answer =  TypeSelect(); //  User inputs Answer 
  switch(Answer)
{
     case 'C':  // case if user wants to use caesar cypher 
     case 'c': cout << Answer << endl;
             OpenFile(inFile); // calls OpenFile function 
             C_Cipher(inFile, normal ); // Calls C_Cipher
            PlayStatus = ReplayStatus(); // Calls ReplayStatus and returns user answer 
     break;
    
     case 'S':  
     case 's': cout << " you chose the Sub Cipher" << endl;
           OpenFile(inFile); // Calls OpenFile function
           S_Cipher(inFile, normal);//Calls S_cipher function 
          PlayStatus =  ReplayStatus(); // Calls ReplayStatus and returns user answer 
     break;
        

     case 'Q':
     case 'q':
     PlayStatus = false; // sets Play status to false to end main program loop
     cout << "Thank you for using the decryption program" << endl;
     break;
}
  
}

return(0);
}        // main




//Prints a intro message 
//Called by main 
 void PrintIntro()

{ // PrintIntro 
  cout <<"================================================================ " << endl; 
  cout <<" Welcome to the decyrption program" << endl; 
  cout <<" This program will decrpyt messages" <<endl;
  cout <<" The message must be encoded with Caeser or Substitution cypher" << endl; 
  cout <<"================================================================ " << endl;

return;

} // PrintIntro 


//User picks which cypher to use, or if they want to close the program 
// called by: main 
char TypeSelect()

{  // TypeSelect

  char Answer;      // user answer 
  bool LegitAnswer; // bad data checking for answer 

   
   // asks user for input of Answer
  cout << "please select which cypher to decode " << endl;
  cout << "input C for Caeser, S for Substitution, or q to quit" << endl;
  cin >> Answer; 

 // checks if answer is valid 
LegitAnswer = (Answer == 'C' | Answer == 'c'|
  Answer == 'S' | Answer == 's' | Answer == 'q' | Answer == 'Q');

 // reprompts user if answer is not valid 
while (LegitAnswer == false) 
 {
   cin.clear ( ) ;
   cin.ignore (200, '\n');
   cout << "Please enter a valid answer ";  // reprompts user 
   cin >> Answer;
   LegitAnswer = (Answer == 'C' | Answer == 'c'| // checks answer again 
   Answer == 'S' | Answer == 's' |  Answer == 'Q' | Answer == 'q' );
}

return (Answer); // returns char answer 

}  // TypeSelect 


// opens selected file for decoding 
// called by: main 
void OpenFile(ifstream& inFile )

{ // OpenFile 

  string ChosenFile; // name of file to decode
  

    // prompts user for a file 
  cout << "please enter a valid file name to decode" << endl;
  cin >> ChosenFile ;

        inFile.open(ChosenFile.c_str());    // opens chosen file 
   
        while(!inFile) // loop checks if user did not input correct file name 
        { 
          cout << " you have entered an invalid file please reinput a valid one" << endl;
          cin >> ChosenFile;
          inFile.clear();
          inFile.open(ChosenFile.c_str()); 
        }

  
} // OpenFile 


// Decodes using Caeser cipher
// called by: main 
void C_Cipher(ifstream& inFile, const alphabet normal)

{ // C_Cipher


                             
 int shift; // number for the shift cipher 
 
 inFile >>  shift; // gets shift number from first line in file 

 char letters; // gets encoded letters from file 


 while (inFile.get(letters)) // loop for getting letters and decoding them 
 { char decoded; 
 for (int count = 0; count <=26; count++){
  
 if (letters==normal[count])
{

 decoded = normal [count-shift];
}

if (letters == ' ') // if a letter is a white space outputs space 
{decoded = ' ';} 

}
 cout << decoded;


}
} // C_Cipher


//Decodes using Substitution cypher
// called by: main
void S_Cipher(ifstream& inFile, const alphabet normal )
{ // S_Cipher


alphabet Substitution; // substitution array gotten from first line of file 
char Encoded; // encoded character from main text

inFile >> Substitution; // gets the substitution alphabet from first line of file 

 cout << Substitution << endl; // outputs the substitution 


 while (inFile.get(Encoded)) // loop for getting letters from file and decoding them 
 { char decoded; // decoded character
 for (int count = 0; count <=26; count++ ){

if (Encoded==Substitution[count])
{ decoded = normal [count];}


if (Encoded  == ' ') // if loop encounters whitespace ouputs a blank 
{decoded = ' ';}


}
cout << decoded; // outputs decoded letter 

}
} // S_Cipher


// Determines if user would like to rerun program
// called by: main 
bool ReplayStatus()

{ // ReplayStatus 

char Answer; // user answer 
bool LegitAnswer;
bool ReturnAnswer;

cout << "would you like to deocde another file?" << endl;
cout << " please enter Y or N" << endl;

cin >>  Answer;

LegitAnswer = (Answer == 'Y' | Answer == 'y'|
  Answer == 'N' | Answer == 'n');

 // reprompts user if answer is not valid
while (LegitAnswer == false)
 {
   cin.clear ( ) ;
   cin.ignore (200, '\n');
   cout << "Please enter a valid answer (y or n) ";
   cin >> Answer;
   LegitAnswer = (Answer == 'Y' | Answer == 'y'|
   Answer == 'N' | Answer == 'n');
}


if (Answer == 'Y' | Answer == 'y')
ReturnAnswer = true;

if (Answer == 'N' | Answer == 'n')
ReturnAnswer = false;

return (ReturnAnswer);
} // ReplayStatus 
