/*
 * Manager.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef MANAGER_H_
#define MANAGER_H_
//#include "Plans/PlnObstacleAvoid.h"
#include "./Robot.h"
#include "./PathPlanning/Plan.h"
#include "./behaviors/Behavior.h"

class Manager {
	Behavior* _curr;
	Robot* _robot;
public:
	Manager(Robot* robot, Plan* pln);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
