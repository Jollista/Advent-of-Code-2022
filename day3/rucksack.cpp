#include <iostream>
#include <fstream>
#include <string>
//#include <ctype.h>
using namespace std;

//return the one character intersection between str1 and str2
char intersect(string str1, string str2)
{
	for (int i = 0; i < str1.length(); i++)
	{
		for (int j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
				return str1[i];
		}
	}

	//catchall
	return '!';
}

//return the int priority of the given character
int priorityOf(char character)
{
	int result = character;

	if (islower(character))
		result -= 96;
	else
		result -= 38;
	
	return result;
}

int main()
{
	//variables for reading input
	ifstream inputFile ("input.txt");
	string rucksack;

	//sum total of missorted priorities
	int sum = 0;

	if (inputFile.is_open())
	{
		//while there's more rucksacks
		while (inputFile.peek() != EOF)
		{
			//get next rucksack
			getline(inputFile, rucksack);

			//get substring compartments
			int compartmentLength = rucksack.length()/2;
			string compartment1 = rucksack.substr(0, compartmentLength);
			string compartment2 = rucksack.substr(compartmentLength, compartmentLength);

			//output
			cout << compartment1 << " | " << compartment2 << endl; //<< ((compartment1.length() == compartment2.length()) ? "True":"False") << endl;

			//get missorted item and its associated priority
			char item = intersect(compartment1, compartment2);
			int priority = priorityOf(item);

			//output
			cout << "missorted item: " << item  << " = " << priority << " priority" << endl;

			//add priority to sum
			sum += priority;
		}

		cout << "\nSum priorities = " << sum << endl;
	}
}