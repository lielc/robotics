/*
 * TurnUntilFree.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: colman
 */

#include "TurnUntilFree.h"

TurnUntilFree::TurnUntilFree(Robot* robot) : Behavior(robot){}

bool TurnUntilFree::startCondition()
{
	if(!(_robot->isForwardFree()))
		return true;
	else
		return false;
}

bool TurnUntilFree::stopCondition()
{
	if(_robot->isForwardFree())
		return true;
	else
		return false;
}

void TurnUntilFree::action()
{
	_robot->setSpeed(0.0, TURN_ANGLE);
}

TurnUntilFree::~TurnUntilFree() {}

