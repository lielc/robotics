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

}

WaypointManager::~WaypointManager() {
}

string WaypointManager::Path()
{
	vector < pair<int,int> > Points;
	string FinalDir;
	int NumOfSteps = 0;
	int NumOfDir = 0;

	string Directions = (new PathPlanner())->pathFind(xStart,yStart,xEnd,yEnd,&Points);

	for (int NumOfPnt=Points.size()-1;NumOfPnt>1;NumOfPnt--)
	{
		if (NumOfSteps==3 || Directions[NumOfDir]!=Directions[NumOfDir+1])
		{
			pair<int,int> pnt;
			pnt.first = Points[NumOfPnt].first;
			pnt.second = Points[NumOfPnt].second;

			FinalPoints.push_back(pnt);
			FinalDir[NumOfDir]=Directions[NumOfDir];
			NumOfDir++;
			NumOfSteps=0;
		}
		NumOfSteps++;
	}
	pair<int,int> pnt;
	pnt.first = xEnd;
	pnt.second = yEnd;
	FinalPoints.push_back(pnt);
	return FinalDir;
}
