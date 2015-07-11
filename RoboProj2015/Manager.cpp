/*
 * Manager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Manager.h"
#include <vector>


Manager::Manager(Robot* robot) {
	_robot = robot;
	behaviors.push_back(new GoForward(_robot));
	behaviors.push_back(new TurnRight(_robot));
	behaviors.push_back(new TurnLeft(_robot));
	behaviors.push_back(new TurnUntilFree(_robot));
}

void Manager::run()
{

	Behavior* currBeh;

	currBeh = getNextBeh(behaviors);

	while(currBeh !=NULL)
	{
		_robot->Read();

		while(currBeh->stopCondition() == false)
		{
			currBeh->action();
			_robot->Read();
		}
		currBeh = getNextBeh(behaviors);
	}
}

Behavior* Manager::getNextBeh(std::vector<Behavior*> behVec) {

	for (unsigned int i=0 ; i < behVec.size() ; i++)
	{
		if (behVec[i]->startCondition())
			return behVec[i];
	}
	return NULL;
}

Manager::~Manager() {
	for (int index = 0; index < behaviors.size(); index++) {
		delete behaviors[index];
	}
}
