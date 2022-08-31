#include "Header.h"

void WriteFile(string filePath, map<MapKey, int, ClassCompare> mapData)
{
	ofstream file;

	file.open(filePath);
	if (file.is_open())
	{
		cout << "Write to file..." << endl;

		file << "Name" << ";" << "Month" << ";" << "Total hours" << endl;

		for (auto pair : mapData) {
			file << pair.first.name << ";" << pair.first.month << ";" << pair.second << endl;
		}
		cout << "File result: " << filePath << endl << endl;
	}
	file.close();

	
}