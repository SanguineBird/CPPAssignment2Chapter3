/*
Meghan Moore
February 7, 2015
CIT 245 - Data Structures and Programming C++
Assignment 2 - Chapter 3
Purpose: Write a program that uses a function that returns a number between 1 and 6.
Tabulate the difference between the expected outcome (odds) and the random number generator outcome – list this as error.
*/

#include <ctime> //time
#include <cstdlib> //srand, rand
#include <iostream> //cin, cout, cerr
using namespace std;

int d6Roll();
bool repeatPrompt();

//------------------------------
int main(){
  //format all following output doubles to two decimal places
  cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
  
  bool tryAgain;
  int rolls, result, dieOne, dieTwo, sum;
  int sumTwo, sumThree, sumFour, sumFive, sumSix, sumSeven, sumEight,
    sumNine, sumTen, sumEleven, sumsumTwelve;
  int oddsTwo, oddsThree, oddsFour, oddsFive, oddsSix, oddsSeven,
    oddsEight, oddsNine, oddsTen, oddsEleven, oddsTwelve;

  cout << "This program rolls two dice and tabulates the results.\n\n";
  
  do{
    //clear all results from previous trial:
    sumTwo = 0; sumThree = 0; sumFour = 0; sumFive = 0; sumSix = 0;
    sumSeven = 0; sumEight = 0; sumNine = 0; sumTen = 0; sumEleven = 0;
    sumsumTwelve = 0;
    oddsTwo = 0; oddsThree = 0; oddsFour = 0; oddsFive = 0; oddsSix = 0;
    oddsSeven = 0; oddsEight = 0; oddsNine = 0; oddsTen = 0;
    oddsEleven = 0; oddsTwelve = 0;
    
    //collect user input:
    cout << "Please enter the number of rolls you want: ";
    cin >> rolls;
    
    //roll dice
    for(int i = 0, i <= rolls, i++){
      cout << "i = " << i << endl; //for testing only!!!!!!!!!!
      dieOne = d6Roll();
      dieTwo = d6Roll();
      sum = dieOne + dieTwo;
      
      switch (sum){
        case 2:
          sumTwo++;
          break;
        case 3:
          sumThree++;
          break;
        case 4:
          sumFour++;
          break;
        case 5:
          sumFive++;
          break;
        case 6:
          sumSix++;
          break;
        case 7:
          sumSeven++;
          break;
        case 8:
          sumEight++;
          break;
        case 9:
          sumNine++;
          break;
        case 10:
          sumTen++;
          break;
        case 11:
          sumEleven++;
          break;
        case 12:
          sumTwelve++;
          break;
        default:
          cerr << "Error: Ending Program";
          exit(1);
      } //end switch
    } //end for
    
    //calculate odds
    oddsTwo = ((1 * rolls) / 36);
    oddsThree = ((2 * rolls) / 36);
    oddsFour = ((3 * rolls) / 36);
    oddsFive = ((4 * rolls) / 36);
    oddsSix = ((5 * rolls) / 36);
    oddsSeven = ((6 * rolls) / 36);
    oddsEight = ((5 * rolls) / 36);
    oddsNine = ((4 * rolls) / 36);
    oddsTen = ((3 * rolls) / 36);
    oddsEleven = ((2 * rolls) / 36);
    oddsTwelve = ((1 * rolls) / 36);
    
    //calculate %Error and print results
    cout << "Sum\t#Rolled\t\tOdds\t\t% Error" << endl;
    cout << "2:\t" << sumTwo << "\t\t" << oddsTwo << "\t\t"
      << ((static_cast<double>(oddsTwo) - static_cast<double>(sumTwo)) * 100.0) << endl;
    cout << "3:\t" << sumThree << "\t\t" << oddsThree << "\t\t"
      << ((static_cast<double>(oddsThree) - (static_cast<double>(sumThree)) * 100.0) << endl;
    cout << "4:\t" << sumFour << "\t\t" << oddsFour << "\t\t"
      << ((static_cast<double>(oddsFour) - (static_cast<double>(sumFour)) * 100.0) << endl;
    cout << "5:\t" << sumFive << "\t\t" << oddsFive << "\t\t"
      << ((static_cast<double>(oddsFive) - (static_cast<double>(sumFive)) * 100.0) << endl;
    cout << "6:\t" << sumSix << "\t\t" << oddsSix << "\t\t"
      << ((static_cast<double>(oddsSix) - (static_cast<double>(sumSix)) * 100.0) << endl;
    cout << "7:\t" << sumSeven << "\t\t" << oddsSeven << "\t\t"
      << ((static_cast<double>(oddsSeven) - (static_cast<double>(sumSeven)) * 100.0) << endl;
    cout << "8:\t" << sumEight << "\t\t" << oddsEight << "\t\t"
      << ((static_cast<double>(oddsEight) - (static_cast<double>(sumEight)) * 100.0) << endl;
    cout << "9:\t" << sumNine << "\t\t" << oddsNine << "\t\t"
      << ((static_cast<double>(oddsNine) - (static_cast<double>(sumNine)) * 100.0) << endl;
    cout << "10:\t" << sumTen << "\t\t" << oddsTen << "\t\t"
      << ((static_cast<double>(oddsTen) - (static_cast<double>(sumTen)) * 100.0) << endl;
    cout << "11:\t" << sumEleven << "\t\t" << oddsEleven << "\t\t"
      << ((static_cast<double>(oddsEleven) - (static_cast<double>(sumEleven)) * 100.0) << endl;
    cout << "12:\t" << sumTwelve << "\t\t" << oddsTwelve << "\t\t"
      << ((static_cast<double>(oddsTwelve) - (static_cast<double>(sumTwelve)) * 100.0) << endl;
    cout << endl;
    
    //ask user if they want to repeat the experiment
    tryAgain = repeatPrompt();
    cout << endl << endl;
  }while (tryAgain = true);
  
  system("pause");
  return 0;
} //end main

//------------------------------
/*This function simulates the roll of a 6-sided die.
Precondition: none. Postcondition: returns pseudo-randon int between 1 and 6.*/
int d6Roll(){
  srand(time(NULL));
  int roll;
  
  roll = rand() % 6 + 1;
  return roll;
} //end d6Roll

//------------------------------
/*This function asks the user if they wish to repeat the main function.
Precondition: function is called into a loop dependent on a boolean value
where a return value of 'false' will end the loop.
Postcondition: If the user selects 1 for 'yes', the function will return
true, and the calling loop should repeat. If the user selects 0 for 'exit',
the function will return 'false', and the calling loop should end.
If any other input is given, the prompt will repeat.*/

bool repeatPrompt(){
  
  bool validInput, repeat;
  int input;

  do{
    cout << "Try Again? (1 = yes, 0 = exit)\n";
    cin >> input;
    cout << endl << endl;
  
    switch (input){
      case 0:
        validInput = true;
        repeat = false;
        break;
      case 1:
        validInput = true;
        repeat = true;
        break;
      default:
        validInput = false;
    } //end switch
  } while(validInput == false);
  
  return repeat;
} //end repeatPrompt
