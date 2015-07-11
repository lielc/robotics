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
#include "./behaviors/GoForward.h"
#include "./behaviors/TurnUntilFree.h"
#include "./behaviors/TurnLeft.h"
#include "./behaviors/TurnRight.h"

class Manager {
	std::vector<Behavior*> behaviors;
	Behavior* _currentBeh;
	Robot* _robot;
public:
	Manager(Robot* robot);
	void run();
	Behavior* getNextBeh(std::vector<Behavior*> behVec);
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
