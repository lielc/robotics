/*
 * node.h
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#ifndef NODE_H_
#define NODE_H_

class node {
public:
	node(int xp, int yp, int d, int p);
	virtual ~node();
	int getxPos()const;
	int getyPos() const;
	int getLevel() const;
	int getPriority() const;
	const int & estimate(const int & xDest, const int & yDest) const;
	void updatePriority(const int & xDest, const int & yDest);
	void nextLevel(const int & i);

};

#endif /* NODE_H_ */
