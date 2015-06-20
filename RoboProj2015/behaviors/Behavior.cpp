/*
 * Behavior.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Behavior.h"

Behavior::Behavior(Robot* robot) : _robot(robot) {}

void Behavior::addBeh(Behavior* behavior) {
	_behVec.push_back(behavior);
}

Behavior* Behavior::getNextBeh() {

	for (unsigned int i=0 ; i < _behVec.size() ; i++)
	{
		if (_behVec[i]->startCond())
			return _behVec[i];
	}
	return NULL;
}

Behavior::~Behavior() {}
