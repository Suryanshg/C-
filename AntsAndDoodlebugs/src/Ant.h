/*
 * Ant.h
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Grid.h"


class Ant: public Organism {
private:
	int row = 0;
	int col = 0;
	int breedCounter=0;
public:
	Ant();
	Ant(int r=0, int c = 0);
	int getRow();
	int getCol();
	int getBreedCounter();
	int move(Grid* grid);
	void moveHelper(Grid* grid,int dir);
	void breedHelper(Grid* grid,int dir);
	bool breed(Grid* grid);
	 ~Ant();
};

#endif /* ANT_H_ */
