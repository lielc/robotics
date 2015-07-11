/*
 * node.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#include "node.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <stdlib.h>


int xPos;
int yPos;
int level;
int priority;
const int dir=8;

node::node(int xp, int yp, int d, int p)
{
	xPos=xp;
	yPos=yp;
	level=d;
	priority=p;
}
node::~node()
{

}
int node::getxPos() const
{
	return xPos;
}
int node::getyPos() const
{
	return yPos;
}
int node::getLevel() const
{
	return level;
}
int node::getPriority() const
{
	return priority;
}

const int & node::estimate(const int & xDest, const int & yDest) const
{
	static int xd, yd, d;
	xd=xDest-xPos;
	yd=yDest-yPos;

	d=abs(xd)+abs(yd);

	return(d);
}
void node::updatePriority(const int & xDest, const int & yDest)
{
	priority=level+estimate(xDest, yDest)*10;
}
void node::nextLevel(const int & i)
{
	level+=(dir==8?(i%2==0?10:14):10);
	//level+=10;
}
bool operator<(const node & a, const node & b)
{
	return (a.getPriority() > b.getPriority());
}


