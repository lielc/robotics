/*
 * Manager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Manager.h"
#include "PathPlanning/WaypointManager.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;


Manager::Manager(Robot* robot) {
	_robot = robot;
}

void Manager::run()
{
	string Directions;
	vector < pair<int,int> > Path;

	WaypointManager* wm = new WaypointManager();
	Directions = wm->Path();
	Path = wm->getFinalPoints();
	pair<int,int> psrc;
	pair<int,int> pdest;
	int sTime;
	double d, dX, dY;
	string currdir;

	while (true)
	{
		for (unsigned int i=0;i<Path.size()-1;i++)
		{
			psrc = Path[i];
			pdest = Path[i+1];
			currdir = Directions.substr(i+1,1);

			dX = (double)pdest.first - (double)psrc.first;
			dY = (double)pdest.second - (double)psrc.second;
			d = sqrt((double)((pow(dX,2))+(pow(dY,2))));
			sTime = (d/_robot->GetSpeed())+1;
			_robot->GoTo((double)pdest.first,(double)pdest.second,(double)(atoi(currdir.c_str())*0.8),sTime);
		}
	}
}

Behavior* Manager::getNextBeh(std::vector<Behavior*> behVec) {

	for (unsigned int i=0 ; i < behVec.size() ; i++)
	{
		if (behVec[i]->startCondition())
			return behVec[i];
	}
	return NULL;
}

Manager::~Manager() {
	for (unsigned int index = 0; index < behaviors.size(); index++) {
		delete behaviors[index];
	}

}
