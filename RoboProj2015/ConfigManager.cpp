/*
 * ConfigManager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "ConfigManager.h"

ConfigManager::ConfigManager() {

}

string getSectionNameFromCurrLine(string currLine)
{
	size_t pos = currLine.find(":");
	string sectionName = currLine.substr(0, pos);

	return sectionName;
}

void ConfigManager::initializeConfParameters()
{
	ifstream myReadFile;
		myReadFile.open(CONFIGURATION_FILE_PATH.c_str());

		while (!myReadFile.eof())
		{
			string currLine;
			getline(myReadFile, currLine);
			string sectionName = getSectionNameFromCurrLine(currLine);

			if (sectionName == MAP_SECTION)
			{

			}
			else if (sectionName == START_LOCATION_SECTION)
			{

			}
			else if (sectionName == GOAL_SECTION)
			{

			}
			else if (sectionName == ROBOT_SIZE_SECTION)
			{

			}
			else if (sectionName == MAP_RESOLUTION_SETION)
			{

			}
			else
			{
			}
		}
}

ConfigManager::~ConfigManager() {
	// TODO Auto-generated destructor stub
}

