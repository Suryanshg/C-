/*
 * Cell.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#include "Cell.h"
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"

/*
 * Constructor for a cell
 */
Cell::Cell() {

	guest = empty;
	ptr=(Organism*)nullptr;
}

/*
 * getter for ptr
 */
Organism* Cell::getPtr(){
	return ptr;
}

/*
 * setter for ptr
 * @param Organism* newPtr, the new pointer to replace the older one
 */
void Cell::setPtr(Organism* newPtr){
	ptr=newPtr;
}
/*
 * Sets the current cell to a given occupant
 * @param occupationStatus g, the status of occupant
 * @return bool, true if it succeeded, false otherwise
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;

	if(guest==empty)
	{
		guest = g;
	}
	else if(g==empty){
		guest=g;
	}
	else
	{
		result = false;
	}
	return result;
}

/*
 * sets the current cell's pointer to
 * 				Ant if the occupationStatus is ant
 * 				Doodlebug if the occupationStatus is doodlebug
 * 				Nullptr if the occupationStatus is empty
 *
 */
void Cell::NewPtr(int r,int c,occupationStatus g){
	if(g==ant){
		ptr= new Ant(r,c);
	}
	else if(g==doodlebug){
		ptr= new Doodlebug(r,c);

	}
	else if(g==empty){
		ptr=(Organism*)nullptr;
	}

}
/*
 * returns the current occupant in the cell
 * @return the current occupant
 * 			0 for empty
 * 			1 for Ant
 * 			2 for doodlebug
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}

/*
 * Destructor for a cell
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

