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

public:
	Robot(char* ip, int port);
	void Read();
	void setSpeed(float xSpeed, float angularSpeed);
	bool isRightFree();
	bool isForwardFree();
	bool isLeftFree();
	virtual ~Robot();
};

#endif /* ROBOT_H_ */
