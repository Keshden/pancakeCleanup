/*
  bodyMassIndex.cpp created by keshden 4/30/2019.
  Version 1.0 will be programmed to simply get the weight and height and calculate.
  Version 2.0*(Hopefully coming soon) will update it to include  checks
    -Verify that a valid weight and height were entered.
    -Verify that user entered information correctly before proceeding with calculations
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

  cout << "Welcome to the Body Mass Index calculator.\n\n"
    << "This program will ask you for your weight and height and calculate your BMI." << endl;

  cout << "The program will also let you know if the BMI indicates underweight,\n overweight, or optimal.\n\n";

  cout << "Please enter your weight in pounds.\n";
  cin >> weight;

  cout << "\n\nPlease enter in your height in inches.\n";
  cin >> height;

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
