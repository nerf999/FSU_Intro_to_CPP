=

/*============================================================================ */
/* PROGRAM cable Bill Calculator 
AUTHOR: <john alton>
FSU MAIL NAME: <JMA20>
RECITATION SECTION NUMBER: <04>
RECITATION INSTRUCTOR NAME:<Priya> 
COP 3363 - Fall 2022
PROJECT NUMBER: 2
DUE DATE: Thursday 9/22/2022
PLATFORM: g++ / UNIX OS

SUMMARY
A customer of a cable company needs to caculate their monthly bill. The cable 
company offers three different packages ( A,B,C).

 Package A is $9.95 permonth with 10 hours of included access with
 each additional hour costing $2.00.

 Package B costs $14.95 per month with 20 hours of included access, and 
each additonal hour costs $2.00. 

Package C costs %19.95 per month with unlimited included hours of access.  

INPUT 

The user will input which cable package they have (A,B,C) 
and the amount of hours they have watched as a numerical value.

OUTPUT 
The program will out put the total cost for the month 
based on the inputs of the customer. if the 
customer could save money by switching to a higher package then the 
program will alert the user of what package they should get and
how much money it would save them. 

ASSUMPTIONS

The user inputs the correct package, and a valid number 
of hours. The user inputs the hours as a number between 0 and 744

/* ========================================================================== */
/* HEADER FILES */

#include <iostream>
#include <iomanip>
using namespace std; 
/* ========================================================================== */  
/* MAIN FUNCTION */ 

int main ()
{  
   // NAMED CONSTANTS 
  char Package;            // Type of subscroption packag 
  double PackagePrice,     // Price of selected package type
   HoursWatched,           // Amount of hours watched for the month
   HourlyRate,             // the cost per each additional hour of watchtime
   FinalPrice,             // final price for the given data
   SavingsB,               // savings if user switched to package B
   SavingsC;               // savings if the user switched to package C
  bool PackageDataOK;      // True if package choice is valid, false outherwise
  bool HoursDataOK;        // True if entered hours are valid, false outherwiise

// print out welcome message and ask user to input package type
cout << "===============================================" << endl;
cout << " Welcome to the Subscription Package Calculator" << endl;

cout << " please enter which package you have (A,B,C)"<< endl;
cin >> Package;

// selected package type determines price and hourly rate for price calculations 
if ((Package == 'A')|(Package == 'a'))
 (PackagePrice = 9.95) && (HourlyRate = 2.00); 

else if ((Package == 'B')|(Package == 'b'))
(PackagePrice = 14.95) && (HourlyRate = 1.00);

else if ((Package == 'C')|(Package == 'c'))
(PackagePrice = 19.95) && (HourlyRate = 0.0);

// test for the validity of selected package type
PackageDataOK  = (Package == 'a'| Package == 'b' | Package == 'c' | Package == 'A' | Package == 'B' | Package == 'C');
if (PackageDataOK) 
{  
 
cout <<"===============================================" << endl;

// user inputs number of hours watched for the month 
cout << " please input number of hours watched for this month" << endl;
cin >> HoursWatched;

cout <<"==============================================="<< endl;
 
//tests for validity of hours watched in a month 
HoursDataOK = (744 >=  HoursWatched) &&(HoursWatched >= 0);
if (HoursDataOK)
 
// test if package is "A"  and if hours watched are under the savings threshhold
{if (((Package == 'A')| (Package == 'a'))&& (10 >=  HoursWatched ))
{FinalPrice = (PackagePrice); // out puts final price with the given data 
cout << "Your bill is $"  << FinalPrice << endl;}

// tests if package is "A" and if given hours is above savings threshhold 
if (((Package == 'A')| (Package == 'a'))&& (HoursWatched > 10))
// determines final price with given data
{ FinalPrice = (PackagePrice + (HoursWatched * HourlyRate)- 20 );

// determines the discount number for switching to paxkage B with no extra hours
if (20 > HoursWatched)
SavingsB = ( FinalPrice - 14.95);
// determines the discount number for switching to package B with excess hours  
if (HoursWatched > 20)
SavingsB = (FinalPrice - (14.95 + (HoursWatched * 1) - 20 ));
// determines discount number for switching to package C 
SavingsC = (FinalPrice - 19.95);

// outputs final bill and the size of discount for different packages. 
cout << " Your bill is $" << FinalPrice << endl;
cout <<"==============================================="<< endl;
cout << " If you switched to package B you would save $"  << SavingsB << endl;
cout <<"==============================================="<< endl;
cout << " If you switched to package C  you would save $"  << SavingsC << endl;
} 

// determines if package is "B" and if hours are under savings threshhold 
if (((Package == 'B')| (Package == 'b'))&& (20 >= HoursWatched))
{FinalPrice = (PackagePrice);  // out puts final price 
cout << " Your bill is $" << FinalPrice << endl;}

// determines if package is "B" and if hours are under savings threshhold 
else if (((Package == 'B')| (Package == 'b'))&& (25 >= HoursWatched))
{FinalPrice = (PackagePrice + (HoursWatched * HourlyRate)- 20 );
cout << " Your bill is $" << FinalPrice << endl;}

// determines if package is "B" and if hours are over savings threshhold
if (((Package == 'B')|(Package == 'b'))&& (HoursWatched > 25))
{FinalPrice = (PackagePrice + (HoursWatched * HourlyRate)- 20 );

// outputs final bill and discount for different packages
cout << " Your bill is $" << FinalPrice << endl;

cout <<"==============================================="<< endl;

SavingsC = (FinalPrice - 19.95);

cout << "If you switched to package C  you would save $"  << SavingsC << endl;

}

// determines if package is "C" 
if ((Package == 'C')|(Package == 'c'))
{FinalPrice = (PackagePrice);
cout << " Your bill is $" << FinalPrice << endl;}

// outputs goodbye message for successful run
cout <<"===============================================" << endl;
cout << " Thank you for using the Cable Package calculator" << endl; 
}

// out puts message for invalid hours entered 
else
cout << "Invalid hours entered" << endl;
}
// out puts message for invalid package entered 
else 
cout << "Invalid package entered" << endl;

return(0); 
}



//=============================================//
//                      END OF PROGRAM         //
//=============================================//
