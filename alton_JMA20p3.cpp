/*============================================================================*/
/* PROGRAM Tractor Beam Calculator
AUTHOR: <john alton>
FSU MAIL NAME: <JMA20>
RECITATION SECTION NUMBER: <04>
RECITATION INSTRUCTOR NAME:<Priya>
COP 3363 - Fall 2022
PROJECT NUMBER: 3
DUE DATE: Thursday 10/06/2022
PLATFORM: g++ / UNIX OS

SUMMARY 

The USS Enterprise is going near a hostile planet
that may use a tractor beam to pull the ship down.
The ship can leave the tractor beam if it has enough 
fuel for the given strength of the beam and the force of gravity.
to determine if the ship can make it out of this scenario a 
simulation must be run. The user is asked to enter the initial 
altitude (In KM), the amount of fuel (In KG), and the strength of 
the tractor beam (Km/min/min). The program will then run
 a minute by minute simulation of what would happen, and recommend a course
of action. 


INPUT 

The user will input the altitude of the ship to the planet 
in KM, The amount of fuel in KG, and the strength of the tractor beam.

OUTPUT

The output will be a simulation of the scenario with the 
given parameters. The simulation will go minute by minute displaying 
the values as they change. the simulation will end when enough fuel is 
in the tank to escape, or it will end when the ship crashes. 

ASSUMPTIONS

The user inputs valid data.


/*===================================================================================*/  
/* HEADER FILES */

#include <iostream>
#include <iomanip>
using namespace std;


/*===================================================================================*/
/* MAIN FUNCTION */ 

int main()
{ 

     // User Inputs 

      double Fuel_amount,     // current fuel amount 
             Ship_altitude,   // altitude of ship above planet 
             Beam_strength,   // strength of tractor beam 
             Fuel_required,   // required fuel to escape beam 
             Time_minutes;    // the minute by minute value of time 

              char Answer;    // Y or N answer from user that starts the simulation 
 
   cout<< "============================================" << endl;

    // print out welcome message  
   cout<< " Welcome to the Tractor Beam Simulation" << endl;
   cout<< "=========================================================" << endl; 
   cout<< " Would you like to run the simulation please enter Y or N" << endl; 
   cin >> Answer;

       // asks user if they want to run simulation. will ask again at end 
       while ((Answer == 'y')||(Answer == 'Y'))
{
                           
   cout<< "============================================" << endl; 
   cout<< " Please input current fuel levels in KG" << endl;
     
    cin >> Fuel_amount; 
   cout<< "============================================" << endl;
   cout<< " Please input ship altitude in KM" << endl;
   
   cin >> Ship_altitude; 
    
   cout<< "============================================" <<endl;
   cout<< " Please input strength of the tractor beam" << endl;      

   cin >> Beam_strength;

   // set initial required fuel 
   Fuel_required = (1 - Ship_altitude / 200000) * Beam_strength;
  
      double Time_minutes = 0.0;  // set time at start of simulation

 
     // runs calculations if fuel is too low or ship hasnt crashed 
     // loop will end if the ship gets enough fuel to escape or crashes    
     while ((Fuel_amount < Fuel_required)&&( Ship_altitude > 0)) 
  
 { 
     if (Time_minutes < 1) // prints chart headers when simulation starts 
      cout << "TIME      ALTITUDE       FUEL AVAILABLE    FUEL REQUIRED" << endl;
  
     if (Time_minutes < 1)
      cout <<"========================================================="<< endl;
 
      
         Fuel_amount += 10; // adds 10 Kg of fuel every loop iteration ( minute)
         Time_minutes += 1; // adds 1 minute to the time every iteration of the loop

 
        // calculates new altitude every time loop executes
       Ship_altitude = (Ship_altitude - Beam_strength * Time_minutes);

       // Calculates new amount of fuel required every iteration of the loop
       Fuel_required = ((1 - Ship_altitude / 200000) * Beam_strength);


          // prints the values for every iteration of the loop 
          cout << Time_minutes << setw(10)  
        << Ship_altitude<< " Km"  << setw(18)<< Fuel_amount<<" Kg" << setw(18)
        << Fuel_required  <<" Kg"<< endl; // outputs values into table
 }      


      // output message for if the ship is going to crash 
      if ( Ship_altitude <= 0 )
      cout << "The ship will crash in " << Time_minutes <<  
         " minutes with the given data" <<  endl;    
      
      // output message for if the ship has enough fuel to escape
      if (Fuel_amount >= Fuel_required )
      cout << " Sufficient fuel amount will be present "<< Time_minutes << " minutes" <<  endl;  


     
              // asks user if they would like to run the simulation again
             cout << " Would you like to run the simulation again? Please enter Y or N" << endl; 
             cin >> Answer;
 }  
             // print closing message 
             cout << " Thank you for using the tractor beam calculator" << endl; 

    return(0);
}



 
/*============================================================================*/
/*                         End of PROGRAM                                     */
/*============================================================================*/
