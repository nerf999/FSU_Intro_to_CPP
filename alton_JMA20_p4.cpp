/*=========================================================================*/

/*PROGRAM Guessing Game

AUTHOR: <John Alton>
FSU MAIL NAME: <JMA20>
RECITATION SECTION NUMBER <04>
RECITATION INSTRUCTOR NAME: <Priya>
COP 3363 - Fall 2022
PROJECT NUNBER: 4
DUE DATE: Thursday 9/27/2022
PLATFORM g++ / UNIX OS


SUMMARY
A user is presented with a simple guessing game. The program will
generate a number between 1 and 100. The user will input a number
and the program will tell the user if the guess was too high, too low
, or correct. The user will also have $1000 to make bets with.
The player has 6 chances to guess correctly before losing. If the
player correctly guesses the number or they run out of guesses the
round will end. The player may then choose if they want to start
another round. The game ends if the player chooses not to start
another round, or if the player runs out of money. */

#include <iostream>                     // standard I/O Library         
#include <iomanip>                      // Output formating 
#include <random>                       //  Psuedorandom number generator          
using namespace std;

void PrintHeading (int money);
int PlayGame(int&  money, int MIN, int MAX);      // funtion prototypes
void GetBet(int money, int& bet);                              
int GetGuess(void);
int CalcNewMoney(int money, int bet, int GuessNumber);                        
bool PlayAgain();
int Randomint (int MIN, int MAX);

/* ================================================================ */

int main () 
{   // main 

  int money = 1000;    // money used for bets  
  int MIN = 1;         // minimum value for random integer
  int MAX = 100;       // maximum value for random integer
  bool PlayStatus;     // decides if gmae can run 
  
       
    PrintHeading (money);    // prints heading information
     
    PlayStatus = true;       // Starts as true on program start 
    
   while ( PlayStatus == true) // runs while playstatus is true
 { 
   

   money = PlayGame (money, MIN, MAX); // Money is determined by integer returned of PlayGame
  
  cout << "you now have $ "<< money << endl; // outputs current money 

   // Ends game and outputs terminating message if user runs out of money
  if (money == 0)
{ PlayStatus = false;
  cout <<" The game will now end because you are out of money" << endl;
}
   
  else
  PlayStatus = PlayAgain(); // sets play status based on user input
   
}
      
    return (0); 

}    //  main 

/* ================================================================ */

  // prints a starting message
  // Called by: main
void PrintHeading (int  money)  

{   //  PrintIntro 
    
    // printed heading 
    cout << "============================================" << endl;
    cout << " Welcome to the High-low Casino game." << endl;     
    cout << " you have $1000 to make bets with" << endl;
    cout << " Guesses must be between 1 and 100" << endl;
    cout << " You have 6 chances to guess the number" << endl;
    cout << " If you guess the right number you will win" << endl; 
    cout << " Your winnings depend on how many guesses it took you to win" << endl; 
    cout << "============================================" << endl;

    return;        

}   // PrintIntro 

/* ================================================================ */
 
    // Play Game gets inputs from users and determines if the user wins the game
    // Called by: main
int PlayGame(int&  money, int MIN, int MAX) 
   
{ // Play Game 
  
  int bet;              // The money the user is wagering 
  int guess;            // The users guess on wat the winning number is
  int GuessNumber = 0;  // The current amount of guesses the user has made 
  int WinningNumber;    // The random chosen winning number 

  GetBet(money, bet);   //GetBet Function  Determines player's bet

  WinningNumber = Randomint (MIN, MAX);  // Dermines winning number 
  
  // Asks for bets and outputs if the guess is too high or low
  // Loop stops if users makes 6 guesses or if they win
  while ((GuessNumber < 6)&&(guess != WinningNumber))
  
  { 
  GuessNumber++; // adds 1 to guess number every loop
   
  cout<< "Please input guess " << GuessNumber  << endl;  // asks for guess  

  guess = GetGuess();   // GetGuess has user input guess 
  cout <<"Your guess is "<<  guess << endl; // outputs guess

     // tells user if guess is too high
  if (guess > WinningNumber)  
   cout << " Guess is too high" << endl;

  // Tells user if guess is too low
  if (guess <  WinningNumber)  
   cout << " Guess is too low" << endl;
}

   // If user reaches 6 guessess without guessing right they lose
   // Bet number is subtracted from money 
   if ((GuessNumber == 6)&&( guess != WinningNumber))
   {money = money - bet;
   cout << " you have run out of guesses for this round" << endl;}  
 
    // If user guesses number right then money is won
    // Calc NewMoney determines what the user wins 
   if (guess ==  WinningNumber)
   {money = money + CalcNewMoney (money, bet, GuessNumber);
   cout << " Your guess was correct you win!" << endl; }   

  return (money);

} // Play Game //

 // asks user for bet and errors checks the answer 
 // is called by: PlayGame
  void GetBet(int money, int& bet) 

{     // GetBet

   bool LegitBet; // validity status of bet 


   // asks for bet and error checks it
   cout << "please enter your bet" << endl;
   cin >> bet;
   while ( !cin )
{
   cin.clear ( ) ;
   cin.ignore (200, '\n');
   cout << "Please enter an interger: ";
   cin >> bet;
}

  LegitBet = ((bet >= 0)&&(bet <=  money)); // determines if bet is valid 

   // executes while bet is not valid asks for valid input 
   // errors checks the new answer
  while (LegitBet == false)
 {cout << "please renter a valid number" << endl;
  cin >> bet;
  while ( !cin )
{
  cin.clear ( ) ;
  cin.ignore (200, '\n');
  cout << "Please enter an integer ";
  cin >> bet;
}
 
LegitBet = ((bet >= 0)&&(bet <=  money)); // checks if bet is now valid 
}

return; // returns to PlayGame

}   // GetBet

 

  // picks a random integer and returns it
  // called by: PlayGame 
 int Randomint (int MIN, int MAX)

{ // Randomint

  int DrawnNumber; // number drawn by system 
   
   // picks a random number between MIN and MAX
   random_device engine;
   uniform_int_distribution<int> numDrawnValue(MIN, MAX);
 
   DrawnNumber = numDrawnValue(engine);

  return (DrawnNumber);

} // Randomint 


 // Gets guess from user and error checks it 
 // called by: PlayGame
int GetGuess(void)

{  // GetGuess

  int guess;      // Users guess 
  int ValidGuess; // vald  integer returned 

  cin >> guess;   // user inputs guess

   // determines if guess is valid 
  if ((1 <= guess )&&(guess <= 100))
  {ValidGuess = guess;}

  else  // guess will be zero if it is not valid 
  {ValidGuess = 0;}

  return(ValidGuess); // returns validGuess 

} // GetGuess


   // calculates the new amount of money
   // called by: PlayGame
  int CalcNewMoney( int money, int bet, int GuessNumber)

{  // CalcNewMoney
 
  int Winnings;  // what the player wins 
  int WinningsRounded; // players winnings truncated
  

  // determines winnings based on bet and GuessNumber
  Winnings = (bet/GuessNumber); 
 
  // Truncates player's winnings 
  WinningsRounded = trunc(Winnings);
 
  // returns WinningsRounded 
  return (WinningsRounded);

} // CalcNewMoney



  // Asks user if they would like to play the game again 
  // called by: main 
  bool PlayAgain ()

{ // PlayAgain


  char Answer;      // Players answer 
  bool LegitAnswer; // Validity of players answer 
  bool ReplayStatus;

   // prompts user if they would like to play again 
  cout << "Would you like to play again?" << endl;
  cout << " Enter Y or N" << endl;
  cin >> Answer;


   // determines if User answer was valid 
  LegitAnswer = (Answer == 'Y' | Answer == 'N'|
  Answer == 'y' | Answer == 'n');
 
 
  // if answer if not valid reprompts user
  while (LegitAnswer == false) 
 {
   cin.clear ( ) ;
   cin.ignore (200, '\n');
   cout << "Please enter a valid answer ";
   cin >> Answer;
   LegitAnswer = (Answer == 'Y' | Answer == 'N'|
   Answer == 'y' | Answer == 'n');
}

     // If answer is Y replay status is true 
   if (Answer == 'y' | Answer == 'Y')
   ReplayStatus = true;
 
     // If answer is N replay status is false
   if (Answer == 'n' | Answer == 'N')
   ReplayStatus = false;

     // If answer is no prints goodbye message 
   if (ReplayStatus == false)
   cout << " Thank you for playing the high low casino game" << endl;

    // returns replay status
   return(ReplayStatus);
} // PlayAgain
