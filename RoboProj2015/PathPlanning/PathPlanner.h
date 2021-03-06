/*
 * PathPlanner.h
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#ifndef PATHPLANNER_H_
#define PATHPLANNER_H_

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

class PathPlanner {
public:

	PathPlanner();
	virtual ~PathPlanner();
	string pathFind(const int xStart, const int yStart, const int xEnd, const int yEnd, vector < pair<int,int> >* Points);

};

#endif /* PATHPLANNER_H_ */
