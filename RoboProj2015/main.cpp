/*
 * main.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Robot.h"
#include "Manager.h"

int main()
{
	Robot robot("localhost",6665);
	//PlnObstacleAvoid plnOA(&robot);
	Manager manager(&robot);
	manager.run();
}
