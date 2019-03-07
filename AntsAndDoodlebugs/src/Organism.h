/*
 * Organism.h
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include "Grid.h"



class Organism {
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	virtual int move(Grid* grid)=0;
	virtual bool breed(Grid* grid)=0;
	void setAmAnt(bool b);
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
