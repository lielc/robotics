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

WaypointManager::WaypointManager() {

}

WaypointManager::~WaypointManager() {
}

string WaypointManager::Path()
{

	ConfigManager* cm = new ConfigManager();
	int const xStart=cm->getStartLocationX();
	int const yStart=cm->getStartLocationY();
	int const xEnd=cm->getGoalLocationX();
	int const yEnd=cm->getGoalLocationY();

	PathPlanner* Pathp = new PathPlanner();
	vector < pair<int,int> > Points;
	string FinalDir = "";
	int NumOfSteps = 0;
	int NumOfDir = 0;

	string Directions = Pathp->pathFind(xStart,yStart,xEnd,yEnd,&Points);

	pair<int,int> pnt;
	pnt.first = xStart;
	pnt.second = yStart;
	FinalPoints.push_back(pnt);

	for (int NumOfPnt=(Points.size()-1);NumOfPnt>1;NumOfPnt--)
	{
		if (NumOfSteps==3 || Directions[NumOfDir]!=Directions[NumOfDir+1])
		{
			pnt.first = Points[NumOfPnt].first;
			pnt.second = Points[NumOfPnt].second;

			FinalPoints.push_back(pnt);
			FinalDir+=Directions[NumOfDir];
			NumOfSteps=0;
		}
		NumOfSteps++;
		NumOfDir++;
	}
	FinalDir+=Directions[NumOfDir];
	pnt.first = xEnd;
	pnt.second = yEnd;
	FinalPoints.push_back(pnt);
	return FinalDir;
}
vector < pair<int,int> > WaypointManager::getFinalPoints()
{
	return FinalPoints;
}

