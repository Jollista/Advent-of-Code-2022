#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//return a fixed number of points based on selection
//'X' = 1; 'Y' = 2; 'Z' = 3; 
int getSelectionPoints(char selection)
{
	switch (selection)
	{
		case 'A': //You choose Rock
			return 1;

		case 'B': //You choose Paper
			return 2;
		
		case 'C': //You choose Scissors
			return 3;
	}

	//catchall
	return -1;
}

//0 if you lose, 3 if you draw, 6 if you win
int getOutcomePoints(char action, char response)
{
	if (action == 'A') //They choose Rock
	{
		switch (response)
		{
			case 'A': //You choose Rock and tie
				return 3;

			case 'B': //You choose Paper and win
				return 6;
			
			case 'C': //You choose Scissors and lose
				return 0;
		}
	} 
	else if (action == 'B') //They choose Paper
	{
		switch (response)
		{
			case 'A': //You choose Rock and lose
				return 0;

			case 'B': //You choose Paper and tie
				return 3;
			
			case 'C': //You choose Scissors and win
				return 6;
		}
	}
	else //action == 'C'; They choose Scissors
	{
		switch (response)
		{
			case 'A': //You choose Rock and win
				return 6;

			case 'B': //You choose Paper and lose
				return 0;
			
			case 'C': //You choose Scissors and tie
				return 3;
		}
	}
	
	//catchall
	return -1;
}

/// @brief Simulate a round of rock paper scissors
/// @param action other player's choice
/// @param response your response
/// @return score for round's outcome + score for your response
int getPoints(char action, char response)
{
	return getSelectionPoints(response) + getOutcomePoints(action, response);
}

/// @brief Determine the response to get a given result in a game of Rock Paper Scissors
/// @param action other player's choice (A=Rock, B=Paper, C=Scissors)
/// @param result your desired result (X=Lose, Y=Tie, Z=Win)
/// @return the response that will cause the desired result (A=Rock, B=Paper, C=Scissors)
char determineResponse(int action, char result)
{
	//if tie, match action
	if (result == 'Y')
		return action;
	
	//else if lose
	if (result == 'X')
	{
		switch (action)
		{
			case 'A': //Rock
				return 'C'; //respond Scissors

			case 'B': //Paper
				return 'A'; //respond Rock

			case 'C': //Scissors
				return 'B'; //respond Paper
		}
	}

	//else if win
	if (result == 'Z')
	{
		switch (action)
		{
			case 'A': //Rock
				return 'B'; //respond Paper

			case 'B': //Paper
				return 'C'; //respond Scissors

			case 'C': //Scissors
				return 'A'; //respond Rock
		}
	}
}

int main()
{
	//input reading vars
	ifstream inputFile ("input.txt");
	string line;

	//total cumulative score
	int score = 0;
	int points = 0;

	//ensure file is open
	if (inputFile.is_open())
	{
		//while there's still more file
		while (inputFile.peek() != EOF)
		{
			getline(inputFile, line);
			points = getPoints(line[0], determineResponse(line[0], line[2]));
			cout << line << " = " << points << endl;
			score += points;
		}

		cout << "Total Score: " << score << endl;
	}
}