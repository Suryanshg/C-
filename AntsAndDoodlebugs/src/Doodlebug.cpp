/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#include "Doodlebug.h"
#include "Grid.h"
/*
 * Constructor for Doodlebug
 */
Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub

}
/*
 * Constructor for Doodlebug
 */
Doodlebug::Doodlebug(int r, int c) {
	// TODO Auto-generated constructor stub
	row=r;
	col=c;

}
/*
 * getter for row
 */
int Doodlebug::getRow(){
	return row;
}

/*
 * getter for col
 */
int Doodlebug::getCol(){
	return deathCount;
}
/*
 * getter for breedCounter
 */
int Doodlebug::getBreedCounter(){
	return breedCounter;
}

/*
 * getter for deathCount
 */
int Doodlebug::getDeathCounter(){
	return deathCount;
}
/*
 * Moves the doodlebug and returns a response
 * @param Grid* grid, the current grid to move on
 * @return int, 0 if the doodlebug didn't move
 * 				1 if it moved but didn't breed
 * 				2 if it ate an ant but didn't breed
 * 				3 if it dies
 * 				4 if it moved and bred
 * 				5 if it ate and bred
 */
int Doodlebug::move(Grid* grid)
{
	int status = 0;
	bool* arrAnts=grid->findNeighbours(row, col, ant);
	bool noAnts=true;//check if there are ants to eat, initially false
	for(int i=0;i<4;i++){
		if(arrAnts[i]==true){
			noAnts=false;
			break;
		}
	}
	if(!noAnts){//if there are ants to eat
		while(status!=2){

			status=eat(grid,arrAnts);



		}

	}
	else{//move if there are empty spaces
		deathCount++;
		if (deathCount==3){
			grid->setCellOccupant(row, col, empty);
			//kill doodlebug
			grid->getBoard()[row][col].setPtr((Organism*)nullptr);

			status=3;
		}
		else{

			bool* arrEmpty=grid->findNeighbours(row, col, empty);
			bool noSpace=true;//check if there is empty space to move or not
			for(int i=0;i<4;i++){
				if(arrEmpty[i]==true){
					noSpace=false;
					break;
				}
			}
			if(!noSpace){//if there is space to move
				while(status!=1){
					int dir=grid->randInt(3);//random direction
					if (arrEmpty[dir]==true){//if allowed to move in that direction
						status=1;
						breedCounter++;
						grid->setCellOccupant(row,col,empty);
						int oldrow=row;
						int oldcol=col;

						moveHelper(grid,dir);
						grid->getBoard()[oldrow][oldcol].setPtr((Organism*)nullptr);


					}
				}
			}
		}
	}
	if(status!=3){
		bool bred=breed(grid);
		if(bred){
			if(status==1){
				status=4;//moved and bred
			}
			else if(status==2){
				status=5;//ate and bred
			}
		}
	}

	return status;
}

/*
 * Helper for the method move
 * @param Grid* grid, the current board
 * @param int dir, the direction to move,
 * 			0 for North
 * 			1 for South
 * 			2 for East
 * 			3 for West
 * @return nothing
 */

void Doodlebug::moveHelper(Grid* grid,int dir){
	if(dir==0){
		grid->getBoard()[row-1][col].setPtr(grid->getBoard()[row][col].getPtr());
		row=row-1;

		grid->setCellOccupant(row,col,empty);
		grid->setCellOccupant(row, col, doodlebug);
	}//Move North
	else if(dir==1){
		grid->getBoard()[row+1][col].setPtr(grid->getBoard()[row][col].getPtr());
		row=row+1;

		grid->setCellOccupant(row,col,empty);
		grid->setCellOccupant(row, col, doodlebug);
	}//Move South
	else if(dir==2){
		grid->getBoard()[row][col+1].setPtr(grid->getBoard()[row][col].getPtr());
		col=col+1;

		grid->setCellOccupant(row,col,empty);
		grid->setCellOccupant(row, col, doodlebug);
	}//Move East
	else if(dir==3){
		grid->getBoard()[row][col-1].setPtr(grid->getBoard()[row][col].getPtr());
		col=col-1;

		grid->setCellOccupant(row,col,empty);
		grid->setCellOccupant(row, col, doodlebug);
	}//Move West
}
/*
 * checks whether the Doodlebug bred or not
 * @return bool, true if it bred, false otherwise
 */
bool Doodlebug::breed(Grid* grid)
{
	bool status = false;
	if (breedCounter>=8){
		bool* arrEmpty=grid->findNeighbours(row, col, empty);
		bool noSpace=true;//assume that there is no space to breed
		for(int i=0;i<4;i++){
			if(arrEmpty[i]==true){
				noSpace=false;
				break;
			}
		}
		if(!noSpace){//if there is space to breed
			while(status!=true){
				int dir=grid->randInt(3);//random direction
				if (arrEmpty[dir]==true){//if allowed to breed in that direction
					status=true;
					breedCounter=0;
					breedHelper(grid,dir);
				}
			}
		}

	}
	return status;
}
/*
 * Helper for the method breed
 * @param Grid* grid, the current board
 * @param int dir, the direction to breed,
 * 			0 for North
 * 			1 for South
 * 			2 for East
 * 			3 for West
 * @return nothing
 */
void Doodlebug::breedHelper(Grid* grid,int dir){
	if(dir==0){
		grid->getBoard()[row-1][col].NewPtr(row-1, col, doodlebug);


		grid->setCellOccupant(row-1, col, doodlebug);
	}//Move North
	else if(dir==1){
		grid->getBoard()[row+1][col].NewPtr(row+1, col,doodlebug);


		grid->setCellOccupant(row+1, col, doodlebug);
	}//Move South
	else if(dir==2){
		grid->getBoard()[row][col+1].NewPtr(row, col+1, doodlebug);


		grid->setCellOccupant(row, col+1, doodlebug);
	}//Move East
	else if(dir==3){
		grid->getBoard()[row][col-1].NewPtr(row, col-1, doodlebug);


		grid->setCellOccupant(row, col-1, doodlebug);
	}//Move West
}
/*
 * checks whether the Doodlebug ate or not
 * @return bool, true if it ate, false otherwise
 */
int Doodlebug::eat(Grid* grid,bool* arrAnts)
{
	int status = 0;
	int dir=grid->randInt(3);//random direction to eat
	if(arrAnts[dir]==true){
		status=2;
		int oldrow=row;
		int oldcol=col;

		//kill ant
		//delete grid->getBoard()[row][col].ptr;
		deathCount=0;
		breedCounter++;
		moveHelper(grid,dir);
		grid->getBoard()[oldrow][oldcol].setPtr((Organism*)nullptr);
		grid->setCellOccupant(oldrow,oldcol,empty);

	}
	return status;
}
/*
 * Destructor for Doodlebug
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

