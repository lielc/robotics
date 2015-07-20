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

	// Asaf :D
	//Robot robot("10.10.245.64",6665);

	Manager manager(&robot);
	manager.run();
}
