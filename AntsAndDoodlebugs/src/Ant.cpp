/*
 * Ant.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#include "Ant.h"
#include "Grid.h"
#include "Cell.h"

/*
 *Constructor for an object of class Ant
 *@return nothing
 */
Ant::Ant()
//:Organism(true)
{

}
/*
 * Another constructor for Ant with rows and columns specified
 * @param int r, the current row of the ant
 * @param int c, the current column of the ant
 * @return nothing
 */
Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;


}

/*
 * getter for row
 */
int Ant::getRow(){
	return row;
}

/*
 * getter for column
 */
int Ant::getCol(){
	return col;
}

/*
 * getter for breedCounter
 */
int Ant::getBreedCounter(){
	return breedCounter;
}
/*
 * Moves the ant and returns the status
 * @param Grid* grid, the current grid
 * @return an int, 0 if it doesn't move
 * 				   1 if it moves without breeding
 * 				   2 if it moves and breeds
 */
int Ant::move(Grid* grid)
{
	int status = 0;
	bool* arrEmpty=grid->findNeighbours(row, col, empty);
	bool noSpace=true;//Assume there is no space to move
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
				grid->setCellOccupant(row,col,empty);
				breedCounter++;
				int oldrow=row;
				int oldcol=col;
				moveHelper(grid,dir);
				grid->getBoard()[oldrow][oldcol].setPtr((Organism*)nullptr);


			}
		}
	}

	bool bred=breed(grid);
	if(bred){
		if (status==1){//moved and bred
			status=2;
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
void Ant::moveHelper(Grid* grid,int dir){
	if(dir==0){
		grid->getBoard()[row-1][col].setPtr(grid->getBoard()[row][col].getPtr());
		row=row-1;

		grid->setCellOccupant(row, col, ant);
	}//Move North
	else if(dir==1){
		grid->getBoard()[row+1][col].setPtr(grid->getBoard()[row][col].getPtr());
		row=row+1;

		grid->setCellOccupant(row, col, ant);
	}//Move South
	else if(dir==2){
		grid->getBoard()[row][col+1].setPtr(grid->getBoard()[row][col].getPtr());
		col=col+1;

		grid->setCellOccupant(row, col, ant);
	}//Move East
	else if(dir==3){
		grid->getBoard()[row][col-1].setPtr(grid->getBoard()[row][col].getPtr());
		col=col-1;

		grid->setCellOccupant(row, col, ant);
	}//Move West
}

/*
 * Checks if the ant bred
 * @return a bool, true if the Ant bred, false otherwise
 */
bool Ant::breed(Grid* grid)
{
	bool status = false;
	if (breedCounter==3){
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
void Ant::breedHelper(Grid* grid,int dir){
	if(dir==0){
		grid->getBoard()[row-1][col].NewPtr(row-1, col, ant);


		grid->setCellOccupant(row-1, col, ant);
	}//Breed North
	else if(dir==1){
		grid->getBoard()[row+1][col].NewPtr(row+1, col, ant);


		grid->setCellOccupant(row+1, col, ant);
	}//Breed South
	else if(dir==2){
		grid->getBoard()[row][col+1].NewPtr(row, col+1, ant);


		grid->setCellOccupant(row, col+1, ant);
	}//Breed East
	else if(dir==3){
		grid->getBoard()[row][col-1].NewPtr(row, col-1, ant);


		grid->setCellOccupant(row, col-1, ant);
	}//Breed West
}


/*
 * Destructor for Ant
 * @return nothing
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

