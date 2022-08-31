#include "Header.h"

#include <time.h>
#include <ctime>

void Menu()
{
	string inFilePath = "input.csv";
	string outfilePath = "output.csv";
	string answer = "";
	cout << "Menu:";
	do
	{
		cout << endl;
		cout << "1 - process file" << endl;
		cout << "2 - exit" << endl;
		cout << ">";

		getline(cin, answer);

		if (answer == "process file" || answer == "1")
		{
			cout << "Enter file path, for example: c:\\input.csv" << endl;
			cout << "or rename the input.csv file by placing it in the directory with the program" << endl;
			cout << "and press enter : " << endl;
			cout << ">";
			getline(cin, inFilePath);
			cout << endl;
			
			if(inFilePath.empty())
			{
				inFilePath = "input.csv";
			}
			
			vector<InputData> data = ReadFile(inFilePath);
			if (!data.empty())
			{
				map<MapKey, int, ClassCompare> output = TransformData(data);
				WriteFile(outfilePath, output);
			}
			else
			{
				cout << "There is no data to write to the file." << endl;
			}
			
		}
		if (answer == "exit" || answer == "2")
		{
			exit(0);
		}
		
	} while (answer != "exit");
}