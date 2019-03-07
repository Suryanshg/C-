/*
 * Doodlebug.h
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Grid.h"

class Doodlebug: public Organism {
private:
	int row = 0;
	int col = 0;
	int breedCounter=0;
	int deathCount=0;
public:
	Doodlebug();
	Doodlebug(int r=0, int c=0);
	int getRow();
	int getCol();
	int getBreedCounter();
	int getDeathCounter();
	int move(Grid* grid);
	void moveHelper(Grid* grid,int dir);
	void breedHelper(Grid* grid,int dir);
	bool breed(Grid* grid);
	int eat(Grid* grid,bool* arrAnts);
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
