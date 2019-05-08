/*
  mathTutor.cpp created by Keshden 4/30/2019
  This will simply display 2 random numbers and ask the user to solve.
  if the user correctly inputs the answer, the program will display thusly.
  IE: "Congratulations, that is correct".
  If incorrect, a message will be displayed for that as well.

  Version 1.0: This will be a simple program that will iterate once, for now, and display corresponding message for correct or incorrect submissions.
  Version 2.0: This will add a lot of functionality, such as:
    -It will provide as many 'problems' as desired by user, using a do while loop
 (?)-It will not only provide the 'incorrect' message, it will also provide a walk through to help them learn faster.
        -Use the %10 in order to get the 1's positions.
        -Use the /10, /100 to get how many 10's and hundreds there are and then *10 or *100 to revert without the 1's/10's present
        -Using all of these methods, can go through the process step by step to show how to do addition of big numbers
*/

#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int num1, num2, sum, userAnswer;
  bool repeat = false;
  /*
  //Place before the loop?
      cout << "Welcome to Math Tutor!\n";
      cout << "\nThis Program will cover addition with Large Numbers(up to 3 digits)";
      cout << "-------------------------\n\n";
  */
  do
  {
    unsigned seed = time(0);
    srand(seed);

    num1 = rand() % 1000;
    num2 = rand() % 1000;

    cout << "Welcome to Math Tutor!\n";
    cout << "\nThis Program will cover addition with Large Numbers(up to 3 digits)";
    cout << "-------------------------\n\n";
    //If I do take the above and place before loop, maybe use this instead
    //cout << "\n\nPlease solve the following addition problem.\n\n";

    cout << "\t " << num1 << endl;
    cout << "\t+" << num2 << endl;
    cout << "\t----" << endl;
    cout << "\t   ?" << endl;

    sum = num1 + num2;

    cout << "\n\nWhat is the solution?\n";
    cin >> userAnswer;

    if(userAnswer == sum)
    {
      cout << "\n\nThat is the correct answer!!!\n";
      cout << "\t " << num1 << endl;
      cout << "\t+" << num2 << endl;
      cout << "\t----" << endl;
      if(userAnswer / 1000 == 1)
        cout << "\t" << userAnswer << "√√√" << endl;
      else
        cout << "\t " << userAnswer << "√√√" << endl;
      cout << "Is correct.";
    }
    else
    //Can use the √√√ as well as x's to denote what is correct and what is wrong
    //can use nested if statements that will either place an X or a √ mark for each position.
      cout << "\n\nActually the answer is: " << sum << endl;

  //sum / 1000 == 1 ? cout << "\t" << sum << endl; : cout << "\t " << sum << endl;

  } while(repeat == true);
  return 0;
}
