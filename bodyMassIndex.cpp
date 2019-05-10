/*
  bodyMassIndex.cpp created by keshden 4/30/2019.
  Version 1.0 will be programmed to simply get the weight and height and calculate.
  Version 2.0*(Hopefully coming soon) will update it to include  checks
    -Verify that a valid weight and height were entered.(X)
    -Verify that user entered information correctly before proceeding with calculations(X)
  Updated to have above 2 mentioned functionality by Keshden as of 5/8/2019
    -After calculations ask user if they wish to repeat
    -Give user option to see what 'weight ranges' would be optimal
  Updated again to finish off the desired functionality. By: Keshden as of 5/10/2019
*/

#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
  int weight, height, userChoice;
  float bmi, lowerRange, upperRange;
  bool correct = false, repeat = false;
  char userConfirmation = 'N';

  cout << "Welcome to the Body Mass Index calculator.\n\n"
    << "This program will ask you for your weight and height and calculate your BMI." << endl;

  cout << "The program will also let you know if the BMI indicates underweight,\noverweight, or optimal.\n\n";
  do
  {
    do
    {
      cout << "Please enter your weight in pounds.\n";
      cin >> weight;

      while(weight <= 0 || weight > 1500)
      {
        if(weight <= 0)
        {
          cout << "Please enter a valid weight.  Your weight cannot be less than or equal to 0\n";
          cout << "Please enter your weight in pounds.\n";
          cin >> weight;
        }
        else
        {
          cout << "You have entered in a weight greater than 1500.\n";
          cout << "According to the Guinness Book of \nWorld Records, the heaviest person recorded ";
          cout << "weighed 1235 Lbs.\nPlease verify that you have correctly entered in your weight.\n";
          cout << "Please enter your weight in pounds.\n";
          cin >> weight;
        }
      }
      cout << "\n\nPlease enter in your height in inches.\n";
      cin >> height;

      while(height <= 0 || height > 120)
      {
        if(height <= 0)
        {
          cout << "You have entered in a height less than or equal to 0.\n";
          cout << "Please verify that you have correctly entered in your height in inches.\n";
          cout << "Please enter in your height again.\n";
          cin >> height;
        }
        else
        {
          cout << "You have entered in a Height that is greater than 120 inches, or 10 feet.\n";
          cout << "Please note that the Guinness Book of World records lists\nthe tallest recorded man to have been: ";
          cout << "8 ft. 11 inches, or 107 inches tall.\n";
          cout << "Please verify that you have correctly entered in your height in inches.\n";
          cout << "Please enter in your height again.\n";
          cin >> height;
        }
      }

      cout << "You have entered your weight as: " << weight << ".\nYou have also entered"
      << "your height as: " << height << ".\nIs this information correct?[Y/N].\n";
      cin >> userConfirmation;
      if(userConfirmation == 'y' || userConfirmation == 'Y')
      {
        correct = true;
      }
      else
      {
        correct = false;
      }
    } while(correct == false);
    bmi = static_cast<double>(weight * 703) / (height * height);

    cout << "\nYour BMI is: " << bmi << "\n\n";

    if (bmi > 25)
      cout << "Your BMI is above the optimal range for your weight and height.\n\n";
    else if (bmi > 18.5)
      cout << "Your BMI is within the optimal range for your weight and height.\n\n";
    else
      cout << "Your BMI is below the optimal range for your weight and height.\n\n";

    userChoice = 0;
    while(userChoice < 1 || userChoice > 3)
    {
      cout << "\n\nThanks for utilizing the Body Mass Index program.";
      cout << "\n\nPlease choose among the following options:";
      cout << "\n1)View your optimal weight range.";
      cout << "\n2)Repeat the program from the beginning.";
      cout << "\n3)Quit or End program.\n";
      cout << "Please enter either a 1, a 2, or a 3.\n";
      cin >> userChoice;
    }

    switch (userChoice)
    {
      //if bmi needs to be between 18.5 and 25 then:
      //to calculate the weight range would be using 18.5 and 25 for x
      //where (x(height times height))/703 = weight
      case 1:

              lowerRange = static_cast<double>(18.5*(height*height))/703;
              upperRange = static_cast<double>(25*(height*height))/703;
              cout << "The optimal weight range will be calculated based on the height you provided.";
              cout << "\nProvided height is: " << height;
              cout << "\nThe optimal weight range is: Between " << lowerRange
                << " and " << upperRange << endl;
              cout << "Repeat program? [Y/N]: \n";
              cin >> userConfirmation;
              if(userConfirmation == 'y' || userConfirmation == 'Y')
                repeat = true;
              else
                repeat = false;
              break;
      case 2:
              cout << "\n\n";
              repeat = true;
              break;
      case 3:
              repeat = false;
              break;
    }
  } while(repeat == true);

  return 0;

}
