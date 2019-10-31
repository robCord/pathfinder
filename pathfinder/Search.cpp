//Pathfinder project
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

//main functions starts 
int main()
{
	//variables

	int targetLocation;

	int humaGuesses = 0;
	int humanTargetPosition = 0;
	//Hold range values for how large our square is for human
	int HumanLowRange = 1;
	int humanHighRange = 64;
	//variable to tell if human has found target 
	bool didHumanFindTarget = false;
	
	cout << "\n\t\t***Welcome to Pathfinder***" << endl;

	//todo: change to a random num generator
	//this holds the number of the square to be found between 1 and 64
	srand(time(0));
	targetLocation = rand() % 64 + 1;
	//******************************************************************************************************************
	//****************************************START HUMAN PLAYER*********************************************************
	//*******************************************************************************************************************
	//
	//Int Humans variables***********
	//
	//hold human's target prediction


	//start human prediction loop
	do
	{
		//display prompt and let human know what is going on
		cout << "You are searching for a target on a Grid with " << humanHighRange << " squares." << endl;

		//get input
		cout << "\nWhat location do you predict the target is at? ";
		cin >> humanTargetPosition;


		cout << "Human you choose " << humanTargetPosition << " as your prediction.\n";
		//give human hint if target is higher or lower than their prediction
		if (humanTargetPosition < targetLocation)
		{
			humaGuesses++;
			cout << "\nHint:: The target is higher than your target prediction.\n";
		}
		else if (humanTargetPosition > targetLocation)
		{
			humaGuesses++;
			cout << "\nHint:: The target is lower than your target prediction.\n";
		}
		//check human target guess
		if (humanTargetPosition == targetLocation)
		{
			cout << "\nHuman found target at " << targetLocation << endl;
			didHumanFindTarget = true;
			cout << "\nHuman guessed " << humaGuesses << " times\n";
		}
		else
		{
			cout << "\nTarget is not at location " << humanTargetPosition << ". Please try again." << endl;
			didHumanFindTarget = false;
		}
	} while (didHumanFindTarget == false);
	//******************************END HUMAN SEARCH*********************************
	//********************************************************************************
	//****************************************START LINEAR SEARCH AI PLAYER***********
	//********************************************************************************
	//
	//Int LINEAR variables***********
	//
	//hold  target prediction
	int linearGuesses = 0;
	int linearTargetPosition = 0;
	//Hold range values for how large our square is for human
	int linearLowRange = 1;
	int linearHighRange = 64;
	//variable to tell if human has found target 
	bool didlinearFindTarget = false;
	do
	{
		//start linear prediction code loop
	//display prompt
	
		cout << "\nLinear search is about to make a prediction\n";
		//get input from linear search AI
		linearTargetPosition++;
		if (linearTargetPosition == targetLocation)
		{
			cout << "\nLinear found target at " << targetLocation << endl;
			didlinearFindTarget = true;

		}
		else
		{
			linearGuesses++;
			cout << "\nTarget is not located " << linearTargetPosition << ". Please try again." << endl;
			didlinearFindTarget = false;
		}
	} while (didlinearFindTarget == false);


	//display game results
	cout << "\n\tHuman took " << humaGuesses << " guesses to find target location\n";
	cout << "\n\tAI took " << linearGuesses << " guesses to find target location";
	//exit function
	return 0;
}