/*
 * Grid.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"



/*
 * Constructor for Grid
 */
Grid::Grid() {
	// TODO Auto-generated constructor stub
	board = (Cell**)nullptr;
	Grid(20); //calls general constructor with default value from command line
}

/*
 * Another Constructor for Grid
 * @param int nSquaresOnASide, the number of squares desired
 */
Grid::Grid(int nSquaresOnASide)
{
	size = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	board = new Cell* [size];  //first allocate array of row pointers

	for(int i=0 ; i < size ; i++)
	{
		board[i] = new Cell[size]; // allocate memory for columns in each row
	}
}

/*
 * getter for board
 */
Cell** Grid::getBoard(){
	return board;
}
/*
 * sets the given cell with a type of occupant
 * @param int r, the current row
 * @param int c, the current column
 * @param occupationStatus g, the occupant
 * @return bool, true if it succeeded, false otherwise
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{

	return board[r][c].setOccupant(g);
}

/*
 * returns the occupation status of the cell on the grid
 * @param int r, the current row
 * @param int c, the current column
 * @return the current occupation status for the cell on the grid
 * 			0 for empty
 * 			1 for Ant
 * 			2 for doodlebug
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return board[r][c].getOccupant();
}

/*returns an array of booleans whether a given type of organism is present
 * at the North,South,East and West direction of a given cell in the exact same order
 * of the directions
 * @param int r, the row of the cell
 * @param int c, the column of the cell
 * @param occupationStatus g, the type of organism we want to look for
 * @return an array of booleans of length 4 in the order NSWE
 * 		true,if it exists
 * 		false, otherwise
 */
bool* Grid::findNeighbours(int r, int c,occupationStatus g){
	bool* arr=new bool[4];
	for(int i=0;i<4;i++){
		arr[i]=false;
	}
	if(r>0){
		if(board[r-1][c].getOccupant()==g){
			arr[0]=true;
		}
	}//North
	if(r<size-1){
		if(board[r+1][c].getOccupant()==g){
			arr[1]=true;
		}
	}//South
	if(c<size-1){
		if(board[r][c+1].getOccupant()==g){
			arr[2]=true;
		}
	}//East
	if(c>0){
		if(board[r][c-1].getOccupant()==g){
			arr[3]=true;
		}
	}//West

	return arr;
}

/*returns a random integer from 0 to n
 *@param int n, the max value
 *@return int, an integer between 0 and n
 */
int Grid::randInt(int n){
	int x=rand();
	return x%(n+1);
}

/*
 * prints the grid
 */
void Grid::printGrid(){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(getCellOccupant(i,j)==empty){
				std::cout<<" ";
			}
			else if(getCellOccupant(i,j)==ant){
				std::cout<<"o";
			}
			else if(getCellOccupant(i,j)==doodlebug){
				std::cout<<"x";
			}
		}
		std::cout<<"\n";
	}
}
/*
 * Destructor for a grid
 */
Grid::~Grid() {

	for(int r=0; r < size; r++)
	{
		for(int c=0; c < size; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			board[r][c].~Cell(); // free memory for columns in each row
		}
	}

}

