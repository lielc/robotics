/*
 * PathPlanner.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "PathPlanner.h"
#include "../environmental/Map.h"
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

class node
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

    public:
        node(int xp, int yp, int d, int p)
            {xPos=xp; yPos=yp; level=d; priority=p;}

        int getxPos() const {return xPos;}
        int getyPos() const {return yPos;}
        int getLevel() const {return level;}
        int getPriority() const {return priority;}

        void updatePriority(const int & xDest, const int & yDest)
        {
             priority=level+estimate(xDest, yDest)*10; //A*
        }

        // give better priority to going strait instead of diagonally
        void nextLevel(const int & i) // i: direction
        {
             level+=(dir==8?(i%2==0?10:14):10);
        }

        // Estimation function for the remaining distance to the goal.
        const int & estimate(const int & xDest, const int & yDest) const
        {
            static int xd, yd, d;
            xd=xDest-xPos;
            yd=yDest-yPos;

            d=abs(xd)+abs(yd);

            return(d);
        }
};

bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
}

string PathPlanner::pathFind(const int xStart, const int yStart, const int xEnd, const int yEnd, vector < pair<int,int> >* Points)
{
	Map* TempMap = new Map();
	int** TempGrid = TempMap->convertImageToGrid(TempMap->inflateMap());
	int const n=TempMap->getWidth();
	int const m=TempMap->getHeight();
	int** map = 0;
	int** closed_nodes_map = 0;
	int** open_nodes_map = 0;
	int** dir_map = 0;

	static priority_queue<node> pq[2];
	static int pqi;
	static node* n0;
	static node* m0;
	static int i, j, x, y, xdx, ydy;
	static char c;
	pqi=0;
	string path="";

	map = new int*[n];
	closed_nodes_map = new int*[n];
	open_nodes_map = new int*[n];
	dir_map = new int*[n];

	for(x=0;x<n;x++)
	{
		map[x] = new int[m];
		closed_nodes_map[x] = new int[m];
		open_nodes_map[x] = new int[m];
		dir_map[x] = new int[m];

		for(y=0;y<m;y++)
		{
			map[x][y]=TempGrid[y][x];
			open_nodes_map[x][y]=0;
			dir_map[x][y]=0;
			closed_nodes_map[x][y]=0;
		}
	}

	n0=new node(xStart, yStart, 0, 0);
	n0->updatePriority(xEnd, yEnd);
	pq[pqi].push(*n0);
	open_nodes_map[x-1][y-1]=n0->getPriority();

	while(!pq[pqi].empty())
	{
		n0=new node(pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),pq[pqi].top().getLevel(),pq[pqi].top().getPriority());
		x=n0->getxPos();
		y=n0->getyPos();
		pq[pqi].pop();
		open_nodes_map[x][y]=0;
		closed_nodes_map[x][y]=1;

		if(x==xEnd && y==yEnd)
		{

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
					pq[pqi].push(*m0);
					dir_map[xdx][ydy]=(i+dir/2)%dir;
				}
				else if(open_nodes_map[xdx][ydy]>m0->getPriority())
				{
					open_nodes_map[xdx][ydy]=m0->getPriority();
					dir_map[xdx][ydy]=(i+dir/2)%dir;

					while(!(pq[pqi].top().getxPos()==xdx && pq[pqi].top().getyPos()==ydy))
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
					pq[pqi].push(*m0);
				}
				else
				{
					delete m0;
				}
			}
		}
		delete n0;
	}
	return path;
}
