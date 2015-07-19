/*
* Main.cpp
*
*  Created on: Apr 14, 2015
*      Author: colman
*/

#include "Map.h"

vector<unsigned char> _map; //the raw pixels
unsigned _width, _height;
double _mapResolution;
int _gridResolution, _robotWidth, _robotDepth;

Map::Map()
{
	ConfigManager confManager;
	confManager.initializeConfParameters();
	_mapResolution = confManager.getMapResolution();
	_gridResolution = confManager.getGridResolution();
	_robotWidth = confManager.getRobotWidth();
	_robotDepth = confManager.getRobotDepth();
	loadImage("roboticLabMap.png");
}

Map::~Map(void)
{
	// Do nothing
}

int Map::getHeight()
{
	return _height;
}

int Map::getWidth()
{
	return _width;
}

//Decode from disk to raw pixels with a single function call
void Map::loadImage(string filename)
{
	//decode
	unsigned error = lodepng::decode(_map, _width, _height, filename);

	//if there's an error, display it
	if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}

//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void Map::saveImage(string filename, vector<unsigned char> image)
{
	//Encode the image
	unsigned error = lodepng::encode(filename, image, _width, _height);

	//if there's an error, display it
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}


// Converts the map from pixels to a simple grid consists of 1 and 0.
// 0 - black, 1 - white
int** Map::convertImageToGrid(vector <unsigned char> mapToConvert)
{
	int** imageToGrid = 0;
	imageToGrid = new int*[_height];

	// Goes over all the pixels of the image
	for (unsigned int h = 0; h < _height; h++)
	{
		imageToGrid[h] = new int[_width];

		for (unsigned int w = 0; w < _width; w ++)
		{
			if (mapToConvert[h * _width * 4 + w * 4] == 255
				&& mapToConvert[h * _width * 4 + w * 4 + 1] == 255
				&& mapToConvert[h * _width * 4 + w * 4 + 2] == 255)
			{
				imageToGrid[h][w] = FREE;
			}
			else
			{
				imageToGrid[h][w] = OCCUPIED;
			}
		}
	}

	return imageToGrid;
}

int** Map::convertImageToGridWithNewResolution(vector <unsigned char> mapToConvert)
{
	int resolutionRatio = ((int)(_gridResolution / _mapResolution) / 2);
	int resolutionCap = ((int)(resolutionRatio * resolutionRatio) / 2);

	int newHeight = (int)(_height / resolutionRatio);
	int newWidth = (int)(_width / resolutionRatio);

	int counter = 0;

	int** newResolutionMap = 0;
	newResolutionMap = new int*[newWidth];

	// Initializes the new map
	for (int i = 0; i < newHeight; i++)
	{
		newResolutionMap[i] = new int[newWidth];
	}

	// We are going to run through the map, in the resolution ratio, and create our new grid
	for (int h = 0; h < _height; h++)
	{
		for (int w = 0; w < _width; w++)
		{
			int map_pixel = h * _width * 4 + w * 4; // current map pixel

			for (int i = -resolutionRatio; i < resolutionRatio; i++)
			{
				for (int j = -resolutionRatio; j < resolutionRatio; j++)
				{
					int offset = _width * i * 4 + j * 4;

					if (map_pixel + offset >= 0 && map_pixel + offset + 3 < mapToConvert.size())
					{
						if (mapToConvert[map_pixel + offset] == 0
							|| mapToConvert[map_pixel + offset + 1] == 0
							|| mapToConvert[map_pixel + offset + 2] == 0)
						{
							counter++;
						}
					}
				}
			}

			// Check if there are enough black pixels to confirm the black pixel on the grid
			if (counter > resolutionCap)
			{
				newResolutionMap[h / resolutionRatio][w / resolutionRatio] = 1;
			}

			else
			{
				newResolutionMap[h / resolutionRatio][w / resolutionRatio] = 0;
			}

			counter = 0;
		}
	}

	_height = newHeight;
	_width = newWidth;

	return newResolutionMap;
}

vector <unsigned char> Map::inflateMap()
{
	// inflate the obstacles according to the map resolution
	//int hightToInflate = (int)((30 / 2.5));
	//int widthToInflate = (int)((30 / 2.5));

	int hightToInflate = (int)(_robotDepth / _mapResolution);
	int widthToInflate = (int)(_robotWidth / _mapResolution);

	// Creating a copy of the current image
	// inflated map will contain the inflated obstacles
	vector <unsigned char> inflatedMap = _map;

	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			int curr_pixel = y * _width * 4 + x * 4;

			// If the current cell is white
			if (_map[curr_pixel] == 255
				&& _map[curr_pixel + 1] == 255
				&& _map[curr_pixel + 2] == 255)
			{
				inflatedMap[curr_pixel] = 255;
				inflatedMap[curr_pixel + 1] = 255;
				inflatedMap[curr_pixel + 2] = 255;
			}

			else
			{
				// Inflating each cell surrounding it with more black cells
				for (int i = -hightToInflate; i < hightToInflate; i++) {
					for (int j = -widthToInflate; j < widthToInflate; j++) {

						// We multiply by 4 cause of bytes
						int inflationPixel = _width * i * 4 + j * 4; // Same calculation is current pixel

						// Check so that it wont go out of our permitted image buffer size
						if (curr_pixel + inflationPixel >= 0 && curr_pixel + inflationPixel + 3 < inflatedMap.size())
						{
							inflatedMap[curr_pixel + inflationPixel] = 0;
							inflatedMap[curr_pixel + 1 + inflationPixel] = 0;
							inflatedMap[curr_pixel + 2 + inflationPixel] = 0;
						}
					}
				}

			}
		}
	}

	//saveImage("../inflated.png", inflatedMap);
	//encodeOneStep("inflatedImage.png", inflatedImage, _height, _height);

	return inflatedMap;
}
