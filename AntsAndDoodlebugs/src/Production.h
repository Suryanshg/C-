/*
 * Production.h
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

class Production {
public:
	Production(int argc, char* argv[]);
	int seed=1;
	int timestepsLeft=1000;
	int gridSize=20;
	int numDoodlebugs=5;
	int numAnts=100;
	int pause=0;
	bool runProduction();
	virtual ~Production();
};

#endif /* PRODUCTION_H_ */
