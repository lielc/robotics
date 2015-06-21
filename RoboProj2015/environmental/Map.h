/*
 * Map.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_
#include <string>
#include "../Utils/lodepng.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int FREE = 0;
const int OCCUPIED = 1;

class Map {
	vector<unsigned char> _image;
	unsigned _width, _height;
public:
	Map();
	virtual ~Map();
	void loadMap(string mapPath);
	void convertWorldLocationToGridCell();
	void convertGridCellToWorldLocation();
};

#endif /* MAP_H_ */
