/*
 * TurnRight.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#include "TurnRight.h"

TurnRight::TurnRight(Robot* robot) : Behavior(robot){}

bool TurnRight::startCondition()
{
	if(_robot->isRightFree() )
		return true;
	else
		return false;
}

bool TurnRight::stopCondition()
{
	if(_robot->isForwardFree())
		return true;
	else
		return false;
}

void TurnRight::action()
{
	_robot->setSpeed(0.0, TURN_ANGLE);
}

TurnRight::~TurnRight() {}

