/*
 * Behavior.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include <vector>
#include "../Robot.h"

class Behavior {
	std::vector<Behavior*> _behVec;

protected:
	Robot* _robot;
	static const double TURN_ANGLE = 0.8;
	static const double FORWARD_SPEED = 0.8;

public:
	Behavior(Robot* robot);
	virtual ~Behavior();
	virtual bool startCondition() = 0;
	virtual bool stopCondition() = 0;
	virtual void action() = 0;
};

#endif /* BEHAVIOR_H_ */
