/*
 * Map.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */
#include "../Utils/lodepng.h"
#ifndef MAP_H_
#define MAP_H_
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
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
