/*
 * Manager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Manager.h"

Manager::Manager(Robot* robot, Plan* pln) {
	_robot = robot;
	//_behaviors[0] = new GoForward();
}

void Manager::run()
{
	_robot->Read();

	/*if(!(_curr->startCond()))
		return;

	_curr->action();
	while(_curr !=NULL)
	{
		while(_curr->stopCond() == false)
		{
			_curr->action();
			_robot->Read();
		}
		_curr = _curr->getNextBeh();
		_robot->Read();
	}*/
}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}
