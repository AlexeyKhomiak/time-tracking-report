#include "Header.h"

vector<InputData> ReadFile(string filePath)
{
	//vector<string> records;
	vector<InputData> inputData;
	InputData temp;

	ifstream file;
	
	int numRow = 1;
	int errorRow = 0;

	file.open(filePath);

	if (file.fail())
	{
		cout << "Unable to open the file " << filePath << endl;
		return inputData;
	}
	cout << "reading file..." << endl;
	while (file.peek() != EOF) {
		string name;
		string email;
		string department;
		string position;
		string project;
		string task;
		string date;
		string hours;

		int year;
		int month;
		int day;

		try
		{
			if (numRow > 1)
			{
				getline(file, temp.name, ';');
				getline(file, temp.email, ';');
				getline(file, temp.department, ';');
				getline(file, temp.position, ';');
				getline(file, temp.project, ';');
				getline(file, temp.task, ';');
				getline(file, date, ';');

				sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day);
				temp.date = getMonthName(month) +" "+ to_string(year);

				getline(file, hours, '\n');
				temp.hours = stoi(hours);

				inputData.push_back(temp);

			}
			else
			{
				getline(file, name, ';');
				if (toLowerCase(name) != "name")
					throw "Column name 'name' is invalid.";

				getline(file, email, ';');
				if (toLowerCase(email) != "email")
					throw "Column name 'email' is invalid.";

				getline(file, department, ';');
				if (toLowerCase(department) != "department")
					throw "Column name 'department' is invalid.";

				getline(file, position, ';');
				if (toLowerCase(position) != "position")
					throw "Column name 'position' is invalid.";

				getline(file, project, ';');
				if (toLowerCase(project) != "project")
					throw "Column name 'project' is invalid.";

				getline(file, task, ';');
				if (toLowerCase(task) != "task")
					throw "Column name 'task' is invalid.";

				getline(file, date, ';');
				if (toLowerCase(date) != "date")
					throw "Column name 'date' is invalid.";

				getline(file, hours, '\n');
				hours = toLowerCase(hours);
				hours.erase(hours.find_last_not_of(" ") + 1);
				if (hours != "logged hours")
					throw "Column name 'logged hours' is invalid.";

			}
		}
		catch (const char* msg)
		{
			cout << "Error occurred: " << msg << endl << endl;
			errorRow++;
			continue;
		}
		catch (const exception& ex)
		{			
			cout << "Error occurred: " << ex.what() << endl << endl;
			errorRow++;
			continue;
		}
		catch (...)
		{
			cout << "Unknown failure occurred." << endl << endl;
			errorRow++;
			continue;
		}

		numRow++;
	}

	cout << "file reading completed" << endl << endl;
	cout << "lines read: " << numRow << endl;
	cout << "error lines: " << errorRow << endl << endl;
	

	file.close();
	return inputData;
}


