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
	const double TURN_ANGLE = 0.5;
	const double FORWARD_SPEED = 0.8;

public:
	Behavior(Robot* robot);
	virtual ~Behavior();
	virtual bool startCond() = 0;
	virtual bool stopCond() = 0;
	virtual void action() = 0;
	void addBeh(Behavior* behvior);
	Behavior* getNextBeh();
};

#endif /* BEHAVIOR_H_ */
