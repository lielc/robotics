/*
 * GoForward.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#include "GoForward.h"

GoForward::GoForward(Robot* robot) : Behavior(robot) {}

GoForward::~GoForward() {}

bool GoForward::startCondition()
{
	if(_robot->isForwardFree() )
		return true;
	else
		return false;
}

bool GoForward::stopCondition()
{
	if(!(_robot->isForwardFree()))
		return true;
	else
		return false;
}

void GoForward::action()
{
	_robot->setSpeed(FORWARD_SPEED, 0.0);
}

