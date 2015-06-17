/*
 * Robot.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Robot.h"
#include <libplayerc++/playerc++.h>

Robot::Robot(char* ip, int port) {
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);
	//For fixing Player's reading BUG
	for(int i=0;i<15;i++)
		Read();
}

Robot::~Robot() {
	delete _pc;
	delete _pp;
	delete _lp;
}
