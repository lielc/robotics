/*
 * TurnUntilFree.h
 *
 *  Created on: Jun 25, 2015
 *      Author: colman
 */

#ifndef TURNUNTILFREE_H_
#define TURNUNTILFREE_H_


#include "./Behavior.h"

class TurnUntilFree: public Behavior{

public:

	TurnUntilFree(Robot* robot);
	virtual ~TurnUntilFree();
	bool startCondition();
	bool stopCondition();
	void action();
};

#endif /* TURNUNTILFREE_H_ */
