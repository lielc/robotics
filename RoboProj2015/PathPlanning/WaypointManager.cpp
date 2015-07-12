/*
 * WaypointManager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "PathPlanner.h"
#include "WaypointManager.h"
#include "../ConfigManager.h"
#include <vector>

using namespace std;

int const xStart=(new ConfigManager())->getStartLocationX();
int const yStart=(new ConfigManager())->getStartLocationY();
int const xEnd=(new ConfigManager())->getGoalLocationX();
int const yEnd=(new ConfigManager())->getGoalLocationY();

WaypointManager::WaypointManager() {
	// TODO Auto-generated constructor stub

}

WaypointManager::~WaypointManager() {
	// TODO Auto-generated destructor stub
}

void Path()
{
	vector < pair<int,int> > Points;
	string Directions = (new PathPlanner())->pathFind(xStart,yStart,xEnd,yEnd,&Points);


}
