#include "Header.h"

string toLowerCase(string str)
{
	string lowerCase = "";
	for (char elem : str)
		lowerCase += tolower(elem);
	return lowerCase;
}