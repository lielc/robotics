/*
 * Robot.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Robot.h"
#include "ConfigManager.h"
#include <libplayerc++/playerc++.h>

Robot::Robot(char* ip, int port) {
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	ConfigManager cm;
	_pp->SetOdometry(cm.getStartLocationX(), cm.getStartLocationY(), cm.getStartLocationYaw());

	_pp->SetMotorEnable(true);

	for(int i=0;i<15;i++)
		Read();
}

bool Robot::GoTo(int x, int y, int yaw)
{
	_pp->GoTo((double)x,(double)y,(double)yaw);
	if ((x-1 <_pp->GetXPos()) && (_pp->GetXPos() < x+1) && (y-1 <_pp->GetYPos()) && (_pp->GetYPos() < y+1))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Robot::Read() {
	_pc->Read();
}

void Robot::setSpeed(float xSpeed, float angularSpeed) {
		_pp->SetSpeed(xSpeed, angularSpeed);
}

bool Robot::isRightFree() {
	if (_lp->GetMinRight() > FREE_DIST)
		return true;
	else
		return false;
}

bool Robot::isLeftFree() {
	if (_lp->GetMinLeft() > FREE_DIST)
		return true;
	else
		return false;
}


bool Robot::isForwardFree() {
	if ((*_lp)[375] > FREE_DIST)
		return true;
	else
		return false;
}

Robot::~Robot() {
	delete _pc;
	delete _pp;
	delete _lp;
}
