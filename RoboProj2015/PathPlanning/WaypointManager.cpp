/*
 * WaypointManager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "WaypointManager.h"
#include "PathPlanner.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

WaypointManager::WaypointManager() {

}

WaypointManager::~WaypointManager() {
}

string getPath(int xStart, int yStart, int xEnd, int yEnd)
{
	return ((new PathPlanner)->pathFind(xStart, yStart, xEnd, yEnd));
}
void selectedWayPoints()
{
	int xStart=0; //need to get from ConfigManager
	int yStart=0; //need to get from ConfigManager
	int xEnd=100; //need to get from ConfigManager
	int yEnd=100; //need to get from ConfigManager

	string path = getPath(xStart,yStart,xEnd, yEnd);
	for(int i=0; i<(path.length()-1);i++)
	{
		if(!(path[i]==path[i+1]))
		{
			//TO DO need to add add particle check
		}
	}
}
