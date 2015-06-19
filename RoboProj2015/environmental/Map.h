/*
 * Map.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_
#include <string>
using namespace std;

class Map {
	int _mapResolutionCM;
	int _gridResolutionCM;
	//char _mapGrid[][];

public:
	Map();
	virtual ~Map();
	void loadMapToGrid(string mapPath);
	void convertWorldLocationToGridCell();
	void convertGridCellToWorldLocation();
};

#endif /* MAP_H_ */
