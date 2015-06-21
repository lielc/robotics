/*
 * WaypointManager.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

class WaypointManager {
public:
	WaypointManager();
	virtual ~WaypointManager();
	string getPath(int xStart, int yStart, int xEnd, int yEnd);
	void selectedWayPoints();
};

#endif /* WAYPOINTMANAGER_H_ */
