/*
 * Behavior.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Behavior.h"

Behavior::Behavior(Robot* robot) : _robot(robot) {}

/*void Behavior::addBeh(Behavior* behavior,  std::vector<Behavior*> behVec) {
	_behVec.push_back(behavior);
}

Behavior* Behavior::getNextBeh(std::vector<Behavior*> behVec) {

	for (unsigned int i=0 ; i < behVec.size() ; i++)
	{
		if (behVec[i]->startCondition())
			return behVec[i];
	}
	return NULL;
}*/

Behavior::~Behavior() {}
