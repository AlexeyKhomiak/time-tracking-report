#include "Header.h"

map<MapKey, int, ClassCompare> TransformData(vector<InputData> data)
{
	map<MapKey, int, ClassCompare> mapData;

	for (int i = 0; i < data.size(); i++)
	{		
		MapKey mapKey = MapKey(data[i].name, data[i].date);
		
		if (mapData.insert(make_pair(mapKey, data[i].hours)).second == false)
        {
			mapData[mapKey] = mapData.at(mapKey) += data[i].hours;
        }
	}

	return mapData;
}