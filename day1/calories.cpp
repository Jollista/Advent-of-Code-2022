#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//update records
void updateRecord(int record[], int current)
{
	//loop through records
	for (int i = 0; i < 3; i++)
	{
		//if record at i is less than current, set it to current and stop
		//else, continue and allow lesser records a chance
		if (record[i] < current)
		{
			//set lesser records to previous next highest
			for (int j = 2; j > i; j--)
			{
				record[j] = record[j-1];
			}

			//update this record
			record[i] = current;

			//stop
			return;
		}
	}
}

int main()
{
	//get input file
	ifstream inFile ("input.txt");
	string str;

	int record[3];
	int current = 0;

	if (inFile.is_open())
	{
		while (inFile.peek() != EOF)
		{
			//get next line
			getline(inFile, str);
			cout << str + "\n";

			//on newline, end of current elf
			if (str.compare("") == 0)
			{
				//output elf total
				cout << "\ttotal: " << current <<endl;

				//record maximum of current max and current count
				updateRecord(record, current);
				
				//reset current
				current = 0; 
			} 
			else
			{
				//convert line to integer and add to current
				current += stoi(str);
			}
		}
		
		//output answer
		cout << endl;
		cout << "1st: " << record[0] << endl;
		cout << "2nd: " << record[1] << endl;
		cout << "3rd: " << record[2] << endl;
		cout << endl << "Total of the top three: " << (record[0]+record[1]+record[2]) << endl;
	}
}