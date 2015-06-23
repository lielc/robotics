/*
 * Manager.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "./Robot.h"
#include "./PathPlanning/Plan.h"
#include "./behaviors/Behavior.h"

class Manager {
	Behavior* _behaviors[4];
	Robot* _robot;
public:
	Manager(Robot* robot, Plan* pln);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
