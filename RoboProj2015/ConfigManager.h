/*
 * ConfigManager.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
const string CONFIGURATION_FILE_PATH = "./parameters.txt";
const string MAP_SECTION = "map:";
const string START_LOCATION_SECTION = "startLocation:";
const string GOAL_SECTION = "goal:";
const string ROBOT_SIZE_SECTION = "robotSize:";
const string MAP_RESOLUTION_SETION = "MapResolutionCM:";
const string GRID_RESOLUTION_SECTION = "GridResolutionCM:";

struct startLocation {
  int X;
  int Y;
  double Yaw;
} ;

struct goal {
  int X;
  int Y;
} ;

struct robotSize {
  int width;
  int depth;
} ;

class ConfigManager {
	string _mapPath;
	startLocation _startLocation;
	goal _goal;
	robotSize _robotSize;
	double _mapResolutionCM;
	int _gridResolutionCM;
public:
	ConfigManager();
	void initializeConfParameters();
	string getMapPath();
	int getStartLocationX();
	int getStartLocationY();
	int getStartLocationYaw();
	int getGoalLocationX();
	int getGoalLocationY();
	int getRobotWidth();
	int getRobotDepth();
	double getMapResolution();
	int getGridResolution();
	virtual ~ConfigManager();
};

#endif /* CONFIGMANAGER_H_ */
