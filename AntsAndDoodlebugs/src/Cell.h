/*
 * Cell.h
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#ifndef CELL_H_
#define CELL_H_




enum occupationStatus { empty, ant, doodlebug};

class Organism;

class Cell {
public:
	occupationStatus guest;
	Organism* ptr;
	Cell();
	bool setOccupant(occupationStatus g);
	void NewPtr(int r,int c,occupationStatus g);
	Organism* getPtr();
	void setPtr(Organism* newPtr);
	occupationStatus getOccupant();
	virtual ~Cell();
};

#endif /* CELL_H_ */
