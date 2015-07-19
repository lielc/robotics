/*
 * Robot.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Robot.h"
#include "ConfigManager.h"
#include <libplayerc++/playerc++.h>
#include <unistd.h>

Robot::Robot(char* ip, int port) {
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);

	for(int i=0;i<15;i++)
		Read();
}

void Robot::GoTo(double x, double y, double yaw, int Time)
{
	_pp->GoTo(x,y,yaw);
	sleep(Time);
	_pp->SetOdometry(x,y,yaw);

}
double Robot::GetSpeed()
{
	return SPEED;
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
