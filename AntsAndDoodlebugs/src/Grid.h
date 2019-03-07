/*
 * Grid.h
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"

class Grid {
public:
	Cell** board;
	int size=0;
	Grid();
	Grid(int nSquaresOnASide);
	Cell** getBoard();
	bool setCellOccupant(int r, int c, occupationStatus g);
	occupationStatus getCellOccupant(int r, int c);
	bool* findNeighbours(int r, int c,occupationStatus g);
	int randInt(int n);
	void printGrid();
	virtual ~Grid();
};

#endif /* GRID_H_ */
