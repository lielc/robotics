/*
 * TurnRight.h
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "./Behavior.h"

class TurnRight: public Behavior {
public:

	TurnRight(Robot* robot);
	virtual ~TurnRight();
	bool startCondition();
	bool stopCondition();
	void action();
};

#endif /* TURNRIGHT_H_ */
