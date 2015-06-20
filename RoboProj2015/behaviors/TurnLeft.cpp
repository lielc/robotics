/*
 * TurnLeft.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot) : Behavior(robot) {}

TurnLeft::~TurnLeft() {}

bool TurnLeft::startCondition()
{
	if(_robot->isLeftFree())
		return true;
	else
		return false;
}

bool TurnLeft::stopCondition()
{
	if(_robot->isForwardFree())
		return true;
	else
		return false;
}

void TurnLeft::action()
{
	_robot->setSpeed(0.0, TURN_ANGLE*(-1));
}
