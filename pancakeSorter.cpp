#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void pancakeGenerator(bool [], int);
void pancakeIllustrator(bool [], int);
void pancakeSolver(bool [], int);
bool checkCompletion(bool [], int);

int main()
{
    //pcamt = pancake amount
    int pcamt = 0, pcInput = 0;
    string validity;
    bool verify = false, same = false, again = true;

    cout << "This program is going to take a number from You(the user) between 1 and 100"
    << endl << "The number will determine how many pancakes there will be!\n";
    cout << "Then that many pancakes will be randomly generated, some facing up\n"
    << "And some facing down.  The program will iterate through until the pancakes all \nface up!\n\n\n";

    while(again == true)
    {
      //create variable to keep track of how many flips it takes to fix
      int flips = 0;
      //Now ask the user for how many pancakes to generate
      while(verify == false)
      {
        cout << "How many pancakes should there be?\n";
        cin >> pcInput;
        cout << "You have chosen " << pcInput << ".  If this is correct, please enter a 'y' to continue.\n";
        cin >> validity;
        if(validity == "y" or validity == "yes")
          verify = true;
      }

      pcamt = pcInput-1;

      //With the amount decided, create the pancakeStack variable and generate it.
      bool pancakeStack[pcamt];
      pancakeGenerator(pancakeStack, pcamt);

      //As a test, do a run through to make sure it retained all that information.
      cout << "Here is the randomized stack of " << pcInput << " Pancakes, from top of stack to bottom(plate)" << endl;
      cout << "The stacks are displayed in groups of 10\n";
      pancakeIllustrator(pancakeStack, pcamt);

      //Need to find the best grouping to flip the stack, so that become closer to perfection.
      same = checkCompletion(pancakeStack, pcamt);

      cout << "Let's solve this puzzle!" << endl;

      while(same == false)
      {
        //Create variable to go through and find biggest possible place to flip
        int findGrouping = pcamt;

        //Check to see if bottom of stack is good or not, if it is, don't touch
        if(pancakeStack[findGrouping] == true)
        {
          findGrouping--;

          //Obviously, if multiple consecutive pancakes(at bottom) are good, don't touch any
          while(pancakeStack[findGrouping] == pancakeStack[findGrouping+1])
          {
            findGrouping--;
          }

          //Now you have found the first possible flipping possition.  Check if matches the top.
          if(pancakeStack[findGrouping] == pancakeStack[0])
          {
            //If it is the same, then simply flip that whole section.
            //Call the solver function to flip the stack.
            pancakeSolver(pancakeStack, findGrouping);

            //Display updated stack of pancakeStack
            pancakeIllustrator(pancakeStack, pcamt);

            //Call the checker to see if it is done
            same = checkCompletion(pancakeStack, pcamt);

            if(same == true)
              cout << "The stack is perfect!" << endl;
            else
              cout << "There are still problems with the stack" << endl;

          }
          else
          {
            //If it isn't the same, then shuffle through to next possible position.
            findGrouping--;
            while(pancakeStack[findGrouping] == pancakeStack[findGrouping+1])
            {
              findGrouping--;
            }

            //Call the solver function to flip the stack.
            pancakeSolver(pancakeStack, findGrouping);

            //Display updated stack of pancakeStack
            pancakeIllustrator(pancakeStack, pcamt);

            //Call the checker to see if it is done
            same = checkCompletion(pancakeStack, pcamt);

            if(same == true)
              cout << "The stack is perfect!" << endl;
            else
              cout << "There are still problems with the stack" << endl;
          }
        }
        else
        {
          //Now you have found the first possible flipping possition.  Check if matches the top.
          if(pancakeStack[findGrouping] == pancakeStack[0])
          {
            //If it is the same, then simply flip that whole section.
            //Call the solver function to flip the stack.
            pancakeSolver(pancakeStack, findGrouping);

            //Display updated stack of pancakeStack
            pancakeIllustrator(pancakeStack, pcamt);

            //Call the checker to see if it is done
            same = checkCompletion(pancakeStack, pcamt);

            if(same == true)
              cout << "The stack is perfect!" << endl;
            else
              cout << "There are still problems with the stack" << endl;

          }
          else
          {
            //If it isn't the same, then shuffle through to next possible position.
            findGrouping--;
            while(pancakeStack[findGrouping] == pancakeStack[findGrouping+1])
            {
              findGrouping--;
            }

            //Call the solver function to flip the stack.
            pancakeSolver(pancakeStack, findGrouping);

            //Display updated stack of pancakeStack
            pancakeIllustrator(pancakeStack, pcamt);

            //Call the checker to see if it is done
            same = checkCompletion(pancakeStack, pcamt);

            if(same == true)
              cout << "The stack is perfect!" << endl;
            else
              cout << "There are still problems with the stack" << endl;
          }
        }
        flips++;
      }
      cout << "Here is the completed stack" << endl;
      pancakeIllustrator(pancakeStack, pcamt);
      cout << "It took " << flips << " flips to correct the stack.\n";
      cout << "Would you like to do it again?<Y/N>\n";
      cin >> validity;
      if(validity == "y" or validity == "yes")
      {
        again = true;
        verify = false;
      }
      else
        again = false;
    }
    return 0;
}

void pancakeGenerator(bool generatedPancake[], int amount)
{
  //create necessary variables as well as the random num generator
  int randomizer[amount];
  unsigned seed = time(0);
  srand(seed);

  //Go through each of the pancakes and randomly create a true or false value
  //Then output to the console to verify it is working.
  for(int x = 0; 0 <=x && x <= amount; x++)
  {
    randomizer[x] = rand() % 2;
    generatedPancake[x] = randomizer[x];
  }
}

void pancakeIllustrator(bool pancake[], int pcamt)
{
  //create a variable to run through the stack of pancakes
  int z = 0;

  //Now display the pancakes from the top of the stack, to the bottom.
  for(z; 0 <= z && z <= pcamt; z++)
  {
    cout << pancake[z] << " ";
    if(pcamt % 10 == 0)
      cout << endl;
  }
  cout << endl;
}


void pancakeSolver(bool pancakeMess[], int max)
{
  //create necessary variables to use to fix the stack
  int iterator = max;
  int frontrunner = 0;
  bool modify[max];

  //Create the modified, or flipped batch.
  for(iterator; 0 <= iterator && iterator <= max; iterator--)
  {
    modify[frontrunner] = !(pancakeMess[iterator]);
    frontrunner++;
  }

  //Now change the original to the new/current state
  for(iterator = 0; 0 <= iterator && iterator <= max; iterator++)
  {
    pancakeMess[iterator] = modify[iterator];
  }
}

bool checkCompletion(bool checking[], int max)
{
  bool allTrue = true;
  for(int x = 0; 0 <= x && x <= max; x++)
  {
    if(checking[x] == false)
      return false;
  }
  return allTrue;
}
