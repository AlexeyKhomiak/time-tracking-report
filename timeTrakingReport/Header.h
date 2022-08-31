#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

class InputData
{
public:
	string name;
	string email;
	string department;
	string position;
	string project;
	string task;
	string date;
	int month;
	int year;
	int hours;

	InputData() {
		name = "";
		email = "";
		department = "";
		position = "";
		project = "";
		task = "";
		date = "";
		month = 0;
		year = 0;
		hours = 0;
	}

	InputData(string n, string e, string d, string p, string pr, string t, string dt, int m, int y, int h)
	{
		name = n;
		email = e;
		department = d;
		position = p;
		project = pr;
		task = t;
		date = dt;
		month = m;
		year = y;
		hours = h;
	}
};

//class OutputData
//{
//public:
//	string name;
//	string month;
//	int hours;
//
//	OutputData() 
//	{
//		name="";
//		month="";
//		hours=0;
//	}
//	OutputData(string n, string m, int h) : name(n), month(m), hours(h)
//	{}
//};

class MapKey 
{
public:
	string name;
	string month;
	
	MapKey(const string& n, string m) : name(n), month(m)
	{}
};

struct ClassCompare
{
	bool operator() (const MapKey& lhs, const MapKey& rhs) const
	{
		if (lhs.name == rhs.name) {
			return lhs.month < rhs.month;
		}
		else
		{
			return lhs.name < rhs.name;
		}
	}
};

void SetColorBgTex(int Bg, int Tex);
void Menu();
vector<InputData> ReadFile(string filePath);
void WriteFile(string filePath, map<MapKey, int, ClassCompare> data);
string toLowerCase(string str);
map<MapKey, int, ClassCompare> TransformData(vector<InputData> data);
string getMonthName(int month);
