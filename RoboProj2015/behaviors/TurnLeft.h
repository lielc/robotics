/*
 * TurnLeft.h
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#ifndef TURNLEFT_H_
#define TURNLEFT_H_

#include "./Behavior.h"

class TurnLeft: public Behavior {
public:
	TurnLeft(Robot* robot);
	virtual ~TurnLeft();
	bool startCondition();
	bool stopCondition();
	void action();
};

#endif /* TURNLEFT_H_ */
