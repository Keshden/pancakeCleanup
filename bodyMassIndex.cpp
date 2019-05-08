/*
  bodyMassIndex.cpp created by keshden 4/30/2019.
  Version 1.0 will be programmed to simply get the weight and height and calculate.
  Version 2.0*(Hopefully coming soon) will update it to include  checks
    -Verify that a valid weight and height were entered.(X)
    -Verify that user entered information correctly before proceeding with calculations(X)
  Updated to have above 2 mentioned functionality by Keshden as of 5/8/2019
    -After calculations ask user if they wish to repeat
    -Give user option to see what 'weight ranges' would be optimal
*/

#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
  int weight, height;
  float bmi;
  bool correct = false;

  cout << "Welcome to the Body Mass Index calculator.\n\n"
    << "This program will ask you for your weight and height and calculate your BMI." << endl;

  cout << "The program will also let you know if the BMI indicates underweight,\n overweight, or optimal.\n\n";
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
        cout << "You have entered in a weight greater than 1500.";
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

    char userConfirmation = 'N';
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

  return 0;

}
