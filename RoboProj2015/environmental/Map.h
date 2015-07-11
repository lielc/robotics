#ifndef MAP_H_
#define MAP_H_

#include "../Utils/lodepng.h"
#include "../ConfigManager.h"
#include <iostream>
#include <list>

using namespace std;

class Map {
public:
	const int FREE = 0;
	const int OCCUPIED = 1;

	Map(int mapResolution, int gridResolution);
	virtual ~Map(void);
	//void getImageInPixels(string mapPath);
	//int** getMapInNewResolution(int** map, int mapWidth, int mapHeight, int newPixelSize);

	vector<unsigned char> inflateMap();
	int** convertImageToGrid(vector<unsigned char> mapToConvert);
	int** convertImageToGridWithNewResolution(vector<unsigned char> mapToConvert);
	int getHeight();
	int getWidth();
	void loadImage(string imagePath);
	void saveImage(string newImagePath, vector<unsigned char> image);
};



#endif /* MAP_H_ */
