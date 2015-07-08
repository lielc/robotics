/*
 * ConfigManager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "ConfigManager.h"

ConfigManager::ConfigManager() {
	initializeConfParameters();
}

int ConfigManager::getGoalLocationX()
{
	return _goal.X;
}

int ConfigManager::getGoalLocationY()
{
	return _goal.Y;
}

int ConfigManager::getStartLocationX()
{
	return _startLocation.X;
}

int ConfigManager::getStartLocationY()
{
	return _startLocation.Y;
}

int ConfigManager::getRobotDepth()
{
	return _robotSize.depth;
}

int ConfigManager::getRobotWidth()
{
	return _robotSize.width;
}

int ConfigManager::getGridResolution()
{
	return _gridResolutionCM;
}

double ConfigManager::getMapResolution()
{
	return _mapResolutionCM;
}

string ConfigManager::getMapPath()
{
	return _mapPath;
}

string getSectionNameFromCurrLine(string currLine)
{
	size_t pos = currLine.find(" ");
	string sectionName = currLine.substr(0, pos);

	return sectionName;
}

void ConfigManager::initializeConfParameters()
{
	ifstream fileReader;
	fileReader.open(CONFIGURATION_FILE_PATH.c_str());

	while (!fileReader.eof())
	{
		string currLine;
		getline(fileReader, currLine);
		string sectionName = getSectionNameFromCurrLine(currLine);

		if (sectionName == MAP_SECTION)
		{
			this->_mapPath = currLine.substr(sectionName.length() + 1);
		}
		else if (sectionName == START_LOCATION_SECTION)
		{
			// Getting the value of the parameters
			string valuesString = currLine.substr(sectionName.length() + 1);
			size_t pos = valuesString.find(" ");
			string currValue = valuesString.substr(0, pos);

			// Cutting the rest of the needed data (Y and Yaw)
			valuesString.erase(0, pos + 1);

			// Initializing x start position
			this->_startLocation.X = atoi(currValue.c_str());

			// Initializing Y start position
			pos = valuesString.find(" ");
			currValue = valuesString.substr(0, pos);

			// Cutting the rest of the needed data (Yaw)
			valuesString.erase(0, pos + 1);

			// Initializing Y
			this->_startLocation.Y = atoi(currValue.c_str());

			// Initializing Yaw with what has remeind from the values string
			this->_startLocation.Yaw = atoi(valuesString.c_str());

		}
		else if (sectionName == GOAL_SECTION)
		{
			// Getting the value of the parameters
			string valuesString = currLine.substr(sectionName.length() + 1);
			size_t pos = valuesString.find(" ");
			string currValue = valuesString.substr(0, pos);

			// Cutting the rest of the needed data (Yaw)
			valuesString.erase(0, pos + 1);

			this->_goal.X = atoi(currValue.c_str());

			// Initializing the last argument with what's left of the values string
			this->_goal.Y = atoi(valuesString.c_str());
		}
		else if (sectionName == ROBOT_SIZE_SECTION)
		{
			// Getting the value of the parameters
			string valuesString = currLine.substr(sectionName.length() + 1);
			size_t pos = valuesString.find(" ");
			string currValue = valuesString.substr(0, pos);

			// Cutting the rest of the needed data (Yaw)
			valuesString.erase(0, pos + 1);

			this->_robotSize.width = atoi(currValue.c_str());

			// Initializing the last argument with what's left of the values string
			this->_robotSize.depth = atoi(valuesString.c_str());
		}
		else if (sectionName == MAP_RESOLUTION_SETION)
		{
			this->_mapResolutionCM = atof(currLine.substr(sectionName.length() + 1).c_str());
		}
		else
		{
			this->_gridResolutionCM = atoi(currLine.substr(sectionName.length() + 1).c_str());
		}
	}

	fileReader.close();
}

ConfigManager::~ConfigManager() {
	// TODO Auto-generated destructor stub
}

