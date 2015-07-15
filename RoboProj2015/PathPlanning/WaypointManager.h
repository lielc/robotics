/*
 * WaypointManager.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <vector>

using namespace std;

class WaypointManager {
public:
	WaypointManager();
	virtual ~WaypointManager();
	string Path();
	vector < pair<int,int> > FinalPoints;
};

#endif /* WAYPOINTMANAGER_H_ */
