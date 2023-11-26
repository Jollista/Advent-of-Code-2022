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
		case 'X': //You choose Rock
			return 1;

		case 'Y': //You choose Paper
			return 2;
		
		case 'Z': //You choose Scissors
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
		case 'X': //You choose Rock and tie
			return 3;

		case 'Y': //You choose Paper and win
			return 6;
		
		case 'Z': //You choose Scissors and lose
			return 0;
		}
	} 
	else if (action == 'B') //They choose Paper
	{
		switch (response)
		{
		case 'X': //You choose Rock and lose
			return 0;

		case 'Y': //You choose Paper and tie
			return 3;
		
		case 'Z': //You choose Scissors and win
			return 6;
		}
	}
	else //action == 'C'; They choose Scissors
	{
		switch (response)
		{
		case 'X': //You choose Rock and win
			return 6;

		case 'Y': //You choose Paper and lose
			return 0;
		
		case 'Z': //You choose Scissors and tie
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
			points = getPoints(line[0], line[2]);
			cout << line << " = " << points << endl;
			score += points;
		}

		cout << "Total Score: " << score << endl;
	}
}