#include <iostream>
#include <fstream>
#include <string>
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

//return true if character is in string
bool in(char character, string str)
{

}

//return the one character intersection between str1 and str2
char intersect3(string str1, string str2, string str3)
{
	for (int i = 0; i < str1.length(); i++)
	{
		if (str2.find(str1[i]) != -1 && str3.find(str1[i]) != -1)
		{
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
	string rucksack[3];

	//sum total of missorted priorities
	int sum = 0;

	if (inputFile.is_open())
	{
		//while there's more rucksacks
		while (inputFile.peek() != EOF)
		{
			//get next rucksack
			cout << "\n\t-- GROUP --" << endl;
			for (int i = 0; i < 3; i++)
			{
				getline(inputFile, rucksack[i]);
				cout << rucksack[i] << endl; //output
			}

			

			//get missorted item and its associated priority
			char item = intersect3(rucksack[0], rucksack[1], rucksack[2]);
			int priority = priorityOf(item);

			//output
			cout << "group badge: " << item  << " = " << priority << " priority" << endl;

			//add priority to sum
			sum += priority;
		}

		cout << "\nSum priorities = " << sum << endl;
	}
}