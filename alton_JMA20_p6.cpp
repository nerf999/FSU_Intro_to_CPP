  /*=========================================================================*/

/* PROGRAM Website Login 

AUTHOR: <John Alton>
FSU MAIL NAME: <JMA20>
RECITATION SECTION NUMBER <04>
RECITATION INSTRUCTOR NAME: <Priya>
COP 3363 - Fall 2022
PROJECT NUNBER: 6
DUE DATE: Thursday 11/29/2022
PLATFORM g++ / UNIX OS

SUMMARY
This program is a password 
system for a website that 
allows users to log in. 
The user must put in specific data 
for their credentials. The user 
has a limited amount of tries 
to put in the data before the
system locks them out. The 
program can handle up to 50
different sets of user info. 


INPUT 
user will input their 
userID, a password, and a 4 
digit pin. The program will 
check input by compairing it 
with a file of stored 
credential information. 

OUTPUT 
the program outputs standard 
introduction, and feedback 
from user input. if the 
user inputs incorrect PINs 
the program will tell the 
user. If the user inputs 
correct information the 
program will alert user 
of a succesful login

ASSUMPTIONS 
The user credentials stored 
in the user.txt file is correct. The user
inputs accurate information for their 
credentials. */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;   // standard libraries    

const int USERAMOUNT = 50; // maximum number of users for array of struct  

// single userRecord struct
struct UserRecord    
{
   string userID;      // string for userID 
   string password;    // string for user password 
   int PIN;            // int for user PIN
};

// array of structs type definition
typedef UserRecord Credentials [USERAMOUNT];   


// Global function prototype 
void OpenFile(ifstream &, int& numusers, Credentials users);
void Startmessage( int& numusers, Credentials users);
void UserInput (string& ID, string& IPassword, int& IPIN); 
bool CompareData (string& ID, string& IPassword, int& IPIN,     
int& numusers, Credentials users);

/* ================================================================ */

int main()

{   // main 

 string ID;            // string for user entered ID
 string IPassword;     // string for user entered password 
 int IPIN;             // int for user entered PIN

Credentials users;     // User Struct array 
int numusers;          // number of users gotten from first line of user.txt file 
int LoginTries = 0;    // number of times user has tried to login 
ifstream inFile;       // standard iftream for inFile 
bool InfoMatch;        // bool variable for if user entered info matches user credentials from user.txt


    OpenFile(inFile, numusers, users );  // gets user credentials from text file 

    Startmessage(numusers, users);       // prints welcome message and stored user credentials from user text 

    InfoMatch = false;                   // starts false for loop 


//while loop for login attempts 
// loop ends if InfoMatch is false or login tries reaches 3 
  while ((InfoMatch == false)&& (LoginTries < 3)) 
{
      UserInput (ID, IPassword, IPIN);  // gets login info from user             

    // compares user input with stored user credentials 
    InfoMatch = CompareData (ID,  IPassword, IPIN, numusers, users);

    LoginTries++; // number of times user has tried to login 

   // prints  user inputs incorrect credentials and is under 3 login attempts 
   if ((InfoMatch == false)&&(LoginTries < 3))
   cout << " Please reenter your credentials" << endl;
}

 // outputs if user entered correct data 
if (InfoMatch == true)
cout << "Login Successful" << endl;

else 
cout <<  "You are out of attempts" << endl;

return(0);
}    // main



// opens user information file
// called by: main
void OpenFile(ifstream& inFile, int& numusers, Credentials users  )

{ // OpenFile
  
    int lcv; // loop control variable 
 
    inFile.open ("users.txt");    // opens file with user credentials  
    if (!inFile)
    {
        cout << "Fatal Error: Data file could not be opened."  // aborts run if not in file 
             << endl << endl;
        exit (EXIT_FAILURE);
    }

    inFile >> numusers;       // gets number of users from first line of file 
    inFile.ignore (200, '\n');   

  // for loop that stores credentials from user.txt into the users struct
  // executes while lcv is < numusers  
  for (lcv = 0; lcv < numusers; lcv++)
    {
        // reads in the userID, password, and PIN for all users
        getline (inFile, users[lcv].userID);
        getline (inFile, users[lcv].password);
        inFile >> users[lcv].PIN ; 
        inFile.ignore (200, '\n');
    }


} // OpenFile 


// prints a starting message and stored user credentials from user.txt
// called by: main 
void Startmessage( int& numusers, Credentials users)

{ // Startmessage 


int lcv;  // loop control variable 

                      // welcome intro with standard info for user 
      cout << "=============================================================="<< endl;
      cout << "Welcome to the Amazing Website login" << endl; 
      cout << "Please enter your user credentials" << endl; 
      cout << "you have three chances to input the correct credentials" << endl; 
      cout << "before being locked out of the login " << endl;  
      cout << "=============================================================="<< endl;

cout << "Saved User Info" << endl; // title of chart 

// echo prints all saved user credentials from user.txt 
// this is for testing purposes. this info would not print in a normal environment 
for ( lcv=0;  lcv < numusers; lcv++)
{   cout <<"=====================================================" << endl;
    cout << "User " << lcv + 1 << endl;
    cout <<"User ID: " << users[lcv].userID << endl;
    cout <<"Password: " << users[lcv].password << endl;
    cout <<"PIN: " << users[lcv].PIN << endl;
}
}// Startmessage

// gets information from user and error checks it  
// called by: main 
void UserInput ( string& ID, string& IPassword, int& IPIN)

{ // UserInput

  cout << "=================================================" << endl; 

     cout << "Please input your user ID with no blanks " << endl;  // user inputs ID
     cin >>  ID;

     cout << "Please input your Password with no blanks " << endl; // user inputs IPassword  
     cin  >> IPassword; 

     cout << "Please input your PIN"  << endl;     // user inputs IPIN
     cin >> IPIN;

  while ( !cin )  
{
   cin.clear ( ) ;
   cin.ignore (200, '\n');
   cout << "Please enter an interger: ";  // error checking for IPIN  
   cin >> IPIN;
}



} // UserInput


// compares user input data from stored user credentials  
// called by: main 
bool CompareData (string& ID, string& IPassword, int& IPIN,
int& numusers, Credentials users)

{// CompareData


 int lcv = 0; // loop control variable 
 bool Match;  // bool variable for matching data 



   Match = false; // Match starts as false before comparison  


  // loop for comparing user input with saved credentials 
while (( lcv < numusers )&&(Match == false))
{ 
    // if all three data types match then Match status is true 
   if ((ID == users[lcv].userID)&& (IPassword == users[lcv].password)
   &&(IPIN == users[lcv].PIN)) 
    Match = true;

lcv++; // increases by 1 every loop 
}

 // if match is false tells the user 
 if (Match == false) 
  cout << " you have input incorrect credentials" << endl; 

return (Match); // returns match status 
}//CompareData
