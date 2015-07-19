/*
 * Robot.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */


#ifndef ROBOT_H_
#define ROBOT_H_
#include <libplayerc++/playerc++.h>

using namespace PlayerCc;
class Robot {
	PlayerClient*_pc;
	Position2dProxy* _pp;
	LaserProxy* _lp;
	PlannerProxy* _plp;
	static const double FREE_DIST = 1.0;
	static const double SPEED = 0.8;

public:
	Robot(char* ip, int port);
	void Read();
	void setSpeed(float xSpeed, float angularSpeed);
	bool isRightFree();
	bool isForwardFree();
	bool isLeftFree();
	void GoTo(double x, double y, double yaw, int Time);
	double GetSpeed();
	virtual ~Robot();
};

#endif /* ROBOT_H_ */
