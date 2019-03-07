/*
 * Organism.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#include "Organism.h"
#include "Grid.h"
bool amAnt = false;
/*
 * Constructor for Organism
 * @return nothing
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}
/*
 * Another Constructor for organism
 * @param bool b, the boolean representing the identity of the organism
 * @return nothing
 */
Organism::Organism(bool b) {
	amAnt = b;

}
/*
 * Checks whether the organism is a prey or not
 * @ return bool, true for if it is an ant, false otherwise
 */
bool Organism::isPrey()
{
	return amAnt;
}
/*
 * Sets the amAnt variable of organism
 * @param bool b, the value to be setted
 * @return void, it just sets the variable
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}
/*
 * Destructor for Organism
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

