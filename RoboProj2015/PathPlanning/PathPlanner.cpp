/*
 * PathPlanner.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "PathPlanner.h"
#include "../environmental/Map.h"
#include "node.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

const int dir=8;
static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};

PathPlanner::PathPlanner() {

 }

PathPlanner::~PathPlanner() {
}



string PathPlanner::pathFind(const int xStart, const int yStart, const int xEnd, const int yEnd, vector < pair<int,int> >* Points)
{
	Map* TempMap = new Map();
	int** TempGrid = TempMap->convertImageToGridWithNewResolution(TempMap->inflateMap());
	int const n=(TempMap->getWidth());
	int const m=(TempMap->getHeight());
	int map[n][m];
	int closed_nodes_map[n][m];
	int open_nodes_map[n][m];
	int dir_map[n][m];

	static priority_queue<node*> pq[2];
	static int pqi;
	static node* n0;
	static node* m0;
	static int i, j, x, y, xdx, ydy;
	static char c;
	pqi=0;

	for(y=0;y<m;y++)
	{
		for(x=0;x<n;x++)
		{
			closed_nodes_map[x][y]=TempGrid[x][y];
			open_nodes_map[x][y]=0;
		}
	}

	n0=new node(xStart, yStart, 0, 0);
	n0->updatePriority(xEnd, yEnd);
	pq[pqi].push(n0);
	open_nodes_map[x][y]=n0->getPriority();

	while(!pq[pqi].empty())
	{
		n0=new node(pq[pqi].top()->getxPos(), pq[pqi].top()->getyPos(),pq[pqi].top()->getLevel(),pq[pqi].top()->getPriority());
		x=n0->getxPos();
		y=n0->getyPos();
		pq[pqi].pop();
		open_nodes_map[x][y]=0;
		closed_nodes_map[x][y]=1;

		if(x==xEnd && y==yEnd)
		{
			string path="";
			while(!(x==xStart && y==yStart))
			{
				pair<int,int> pnt;
				pnt.first = x;
				pnt.second = y;
				Points->push_back(pnt);
				j=dir_map[x][y];
				c='0'+(j+dir/2)%dir;
				path=c+path;
				x+=dx[j];
				y+=dy[j];
			}
			pair<int,int> pnt;
			pnt.first = x;
			pnt.second = y;
			Points->push_back(pnt);

			delete n0;


			while(!pq[pqi].empty())
			{
				pq[pqi].pop();
			}
			return path;
		}
		for (i=0;i<dir;i++)
		{
			xdx=x+dx[i];
			ydy=y+dy[i];

			if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || map[xdx][ydy]==1 || closed_nodes_map[xdx][ydy]==1))
			{
				m0=new node(xdx, ydy, n0->getLevel(),n0->getPriority());
				m0->nextLevel(i);
				m0->updatePriority(xEnd, yEnd);

				if(open_nodes_map[xdx][ydy]==0)
				{
					open_nodes_map[xdx][ydy]=m0->getPriority();
					pq[pqi].push(m0);
					dir_map[xdx][ydy]=(i+dir/2)%dir;
				}
				else if(open_nodes_map[xdx][ydy]>m0->getPriority())
				{
					open_nodes_map[xdx][ydy]=m0->getPriority();
					dir_map[xdx][ydy]=(i+dir/2)%dir;

					while(!(pq[pqi].top()->getxPos()==xdx && pq[pqi].top()->getyPos()==ydy))
					{
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop();

					if(pq[pqi].size()>pq[1-pqi].size())
					{
						pqi=1-pqi;
					}
					while(!pq[pqi].empty())
					{
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi=1-pqi;
					pq[pqi].push(m0);
				}
				else
				{
					delete m0;
				}
			}
		}
		delete n0;
	}
	return "";
}
